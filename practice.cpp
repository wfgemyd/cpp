//Finding the max and min
#include <vector>
using namespace std;

int min(vector<int> list){
	int mini = list[0];
	int len = size(list);
	for (int i = 0; i <= len - 1; i++) {
		if (list[i] < mini) {
			mini = list[i];
			cout << mini;
		}
	}
	return mini;
}

int max(vector<int> list){
	int max = list[0];
	int len = size(list);
	for (int i = 0; i <= len - 1; i++) {
		if (list[i] > max) {
			max = list[i];
			cout << max;
		}
	}
	return max;
}
//_____________________________________________________
