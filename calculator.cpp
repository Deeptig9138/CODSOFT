#include <iostream>
#include <limits>

using namespace std;

float calculate(float num1, float num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero." << endl;
                return 0;
            } else {
                return num1 / num2;
            }
        default:
            cout << "Invalid operation." << endl;
            return 0;
    }
}

int main() {
    while (true) {
        cout << "\nSimple Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice (1/2/3/4/5): ";
        
        string choice;
        cin >> choice;

        if (choice == "5") {
            cout << "Goodbye!" << endl;
            break;
        }

        char operation;
        if (choice == "1") {
            operation = '+';
        } else if (choice == "2") {
            operation = '-';
        } else if (choice == "3") {
            operation = '*';
        } else if (choice == "4") {
            operation = '/';
        } else {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        float num1, num2;
        cout << "Enter first number: ";
        if (!(cin >> num1)) {
            cout << "Invalid input. Please enter numeric values." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cout << "Invalid input. Please enter numeric values." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        float result = calculate(num1, num2, operation);
        if (!(num2 == 0 && operation == '/')) {
            cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
        }
    }

    return 0;
}
