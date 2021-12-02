#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

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

struct star {
	int x_coord;
	int y_coord;
	int x_vel;
	int y_vel;	
};

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

std::vector<star> extract_stars(std::vector<std::string> lines) {
	std::vector<star> stars;
	star current_star;
	std::string current_line;

	int pos_r_arrow, pos_comma, pos_l_arrow;

	for(int i=0; i<lines.size(); i++) {
		current_line = lines[i];
		pos_l_arrow = current_line.find_first_of("<");
		pos_comma = current_line.find_first_of(",");
		pos_r_arrow = current_line.find_first_of(">");

		current_star.x_coord = std::stoi(current_line.substr(pos_l_arrow+1, pos_comma));
		current_star.y_coord = std::stoi(current_line.substr(pos_comma+1,pos_r_arrow));

		pos_l_arrow = current_line.find_first_of("<", pos_l_arrow+1);
		pos_comma = current_line.find_first_of(",", pos_comma+1);
		pos_r_arrow = current_line.find_first_of(">", pos_r_arrow+1);

		current_star.x_vel = std::stoi(current_line.substr(pos_l_arrow+1, pos_comma));
		current_star.y_vel = std::stoi(current_line.substr(pos_comma+1,pos_r_arrow));

		// std::cout << "Star " << i << " :" << current_star.x_coord << ", " << current_star.y_coord << std::endl;

		stars.push_back(current_star);
	}

	return stars;
}

int main() {
	std::vector<star> stars;
	std::vector<std::string> lines;
	int adjacent_count=0, second_count, max_count=0;
	star current_star;
	int max_x = 0, min_x = 0 , max_y = 0, min_y = 0, x_size, y_size;
	std::map<int, int> adjacent_counts;

	lines = readFile("../../../input/2018/input19.txt");
	stars = extract_stars(lines);

	for(int j=0; j<stars.size(); j++) {
		stars[j].x_coord = stars[j].x_coord + stars[j].x_vel*10830;
		stars[j].y_coord = stars[j].y_coord + stars[j].y_vel*10830;
	}



	for(second_count=10830; second_count < 10950; second_count++) {
		adjacent_count = 0;
		for(int j=0; j<stars.size(); j++) {
			stars[j].x_coord = stars[j].x_coord + stars[j].x_vel;
			stars[j].y_coord = stars[j].y_coord + stars[j].y_vel;
		}

		max_x = min_x = stars[0].x_coord;
		max_y = min_y = stars[0].y_coord;

		for(int i=0; i<stars.size(); i++){
			current_star = stars[i];
			max_x = (current_star.x_coord > max_x) ? current_star.x_coord : max_x;
			max_y = (current_star.y_coord > max_y) ? current_star.y_coord : max_y;
			min_x = (current_star.x_coord < min_x) ? current_star.x_coord : min_x;
			min_y = (current_star.y_coord < min_y) ? current_star.y_coord : min_y;
		}
		x_size = abs(max_x-min_x+1);
		y_size = abs(max_y-min_y+1);
		Matrix sky(x_size, y_size);

		for(int i=0; i<x_size; i++) {
			for(int j=0; j<y_size; j++) {
				sky(i,j) = 0;
			}
		}
		std::cout << "max: " << max_x << ":" << max_y << std::endl << "min: " << min_x << ":" << min_y << std::endl;

		for(int i=0; i<stars.size(); i++) {
			std::cout << "Star " << i << " pos: " << stars[i].x_coord-min_x << ", " << stars[i].y_coord-min_y << std::endl;
			sky(stars[i].x_coord-min_x, stars[i].y_coord-min_y) = 1;
		}



		for(int i=0; i<y_size; i++) {
			for(int j=0; j<x_size; j++) {
				if(sky(j,i)) {
					std::cout << "#";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
		std::cout << second_count << std::endl;
		getchar();

		// for(int j=0; j<stars.size(); j++) {
		// 	for(int k=j; k<stars.size(); k++) {
		// 		if(abs(stars[j].x_coord - stars[k].x_coord) + abs(stars[j].y_coord-stars[k].x_coord) <= 2) {
		// 			adjacent_count++;
		// 		}
		// 	}
		// }
		// max_count = adjacent_count > max_count ? adjacent_count : max_count;
		// adjacent_counts[second_count] = adjacent_count;
		// std::cout << "Second " << second_count << " has more than " << adjacent_count << " adjacent stars" << std::endl;
	}

	std::cout << std::endl;
}

