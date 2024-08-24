#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Base class for Account
class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(const string& accNum, double bal)
        : accountNumber(accNum), balance(bal) {}

    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    virtual string getAccountType() const = 0;

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Withdraw amount must be positive." << endl;
        }
    }

    void saveToFile(ofstream& file) {
        file << accountNumber << " " << balance << " " << getAccountType() << endl;
    }
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
public:
    SavingsAccount(const string& accNum, double bal)
        : Account(accNum, bal) {}

    string getAccountType() const override {
        return "Savings";
    }
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(const string& accNum, double bal)
        : Account(accNum, bal) {}

    string getAccountType() const override {
        return "Current";
    }
};

// Bank class to manage accounts
class Bank {
    vector<Account*> accounts;

public:
    Bank() {
        loadAccountsFromFile();
    }

    ~Bank() {
        for (auto account : accounts) {
            delete account;
        }
    }

    void createAccount(Account* account) {
        accounts.push_back(account);
        saveAccountsToFile();
    }

    Account* findAccount(const string& accountNumber) {
        for (auto account : accounts) {
            if (account->getAccountNumber() == accountNumber) {
                return account;
            }
        }
        return nullptr;
    }

    void deposit(const string& accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account) {
            account->deposit(amount);
            saveAccountsToFile();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdraw(const string& accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account) {
            account->withdraw(amount);
            saveAccountsToFile();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void transfer(const string& fromAccount, const string& toAccount, double amount) {
        Account* from = findAccount(fromAccount);
        Account* to = findAccount(toAccount);
        if (from && to) {
            from->withdraw(amount);
            to->deposit(amount);
            saveAccountsToFile();
        } else {
            cout << "One or both accounts not found." << endl;
        }
    }

    void showAccountDetails(const string& accountNumber) {
        Account* account = findAccount(accountNumber);
        if (account) {
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Balance: " << account->getBalance() << endl;
            cout << "Account Type: " << account->getAccountType() << endl;
        } else {
            cout << "Account not found." << endl;
        }
    }

private:
    void loadAccountsFromFile() {
        ifstream file("bank_data.txt");
        if (!file) return; // File doesn't exist yet

        string accountNumber, accountType;
        double balance;
        while (file >> accountNumber >> balance >> accountType) {
            if (accountType == "Savings") {
                accounts.push_back(new SavingsAccount(accountNumber, balance));
            } else if (accountType == "Current") {
                accounts.push_back(new CurrentAccount(accountNumber, balance));
            }
        }
        file.close();
    }

    void saveAccountsToFile() {
        ofstream file("bank_data.txt");
        for (auto account : accounts) {
            account->saveToFile(file);
        }
        file.close();
    }
};

// Main function to interact with the Bank system
int main() {
    Bank bank;
    int choice;
    string accountNumber, fromAccount, toAccount;
    double amount, initialBalance;

    do {
        cout << "\nBanking System";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Transfer";
        cout << "\n5. Show Account Details";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
                cout << "Select Account Type (1 for Savings, 2 for Current): ";
                int accountType;
                cin >> accountType;

                if (accountType == 1) {
                    bank.createAccount(new SavingsAccount(accountNumber, initialBalance));
                    cout << "Savings Account created successfully." << endl;
                } else if (accountType == 2) {
                    bank.createAccount(new CurrentAccount(accountNumber, initialBalance));
                    cout << "Current Account created successfully." << endl;
                } else {
                    cout << "Invalid account type selected." << endl;
                }
                break;
            }
            case 2: {
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                cout << "\nEnter From Account Number: ";
                cin >> fromAccount;
                cout << "Enter To Account Number: ";
                cin >> toAccount;
                cout << "Enter Amount to Transfer: ";
                cin >> amount;
                bank.transfer(fromAccount, toAccount, amount);
                break;
            }
            case 5: {
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                bank.showAccountDetails(accountNumber);
                break;
            }
            case 6: {
                cout << "Exiting the system..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please choose again." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
