#include<iostream>

// Function to double each digit and print in reverse order
void doubleDigits(long long num) {
    std::cout << "Doubled digits in reverse order:" << std::endl;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        int doubledDigit = digit * 2;

        // Print the doubled digit in reverse order
        std::cout << doubledDigit % 10 << std::endl;
        std::cout << doubledDigit / 10 << std::endl;

        // Calculate the sum of doubled digits
        sum += doubledDigit % 10 + doubledDigit / 10;

        // Move to the next digit
        num /= 10;
    }

    // Print the sum on the screen
    std::cout << "Sum of doubled digits: " << sum << std::endl;
}

int main() {
    // Take the student ID as input
    long long studentID;
    std::cout << "Enter your VU Student ID (numeric part only): ";
    std::cin >> studentID;

    // Call the function to double each digit and print in reverse order
    doubleDigits(studentID);

    return 0;
}

