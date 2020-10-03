#include <iostream>

int main() {
	// all int vars have default initial value of zero
	int num {};
	int count {};
	int sum {};

	// Note: 'Enter a number' must be printed once before the
	// loop to ensure a message is printed before the first
	// time the user enters a number.
	std::cout << "Enter a number: ";

	// The while loop first removes a value from std::cin and attempts
	// to put it in num.  If successful, the statement 'std::cin >> num'
	// evaluates to true and the while loop is executed.
	// If unsuccessful (ie if the value in std::cin was not able to
	// be converted into an int) then 'std::cin >> num' evaluates
	// to false and the while loop is not executed.
	while(std::cin >> num) {
		sum += num;	// equivalent to sum = sum + num
		count += 1; // equivalent both to count++ and count += 1
		std::cout << "Enter a number: ";
	}

	// If the program runs this code, the conditional statement in the
	// while loop must have been false (std::cin >> num evaluted to false)
	std::cout << "Input was invalid." << std::endl;
	std::cout << "Number of Values Entered: " << count << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	
	return 0;
}
