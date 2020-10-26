#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <list>

// Helper function to process a word
//		Used by recently_seen and frequencies
std::string process_word(std::string const& word) {
	std::string processed {};

	for (auto c : word) {
		if (isupper(c)) {
			processed += tolower(c);
		} else if (isalnum(c)) {
			processed += c;
		}
	}

	return processed;
}

/*
 * Exercise 1
 * 
 * "recently_seen" computes a list of unique words such that the most recently seen 
 * word appears at the top of the list. All words must be lowercase with no 
 * punctuation when they are used as keys to the map.
 * 
 * After looping through all the words in the input, the function prints out the 
 * most recently seen list.
 */
void recently_seen(std::vector<std::string> const& words) {
	std::list<std::string> recent {};

	for (auto& w : words) {
		// remove punctuation and convert uppercase to lowercase
		std::string word {process_word(w)};

		// iterate through the list and remove any instance of the key word
		for (auto iter {recent.begin()}; iter != recent.end(); ++iter) {
			if (*iter == word) {
				recent.erase(iter);
				break;
			}
		}

		// move to front
		recent.push_front(word);
	}

	for (auto& w : recent) {
		std::cout << w << '\n';
	}
}

/*
 * Exercise 2
 * 
 * "punctuation" keeps track of all unique punctuation characters which appeared 
 * in the input vector using a std::set. This includes punctuation in words like
 * apostrophes.
 * 
 * After computing the punctuation set, the function prints out the characters.
 */
void punctuation(std::vector<std::string> const& words) {
	std::set<char> punct{};

	for (auto& w : words) {
		for (auto c : w) {
			// throw any punctuation characters into the set
			if (ispunct(c)) {
				punct.insert(c);
			}
		}
	}

	for (auto c : punct) {
		std::cout << c << ' ';
	}
	std::cout << '\n';
}

/* 
 * Exercise 3
 * 
 * "frequencies" computes the word frequencies of every unique word in the 
 * vector of input using a std::map. All words must be lowercase with no 
 * punctuation when they are used as keys to the map.
 * 
 * After computing the frequencies, the function prints out the frequency data.
 */
void frequencies(std::vector<std::string> const& words) {
	std::map<std::string, int> frequency {};

	for (auto& w : words) {
		// remove punctuation and convert uppercase to lowercase
		std::string word {process_word(w)};

		auto iter {frequency.find(word)};

		// if the key word is in the map, increment frequency counter
		if (iter != frequency.end()) {
			iter->second += 1;
		// else, create a new map record for the key word
		} else {
			frequency.insert({word, 1}); 
		}
	}

	for (auto& data : frequency) {
		// data.first is the key, data.second is the value
		std::cout << data.first << ": " << data.second << '\n';
	}
}

int main() {
	std::vector<std::string> words {};
	std::string word {};

	// build vector from piped input
	while (std::cin >> word) {
		words.push_back(word);
	}

	std::cout << "Exercise 1: Computing most recently seen list\n";
	recently_seen(words);
	
	std::cout << "\nExercise 2: Computing punctuation set\n";
	punctuation(words);
	
	std::cout << "\nExercise 3: Computing word frequencies\n";
	frequencies(words);
}
