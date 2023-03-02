#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;


bool narcissistic(int value) {
	int sum = 0;
	vector<int> num;
	int val = value;
	int temp = 0;
	while (value != 0) {
		temp = value % 10;
		value /= 10;
		num.push_back(temp);
		
	}
	int len = num.size();
	for (int i = 0; i < len; i++) {
		num[i] = pow(num[i],len);
		sum += num[i];
		cout << sum << endl;

	}
	if(sum==val)return true;
	return false;
}

int main() {
	narcissistic(4887);

	return 0;
}