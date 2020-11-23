/* lab07.cpp

   CSC 116 Fall 2019 - Lab 7
   
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "matrix.hpp"

/* Do not modify the read_matrix function */
Matrix read_matrix() {
    std::cout << "Enter the number of rows and columns: " << std::endl;
    unsigned int rows {}, cols {};
    if (!(std::cin >> rows) || !(std::cin >> cols)) {
        throw std::runtime_error("Invalid row or column count");
    }
    std::cout << "Enter the elements of the matrix: " << std::endl;
    Matrix M(rows,cols,0);
    for(unsigned int i {0}; i < rows; i++) {
        for (unsigned int j {0}; j < cols; j++) {
            double element {};
            if (!(std::cin >> element)) {
                throw std::runtime_error("Invalid matrix element");
            }
            M.at(i,j) = element;
        }
    }
    std::cout << std::endl;
    std::cout << "Successfully read a matrix with dimensions " << rows << " x " << cols << std::endl;
    return M;
}


int main() {

    int test_case {};
	std::cout << "Run test case (1 or 2): ";
	std::cin >> test_case;
	std::cout << std::endl;
	if (!std::cin || !(test_case == 1 || test_case == 2)) {
		std::cout << "Invalid test case entered!" << std::endl;
		return 1;
	} else {
		std::cout << "Running test case " << test_case << std::endl;
	}

    if (test_case==1) {

        std::cout << "Reading matrix" << std::endl;
        Matrix M {0,0};
        try {
            M = read_matrix();
        } catch(std::runtime_error e) {
            std::cout << "Unable to read matrix: " << e.what() << std::endl;
            return 0;
        }
        std::cout << "M: " << std::endl;
        M.print();
        if (M.is_diagonal()) {
            std::cout << "M is diagonal." << std::endl;
        } else {
            std::cout << "M is not diagonal." << std::endl;
        }

        try {
            auto trace = M.trace();
            std::cout << "Trace of M: " << trace << std::endl;
        } catch(std::domain_error e) {
            std::cout << "Unable to compute trace: " << e.what() << std::endl;
        }

    } else if (test_case==2) {

        std::cout << "Reading first matrix" << std::endl;
        Matrix M1 {0,0};
        try {
            M1 = read_matrix();
        } catch (std::runtime_error e) {
            std::cout << "Unable to read matrix: " << e.what() << std::endl;
            return 0;
        }
        std::cout << "M1: " << std::endl;
        M1.print();
        std::cout << "Reading second matrix" << std::endl;
        Matrix M2 {0,0};
        try {
            M2 = read_matrix();
        } catch (std::runtime_error e) {
            std::cout << "Unable to read matrix: " << e.what() << std::endl;
            return 0;
        }
        std::cout << "M2: " << std::endl;
        M2.print();

        std::cout << "M1 == M2? " << ((M1==M2)?"true":"false") << std::endl;
        std::cout << "M1 != M2? " << ((M1!=M2)?"true":"false") << std::endl;
        std::cout << "2*M1:" << std::endl;
        (2*M1).print();
        std::cout << "3*M1:" << std::endl;
        (3*M1).print();
        std::cout << "M1*4:" << std::endl;
        (M1*4).print();
        
        try {
            std::cout << "M1+M2:" << std::endl;
            (M1+M2).print();
            std::cout << "M1-M2:" << std::endl;
            (M1-M2).print();
        } catch( std::domain_error e ) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    }
    return 0;
}
