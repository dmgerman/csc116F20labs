#include <iostream>
#include <vector>

int main() {
	int num {};
	std::vector<int> vec {};

	// Alternate method of looping demonstrated here.  
	// Recall that in ex1 we used: 
	// 	while(std::cin >> num)
	// in this case, an infinite loop has been made with 
	// 	for(;;)  
	// and a break statement is used to exit the loop.
	for(;;) {
		std::cout << "Enter a number: ";
		// Read in next line
		if(std::cin >> num) {
			vec.push_back(num);			
		} else {
			// We're done reading numbers... break out of loop!
			std::cout << "Input was invalid." << std::endl;
			break;
		}
	}
	std::cout << "Number of Values Entered: " << vec.size() << std::endl;

	std::cout << "Values: ";
	for(auto val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
