#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public: 
    void createAccount(int number, string name, double initialBalance) {
        accountNumber = number;
        accountHolderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully!" << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    virtual void calculateInterest() {
    }

    virtual void displayAccountInfo() {
        cout << "Account Number      : " << accountNumber << endl;
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Account Balance     : $" << balance << endl;
    }  
};

class SavingsAccount : public BankAccount {
protected:
    double interestRate;
    
public: 
    void setupSavings(int number, string name, double initialBalance, double rate) {
        createAccount(number, name, initialBalance);
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest calculated (" << interestRate << "%). Added: $" << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate       : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
protected:
    double overdraftLimit;

public:
    void setupChecking(int number, string name, double initialBalance, double limit) {
        createAccount(number, name, initialBalance);
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal Successful (Overdraft Used if Balance is negative)!" << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit     : $" << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
protected:
    int term;

public:
    void setupFixedDeposit(int number, string name, double initialBalance, int months) {
        createAccount(number, name, initialBalance);
        term = months;
    }

    void calculateInterest() override {
        double interest = balance * 0.07 * (term / 12.0); // Assuming standard flat 7% yearly interest
        balance += interest;
        cout << "Fixed Deposit interest added for " << term << " months: $" << interest << endl;
    }

    void displayAccountInfo() override {
        BankAccount::displayAccountInfo();
        cout << "Deposit Term Period : " << term << " months" << endl;
    }
};

int main() {
 
    SavingsAccount s;
    CheckingAccount c;
    FixedDepositAccount fd;
    
    BankAccount* accountPtr = nullptr; 

    int number;
    string name;
    double initialBalance; 
    double limit, rate; 
    int months;
    int choice;

    do {
        cout << "\n------- Banking System -------" << endl;
        cout << "1. Create Savings Account " << endl;
        cout << "2. Create Checking Account " << endl;
        cout << "3. Create Fixed Deposit Account " << endl;
        cout << "4. Deposit Funds " << endl;
        cout << "5. Withdraw Funds " << endl;
        cout << "6. Calculate Period Interest " << endl;
        cout << "7. Display Current Active Account Details " << endl;
        cout << "8. Exit " << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter account number : ";
            cin >> number;
            cout << "Enter account holder name : ";
            cin >> name;
            cout << "Enter initial balance : ";
            cin >> initialBalance;

            if (choice == 1) {
                cout << "Enter interest rate (%): ";
                cin >> rate;
                s.setupSavings(number, name, initialBalance, rate);
                accountPtr = &s; 
                cout << "Savings Account Created Successfully!" << endl;
            } 
            else if (choice == 2) {
                cout << "Enter Overdraft Limit : ";
                cin >> limit;
                c.setupChecking(number, name, initialBalance, limit);
                accountPtr = &c; 
                cout << "Checking Account Created Successfully!" << endl;
            } 
            else {
                cout << "Enter term duration (in months): ";
                cin >> months;
                fd.setupFixedDeposit(number, name, initialBalance, months);
                accountPtr = &fd; 
                cout << "Fixed Deposit Account Created Successfully!" << endl;
            }
        }
        else if (choice == 4) {
            if (accountPtr != nullptr) {
                double transactionAmount;
                cout << "Enter amount to deposit: ";
                cin >> transactionAmount;
                accountPtr->deposit(transactionAmount); 
            } else {
                cout << "No active account selected yet!" << endl;
            }
        }
        else if (choice == 5) {
            if (accountPtr != nullptr) {
                double transactionAmount;
                cout << "Enter amount to withdraw: ";
                cin >> transactionAmount;
                accountPtr->withdraw(transactionAmount); 
            } else {
                cout << "No active account selected yet!" << endl;
            }
        }
        else if (choice == 6) {
            if (accountPtr != nullptr) {
                accountPtr->calculateInterest(); 
            } else {
                cout << "No active account selected yet!" << endl;
            }
        }
        else if (choice == 7) {
            if (accountPtr != nullptr) {
                cout << "\n--- Active Account Information ---" << endl;
                accountPtr->displayAccountInfo();
            } else {
                cout << "No active account found!" << endl;
            }
        }
        else if (choice == 8) {
            cout << "Exited Successfully!" << endl;
        }
        else {
            cout << "Invalid choice, please select a valid number option." << endl;
        }

    } while (choice != 8);

    return 0;
}