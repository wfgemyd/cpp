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

	int age_checker(int age) {
		
		if (age < 16) {

			cout << "too young for a bank account\n\n";
			while (age < 16) {
				cout <<"Enter a valid age: ";
				cin >> age;
			}
			return this->age = age;

		}else if (age > 101) {
			cout << "Probably a typo\n\n";
			while (age > 101) {
				cout << "Enter a valid age: ";
				cin >> age;
			}
			return this->age = age;
		}else return age;

	}

	Person(int id_num, string name, string surname, int age, string address, int phone_number) {
		this->id_num = id_num;
		this->name = name;
		this->surname = surname;
		this->age = age_checker(age);
		this->address = address;
		this->phone_number = phone_number;
	}
	
	void print() {
		cout << "ID: " << id_num << endl;
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Address: " << address << endl;
		cout << "Phone number: " << phone_number <<"\n\n" << endl;
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

string random_name() {

	string name = "";
	int name_length = rand() % 10 + 1;
	for (int i = 0; i < name_length; i++) {
		name += (char)(rand() % 26 + 97);
	}
	return name;

}

class privateAccount : public Person {
public:
	int account_num;
	double balance;
	double interest_rate;
	char account_type;
	
	privateAccount(Person person, double balance, double interest_rate, char account_type) : Person(person) {
		this->account_num = accountNumChecker(); 
		this->balance = balance;
		this->interest_rate = interest_rate;
		this->account_type = set_account_type(account_type);
	}

	int business_num;
	string business_name;
	string business_address;
	int business_phone_number;

	privateAccount(Person person, double balance, double interest_rate, char account_type, int business_num) : Person(person) {
		this->account_num = accountNumChecker();
		this->balance = balance;
		this->interest_rate = interest_rate;
		this->account_type = account_type;

		this->business_num = business_num;
		this->business_name = random_name();
		this->business_address = person.address;
		this->business_phone_number = person.phone_number;
	}

	void printp() {
		Person::print();
		cout << "Account number: " << account_num << endl;
		cout << "Balance: " << balance << endl;
		cout << "Interest rate: " << interest_rate << endl;
		cout << "Account type: " << account_type << endl;
	}
	void printb() {
		cout << "\n\n";
		Person::print();
		cout << "Account number: " << account_num << endl;
		cout << "Balance: " << balance << endl;
		cout << "Interest rate: " << interest_rate << endl;
		cout << "Account type: " << account_type << endl;
		cout << "Business number: " << business_num << endl;
		cout << "Business name: " << business_name << endl;
		cout << "Business address: " << business_address << endl;
		cout << "Business phone number: " << business_phone_number << "\n\n" << endl;
	}

	double set_balance(double balance) {
		this->balance = balance;
		return balance;
	}

	double set_interest_rate(double interest_rate) {
		this->interest_rate = interest_rate;
		return interest_rate;
	}

	char set_account_type(char account_type) {
		return this->account_type = account_type;;
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


void print_accounts() {
	string outt = "";
	for (int i = 0; i < accounts.size(); i++) {
		if (accounts.size() - 1 == i) outt = outt + to_string(accounts[i]);
		else
		{
			outt = outt + to_string(accounts[i]) + " ,";
		}
		
	}
	cout << outt;
}


void UI() {
	cout << "1. Create private account" << endl;
	cout << "2. Create business account" << endl;
	cout << "3. Deposit" << endl;
	cout << "4. Withdraw" << endl;
	cout << "5. Interest" << endl;
	cout << "6. Transfer" << endl;
	cout << "7. Print accounts" << endl;
	cout << "8. Exit" << endl;
}//the actuall usage of the menu must be implemented. 


int main() {
	Person person(1, "John", "Doe", 20, "Street", 123456789);
	Person person2(2, "aa", "bjjjb", 30, "Sujjjet", 7698789);
	Person person3(3, "ada", "b4b", 34, "44ajeeet", 7698789);
	Person person4(4, "aga", "bgwb", 85, "Seeeet", 7698789);
	Person person5(5, "aah", "beb", 24, "ahft", 7698789);


	privateAccount private_account(person, 1000, 0.5, 'b', 1916548);
	private_account.printb();
	accounts.push_back(private_account.account_num);

	privateAccount private_account2(person2, 1000, 0.5, 'b', 1916548);
	private_account2.printb();
	accounts.push_back(private_account2.account_num);

	privateAccount private_account3(person3, 10400, 0.4, 'p');
	private_account3.printp();
	accounts.push_back(private_account3.account_num);

	privateAccount private_account4(person4, 120, 0.8, 'p');
	private_account4.printp();
	accounts.push_back(private_account4.account_num);

	privateAccount private_account5(person5, 10430, 0.2, 'p');
	private_account5.printp();
	accounts.push_back(private_account5.account_num);

	

	return 0;
}
