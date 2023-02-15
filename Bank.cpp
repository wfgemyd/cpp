#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Person {
public:
	int id_num;
	string name;
	string surname;
	int age;
	string address;
	int phone_number;

	Person(int id_num, string name, string surname, int age, string address, int phone_number) {
		this->id_num = id_num;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->address = address;
		this->phone_number = phone_number;
	}
	
	void print() {
		cout << "ID: " << id_num << endl;
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Address: " << address << endl;
		cout << "Phone number: " << phone_number << endl;
	}

	string set_address(string address) {
		this->address = address;
		return address;
	}

	int set_phone_number(int phone_number) {
		this->phone_number = phone_number;
		return phone_number;
	}
};

vector<int> accounts;

int accountNumChecker() {
	int randon_num = rand() % 1000000;
	if (accounts.size() == 0) return randon_num;

	if (count(accounts.begin(), accounts.end(), randon_num)) 
	{ 
		return accountNumChecker();
	}
	else
	return randon_num;

}

class privateAccount: private Person{
public:
	int account_num;
	double balance;
	double interest_rate;
	int account_type;

	privateAccount(Person person, double balance, double interest_rate, int account_type): Person(person) {
		this->account_num = accountNumChecker(); // Random account number generator //must check in the future if the account number is already taken
		this->balance = balance;
		this->interest_rate = interest_rate;
		this->account_type = account_type;
	}

	void print() {
		Person::print();
		cout << "Account number: " << account_num << endl;
		cout << "Balance: " << balance << endl;
		cout << "Interest rate: " << interest_rate << endl;
		cout << "Account type: " << account_type << endl;
	}

	double set_balance(double balance) {
		this->balance = balance;
		return balance;
	}

	double set_interest_rate(double interest_rate) {
		this->interest_rate = interest_rate;
		return interest_rate;
	}

	int set_account_type(int account_type) {
		this->account_type = account_type;
		return account_type;
	}

	double deposit(double amount) {
		balance += amount;
		return balance;
	}

	double withdraw(double amount) {
		balance -= amount;
		return balance;
	}

	double interest() {
		balance += balance * interest_rate;
		return balance;
	}

	double transfer(double amount, privateAccount account) {
		balance -= amount;
		account.balance += amount;
		return balance;
	}
	

};




int main() {
	Person person(1, "John", "Doe", 20, "Street", 123456789);
	person.print();
	cout << endl;
	
	cout << person.set_address("Street 123") << endl;
	cout << person.set_phone_number(987654321) << endl;
	cout << endl;
	person.print();
	cout <<"\n" << endl;


	privateAccount private_account(person, 1000, 0.5, 1);
	private_account.print();
	cout << endl;
	accounts.push_back(private_account.account_num);

	privateAccount private_account2(person, 10400, 0.4, 3);
	private_account2.print();
	cout << endl;
	accounts.push_back(private_account2.account_num);

	privateAccount private_account3(person, 120, 0.8, 9);
	private_account3.print();
	cout << endl;
	accounts.push_back(private_account3.account_num);

	privateAccount private_account4(person, 10430, 0.2, 33);
	private_account4.print();
	cout << endl;
	accounts.push_back(private_account4.account_num);

	return 0;
}
