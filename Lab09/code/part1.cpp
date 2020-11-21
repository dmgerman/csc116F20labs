/* part1.cpp
   CSC 116 - Fall 2016 - Lab 9

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

// ================================================================
/* Part 1A: Print Vector

   The three versions of sum_vector below each return the sum of
   all elements in the provided vector.

   TODO:
   - Write a single templated version of sum_vector to replace all three versions.
*/

int sum_vector(std::vector<int> const& V) {
    int sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

double sum_vector(std::vector<double> const& V) {
    double sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

std::string sum_vector(std::vector<std::string> const& V) {
    std::string sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

template<typename T>
void print_vector(std::vector<T> const& V) {
    for (auto x : V) {
        std::cout << x << ", ";
    }
    
    std::cout << std::endl;
}

void test_print_vector()
{
    std::vector<int> int_vector {6,4,11,9};
    std::vector<double> float_vector { 1.1, 2.2, 6.6, 1.0};
    std::vector<std::string> string_vector {"Hello", "-", "World"};

    std::cout << "int vector: ";
    print_vector(int_vector);
    std::cout << "Sum: " << sum_vector(int_vector) << std::endl << std::endl;

    std::cout << "float vector: ";
    print_vector(float_vector);
    std::cout << "Sum: " << sum_vector(float_vector) << std::endl << std::endl;

    std::cout << "string vector: ";
    print_vector(string_vector);
    std::cout << "Sum: " << sum_vector(string_vector) << std::endl << std::endl;
}

// ================================================================
/* Part 1B: Sum Container

   The four versions of sum_container below each return the sum
   of all elements in the provided vector or set with element type
   int or string.

   TODO: Write a single templated version of sum_container to replace
   all four versions.
*/

int sum_container(std::vector<int> const& V) {
    int sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

std::string sum_container(std::vector<std::string> const& V) {
    std::string sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

int sum_container(std::set<int> const& V) {
    int sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

std::string sum_container(std::set<std::string> const& V) {
    std::string sum {};
    for (auto x : V) {
        sum += x;
    }

    return sum;
}

template<typename T>
void print_container(T const& V) {
    for (auto x : V) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void test_sum_container()
{
    std::vector<int> int_vector {6,4,11,9};
    std::set<int> int_set {1,2,3,4,5};
    std::vector<std::string> string_vector {"Hello", "-", "World"};
    std::set<std::string> string_set { "Pear", "Pineapple", "Raspberry" };

    std::cout << "vector of ints: ";
    print_container(int_vector);
    std::cout << "Sum: " << sum_container(int_vector) << std::endl << std::endl;

    std::cout << "set of ints: ";
    print_container(int_set);
    std::cout << "Sum: " << sum_container(int_set) << std::endl << std::endl;

    std::cout << "vector of strings: ";
    print_container(string_vector);
    std::cout << "Sum: " << sum_container(string_vector) << std::endl << std::endl;

    std::cout << "set of ints: ";
    print_container(string_set);
    std::cout << "Sum: " << sum_container(string_set) << std::endl << std::endl;
}

// ================================================================
/* Part 1C: Find Matching Keys

   The three versions of find_matching_keys below each return a set of
   all keys in a map which map to a specified value.

   TODO:
   - Write a single templated version of find_matching_keys to replace all three versions.
*/

/* Given a map which maps strings to ints, return a set of all keys
   which map to the provided value */
std::set<std::string> find_matching_keys(std::map<std::string, int> const& M, int search_value) {
    std::set<std::string> result {};
    for (auto P : M) {
        auto key = P.first;
        auto value = P.second;

        if (search_value == value) {
            result.insert(key);
        }
    }

    return result;
}


/* Given a map which maps strings to strings, return a set of all keys
   which map to the provided value */
std::set<std::string> find_matching_keys(std::map<std::string, std::string> const& M, std::string search_value) {
    std::set<std::string> result {};
    for (auto P : M) {
        auto key = P.first;
        auto value = P.second;

        if (search_value == value) {
            result.insert(key);
        }
    }

    return result;
}


/* Given a map which maps ints to strings, return a set of all keys
   which map to the provided value */
std::set<int> find_matching_keys(std::map<int, std::string> const& M, std::string search_value) {
    std::set<int> result {};
    for (auto P : M) {
        auto key = P.first;
        auto value = P.second;

        if (search_value == value) {
            result.insert(key);
        }
    }

    return result;
}

template<typename T>
void print_set(std::set<T> const& V) {
    for (auto x : V) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

template<typename T, typename U>
void print_map(std::map<T, U> const& m) {
    for (auto pair : m) {
        std::cout << "K: " << pair.first << " V:" << pair.second << std::endl;
    }
}

void test_find_matching_keys()
{
    std::map<std::string, int> fruit_prices { {"Raspberry", 10}, {"Grapefruit",7}, {"Pineapple", -10}, {"Pear", 10}, {"Pomegranate", 5} };

    std::map<std::string, std::string> prerequisites { {"MATH 101", "MATH 100"}, {"MATH 122", "MATH 100"}, {"CSC 116", "CSC 111"} };

    std::map<int, std::string> letter_grades { {87, "A"}, {68,"C+"}, {71, "B-"}, {66, "C+"}, {93, "A+"}, {88,"A"} };

    print_map( fruit_prices );
    std::cout << "Fruits with price 10: ";
    print_set( find_matching_keys( fruit_prices, 10 ) );
    std::cout << std::endl;

    print_map( prerequisites );
    std::cout << "Courses requiring MATH 100: ";
    print_set( find_matching_keys( prerequisites, "MATH 100" ) );
    std::cout << std::endl;

    print_map( letter_grades );
    std::cout << "A grades: ";
    print_set( find_matching_keys( letter_grades, "A" ) );
    std::cout << std::endl;
}

int main()
{
    std::cout << "Please enter 1, 2, or 3 to select test." << std::endl;
    std::cout << "1) Sum Vector" << std::endl << "2) Sum Colection" << std::endl << "3) Find matching keys" << std::endl;
    int test_case{0};
    std::cin >> test_case;
    switch (test_case) {
        case 1:
            test_print_vector();
            break;

        case 2:
            test_sum_container();
            break;

        case 3:
            test_find_matching_keys();
            break;

        default:
            std::cout << "No maching test for ";
            return 1;
    }
    return 0;
}
