/*
 * part3.cpp
 * CSC 116 Fall 2019 - Lab 08
 */

#include <iostream>
#include <string>

#include "square.hpp"
#include "point.hpp"

int main() {

  Square square1 { Point(), 2 };

  std::cout << "Square1 name: " << square1.name() << std::endl;
  std::cout << "Square1 area: "  << square1.area() << std::endl;
  std::cout << "Square1 dimensions: "  << square1.width() << " x " << square1.height() << std::endl;
  std::cout << "Square1 center: "  << square1.center() << std::endl;
  std::cout << "Square1 min/max: " << square1.getMin() << " " << square1.getMax() << std::endl;

  Square square2 { {1, 2} , 3 };
  std::cout << "Square2 name: " << square2.name() << std::endl;
  std::cout << "Square2 area: "  << square2.area() << std::endl;
  std::cout << "Square2 dimensions: "  << square2.width() << " x " << square2.height() << std::endl;
  std::cout << "Square2 center: " << square2.center() << std::endl;
  std::cout << "Square2 min/max: " << square2.getMin() << " " << square2.getMax() << std::endl;

  return 0;
}
