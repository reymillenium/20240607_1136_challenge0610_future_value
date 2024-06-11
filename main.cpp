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
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <algorithm>

template<typename T>
auto get_value(const std::string &) -> T;

std::string humanize_unsigned_integer(unsigned long long int);

std::string humanize_unsigned_double(long double, int = 2);

std::string monetize_double(long double, int = 2, bool = true, const std::string & = "$");

void scold_user_if_invalid_input(long double, double);

bool is_invalid(long double, double);

double future_value(double, double, int);

void render_future_value_table(double, double, int);

void render_table_header();

void render_table_row(double, double, int);

int main() {
    bool keep_calculating {false};

    do {
        double account_present_value;
        double monthly_interest_rate;
        int months_amount;

        std::cout << std::endl;

        // Input of the Account's Present Value + Validation
        do {
            account_present_value = get_value<double>("  Enter the account's Present Value: ");
            scold_user_if_invalid_input(account_present_value, 0);
        } while (is_invalid(account_present_value, 0));

        // Input of the Monthly Interest Rate + Validation
        do {
            monthly_interest_rate = get_value<double>("  Enter the monthly interest rate: ");
            scold_user_if_invalid_input(monthly_interest_rate, 0);
        } while (is_invalid(monthly_interest_rate, 0));

        // Input of the Nnumber of Months that the money will be left in the account + Validation
        do {
            months_amount = get_value<int>("  Enter the number of months that the money will be left in the account: ");
            scold_user_if_invalid_input(months_amount, 0);
        } while (is_invalid(months_amount, 0));

        // Outputs Block
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::endl;

        std::cout << "  The Future Value of the account, starting with an initial capital of " << monetize_double(account_present_value) << "," << std::endl;
        std::cout << "  with a monthly interest rate of " << monthly_interest_rate << " (" << (monthly_interest_rate * 100.00) << " %)" << "," << std::endl;
        std::cout << "  and after " << months_amount << " month" << (months_amount == 1 ? "" : "s") << ", is equal to: " << monetize_double(future_value(account_present_value, monthly_interest_rate, months_amount)) << std::endl;
        std::cout << "  And that figure can be broken down month by month as follows:" << std::endl;
        render_future_value_table(account_present_value, monthly_interest_rate, months_amount);
        std::cout << std::endl;

        // Assesing if the user wants to continue using the program:
        auto keep_calculating_str = get_value<std::string>("  Would you like to keep calculating the Future Value (y/n)? ");
        // Transforms keep_calculating_str to lowercase
        std::transform(keep_calculating_str.begin(), keep_calculating_str.end(), keep_calculating_str.begin(), [](const unsigned char c) { return std::tolower(c); });
        keep_calculating = keep_calculating_str != "n" && keep_calculating_str != "no";
    } while (keep_calculating);

    return 0;
}

template<typename T>
auto get_value(const std::string &message) -> T {
    std::cout << message;
    T value;
    std::cin >> value;
    std::cin.ignore();
    return value;
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

std::string monetize_double(const long double double_value, const int precision, const bool prepend, const std::string &symbol) {
    return static_cast<std::string>(prepend ? (symbol + " ") : "") + humanize_unsigned_double(double_value, precision) + static_cast<std::string>(prepend ? "" : " " + symbol);
}

bool is_invalid(const long double value, const double min_value) {
    return value < min_value;
}

void scold_user_if_invalid_input(const long double value, const double min_value) {
    if (is_invalid(value, min_value)) std::cout << "You must type a number greater or equal than " << min_value << ". Try again!" << std::endl;
}

double future_value(const double present_value, const double monthly_interest, const int months_amount) {
    return present_value * pow((1 + monthly_interest), months_amount);
}

void render_future_value_table(const double present_value, const double monthly_interest, const int months_amount) {
    render_table_header();
    for (int month = 1; month <= months_amount; month++)
        render_table_row(present_value, monthly_interest, month);
}

void render_table_header() {
    std::cout << std::endl;
    std::cout << "  --------------------------" << std::endl;
    std::cout << "  | Month |  Future Value  |" << std::endl;
    std::cout << "  --------------------------" << std::endl;
}

void render_table_row(const double account_present_value, const double monthly_interest_rate, const int months_amount) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  | " << std::setw(5) << months_amount << " | " << std::setw(14) << monetize_double(future_value(account_present_value, monthly_interest_rate, months_amount), 2, false, "USD") << " |" << std::endl;
    std::cout << "  --------------------------" << std::endl;
}
