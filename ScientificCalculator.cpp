#include <iostream>
#include <cmath>
#include <conio.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define RESET "\x1B[0m"

using namespace std;

// Function declarations
float Power(float, float);
float Sine(float);
float SquareRoot(float);
float Cosine(float);
float Tangent(float);
float NaturalLog(float);
float Base10Log(float);
float Exponential(float);
float Absolute(float);
float Ceiling(float);
float Floor(float);
double simple(float num1, float num2, char operation);

int main() {
    float a, b;
    char choice;

    while (true) {
        system("cls"); // Clear screen (optional)
        cout << BLUE << "====== SCIENTIFIC CALCULATOR ======" << RESET << endl;
        cout << GREEN << "Press '1' for Power (x^y)" << RESET << endl;
        cout << GREEN << "Press '2' for Sin(x in radians)" << RESET << endl;
        cout << GREEN << "Press '3' for Square Root" << RESET << endl;
        cout << GREEN << "Press '4' for Cos(x)" << RESET << endl;
        cout << GREEN << "Press '5' for Tan(x)" << RESET << endl;
        cout << GREEN << "Press '6' for Natural Log (ln x)" << RESET << endl;
        cout << GREEN << "Press '7' for Base-10 Log (log10 x)" << RESET << endl;
        cout << GREEN << "Press '8' for Exponential (e^x)" << RESET << endl;
        cout << GREEN << "Press '9' for Absolute Value" << RESET << endl;
        cout << GREEN << "Press 'a' for Ceil(x)" << RESET << endl;
        cout << GREEN << "Press 'b' for Floor(x)" << RESET << endl;

        cout << YELLOW << "Press '+' for Addition" << RESET << endl;
        cout << YELLOW << "Press '-' for Subtraction" << RESET << endl;
        cout << YELLOW << "Press '*' for Multiplication" << RESET << endl;
        cout << YELLOW << "Press '/' for Division" << RESET << endl;

        cout << RED << "Press '0' to Exit" << RESET << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == '0') break;

        switch (choice) {
            case '1':
                cout << "Enter base: ";
                cin >> a;
                cout << "Enter exponent: ";
                cin >> b;
                cout << "Result: " << Power(a, b);
                break;
            case '2':
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "sin(" << a << ") = " << Sine(a);
                break;
            case '3':
                cout << "Enter number: ";
                cin >> a;
                cout << "v" << a << " = " << SquareRoot(a);
                break;
            case '4':
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "cos(" << a << ") = " << Cosine(a);
                break;
            case '5':
                cout << "Enter angle in radians: ";
                cin >> a;
                cout << "tan(" << a << ") = " << Tangent(a);
                break;
            case '6':
                cout << "Enter number: ";
                cin >> a;
                cout << "ln(" << a << ") = " << NaturalLog(a);
                break;
            case '7':
                cout << "Enter number: ";
                cin >> a;
                cout << "log10(" << a << ") = " << Base10Log(a);
                break;
            case '8':
                cout << "Enter number: ";
                cin >> a;
                cout << "e^" << a << " = " << Exponential(a);
                break;
            case '9':
                cout << "Enter number: ";
                cin >> a;
                cout << "| " << a << " | = " << Absolute(a);
                break;
            case 'a':
                cout << "Enter number: ";
                cin >> a;
                cout << "Ceiling of " << a << " = " << Ceiling(a);
                break;
            case 'b':
                cout << "Enter number: ";
                cin >> a;
                cout << "Floor of " << a << " = " << Floor(a);
                break;
            case '+': case '-': case '*': case '/':
                cout << "Enter 1st number: ";
                cin >> a;
                cout << "Enter 2nd number: ";
                cin >> b;
                cout << "Result: " << simple(a, b, choice);
                break;
            default:
                cout << RED << "Invalid choice. Try again!" << RESET;
        }

        cout << "\n\nPress any key to continue...";
        getch();
    }

    cout << GREEN << "Calculator closed. Goodbye!" << RESET << endl;
    return 0;
}

// ==== Function Definitions ====

double simple(float num1, float num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : NAN;
        default: return 0;
    }
}

float Power(float x, float y)         { return pow(x, y); }
float Sine(float x)                   { return sin(x); }
float SquareRoot(float x)            { return sqrt(x); }
float Cosine(float x)                { return cos(x); }
float Tangent(float x)               { return tan(x); }
float NaturalLog(float x)            { return log(x); }
float Base10Log(float x)             { return log10(x); }
float Exponential(float x)           { return exp(x); }
float Absolute(float x)              { return fabs(x); }
float Ceiling(float x)               { return ceil(x); }
float Floor(float x)                 { return floor(x); }

