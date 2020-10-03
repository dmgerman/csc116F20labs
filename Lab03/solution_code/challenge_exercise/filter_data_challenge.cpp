#include <iostream>
#include <vector>

// simple helper function to print a vector
void print_data(const std::vector<int>& data) {
    for(auto val : data) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}

void filter_data(const std::vector<int>& filter, std::vector<int>& data) {
    // the value "filter.size() - 1" is used often, so make a variable for it
    int len {(int) filter.size() - 1};

    /*
      A lot of complications can occur if we start the loop from 0 (see the write up).
      They can be avoided by starting the loop ahead. Specifically, starting it at the filter's length.

      We walk forwards through the data set up to the index "i" position while comparing values against the 
      filter. The position in data set 1 to begin ("pos" in the code) is "i - (length of the filter)". 
     */
    
    // begin loop ahead and check data leading up to loop position
    // loop can run without risking stepping outside of data's bounds
    for(int i {len}; i < (int) data.size(); ++i) {
        // control flag telling program whether the filter was matched
        bool match {true};
        // the position of the start of the data set 1 subsequence to test against the filter
        int pos {i - len};

        for(int j {0}; j <= len; ++j) {
            // does the element in the data set match the corresponding element in the filter?
            if(data[pos + j] != filter[j]) {
                // the filter was not matched
                match = false;
                break;
            }
        }

        // match will be true if all the characters in the filter matched
        if(match) {
            // delete data leading up to the current index position
            for(int j {0}; j <= len; ++j) {
                data.erase(data.begin() + pos);
            }
            // offset "i" to accommodate erased data
            i = pos - len - 1;
        }
    }
} 

int main() {
    std::vector<int> data1 {};
    std::vector<int> data2 {};

    bool set {};
    int input {};

    // read input from standard input integer-by-integer
    while(std::cin >> input) {
        // check if the number was -1, denoting to switch to data set 2
        if(input == -1) {
            set = true;
            // "continue" cuts the loop short and jumps back up the while condition check
            continue;
        }

        // build the correct data set from the new input
        if(set) {
            data2.push_back(input);
        } else {
            data1.push_back(input);
        }
    }

    std::cout << "Data Set 1: ";
    print_data(data1);

    std::cout << "Data Set 2: ";
    print_data(data2);

    // if data set 1 is empty, we don't want to run the filter
    if(data1.size()) {
        filter_data(data1, data2);
    }

    std::cout << "Filtered: ";
    print_data(data2);
}
