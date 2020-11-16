/* point.cpp
 * CSC 116 Fall 2019 - Lab 08
 */

#include <cmath>
#include "point.hpp"

// constructors

// student must implement this constructor
Point::Point(Point const & p) {
}

// student must implement this constructor
Point::Point(double x, double y) {
}

// student must implement this constructor
Point::Point() {
}

// return the X coordinate of the point
double Point::getX() const {
    // student code here
}

// return the Y coordinate of the point
double Point::getY() const {
    // student code here
}

// return a new point with the coordinates
// inverted:
//   the new point will have coordinates
// at (-getX(), -getY())
Point Point::operator-() const {
    // student code here
}

// Add two points together
// should return a new point
Point Point::operator+(Point const & p2) const {
	// student code here
}

// Multiple elements of the point by a scalar
// should return a new point
Point Point::operator*(double s) const {
	// student code here
}

// compute the distance between the current
// point and the point p2
double Point::distance(Point const & p2) const {
    // student code here
}

// add the operator << to allow printing directly to a stream
std::ostream & operator<< (std::ostream & output, Point const & p) {
    // student code here
}

std::ostream & operator<< (Point const & p, std::ostream & output) {
    // student code here
}
