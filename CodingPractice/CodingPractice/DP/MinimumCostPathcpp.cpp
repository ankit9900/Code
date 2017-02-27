#include <iostream>
#include <map>
#include <string>
#include <ctime>
using namespace std;
// Minimum cost  DP

#define R  5
#define C 5
int min(int rep, int ins, int del) {
	int ret = INT_MAX;
	if (ret >= ins) {
		ret = ins;
	}
	if (ret >= rep){
		ret = rep;
	}
	if (ret >= del){
		ret = del;
	}
	cout << " rep " << rep << " ins " << ins << " del " << del << " ret " << ret << endl;
	return ret;
}

map<string, int> dpMap;



int findMinCostUtil(int mat[][5], int i, int j) {
	int val = 0;
	if ((i < 0) || (j < 0))
		return INT_MAX;
	if ((i == 0) && (j == 0)) {
		return mat[0][0];
	}

	int diag = findMinCostUtil(mat, i - 1, j - 1);
	
	int rt = findMinCostUtil(mat, i - 1, j);
	
	int left = findMinCostUtil(mat, i, j - 1);
	

	val = mat[i][j] + min(diag, rt, left);
	return val;
}
int findMinCost(int mat[][5], int i, int j, int len){
	if ((i < 0) || (j < 0) || (i > len) || (j > len)){
		return -1;
	}
	return findMinCostUtil(mat, i, j);

}
int findInmap(string str1, string str2) {
	string str = str1 + str2;
	if (dpMap.find(str) == dpMap.end()) {
		return INT_MAX;
	}
	return dpMap.at(str);
}
int dp[R][C];
void fill(){
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			dp[i][j] = INT_MAX;
		}
	}
}
int findMinCostUtilDP(int mat[][5], int i, int j, int len) {
	int val = 0;
	int diag = 0;
	int rt =0 ;
	int left = 0;
	
	if ((i < 0) || (j < 0))
		return INT_MAX;
	if (dp[i][j] != INT_MAX) {
		return dp[i][j];
	}
	
	if ((i ==0) && (j == 0)) {
		return mat[0][0];
	}
	
	diag =  findMinCostUtilDP(mat, i - 1, j - 1, len);
	dp[i - 1][j - 1] = diag;
	
	rt = findMinCostUtilDP(mat, i - 1, j, len);
	dp[i - 1][j] = rt;
	
	left = findMinCostUtilDP(mat, i, j - 1, len);
	dp[i][j-1] = left;
	
	val = min(diag, rt, left) +mat[i][j];
	dp[i][j] = val;
	return val;
}

int findMinCostDP(int mat[][5], int i, int j, int len){
	if ((i < 0) || (j < 0) || (i > len) || (j > len)){
		return -1;
	}
	return findMinCostUtilDP(mat, i, j, len);
}

int main() {
	int N = 4;
	int mat[5][5] = {
		{1,2,3,6,7},
		{4,8,2,10,11},
		{1,5,3,23,88}
	};

  	clock_t begin = clock();
	cout << "Without dp " << findMinCost(mat, 2, 4, 5) << endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;
	

	fill();
	begin = clock();
	cout << "With dp " << findMinCostDP(mat, 2, 4, 5) << endl;
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;
	
	system("pause");
	return 0;
}