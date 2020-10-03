#include <iostream>
#include <string>
#include <vector>

int main() {
    int count {0};
    bool in_allit {false};
    char seq_start {' '};
    std::string word {}, prev {};
	std::vector<std::string> words {};
	
	/*
	 For the second component, computing word frequencies, there's no need to 
	 perserve each alliteration separately. 
	 
	 The word frequencies are computed accross all the alliterations, so every 
	 word which is part of an alliteration will be added to a single vector. 

	 Once all the alliterations have been found, the vector can be searched for
	 frequencies of each word.
	*/
	
	// most of this loop is taken from exercise 5, comments will cover new code
    while (std::cin >> word) {
        if (in_allit) {
            if (seq_start != word.at(0)) {
                seq_start = word.at(0);
                in_allit = false;

				// print a new line to finish the current alliteration
				std::cout << std::endl;
				// store this word in case it is part of a new alliteration
				prev = word;
            } else {
				// the word is part of the current alliteration, print it out and store it in the vector
				std::cout << ' ' << word;
				words.push_back(word);
			}
        } else {
            if (seq_start == word.at(0)) {
                ++count;
                in_allit = true;
				// print the word stored in the previous iteration and the new word
				std::cout << "Alliterations " << count << ": " << prev << ' ' << word;
				
				// push the two alliterative words onto our alliteration vector for computing frequencies
				words.push_back(prev);
				words.push_back(word);
            } else {
                seq_start = word.at(0);
				// even though we don't know if this word is part of an alliteration,
				//		we need to store it in case it is.
				prev = word;
            }
        }
    }
	
	// two new vectors are needed: one for unique words and another for the frequency values
	std::vector<std::string> unique_words {};
	std::vector<int> frequencies {};

	// loop through every word which is part of an alliteration
	for (const auto& w : words) {
		bool found {false};
		
		// check the word against all the words we've already seen
		for (size_t i {0}; i < unique_words.size(); ++i) {
			// if we have already seen this word, increment it's frequency count
			if (w == unique_words.at(i)) {
				frequencies.at(i) += 1;
				// set control variable to true (the word was found)
				found = true;
			}
		}

		// if the word was not found
		if (!found) {
			// push the word onto the vector of unique words and give it a frequency of 1
			unique_words.push_back(w);
			frequencies.push_back(1);

			// NOTE: the word and its frequency will be located at the same index of their respective vectors.
			//		this isn't the best way to do this, but it works for our purposes.
		}
	}
	
	std::cout << "\nWord Frequencies:\n";
	for (size_t i {0}; i < unique_words.size(); ++i) {
		std::cout << unique_words.at(i) << ' ' << frequencies.at(i) << std::endl;
	}
		
	return 0;
}
