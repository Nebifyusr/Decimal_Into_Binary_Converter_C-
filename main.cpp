#include <iostream>
#include <string>
#include <bitset>

std::string underlineExceptions(std::string number_str) {
    std::string result = "";

    for (char digit : number_str) {
        if (digit != '0' && digit != '1') {
            return "Error: Unexpected digit '" + std::string(1, digit) + "' found.";
        } else {
            result += "\033[4m" + std::string(1, digit) + "\033[0m";  // Using ANSI escape codes for underlining
        }
    }

    return result;
}

std::string decToBin(std::string user_input) {
    try {
        int number = std::stoi(user_input);
        std::string binary = std::bitset<32>(number).to_string();  // Convert to binary string
        size_t pos = binary.find('1'); // Find first non-zero bit
        return binary.substr(pos); // Remove leading zeros
    } catch (std::invalid_argument const &e) {
        return "Error: Input is not a valid number.";
    }
}

std::string binToDec(std::string user_input) {
    try {
        int number = std::stoi(user_input, nullptr, 2); // Convert binary to decimal
        return std::to_string(number);
    } catch (std::invalid_argument const &e) {
        return "Error: Input is not a valid binary number.";
    }
}

int main() {
    std::cout << "=================================" << std::endl;
    std::cout << "CONVERTER" << std::endl;
    std::cout << "=================================" << std::endl;

    bool run = true;
    while (run) {
        std::cout << "[1] Decimal to Binary" << std::endl;
        std::cout << "[2] Binary to Decimal" << std::endl;
        std::string user_input;
        std::cin >> user_input;

        if (user_input == "1") {
            std::string decimal_input;
            std::cout << "Enter a decimal number: ";
            std::cin >> decimal_input;
            std::string result = decToBin(decimal_input);
            std::cout << "Binary representation: " << result << std::endl;

        } else if (user_input == "2") {
            std::string binary_input;
            std::cout << "Enter a binary number: ";
            std::cin >> binary_input;
            std::string error_message = underlineExceptions(binary_input);

            if (error_message.substr(0, 5) == "Error") {
                std::cout << error_message << std::endl;
            } else {
                std::string result = binToDec(binary_input);
                std::cout << "Decimal representation: " << result << std::endl;
            }

        } else {
            std::cout << "Invalid Input" << std::endl;
        }
        system("cls"); 
    }

    return 0;
}
