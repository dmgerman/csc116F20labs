#include <iostream>
#include <vector>

int main() {
	int num {};
	std::vector<int> vec {};

	for (;;) { // infinite loop
		std::cout << "Enter a number: ";
		// Read in next line
		if (std::cin >> num) {
			vec.push_back(num);			
		} else {
			// We're done reading numbers.. break out of loop!
			std::cout << "Input was invalid.\n";
			break;
		}
	}
	
	std::cout << "vec contains " << vec.size() << " elements\n";

	std::cout << "Values (forwards): ";
	for (auto val : vec) {
		std::cout << val << ' ';
	}
	std::cout << std::endl;

	// To display the values in reverse orders, the for-each loop
	// is not usable. vec.at(i) can be used to access the contents
	// of the ith element of vec. 
	// NOTE: the first element is accessed with vec.at(0)
	// because of this, the last element is always vec.at(vec.size() - 1)
	std::cout << "Values (reverse): ";
	for (int i = vec.size() - 1; i >= 0; --i) {
		std::cout << vec.at(i) << ' ';
	}
	std::cout << std::endl;
	
	return 0;
}
