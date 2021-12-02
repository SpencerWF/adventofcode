#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

// define character size
#define CHAR_SIZE 128

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
  if(rows == 0 || cols == 0)
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
  if(row >= rows_ || col >= cols_)
    throw "Matrix subscript out of bounds";
  return data_[cols_*row + col];
}
inline
double Matrix::operator() (unsigned row, unsigned col) const
{
  if(row >= rows_ || col >= cols_)
    throw "const Matrix subscript out of bounds";
  return data_[cols_*row + col];
}

struct coord {
	int x_coord;
	int y_coord;	
};

// C++ implementation of Trie Data Structure
int main() {
	std::vector<std::string> lines;
	std::vector<int> areas;
	std::string current_line;
	int max_x=0, max_y=0, pos_comma, dist, current_dist, max_area=0, region_counter=0;
	std::map<int, coord> coordinates;
	coord current_coord;

	lines = readFile("../../../input/2018/input11.txt");

	areas.push_back(0);

	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];
		//std::cout << current_line << std::endl;
		pos_comma = current_line.find_first_of(",");
		current_coord.x_coord = std::stoi(current_line.substr(0,pos_comma));
		current_coord.y_coord = std::stoi(current_line.substr(pos_comma+1,current_line.length() - pos_comma));
		if(current_coord.x_coord > max_x) {
			max_x = current_coord.x_coord;
		}
		if(current_coord.y_coord > max_y) {
			max_y = current_coord.y_coord;
		}
		coordinates[i+1] = current_coord;
		areas.push_back(0);
	}

	for(std::map<int, coord>::iterator it=coordinates.begin(); it!=coordinates.end(); ++it) {
		std::cout << it->first << ": " << it->second.x_coord << ", " << it->second.y_coord << std::endl;
	}

	Matrix layout(max_x+10, max_y+10);

	for(int i=0; i<max_x+10; i++) {
		for(int j=0; j<max_y+10; j++) {
			layout(i,j) = 0;
		}
	}

	for(int i=0; i<max_x+10; i++) {
		for(int j=0; j<max_y+10; j++) {
			for(std::map<int, coord>::iterator it=coordinates.begin(); it!=coordinates.end(); ++it) {
				current_coord = it->second;
				dist = abs(i - current_coord.x_coord) + abs(j - current_coord.y_coord);
				// std::cout << "Distance for point (" << i << ", " << j << ") is " << dist << std::endl;
				layout(i,j) += dist;

			}
		}
	}

	for(int i=0; i<max_x+10; i++) {
		for(int j=0; j<max_y+10; j++) {
			if(layout(i,j) < 10000) {
				region_counter++;
			}
		}
	}

	std::cout << "Region size is " << region_counter << std::endl;
}

