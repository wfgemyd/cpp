#include <iostream>
#include <string>

using namespace std;

class cParts {
	string sEngine;
	bool bTouchscreen;
	int nWheelSize;
	int nAirBags;

	cParts(string sEngine, bool bTouchscreen, int nWheelSize, int nAirBags) {
		this->sEngine = sEngine;
		this->bTouchscreen = bTouchscreen;
		this->nWheelSize = nWheelSize;
		this->nAirBags = nAirBags;
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

	int nCarNumGen() {
		return rand() % 1000;
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



};

int main() {
	cCar car1("Lada", "11/12/22", "19/12/23", true, 1999);

	cout << car1.aGetCarModel() << "\n ";
	cout << car1.aGetCarNumber() << "\n";
	cout<< car1.aGetCarAvailabilty();
	return 0;
}
