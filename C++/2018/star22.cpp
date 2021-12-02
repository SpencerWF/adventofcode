#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <array>
#include <map>

#define GRID 1133
#define GRID_SIZE 300

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

int main() {
	int x_location, y_location, power_total=0, power_buffer = 0, square_size=1, sel_square, edge, greater, power_max=0, add_count;
	Matrix battery_set(GRID_SIZE, GRID_SIZE);
	std::string hundreds;
	int buffer;

	std::cout << "Running fine" << std::endl;

	for(int i=0; i<GRID_SIZE; i++) {
		for(int j=0; j<GRID_SIZE; j++) {
			battery_set(i,j) = (i+10)*((i+10)*j+GRID);
			// std::cout << "Battery " << i << "," << j << " has a value of " << battery_set(i,j);
			if(battery_set(i,j) > 99){
				buffer = battery_set(i,j);
				buffer = (buffer%1000)/100;
				battery_set(i,j) = buffer-5;
			}
			else{battery_set(i,j)=0;}
			if(battery_set(i,j) > 0) {
				power_max += battery_set(i,j);
			}
		}
	}

	std::cout << "Maximum power is " << power_max << std::endl;

	for(int i=0; i<GRID_SIZE; i++) {
		for(int j=0; j<GRID_SIZE; j++) {
			greater = (i > j ? i : j) -1;
			add_count=1;
			power_buffer = battery_set(i,j);
			for(;square_size<GRID_SIZE-greater;square_size++) {
				// std::cout << "square_size is " << square_size << " for " << i << "," << j << std::endl;
				edge = square_size-1;
				for(int k=0; k<square_size-1; k++) {
					power_buffer += battery_set(i+edge,j+k);
					add_count++;
				}

				for(int k=0; k<square_size-1; k++) {
					power_buffer += battery_set(i+k, j+edge);
					add_count++;
				}
				if(square_size > 1) {
					power_buffer += battery_set(i+square_size-1,j+square_size-1);
					add_count++;
				}
				//For k=square size -1, need all coords with 0<=l<squaresize
				if(power_buffer > power_total) {
					power_total = power_buffer;
					x_location = i;
					y_location = j;
					sel_square = square_size;
					std::cout << "Location for highest power density is: " << x_location << ", " << y_location << " with square size " << sel_square << std::endl;
					std::cout << add_count << " locations added for square size " << square_size << " while power total is " << power_total << std::endl;

				}
			}
			square_size = 1;
		}
	}
	
	std::cout << "Location for highest power density is: " << x_location << ", " << y_location << " with square size " << sel_square << " and power of " << power_total << std::endl;
	std::cout << std::endl;
}

