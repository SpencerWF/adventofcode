#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<std::string> readFile(std::string filename) {
	int currentLength = 1;

	std::vector<std::string> subwords;

	//Opening file to extract words
	std::ifstream file;
	file.open (filename);
	if (!file.is_open()) return subwords;

	//Put words into a vector of strings
	std::string word;
	while (std::getline(file, word))
	{
		subwords.push_back(word);
	}
	file.close();
	return subwords;
}

class Matrix {
public:
  Matrix(unsigned rows, unsigned cols);
  double& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  double  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs
  // ...
 ~Matrix();                              // Destructor
  Matrix(const Matrix& m);               // Copy constructor
  Matrix& operator= (const Matrix& m);   // Assignment operator
  // ...
private:
  unsigned rows_, cols_;
  double* data_;
};
inline
Matrix::Matrix(unsigned rows, unsigned cols)
  : rows_ (rows)
  , cols_ (cols)
//, data_ ← initialized below after the if...throw statement
{
  if (rows == 0 || cols == 0)
    throw "Matrix constructor has 0 size";
  data_ = new double[rows * cols];
}
inline
Matrix::~Matrix()
{
  delete[] data_;
}
inline
double& Matrix::operator() (unsigned row, unsigned col)
{
  if (row >= rows_ || col >= cols_)
    throw "Matrix subscript out of bounds";
  return data_[cols_*row + col];
}
inline
double Matrix::operator() (unsigned row, unsigned col) const
{
  if (row >= rows_ || col >= cols_)
    throw "const Matrix subscript out of bounds";
  return data_[cols_*row + col];
}

struct cloth_square {
	unsigned column_start, column_end;
	unsigned row_start, row_end;
};


// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> lines;
	std::vector<cloth_square> squares;
	std::string current_line;
	cloth_square current_square;
	int pos_at, pos_comma, pos_colon, pos_x;
	unsigned max_x=0, max_y=0, cloth_count=0;
	bool overlap_check;

	lines = readFile("../../../input/2018/input5.txt");

	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];
		//std::cout << current_line << std::endl;
		pos_at = current_line.find_first_of("@");
		pos_comma = current_line.find_first_of(",");
		pos_colon = current_line.find_first_of(":");
		pos_x = current_line.find_first_of("x");

		current_square.column_start = std::stoi(current_line.substr(pos_at + 1,pos_comma-pos_at-1));
		current_square.row_start = std::stoi(current_line.substr(pos_comma + 1,pos_colon-pos_comma-1));

		current_square.column_end = std::stoi(current_line.substr(pos_colon + 1,pos_x-pos_colon-1));
		current_square.row_end = std::stoi(current_line.substr(pos_x + 1,current_line.length()));

		if((current_square.column_start + current_square.column_end) > max_x) {
			max_x = current_square.column_start + current_square.column_start;
		}

		if((current_square.row_start + current_square.row_end) > max_y) {
			max_y = current_square.row_start + current_square.row_end;
		}
		squares.push_back(current_square);
		//std::cout << max_x << " : " << max_y << " these are type " << std::endl;
	}

	Matrix cloth(max_x, max_y);

	for(int i=0; i<max_x; i++) {
		for(int j=0; j<max_y; j++) {
			cloth(i,j)=0;
		}
	}

	for(int i=0; i<squares.size(); i++) {
		current_square = squares[i];
		for(int j=current_square.column_start; j<current_square.column_start + current_square.column_end; j++) {
			for(int k=current_square.row_start; k<current_square.row_start + current_square.row_end; k++) {
				cloth(j,k)++;
			}
		}
	}

	for(int i=0; i<squares.size(); i++) {
		current_square = squares[i];
		overlap_check = true;
		for(int j=current_square.column_start; j<current_square.column_start + current_square.column_end; j++) {
			for(int k=current_square.row_start; k<current_square.row_start + current_square.row_end; k++) {
				if(cloth(j,k) > 1) {
					overlap_check = false;

				}
			}
		}
		if(overlap_check == true) {
			std::cout << "The not overlapping square is: " << i+1 << std::endl;
			break;
		}
	}
}