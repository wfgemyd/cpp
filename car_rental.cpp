#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class cParts {
public:
	string *sEngine;
	bool *bTouchscreen;
	int *nWheelSize;
	int *nAirBags;

	cParts(string sEngine, bool bTouchscreen, int nWheelSize, int nAirBags) {
		this->sEngine = new string;
		this->bTouchscreen = new bool;
		this->nWheelSize = new int;
		this->nAirBags = new int;

		*this->sEngine = sEngine;
		*this->bTouchscreen = bTouchscreen;
		*this->nWheelSize = nWheelSize;
		*this->nAirBags = nAirBags;
	}
	cParts(const cParts &p) {
		sEngine = new string(*p.sEngine);
		bTouchscreen = new bool(*p.bTouchscreen);
		nWheelSize = new int(*p.nWheelSize);
		nAirBags = new int(*p.nAirBags);
	}
	~cParts()
	{
		delete sEngine;
		delete bTouchscreen;
		delete nWheelSize;
		delete nAirBags;
	}
};


class cCar {
private:
	string sModel;
	int nCarNumber;
	bool bAvailable;
	int year;
	string sLeaseDate;
	string sReturnDate;
	vector <string> sPrevNumbers;
	int BNumberValidation(int nRandNum) {
		if (sPrevNumbers.size() == 10) {
			cout << "The capasity has been reached\n";
		}
		for (int i=0; i==sPrevNumbers.size()-1; i++) {
			if (sPrevNumbers[i]== to_string(nRandNum))
			{
				return false;
			}
			return true;
		}
	}

	int nCarNumGen() {
		int temp = rand() % 10;
		if (BNumberValidation(temp)) {
			sPrevNumbers.push_back(to_string(temp));
			return temp;
		}
		nCarNumGen();
	}
public:
	cCar(string sModel, string sLeaseDate,string sReturnDate, bool bAvailable, int year){
		cout << "The constructur was called\n";
		this->sModel = sModel;
		this->nCarNumber = nCarNumGen();
		this->sLeaseDate = sLeaseDate;
		this->sReturnDate = sReturnDate;
		this->bAvailable = bAvailable;
		this->year = year;	
	}
	string aGetCarModel() {
		return sModel;
	}
	string aGetCarAvailabilty() {
		return bAvailable ? "true" : "false";
	}
	int aGetCarNumber() {
		return nCarNumber;
	}

	string vPrintDates() {
		return "start:"+sLeaseDate + " end:" + sReturnDate;
	}
	void vShowAllInfo() {
		cout << sModel << "\n" << aGetCarAvailabilty() << "\n" << aGetCarNumber() << "\n" << vPrintDates() << "\n" << year << "\n";
		cout << "*******************************************\n*******************************************";
	}


};

int main() {
	cCar car1("Lada", "1/12/22", "19/12/23", true, 1996);
	cCar car2("aff", "3/12/22", "12/12/23", false, 1994);
	cCar car3("Lhha", "7/12/22", "16/12/23", true, 1992);
	cCar car4("LATJa", "14/12/22", "18/12/23", false, 1999);
	cCar car5("AFG", "13/12/22", "15/12/23", true, 1943);
	cCar car6("khyed", "11/12/22", "16/12/23", false, 2009);
	

	car1.vShowAllInfo();
	car2.vShowAllInfo();
	car3.vShowAllInfo();
	car4.vShowAllInfo();
	car5.vShowAllInfo();
	car6.vShowAllInfo();

	return 0;
}
