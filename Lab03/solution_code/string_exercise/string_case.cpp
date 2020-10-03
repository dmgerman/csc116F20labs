/* string_case.cpp
   CSC 116 - Fall 2019 - Lab 3
   Various functions involving uppercase and lowercase letters.
   Warning: The code below contains several bugs.
   Exercise: Find and fix the bugs.
*/
#include <iostream>
#include <string>
#include <cctype>

/* count_case(s, uppercase, lowercase)
   Count the number of uppercase and lowercase letters in the provided
   string s. The respective counts of each type of letter are stored
   in the provided integer references.
   The functions isupper(c) and islower(c), in cctype.h, may be useful
   for deciding if a character is uppercase or lowercase.
*/
void count_case(std::string const &s, int &lower_case, int &upper_case) {
    lower_case = 0;
    upper_case = 0;
    for(auto c : s) {
        if(std::islower(c)) {
            ++lower_case;
		// BUG FIX #1: previously counted everything not lowercase as uppercase
        } else if (std::isupper(c)) {
            ++upper_case;
        }
    }
}

/* remove_uppercase(s)
   Given a string s, return a new string containing all of the
   non-uppercase letters of s.
*/
std::string remove_uppercase(std::string const &s) {
    std::string output{};
	// BUG FIX #2: previously excluded the last character of the string
    for(unsigned i{0}; i < s.size(); ++i) {
        if(!std::isupper(s.at(i))) {
            output += s.at(i);
        }
    }
    return output;
}

int main() {

    std::string s{};
    while(std::getline(std::cin, s)) {
        std::cout << "Input line: " << s << std::endl;

        int l{0},u{0};
        count_case(s, l, u);
        std::cout << "Number of lower case letters: " << l << std::endl;
        std::cout << "Number of upper case letters: " << u << std::endl;

        std::string no_upper{remove_uppercase(s)};
        std::cout << "Upper case letters removed: " << no_upper << std::endl;

        std::cout << std::endl;
    }

    return 0;
}