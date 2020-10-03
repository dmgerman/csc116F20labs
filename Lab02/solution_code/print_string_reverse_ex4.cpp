#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> lines {};
    std::string curr_line {};
	
    while (std::getline(std::cin, curr_line)) {
        lines.push_back(curr_line);
    }

    // loop through the vector of lines in reverse
    for (int i {(int) lines.size() - 1}; i >= 0; --i) {
        curr_line = lines.at(i);
		
        // a line is a sequence of characters
        // by looping through the line in reverse, we can print the character sequence in reverse
        for (int j {(int) curr_line.size() - 1}; j >= 0; --j) {
            std::cout << curr_line.at(j);
        }
        std::cout << std::endl;
    }
	
    return 0;
}
