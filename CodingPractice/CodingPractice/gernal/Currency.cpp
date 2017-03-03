#include <iostream>

using namespace std;

int findMinCurrency(){
	int numP = 0;
	int count = 0;
	cout << "Enter planets " << endl;
	cin >> numP;
	if (numP > 50){
		return 0;
	}
	int** pp = new int*[numP+1];
	int *tmp = new int[numP+1];
	for (int i = 0; i <= numP; ++i) {
		pp[i] = new int[numP];
	}
	for (int i = 0; i <= numP; ++i){
		for (int j = 0; j <= numP; ++j){
			pp[i][j] = INT_MAX;
		}
	}
	for (int z = 0; z <= numP; ++z) {
		tmp[z] = INT_MAX;
	}
	for (int i = 1; i <= numP; i++) {
		int x;
		cin >> x; 
		for (int j = 1; j <= x; j++) {
			int tmp;
			cin >> tmp;
			pp[i][tmp] = tmp;
		}
	}

		for (int j = 1; j <= numP; ++j) {
			if (pp[1][j] != INT_MAX) {
				tmp[pp[1][j]] = 1;
			}
		}

	for (int i = 2; i <= numP; ++i) {
		bool no = true;
		for (int j = 1; j <= numP; ++j) {
			if (pp[i][j] != INT_MAX) {
				if (tmp[pp[i][j]] == INT_MAX) {
					tmp[pp[i][j]] = 1;
				}
				else if (tmp[pp[i][j]] == 1) {
					no = false;
				}
			}
		}
		if (no) {
			count++;
		}
	}
	return count;
}

int main() {
	
	cout << "Answer is " << findMinCurrency() << endl;
	system("pause");
	return 0;

}