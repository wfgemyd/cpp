#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

vector <int> nPrevNumbers;

class cCarParts {
public:
	string sEngine;
	int nBattaryVolt;
	bool bTouchscreen;
	int nWheelSize;
	int nAirBags;
	
	cCarParts(string sEngine, int nBattaryVolt, bool bTouchscreen, int nWheelSize, int nAirBags) { //constructor
		this->sEngine = sEngine;
		this->nBattaryVolt = nBattaryVolt;
		this->bTouchscreen = bTouchscreen;
		this->nWheelSize = nWheelSize;
		this->nAirBags = nAirBags;
	}

	string sGetEngine() {
		return sEngine;
	}

	int nGetWheelSize() {

		return nWheelSize;
	}

	int nSetNewWheelSize(int nNewWheelSize) {

		this->nWheelSize = nNewWheelSize;
	}
};


class cCar :public cCarParts{
private:
	string sModel;
	int nCarNumber;
	bool bAvailable;
	int year;
	string sLeaseDate;
	string sReturnDate;
	bool tuned = false;
	
	int BNumberValidation(int temp) {
	
		for (int i : nPrevNumbers) {
			if (temp == i)
				return false;
		}
		nPrevNumbers.push_back(temp);
		return true;
	}

	int nCarNumGen() {
		int temp = rand() % 1000;
		if (BNumberValidation(temp)) {
			return temp;
		}
		return nCarNumGen();
	}

public:
	
	cCar(string sModel, string sLeaseDate,string sReturnDate, bool bAvailable, int year):cCarParts(sEngine, nBattaryVolt, bTouchscreen, nWheelSize, nAirBags) {
		
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
		cout << "*******************************************\n*******************************************\n";
	}
	bool bGotTuned() {
		return tuned;
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
