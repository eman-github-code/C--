#include<iostream>
#include<string>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Take the student ID as input
    std::string studentID;
    std::cout << "Enter your Student ID: ";
    std::cin >> studentID;

    // Store the first two alphabets of the student ID
    std::string programPrefix = studentID.substr(0, 2);

    // Determine the program name based on the criteria
    std::string programName = "Unknown";
    if (programPrefix == "bc") {
        programName = "Bachelors";
    } else if (programPrefix == "mc") {
        programName = "Masters";
    }

    // Display the program name
    std::cout << "Program Name: " << programName << std::endl;

    // Reverse only the digits of the Student ID
    std::string reversedID = "";
    for (int i = studentID.length() - 1; i >= 2; --i) {
        reversedID += studentID[i];
    }

    // Display the last two digits of the reversed ID
    std::cout << "Last two digits of reversed ID: " << reversedID.substr(0, 2) << std::endl;

    // Identify if the last digit of the reversed ID is prime
    int lastDigit = reversedID[0] - '0';
    if (isPrime(lastDigit)) {
        std::cout << "The last digit is a prime number." << std::endl;
    } else {
        std::cout << "The last digit is not a prime number." << std::endl;
    }

    return 0;
}

