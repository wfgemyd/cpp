#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;



//---------------------------------------------------------------------------------------------------------------------------------------------------
//|  person class is created with a relationship that a person can exist with a bank account but if s/he want tto do it there is an age restriction |
//---------------------------------------------------------------------------------------------------------------------------------------------------

//bank-->vecor of accounts -> will call the functions of the account class-->a person can have multiple accounts and a person can be an owner of multiple accounts

class bank;
class account;
class Person;

class bank {

	private:
	string name;
	vector<account> accounts;
	vector<Person> owners;

	public:
	bank(string name){
		this->name = name;
	}

	void addAccount(account a) {
		accounts.push_back(a);
	}

	void addOwner(Person p) {
		owners.push_back(p);
	}

	void printAccounts() {
		for (int i = 0; i < accounts.size(); i++) {
			cout << accounts[i].getAccountNumber() << endl;
		}
	}

	void printOwners() {
		for (int i = 0; i < owners.size(); i++) {
			cout << owners[i].getName() << endl;
		}
	}

};

class account{

	private:
	int accountNumber;
	double balance;
	vector<Person> owners;

	public:
		account(int accountNumber, double balance, Person owner){
		this->accountNumber = accountNumber;
		this->balance = balance;
		this->owners.push_back(owner);
		}

		int getAccountNumber() {
			return accountNumber;
		}

		double getBalance() {
			return balance;
		}

		vector<Person> getOwner(vector<Person> owners) {
			return owners;
		}
		Person setOwner(Person owner){
			owners.push_back(owner);
		}

		void deposit(double amount) {
			balance += amount;
		}

		void withdraw(double amount) {
			balance -= amount;
		}

};

class Person {

	private:
	string name;
	int age;
	vector<account> accounts;

	public:
		Person(string name, int age) {
		this->name = name;
		this->age = age;
		}

		string getName(){
			return name;
		}

		int getAge(){
			return age;
		}

		void addAccount(account a){
			accounts.push_back(a);
		}

		void printAccounts() {
		for (int i = 0; i < accounts.size(); i++) {
			cout << accounts[i].getAccountNumber() << endl;
		}
	}

};

int main() {

	bank b("Bank of America");
	Person p1("John", 20);
	Person p2("Mary", 30);
	Person p3("Bob", 40);
	Person p4("Alice", 50);

	account a1(1, 1000, p1);
	account a2(2, 2000, p2);
	account a3(3, 3000, p3);
	account a4(4, 4000, p4);

	b.addAccount(a1);
	b.addAccount(a2);
	b.addAccount(a3);
	b.addAccount(a4);

	b.addOwner(p1);
	b.addOwner(p2);
	b.addOwner(p3);
	b.addOwner(p4);

	b.printAccounts();
	b.printOwners();

	return 0;
}
