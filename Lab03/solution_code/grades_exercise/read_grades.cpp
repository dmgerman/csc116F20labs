/* read_grades.cpp
   CSC 116 - Fall 2019 - Lab 3
*/
#include <iostream>
#include <vector>
#include <algorithm>


void print_vector(std::vector<int> const &V);

/* compute_mean(V)
 * Given a vector V containing ints, return the average
 * of all elements in V. (Note that the average will be a
 * float, not an int).
 * If the vector V contains no elements, the result must be 0.
 */
float compute_mean(std::vector<int> const &V) {
    int sum {0};
    for (int val : V) {
        sum += val;
    }
    // static_cast is a special way of doing "(float) ((float) sum / V.size())"
    return static_cast<float>((float) sum / V.size());
}

/* compute_median(V)
 * Given a vector V containing ints, return the median of all
 * elements in V.
 *
 * Recall that the median of a sequence is the value that
 * would appear in the "middle" of the sorted version of the sequence.
 * If the sequence has an odd number of elements, the median
 * will be the single value in the middle. If the sequence
 * has an even number of elements, the median will be the
 * average of the two values in the middle.
 *
 * For example, the median of the sequence {3, 6, 2, 1, 0} is 2,
 * and the median of the sequence {7, 9, 2, 3, 1, 4} is 3.5.
 *
 * If the vector V contains no elements, the result must be 0.
 */
float compute_median(std::vector<int> const &V) {
    if (V.size() == 0) {
        return 0.0f;
    }
    // copy the const vector so we can sort it
    std::vector<int> copy {V};
    std::sort(copy.begin(), copy.end());

    // if we have an even amount of values, we take the average of the two medians
    if (copy.size() % 2 == 0) {
        float left = copy.at(copy.size()/2 - 1);
        float right = copy.at(copy.size()/2);
        return static_cast<float>((left + right) / 2);
    } else {
        return static_cast<float>(copy.at(copy.size()/2));
    }
}

/* delete_zeros(V)
 * Given a vector V containing ints, delete all
 * zero values from V.
 */
void delete_zeros(std::vector<int> &V) {
    std::vector<int> no_zeros {};
    for (int val : V) {
        // construct a vector of non-zero element
        if (val != 0) {
            no_zeros.push_back(val);
        }
    }
    V = no_zeros;
}

/*
*   If we incremented i at the end of every iteration, we'd leave behind a zero
*   anywhere in the vector where there are 2 consecutive zeros.
*       - if this is unclear, make sure you understand the effect of V.erase()
*/
void erase_zeros(std::vector<int> &V) {
    for (int i = 0; i < (int) V.size(); ++i){
        if (V.at(i) == 0) {
            // erase the zero, then accommodate for the shift in indexes
            V.erase(V.begin() + i);
            i -= 1;
        }
    }
}

/* print_vector(V)
 * Print the elements of the vector V
 */
void print_vector(std::vector<int> const &V) {
    for(auto x : V) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    // Read in grades and push_back into vector
    std::vector<int> grades{};
    int n{};
    while(std::cin >> n) {
        grades.push_back(n);
    }

    std::cout << "Read " << grades.size() << " grades" << std::endl;
    std::cout << "Original grades: ";
    print_vector(grades);

    std::cout << "Average: " << compute_mean(grades) << std::endl;
    std::cout << "Median: " << compute_median(grades) << std::endl;

    // Delete all of the zero grades from the vector
    // interchangeable with: erase_zeros(grades)
    // delete_zeros(grades);
    erase_zeros(grades);

    std::cout << "Grades with zeros removed: ";
    print_vector(grades);

    std::cout << "Average (zeros excluded): " << compute_mean(grades) << std::endl;
    std::cout << "Median (zeros excluded): " << compute_median(grades) << std::endl;

    return 0;
}
