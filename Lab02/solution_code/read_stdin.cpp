#include <iostream>
#include <string>

int main() {
    std::string s {};
	
    // repeatedly get a line of input from standard input
    // when the End-of-File character is hit (Ctrl+D on Linux), the loop ends
    while (std::getline(std::cin, s)) {
        std::cout << s << std::endl;
    }
	
    return 0;
}
