#include <iostream>
using namespace std;
//  N queen Problem
#define N 8



class Board {
	int** sq;
public:
	~Board() {
		for (int i = 0; i < N; ++i){
			delete[] sq[i];
		}
		delete[] sq;
	}
	void display() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j){
				cout << sq[i][j] << " ";
			}
			cout << endl;
		}

	}
	int** getSq() {
		return sq;
	}
	Board() {
		sq = new int*[N];
		for (int i = 0; i < N; ++i){
			sq[i] = new int[N];
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j){
				sq[i][j] = 0;
			}
		}
	}

	bool isSafe1(int row, int col, int** sq) {
		int j ;
		int i = col;
		// check col
		
		i = col;
		for ( j = 0; j <= row; ++j){
			if (sq[j][i]){
				return false;
			}
		}
		j = col;
		for (int i = row-1; i >= 0; i--) {
			j++;
			if ((i < N) && (i >= 0) && (j < N) && (j >= 0)) {
				if ((sq[i][j] == 1) || (sq[j][i]) == 1) {
					return false;
				}
			}
		}
		// for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if ((i < N) && (i >= 0) && (j < N) && (j >= 0)) {
				if (sq[i][j] == 1) {
					return false;
				}
			}
		}
		for (i = row, j = col; i < N && j <N; i++, j++) {
			if ((i < N) && (i >= 0) && (j < N) && (j >= 0)) {
				if (sq[i][j] == 1) {
					return false;
				}
			}
		}

		return true;
	}
	bool solveNqueens(int col, int row, int** sq){
		if (row == N){
			return true;
		}
		int i;
		int j;
		for (int i = row; i < col; ++i){
			bool isSafe = false;
			for (j = 0; j < col; ++j) { //  queen == i
				if (isSafe1(i, j, sq)) {
					isSafe = true;
					sq[i][j] = 1;
					bool retVal = solveNqueens(col, row + 1, sq);
					if (retVal == false){
						sq[i][j] = 0;
						continue;
					}
					else {
						return true;
					}
				}
			}
			return false;
		}
	}
};

int main() {
	Board b;
	if (b.solveNqueens(8, 0, b.getSq())){
		b.display();
	}
	system("pause");
	return 0;
}