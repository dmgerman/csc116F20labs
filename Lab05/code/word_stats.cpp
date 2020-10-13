#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <list>

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
