#include <iostream>

int main() {
    int count {0};
    bool in_allit {false};
    char seq_start {' '};
    std::string word {};
	
    // read input word-by-word
    // the program can either be in an alliteration or not in an alliteration
    //      the two states a program can be in are captured in the first "if-else"
    while (std::cin >> word) {
        // program is in an existing alliteration
        if (in_allit) {
            // check the new word against the letter of the alliteration
            if (seq_start != word.at(0)) {
                // reset alliteration state because new word is not part of the current alliteration
                seq_start = word.at(0);
                in_allit = false;
            }
        // program is not in an existing alliteration
        } else {
            // check new word's first letter against the last word's first letter
            if (seq_start == word.at(0)) {
                // new word's first letter is the same as the previous word's first letter
                //      program is now in an alliteration
                ++count;
                in_allit = true;
            } else {
                // set variable to contain new word's first letter (to check against the next word)
                seq_start = word.at(0);
            }
        }
    }
	
    std::cout << "Found " << count << " alliterations." << std::endl;
	
	return 0;
}
