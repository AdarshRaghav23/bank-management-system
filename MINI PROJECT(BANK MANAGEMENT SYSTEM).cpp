#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    double balance;

public:
    void create() {
        cout << "\nEnter Account Number: ";
        cin >> accNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Created!\n";
    }

    int getAccNo() {
        return accNo;
    }

    void deposit() {
        double amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Deposited Successfully!\n";
    }

    void withdraw() {
        double amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if (amt > balance)
            cout << "Insufficient Balance!\n";
        else {
            balance -= amt;
            cout << "Withdrawal Successful!\n";
        }
    }

    void display() {
        cout << "\n--- Account Info ---\n";
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice, accNo;

    do {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Search Account\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            BankAccount acc;
            acc.create();
            accounts.push_back(acc);
            break;
        }

        case 2: {
            cout << "Enter Account Number: ";
            cin >> accNo;
            for (auto &acc : accounts) {
                if (acc.getAccNo() == accNo) {
                    acc.deposit();
                    break;
                }
            }
            break;
        }

        case 3: {
            cout << "Enter Account Number: ";
            cin >> accNo;
            for (auto &acc : accounts) {
                if (acc.getAccNo() == accNo) {
                    acc.withdraw();
                    break;
                }
            }
            break;
        }

        case 4: {
            cout << "Enter Account Number: ";
            cin >> accNo;
            for (auto &acc : accounts) {
                if (acc.getAccNo() == accNo) {
                    acc.display();
                    break;
                }
            }
            break;
        }

        case 5:
            for (auto &acc : accounts)
                acc.display();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}