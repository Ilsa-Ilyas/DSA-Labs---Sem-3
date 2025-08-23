#include <iostream>
using namespace std;

//class made
class BankAccount {

    //private data members
    private:
    double balance;

//public members and functions
    public:
    
    //default constructor
    BankAccount() {
        balance = 0.0;}

    //parameterized constructor
    BankAccount(double bal) {
        balance = bal;
    }

    //copy constructor
    BankAccount(const BankAccount &other) {
        balance = other.balance;
    }

    double getBalance() const {
        return balance;
    }

    void deduct(double amt) {
        if (amt <= balance) {
            balance -= amt;
        }
    }

};

int main() {
    //1. default constructor
    BankAccount acc1;
    cout << "account-1 balance: $" << acc1.getBalance() << endl;

    //2. parameterized constructor
    BankAccount acc2(1000.0);
    cout << "account-2 balance: $" << acc2.getBalance() << endl;

    //3. copy constructor
    BankAccount acc3(acc2);
    acc3.deduct(200.0);
    cout << "account-3 balance after deducting $200: $" << acc3.getBalance() << endl;
    cout << "account-2 balance (should be unchanged): $" << acc2.getBalance() << endl;

    return 0;
}