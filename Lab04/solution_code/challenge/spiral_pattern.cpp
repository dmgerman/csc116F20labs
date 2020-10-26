#include <iostream>
#include <vector>

using matrix_type = std::vector<std::vector<int>>;

// helper function which checks if (0 <= value < bound)
bool inbounds(int value, size_t bound) {
	return (value >= 0) && (value < static_cast<int>(bound));
} 

// draws the spiral pattern inside the provided square matrix
void draw_spiral(matrix_type& matrix) {
	// find the center index position
	int row {static_cast<int>(matrix.size()) / 2};
	int column {static_cast<int>(matrix.size()) / 2};

	// "value" is the integer value to write into the matrix
	// "bead" is the number of times "value" will be written to the matrix
	size_t value {1}, bead {1};

	// control variable to indicate how to move the index position each iteration
	bool direction {true};

	// loop until one of the indexes is out of bounds
	while (inbounds(row, matrix.size()) && inbounds(column, matrix.size())) {
		matrix.at(row).at(column) = value;
		--bead;

		// if the value written was odd, "row" changes
		if (value % 2) {
			if (direction) {
				--row;
			} else {
				++row;
			}
		// if the value written was even, "column" changes
		} else {
			if (direction) {
				--column;
			} else {
				++column;
			}
		}

		// if the bead of "value" has finished, refresh "bead" and "value"
		if (!bead) {
			bead = ++value;

			// "direction" only changes when value is odd
			if (value % 2) {
				direction = !direction;
			}
		}
	}
}

// helper function which prints the provided matrix
void print(const matrix_type& matrix) {
	for (auto& row : matrix) {
		for (auto value : row) {
			std::cout << value << ' ';
		}
		std::cout << std::endl;
	}
}

int main(int argc, char** argv) {
	// check that the user provided a command line argument
	if (argc != 2) {
		std::cout << "One integer command line argument must be provided\n";
		return EXIT_FAILURE;
	}

	size_t dimension {0};

	// attempt to convert the command line argument into an integer
	try {
		// stoi can throw an "invalid_argument"
		int test {std::stoi(argv[1])};

		if (test < 0) {
			// the "catch" block will catch this exception if thrown
			throw std::invalid_argument("Command line argument was negative");
		}
		dimension = static_cast<int>(test);
	} catch (std::invalid_argument& e) {
		std::cout << "The command line argument must be a positive integer\n";
		return EXIT_FAILURE;
	}

	// create an "empty" square matrix from the dimension
	matrix_type matrix {dimension, std::vector<int>(dimension, 0)};

	// student implements this function
	draw_spiral(matrix);

	print(matrix);

	return EXIT_SUCCESS;
}
