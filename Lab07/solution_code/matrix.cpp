/* matrix.cpp
   CSC 116 Fall 2019 - Lab 7
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include "matrix.hpp"


/* Constructor( num_rows, num_cols )
   Create a matrix of the given size, with all values
   set to zero.
*/
Matrix::Matrix(unsigned int num_rows, unsigned int num_cols) : Matrix (num_rows, num_cols, 0) {
    // Nothing to do here because we've called the other constructor above
}

/* Constructor( num_rows, num_cols, initial_value, default_value )
   Create a matrix of the given size, with all values
   set to the default value provided.
*/
Matrix::Matrix(unsigned int num_rows, unsigned int num_cols, double default_value) {
    // fill vector with num_rows entries, each defaulting to an empty vector of doubles
    entries.resize(num_rows, std::vector<double>(num_cols, default_value));
}

/* get_num_rows()
   Return the number of rows in the matrix
*/
unsigned int Matrix::get_num_rows() const {
    return entries.size();
}

/* get_num_cols()
   Return the number of columns in the matrix
*/
unsigned int Matrix::get_num_cols() const {
    if (get_num_rows() == 0) {
        return 0;
    }
    // we can assume the matrix is rectangular, thus all rows have same number of columns
    return entries.at(0).size();
}

/* print()
   Output the matrix to standard output
*/
void Matrix::print() const {
    for(unsigned int i {0}; i < get_num_rows(); i++) {
        for(unsigned int j {0}; j < get_num_cols(); j++)
            std::cout << at(i,j) << " ";
        std::cout << std::endl;
    }
}

/* at(i,j)
   Return a reference to the element at row i, column j.
   If the provided indices are out of range, throw an instance
   of std::out_of_range with the message "Invalid indices"
*/
double& Matrix::at(unsigned int i, unsigned int j) {
    // i & j never negative because they're unsigned ints
    if (i < get_num_rows() && j < get_num_cols()) {
        return entries.at(i).at(j);
    }
    throw std::out_of_range("Invalid indices");
}

/* at(i,j)
   Return a constant reference to the element at row i, column j.
   If the provided indices are out of range, throw an instance
   of std::out_of_range with the message "Invalid indices"
*/
double const & Matrix::at(unsigned int i, unsigned int j) const {
    // i & j never negative because they're unsigned ints
    if (i < get_num_rows() && j < get_num_cols()) {
        const double & val = entries.at(i).at(j);
        return val;
    }
    throw std::out_of_range("Invalid indices");
}


/* trace()
   Compute and return the trace of this matrix.
   The trace of a square matrix is the sum of the diagonal entries.
   For example, the trace of the matrix
      1 2 3
      4 5 6
      7 8 9
   is 15.
   If this matrix is not square, the method must throw a std::domain_error
   with message "Unable to compute trace of a non-square matrix".
*/
double Matrix::trace() const {
    if (get_num_cols() != get_num_rows()) {
        throw std::domain_error("Unable to compute trace of a non-square matrix");
    }
    double sum {0};
    for (unsigned int i = 0; i < get_num_cols(); i++) {
        sum += at(i, i);
    }
    return sum;
}

/* is_diagonal()
   Return true if this matrix is square and diagonal (that is, if all of the non-diagonal
   elements are 0) and false otherwise.
*/
bool Matrix::is_diagonal() const {
    if (get_num_cols() != get_num_rows()) {
        return false;
    }
    // if matrix is empty, then it is vacuously true that it is diagonal
    // in that case, we never enter the for loops and return true
    for (unsigned int i = 0; i < get_num_rows(); i++) {
        for (unsigned int j = 0; j < get_num_cols(); j++) {
            if (i != j && at(i,j) != 0) {
                return false;
            }
        }
    }
    return true;
}

/* *** Part 2 *** */

/* Methods of Matrix class */

/* operator- (other_matrix)
   Compute the difference between this matrix and the provided matrix
   and return the result.
   If the provided matrix does not have matching dimensions to this
   matrix, throw a std::domain_error with the message "Incompatible dimensions"
*/
Matrix Matrix::operator-( Matrix const & other_matrix ) const {
    if (get_num_cols() != other_matrix.get_num_cols() || get_num_rows() != other_matrix.get_num_rows()) {
        throw std::domain_error("Incompatible dimensions");
    }
    Matrix result(get_num_rows(), get_num_cols());
    for (unsigned int i = 0; i < get_num_rows(); i++) {
        for (unsigned int j = 0; j < get_num_cols(); j++) {
            result.at(i,j) = at(i,j) - other_matrix.at(i,j);
        }
    }
    return result;
}

/* operator+ (other_matrix)
   Compute the sum of this matrix and the provided matrix
   and return the result.
   If the provided matrix does not have matching dimensions to this
   matrix, throw a std::domain_error with the message "Incompatible dimensions"
*/
Matrix Matrix::operator+( Matrix const & other_matrix ) const {
    if (get_num_cols() != other_matrix.get_num_cols() || get_num_rows() != other_matrix.get_num_rows()) {
        throw std::domain_error("Incompatible dimensions");
    }
    Matrix result(get_num_rows(), get_num_cols());
    for (unsigned int i = 0; i < get_num_rows(); i++) {
        for (unsigned int j = 0; j < get_num_cols(); j++) {
            result.at(i,j) = at(i,j) + other_matrix.at(i,j);
        }
    }
    return result;
}

/* operator*(scalar)
   Compute and return the product of this matrix and the provided scalar value.
   This only covers multiplication by a scalar on the right. Multiplication
   by a scalar on the left cannot be handled by an operator which is part of the class.
*/
Matrix Matrix::operator*( double scalar ) const {
    Matrix result(get_num_rows(), get_num_cols());
    for (unsigned int i = 0; i < get_num_rows(); i++) {
        for (unsigned int j = 0; j < get_num_cols(); j++) {
            result.at(i,j) = at(i,j) * scalar;
        }
    }
    return result;
}


/* Functions outside Matrix class */


/* operator*( scalar, M )
   Compute and return the product of the provided scalar and provided matrix.
   Note that this operator is not part of the Matrix class, and therefore
   does not have access to the private members of that class, unless you add
   a friend directive for it.
*/
// NOTE: this function must be implemented outside the class because its first arg is not a Matrix object
Matrix operator*( double scalar, Matrix const &  M ) {
    // we use the other operator overload that we implemented above
    return M * scalar;
}

/* Floating point types should never be compared for equality directly,
   since they have inherent inaccuracies. Instead, use the function below
   to test whether two doubles are equal to within a tolerance of 10^{-7}.
*/
bool doubles_equal( double a, double b ) {
    return fabs(a-b) < 1e-7;
}

/* operator==( M1, M2 )
   Return true if M1 and M2 have the same dimensions and
   are equal (element-wise) and false otherwise.
   Use the doubles_equal function above to compare values.
*/
bool operator==(Matrix const & M1, Matrix const & M2) {
    if (M1.get_num_cols() != M2.get_num_cols() || M1.get_num_rows() != M2.get_num_rows()) {
        return false;
    }
    // at this point, we know M1 and M2 have the same dims
    Matrix result(M1.get_num_rows(), M1.get_num_cols());
    for (unsigned int i = 0; i < M1.get_num_rows(); i++) {
        for (unsigned int j = 0; j < M1.get_num_cols(); j++) {
            if (!doubles_equal(M1.at(i,j), M2.at(i,j))) {
                return false;
            }
        }
    }
    return true;
}
/* operator!=( M1, M2 )
   Return true if M1 and M2 are not equal. This should
   have the opposite behavior to the == operator.
*/
bool operator!=(Matrix const & M1, Matrix const & M2) {
    // we use the other operator overload that we implemented above
    return !(M1 == M2);
}