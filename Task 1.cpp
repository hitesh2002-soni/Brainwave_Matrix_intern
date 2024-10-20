//fully functional ATM interface using C++

#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    int pin;

public:
    ATM() {
        balance = 1000.00; 
        pin = 1234; 
    }

    bool verifyPin(int enteredPin) {
        if (enteredPin == pin) {
            return true;
        } else {
            return false;
        }
    }
 
    void displayMenu() {
        cout << "ATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
    }

    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }
    
    void depositMoney() {
        double amount;
        cout << "Enter the amount to deposit: $";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully! New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter the amount to withdraw: $";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully! New balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void run() {
        int choice;
        int enteredPin;
        cout << "Welcome to the ATM!\n";
        cout << "Please enter your PIN: ";
        cin >> enteredPin;

        if (verifyPin(enteredPin)) {
            do {
                displayMenu();
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    depositMoney();
                    break;
                case 3:
                    withdrawMoney();
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
                cout << endl;

            } while (choice != 4); 
        } else {
            cout << "Incorrect PIN. Access denied.\n";
        }
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}

