#include <iostream>
#include <vector>
#include <string>

// two new parameters to main: 
//      - "argc" the number of command line arguments
//      - "argv" an array of strings containing the command line arguments
int main(int argc, char** argv) {
    std::vector<std::string> arguments {};
    int sum {0};
	
	// convert each command line argument into a std::string
	for (int i {1}; i < argc; i++) {
        arguments.push_back(argv[i]);
    }
	
    // sum the command line arguments
    for (auto arg : arguments) {
        // "std::stoi" converts a std::string into and int
        sum += std::stoi(arg);
    }
    std::cout << sum << std::endl;
	
    return 0;
}
