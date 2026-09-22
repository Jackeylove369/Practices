#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function declarations
void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exp);
double squareRoot(double num);
int factorial(int n);
void simpleCalculator();
void scientificCalculator();

int main() {
    int choice;

    while (1) {
        printf("\n========== Calculator Program ==========\n");
        printf("1. Basic Calculator (+, -, *, /)\n");
        printf("2. Scientific Calculator (Power, Sqrt, Factorial)\n");
        printf("3. Exit\n");
        printf("========================================\n");
        printf("Select an option (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
        case 1:
            simpleCalculator();
            break;
        case 2:
            scientificCalculator();
            break;
        case 3:
            printf("Thanks for using. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again!\n");
        }
    }

    return 0;
}

// Basic Calculator
void simpleCalculator() {
    double num1, num2, result;
    char op;

    printf("\n--- Basic Calculator ---\n");
    printf("Format: number1 operator number2\n");
    printf("Supported operators: +, -, *, /\n");
    printf("Enter expression: ");

    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("Invalid input format!\n");
        while (getchar() != '\n');
        return;
    }

    switch (op) {
    case '+':
        result = add(num1, num2);
        printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
        break;
    case '-':
        result = subtract(num1, num2);
        printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
        break;
    case '*':
        result = multiply(num1, num2);
        printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
        break;
    case '/':
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed!\n");
            return;
        }
        result = divide(num1, num2);
        printf("%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
        break;
    default:
        printf("Unsupported operator: %c\n", op);
    }
}

// Scientific Calculator
void scientificCalculator() {
    int choice;
    double num1, num2, result;
    int n, factResult;

    printf("\n--- Scientific Calculator ---\n");
    printf("1. Power (a^b)\n");
    printf("2. Square Root (√x)\n");
    printf("3. Factorial (n!)\n");
    printf("4. Back to Main Menu\n");
    printf("Select an option (1-4): ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    switch (choice) {
    case 1:
        printf("Enter base and exponent (separated by space): ");
        scanf("%lf %lf", &num1, &num2);
        result = power(num1, num2);
        printf("%.2lf ^ %.2lf = %.4lf\n", num1, num2, result);
        break;
    case 2:
        printf("Enter a number to take square root: ");
        scanf("%lf", &num1);
        if (num1 < 0) {
            printf("Error: Cannot take square root of a negative number!\n");
            return;
        }
        result = squareRoot(num1);
        printf("√%.2lf = %.4lf\n", num1, result);
        break;
    case 3:
        printf("Enter a non-negative integer: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Error: Factorial is not defined for negative numbers!\n");
            return;
        }
        factResult = factorial(n);
        printf("%d! = %d\n", n, factResult);
        break;
    case 4:
        return;
    default:
        printf("Invalid choice!\n");
    }
}

// Addition
double add(double a, double b) {
    return a + b;
}

// Subtraction
double subtract(double a, double b) {
    return a - b;
}

// Multiplication
double multiply(double a, double b) {
    return a * b;
}

// Division
double divide(double a, double b) {
    return a / b;
}

// Power
double power(double base, double exp) {
    return pow(base, exp);
}

// Square Root
double squareRoot(double num) {
    return sqrt(num);
}

// Factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
