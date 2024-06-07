/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                       *
 *       Created by: Reinier Garcia Ramos                *
 *       reymillenium@gmail.com                          *
 *                                                       *
 *       https://www.linkedin.com/in/reiniergarcia       *
 *       https://github.com/reymillenium                 *
 *       https://www.reiniergarcia.dev                   *
 *                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <climits>
#include <iomanip> // for setprecision, setw, fixed
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream, humanize_integer, humanize_double
#include <vector> // to use vectors
#include <fstream> // For ifstream, ofstrea, fstream
#include <numeric> // For accumulate, transform_reduce (in the vectors)
#include <algorithm> // For max_element, min_element (to use in vectors), or for max()

template<typename T>
void print(const T &);

template<typename T>
void print_n_times(const T &, int);

template<typename T>
void printl(const T &);

template<typename T>
void printl_n_times(const T &, int);

template<typename T>
auto get_value(const std::string &) -> T;

std::string get_string_from_message(const std::string &);

std::string get_string();

std::string humanize_integer(long long int);

std::string humanize_double(long double, int = 2);

std::string humanize_unsigned_integer(unsigned long long int);

std::string humanize_unsigned_double(long double, int = 2);

std::string monetize_integer(unsigned long int, bool = true, const std::string & = "$");

std::string monetize_double(long double, int = 2, bool = true, const std::string & = "$");

double round_up(double, int);

int recursive_sum(unsigned long long int);

std::string ordinal_from_number(long long int);

bool is_prime(unsigned long long int);

// class MonthlyRainLog {
// public:
//     std::string month_name;
//     double rain_amount;
//
//     // dummy constructor
//     MonthlyRainLog() {
//     }
//
//     // Parameterized constructor
//     MonthlyRainLog(const std::string &a_month_name, const double &a_rain_amount) {
//         month_name = a_month_name;
//         rain_amount = a_rain_amount;
//     }
// };

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

template<typename T>
void print(const T &item) {
    std::cout << item;
}

template<typename T>
void print_n_times(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        print(item);
    }
}

template<typename T>
void printl(const T &item) {
    std::cout << item << std::endl;
}

template<typename T>
void printl_n_times(const T &item, const int times) {
    for (int i = 0; i < times; i += 1) {
        printl(item);
    }
}

template<typename T>
auto get_value(const std::string &message) -> T {
    std::cout << message;
    T value;
    std::cin >> value;
    std::cin.ignore();
    return value;
}

std::string get_string_from_message(const std::string &message) {
    std::cout << message;
    std::string value;
    std::getline(std::cin, value);
    return value;
}

std::string get_string() {
    std::string value;
    std::getline(std::cin, value);
    return value;
}

std::string humanize_integer(const long long int integer_value) {
    const bool is_negative = integer_value < 0;
    std::string integer_as_string = std::to_string(integer_value);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = integer_as_string.length() - 3; j > (is_negative ? 1 : 0); j -= 3) {
        integer_as_string.insert(j, ",");
    }
    return integer_as_string;
}

std::string humanize_double(const long double double_value, const int precision) {
    const auto integer_value = static_cast<long long int>(double_value);
    const long double decimals = double_value - integer_value;
    const bool has_negative_decimals = decimals < 0;

    // Extracts into a string the decimal part, rounded to two significant digits
    std::stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << std::fixed << std::setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const std::string decimals_as_string = stream.str(); // It still includeds the zero & the dot. Ex: 0.34, -0.34 (the zero, and possibly also a negative sign, must be removed next)
    return humanize_integer(integer_value) + decimals_as_string.substr(has_negative_decimals ? 2 : 1, precision + 1);
}

std::string humanize_unsigned_integer(const unsigned long long int integer_value) {
    std::string integer_as_string = std::to_string(integer_value);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = integer_as_string.length() - 3; j > 0; j -= 3) {
        integer_as_string.insert(j, ",");
    }
    return integer_as_string;
}

std::string humanize_unsigned_double(const long double double_value, const int precision) {
    const auto integer_value = static_cast<unsigned long long int>(double_value);
    const long double decimals = double_value - integer_value;
    // Extracts into a string the decimal part, rounded to two significant digits
    std::stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << std::fixed << std::setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const std::string decimals_as_string = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanize_unsigned_integer(integer_value) + decimals_as_string.substr(1, precision + 1);
}

std::string monetize_integer(const unsigned long int integer_value, const bool prepend, const std::string &symbol) {
    return static_cast<std::string>(prepend ? (symbol + " ") : "") + humanize_unsigned_integer(integer_value) + static_cast<std::string>(prepend ? "" : " " + symbol);
}

std::string monetize_double(const long double double_value, const int precision, const bool prepend, const std::string &symbol) {
    return static_cast<std::string>(prepend ? (symbol + " ") : "") + humanize_unsigned_double(double_value, precision) + static_cast<std::string>(prepend ? "" : " " + symbol);
}

double round_up(const double value, const int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

int recursive_sum(const unsigned long long int number) {
    if (number != 0)
        return number + recursive_sum(number - 1);
    return 0;
}

std::string ordinal_from_number(const long long int number) {
    const long long int last_digit = number % 10;
    std::string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (last_digit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return std::to_string(number) + additive;
}

bool is_prime(const unsigned long long int value) {
    if (value <= 1)
        return false;
    for (unsigned long long int i = 2; i <= value / 2; i++) {
        if (value % i == 0)
            return false;
    }
    return true;
}
