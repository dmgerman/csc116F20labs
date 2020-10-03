#include <iostream>
#include <vector>

int main() {
	int num {};
	std::vector<int> vec {};
	// example solution uses another vector to store sorted input 
	std::vector<int> sorted {};

	// There are many ways to approach this problem.  The solution uses
	// the following approach:
	// If std::cin contains a valid int, do the following:
	// - append num to the end of vec
	// - find the position in sorted at which num belongs (position i)
	// - Insert num in position i of sorted
	// If std::cin does not contain a valid int, break from the infinite loop
	for (;;) { // Infinite loop
		std::cout << "Enter a number: ";
		// Read in next line
		if (std::cin >> num) {
			vec.push_back(num);
			
			// "i" is used outside the scope of the for-loop, so it must be declared outside the for-loop
			size_t i {0};

			// iterate through sorted vector to find position to insert new value
			for (; i < sorted.size(); ++i) {
				if(sorted.at(i) >= num) { 
					break; 
				}
			} 

			sorted.insert(sorted.begin() + i, num);
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

	std::cout << "Values (reverse): ";
	for (int i = vec.size() - 1; i >= 0; --i) {
		std::cout << vec.at(i) << ' ';
	}
	std::cout << std::endl;
	
	// for-each loop works fine here since the elements are in sorted order
	std::cout << "Values (sorted): ";
	for (auto val : sorted) {
		std::cout << val << ' ';
	}
	std::cout << std::endl;
	
	return 0;
}
