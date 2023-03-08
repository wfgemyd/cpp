#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account; // forward declaration

class Person {
private:
    string name;
    int age;
    

public:
    vector<Account*> accounts;
    Person(string name, int age) : name(name), age(age) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void addAccount(Account* account) {
        accounts.push_back(account);
    }
    /*use of undefined type 'Account'   line 33	

    void printAccounts() const {
		cout << "Accounts of " << name << ":" << endl;
        
        for (const auto& account : accounts) {                   //line 33
			cout << "  " << account->getNumber() << " (" << account->getBalance() << ")" << endl;
		}
        
	}
    */
};

class Account {
private:
    int number;
    double balance;
    vector<Person*> owners;

public:
    Account(int number, double balance) : number(number), balance(balance) {}

    int getNumber() const {
        return number;
    }

    double getBalance() const {
        return balance;
    }

    void addOwner(Person* owner) {
        owners.push_back(owner);
    }

    vector<Person*> getOwners() const {
        return owners;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
};

class Bank {
private:
    string name;
    vector<Account*> accounts;
    vector<Person*> customers;

public:
    Bank(string name) : name(name) {}

    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    void addCustomer(Person* customer) {
        customers.push_back(customer);
    }

    vector<Account*> getAccounts() const {
        return accounts;
    }

    vector<Person*> getCustomers() const {
        return customers;
    }
    void account_of_person() { //different approach, trying to acces the accounts vector through the person class but no to store it directly because it doesnt work.
        cout << "Accounts of customers:" << endl;
        for (const auto& customer : customers) {
            cout << customer->getName() << ":" << endl;
            for (const auto& account : customer->accounts) {
                cout << "  " << account->getNumber() << " (" << account->getBalance() << ")" << endl;
            }
        }
    }

    void printAccounts() const {
        cout << "Avilable accounts of " << name << ":" << endl;
        for (const auto& account : accounts) {
            cout << "  " << account->getNumber() << " (" << account->getBalance() << ")" << endl;
        }
    }

    void printCustomers() const {
        cout << "Customers of " << name << ":" << endl;
        for (const auto& customer : customers) {
            cout << "  " << customer->getName() << " (" << customer->getAge() << ")" << endl;
        }
    }
};

int main() {
    // create bank and customers
    Bank bank("Bank of CPP");
    Person* john = new Person("John", 25);
    Person* mary = new Person("Mary", 30);
    Person* bob = new Person("Bob", 35);

    // add customers to bank
    bank.addCustomer(john);
    bank.addCustomer(mary);
    bank.addCustomer(bob);

    // create accounts and add to bank and customers
    Account* account1 = new Account(1001, 1000);
    Account* account2 = new Account(1002, 2000);
    Account* account3 = new Account(1003, 3000);
    Account* account4 = new Account(1004, 4000);

    bank.addAccount(account3);
    bank.addAccount(account4);

    account1->addOwner(john);
    account1->addOwner(mary);
    john->addAccount(account1);
    john->addAccount(account2);
    mary->addAccount(account1);

    bank.printAccounts();
    bank.printCustomers();
    cout << "||||||||||||||||||||||||||||||||\n\n";
    bank.account_of_person();
    return 0;

}
