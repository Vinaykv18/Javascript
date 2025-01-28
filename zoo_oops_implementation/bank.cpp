#include <iostream>
#include <string>
using namespace std;

// Class to represent a Bank Account
class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount()
    {
      accountHolderName="";
      accountNumber = "";
      balance=0.0;
    }
    BankAccount(string accNumber, string holderName, double initialBalance) {
        accountNumber = accNumber;
        accountHolderName = holderName;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Method to display account details
    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    int numberOfAccounts;

    // Ask user how many bank accounts they want to create
    cout << "Enter the number of bank accounts: ";
    cin >> numberOfAccounts;

    // Create an array of pointers to BankAccount objects
    //BankAccount** accounts = new BankAccount*[numberOfAccounts];
     BankAccount accounts[numberOfAccounts];

    // Input details for each account
    for (int i = 0; i < numberOfAccounts; i++) {
        string accNumber, holderName;
        double initialBalance;

        cout << "Enter details for account " << (i + 1) << ":\n";
        cout << "Account Number: ";
        cin >> accNumber;
        cout << "Account Holder Name: ";
        cin.ignore(); // To handle newline character from previous input
        getline(cin, holderName);
        cout << "Initial Balance: ";
        cin >> initialBalance;

        // Create a new account
        accounts[i] = BankAccount(accNumber, holderName, initialBalance);
    }

    // Display all accounts
    cout << "\nAll Bank Accounts Information:\n";
    for (int i = 0; i < numberOfAccounts; i++) {
        accounts[i].displayAccountInfo();
    }

    // Example operations
    accounts[0].deposit(500.00);   // Deposit to the first account
    accounts[1].withdraw(200.00);  // Withdraw from the second account

    // Display updated account information
    cout << "\nUpdated Bank Accounts Information:\n";
    for (int i = 0; i < numberOfAccounts; i++) {
        accounts[i].displayAccountInfo();
    }

    // Cleanup memory
    // for (int i = 0; i < numberOfAccounts; i++) {
    //     delete accounts[i];
    // }
   //2
   // delete[] accounts;

    return 0;
}
