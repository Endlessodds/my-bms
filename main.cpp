#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Class representing a single bank account
class Account {
private:
    // Private member variables to store account data
    string name;
    string phoneNumber;
    int accountNumber;
    double balance;
    string pin;

public:
    // Constructor initializes balance and account number
    Account() : balance(0.0), accountNumber(0) {}

    // Generate and return the next account number by reading/writing from a file
    int getNextAccountNumber() {
        ifstream file("account_number.txt");
        int number = 0;
        if (file.is_open()) {
            file >> number;
            file.close();
        }
        number++;
        ofstream outFile("account_number.txt");
        if (outFile.is_open()) {
            outFile << number;
            outFile.close();
        }
        return number;
    }

    // Create a new account by taking user input and saving to file
    void createAccount() {
        cout << "\nEnter your name: ";
        getline(cin, name);

        cout << "Enter your phone number: ";
        getline(cin, phoneNumber);

        cout << "Set a 4-digit PIN for your account: ";
        getline(cin, pin);

        accountNumber = getNextAccountNumber();
        balance = 0.0;
        saveRecord(); // Save account to file

        cout << "\nAccount created successfully! Your account number is: " << accountNumber << "\n";
    }

    // Load an account from file based on account number
    bool loadAccount(int accNumber) {
        ifstream file(to_string(accNumber) + ".txt");
        if (file.is_open()) {
            getline(file, name);
            getline(file, phoneNumber);
            file >> accountNumber;
            file >> balance;
            file.ignore(); // Skip newline
            getline(file, pin);
            file.close();
            return true;
        } else {
            return false;
        }
    }

    // Verify if the entered PIN matches the account's PIN
    bool verifyPIN(const string &inputPIN) {
        return inputPIN == pin;
    }

    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Invalid amount.\n";
        }
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else if (amount <= 0) {
            cout << "Invalid amount.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
        }
    }

    // Display account information
    void displayAccountInfo() {
        cout << "\n===== Account Info =====\n";
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << "\n\n";
    }

    // Save current account data to a file
    void saveRecord() {
        ofstream file(to_string(accountNumber) + ".txt");
        if (file.is_open()) {
            file << name << endl;
            file << phoneNumber << endl;
            file << accountNumber << endl;
            file << balance << endl;
            file << pin << endl;
            file.close();
        } else {
            cout << "Error saving account.\n";
        }
    }

    // Return the current balance
    double getBalance() {
        return balance;
    }

    // Return the account number
    int getAccountNumber() {
        return accountNumber;
    }

    // Transfer money to another account by account number
    void transfer(int receiverAccountNumber, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance to transfer.\n";
            return;
        }

        if (amount <= 0) {
            cout << "Invalid transfer amount.\n";
            return;
        }

        Account receiver;
        if (receiver.loadAccount(receiverAccountNumber)) {
            balance -= amount;
            receiver.balance += amount;
            saveRecord();
            receiver.saveRecord();
            cout << "Transferred $" << fixed << setprecision(2) << amount << " to Account " << receiverAccountNumber << ".\n";
        } else {
            cout << "Receiver account not found.\n";
        }
    }
};

// Menu shown after successful login
void atmMenu(Account &user) {
    int choice;
    double amount;
    do {
        cout << "\n===== ATM Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. View Account Info\n";
        cout << "5. Transfer Money\n";
        cout << "6. Save and Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            user.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            user.withdraw(amount);
            break;
        case 3:
            cout << "Your current balance is: $" << fixed << setprecision(2) << user.getBalance() << "\n";
            break;
        case 4:
            user.displayAccountInfo();
            break;
        case 5: {
            int receiverAccNum;
            cout << "Enter receiver's account number: ";
            cin >> receiverAccNum;
            cout << "Enter amount to transfer: $";
            cin >> amount;
            user.transfer(receiverAccNum, amount);
            break;
        }
        case 6:
            user.saveRecord();
            cout << "Account saved. Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

// Entry point of the application
int main() {
    int mainChoice;

    do {
        cout << "\n===== Welcome to the ATM =====\n";
        cout << "1. Create New Account\n";
        cout << "2. Log into Existing Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;
        cin.ignore(); // Clear leftover newline from input buffer

        if (mainChoice == 1) {
            Account newUser;
            newUser.createAccount();
        }
        else if (mainChoice == 2) {
            int accNumber;
            string inputPIN;
            cout << "Enter your account number: ";
            cin >> accNumber;
            cin.ignore();

            Account existingUser;
            if (existingUser.loadAccount(accNumber)) {
                cout << "Enter your 4-digit PIN: ";
                getline(cin, inputPIN);
                if (existingUser.verifyPIN(inputPIN)) {
                    cout << "Login successful!\n";
                    atmMenu(existingUser);
                } else {
                    cout << "Incorrect PIN. Access denied.\n";
                }
            } else {
                cout << "Account not found.\n";
            }
        }
        else if (mainChoice == 3) {
            cout << "Thank you for using the ATM. Goodbye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}
