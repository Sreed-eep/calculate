#include <iostream>
#include <cmath>
#include <stdexcept>

// Function declarations
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double squareRoot(double a);
double exponentiation(double a, double b);
double calculateTrigonometry(char operation, double angle);

// Main function
int main() {
    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            break;
        }

        double num1, num2, result;
        char trigOp;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = add(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 2:
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = subtract(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 3:
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = multiply(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 4:
                    std::cout << "Enter two numbers: ";
                    std::cin >> num1 >> num2;
                    result = divide(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 5:
                    std::cout << "Enter a number: ";
                    std::cin >> num1;
                    result = squareRoot(num1);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 6:
                    std::cout << "Enter base and exponent: ";
                    std::cin >> num1 >> num2;
                    result = exponentiation(num1, num2);
                    std::cout << "Result: " << result << std::endl;
                    break;
                case 7:
                    std::cout << "Enter trigonometric function (s for sin, c for cos, t for tan) and angle in degrees: ";
                    std::cin >> trigOp >> num1;
                    result = calculateTrigonometry(trigOp, num1);
                    std::cout << "Result: " << result << std::endl;
                    break;
                default:
                    std::cerr << "Invalid choice. Please try again." << std::endl;
            }
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}

// Function definitions
void showMenu() {
    std::cout << "\nCalculator Menu:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Square Root\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Trigonometry (sin, cos, tan)\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero is undefined.");
    }
    return a / b;
}

double squareRoot(double a) {
    if (a < 0) {
        throw std::runtime_error("Square root of negative number is undefined.");
    }
    return std::sqrt(a);
}

double exponentiation(double a, double b) {
    return std::pow(a, b);
}

double calculateTrigonometry(char operation, double angle) {
    // Convert angle from degrees to radians
    double radians = angle * (M_PI / 180.0);

    switch (operation) {
        case 's':
            return std::sin(radians);
        case 'c':
            return std::cos(radians);
        case 't':
            return std::tan(radians);
        default:
            throw std::runtime_error("Invalid trigonometric operation.");
    }
}
