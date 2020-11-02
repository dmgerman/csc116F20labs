//
// Created by khaled Kelany on 2020-11-01.
//

#include <iostream>
#include <functional>
#include <string>
#include <vector>

class Rational {
public:
    /*
     * Construct a zero rational number.
     * This constructor is fully implemented.
     */
    Rational() {
        Rational(0, 1);
    }

    /*
     * Copy the initial value of the numerator and denominator
     * If the denominator value is zero, throw std::runtime_error exception
     */
    Rational(int n, int d) {
        /*
         * Your code goes here.
         */
        reduce();
    };

    /*
     * Reduce the fraction by diving by GCD. Make sure to call this function after each mathematical operation to make
     * the fraction stored in the reduced form.
     */
    void reduce() {
    }

    /*
     * Adding two rational numbers.
     */
    Rational operator+(const Rational &a) const {
    }

    /*
     * Adding integer to rational number.
     */
    Rational operator+(const int i) const {
    }

    /*
     * Subtracting two rational numbers.
     */
    Rational operator-(const Rational &a) const {
    }

    /*
     * Subtracting integer from rational number.
     */
    Rational operator-(const int i) const {
    }

    /*
     * Multiplying two rational numbers.
     */
    Rational operator*(const Rational &a) const {
    }

    /*
     * Multiplying integer by rational number.
     */
    Rational operator*(const int i) const {
    }

    /*
     * Dividing two rational numbers.
     * If dividing by zero, throw a std::runtime_error exception.
     */
    Rational operator/(const Rational &a) const {
    }

    /*
     * Dividing rational numbers by integer.
     * If dividing by zero, throw a std::runtime_error exception.
     */
    Rational operator/(const int i) const {
    }

    /*
     * Print the rational number in the form of a/b.
     */
    void printRational() {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    /*
     * Numerator getter.
     */
    int getNumerator() const {
        return numerator;
    }

    /*
     * Denominator getter.
     */
    int getDenominator() const {
        return denominator;
    }

private:
    int numerator{};
    int denominator{};
};

void evaluate_exception(std::function<void()> test) {
    static std::string fail{"FAIL\n"};
    static std::string pass{"PASS\n"};

    try {
        test();
        std::cout << fail;
    } catch (std::runtime_error &e) {
        std::cout << pass;
    }
}

void evaluate_test(bool result) {
    static std::string fail{"FAIL\n"};
    static std::string pass{"PASS\n"};

    if (result) {
        std::cout << pass;
    } else {
        std::cout << fail;
    }
}

int main() {
    Rational default_rational{};
    Rational zero_rational{0, 1};
    Rational rational1{5, 7};
    Rational rational2{110, 30};

    std::cout << "Testing Exceptions\n";

    std::cout << "\tZero denominator: ";
    evaluate_exception([&]() { Rational{5, 0}; });

    std::cout << "\tDividing by zero fraction: ";
    evaluate_exception([&]() { rational1 / zero_rational; });

    std::cout << "\tDividing by zero integer: ";
    evaluate_exception([&]() { rational1 / 0; });

    std::cout << "\nTesting Functions\n";

    std::cout << "\tAdding 110/30 to 5/7: ";
    default_rational = rational1 + rational2;
    evaluate_test(default_rational.getNumerator() == 92 && default_rational.getDenominator() == 21);

    std::cout << "\tSubtracting 110/30 from 5/7: ";
    default_rational = rational1 - rational2;
    evaluate_test(default_rational.getNumerator() == -62 && default_rational.getDenominator() == 21);

    std::cout << "\tMultiplying 5/7 by 110/30: ";
    default_rational = rational1 * rational2;
    evaluate_test(default_rational.getNumerator() == 55 && default_rational.getDenominator() == 21);

    std::cout << "\tDividing 5/7 by 110/30: ";
    default_rational = rational1 / rational2;
    evaluate_test(default_rational.getNumerator() == 15 && default_rational.getDenominator() == 77);

    std::cout << "\tAdding 3 to 5/7: ";
    default_rational = rational1 + 3;
    evaluate_test(default_rational.getNumerator() == 26 && default_rational.getDenominator() == 7);

    std::cout << "\tSubtracting 3 from 5/7: ";
    default_rational = rational1 - 3;
    evaluate_test(default_rational.getNumerator() == -16 && default_rational.getDenominator() == 7);

    std::cout << "\tMultiplying 5/7 by 3: ";
    default_rational = rational1 * 3;
    evaluate_test(default_rational.getNumerator() == 15 && default_rational.getDenominator() == 7);

    std::cout << "\tDividing 5/7 by 3: ";
    default_rational = rational1 / 3;
    evaluate_test(default_rational.getNumerator() == 5 && default_rational.getDenominator() == 21);

    return 0;
}