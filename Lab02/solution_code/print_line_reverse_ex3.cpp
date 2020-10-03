#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> lines {};
    std::string line {};
	
    // read a line of text from standard input, then push it to a vector
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    // when initializing "i" with "{...}", you must explicitly cast differing types
    //      in this case lines.size() is an "unsigned int" and is casted to an integer using "(int)"
    for (int i {(int) lines.size() - 1}; i >= 0; --i) {
        std::cout << lines.at(i) << std::endl;
    }
	
    return 0;
}
