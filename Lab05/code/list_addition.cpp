#include <iostream>
#include <list>

/*
 * Challenge Exercise
 */
std::list<int> add_lists(std::list<int> list1, std::list<int> list2) {
	// Implement challenge exercise here
}

/*** Tester code below ***/
/* (You do not need to understand or modify any of the tester code) */

std::list<int> create_num_list(int start_value) {
	std::list<int> result {};

	for(int value {start_value}; value != 0; value /= 10){
		result.push_front(value%10);
	}

	return result;
}

bool check_list(std::list<int> const& num, int start_value, int test_id) {

	int test_value = start_value;

	for (auto it {num.rbegin()}; it != num.rend(); ++it) {
		if (test_value == 0){
			std::cout << "\tTest " << test_id << " failed (list contains too many values)\n";
			return false;
		}
		if (*it != (test_value % 10)) {
			std::cout << "\tTest " << test_id << " failed (list contains an incorrect value)\n";
			return false;
		}
		test_value /= 10;
	}
	if (test_value != 0){
		std::cout << "\tTest " << test_id << " failed (list contains too few values)\n";
		return false;
	}
	return true;
}

void print_list( std::list<int> L ){
	for(auto el: L){
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::list<int> test_numbers {111, 116, 265, 475, 999};
	int test_id {1};
	for(auto iter1 {test_numbers.begin()}; iter1 != test_numbers.end(); iter1++){
		auto v1 = *iter1;
		for(auto iter2 = iter1; iter2 != test_numbers.end(); iter2++){
			auto v2 = *iter2;
			//Construct a list for each value
			std::list<int> L1 {create_num_list(v1)};
			std::list<int> L2 {create_num_list(v2)};
			//Verify that the lists were constructed correctly
			check_list(L1, v1, 0);
			check_list(L2, v2, 0);

			std::list<int> result = add_lists(L1, L2);
			if (!check_list(result, v1+v2, test_id)){
				std::cout << "     L1: ";
				print_list(L1);
				std::cout << "     L2: ";
				print_list(L2);
				std::cout << "  L1+L2: ";
				print_list(result);
				test_id++;
				return 0;
			}
			std::cout << "Test " << test_id << " (" << v1 << " + " << v2 << ") passed." << std::endl;
			test_id++;
		}
	}	

	return 0;
}
