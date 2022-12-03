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
#include <ctime>
using namespace std;

int main()
{
	int num, guess, tries;
	tries = 0;
	srand(time(NULL));
	num = rand() % 100 + 1;
	
	cout << "**** GUESSING GAME ****";
	cout << "Guess a number between 1-100.\n Good luck!\n";
	do {
		cout << "Give your best guess: ";
		cin >> guess;
		if (guess < num) {
			tries++;
			cout << "Cold\n";
		}
		else{
			tries++;
			cout << "Hot\n";
		}
	} while (guess != num);
	cout << "it took you " << tries << " tries to guess: " << num;

	return 0;
}
//_____________________________________________________
