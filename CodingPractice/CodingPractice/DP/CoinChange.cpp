#include <iostream>
#include <map>
#include <ctime>

using namespace std;

// Minimum Coin Change
// arr[] = {1, 2, 3};
// N = 10

int findMinChange(int arr[], int N, int len) {
	int min = INT_MAX;
	if (N == 0) {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if (arr[i] <= N) {
			int ret = 1 + findMinChange(arr, N - arr[i], len);
			if ((ret != INT_MAX) && (ret + 1 < min)) {
				min = ret;
			}
		}
	}
	return min;
}

int findMinChangeDP1(int money, int arr[], int len) {
	int* change = new int[money + 1];
	for (int i = 0; i <= money;++i)
		change[i] = 0;
	int i, j;
	for (j = 1; j <= money; ++j) {
		int min = INT_MAX;
		for (i = 0; i < len; i++) {
			if ((j >= arr[i]) && (change[j - arr[i]] + 1) < min) {
				min = change[j - arr[i]] + 1;
			}
		}
		change[j] = min;
	}
	return change[money];
}

int main() {
	int arr[] = {2, 3, 5 ,1,4,7};
	//int arr[] = {  3, 5, 1 };
	
	int size = sizeof(arr) / sizeof(arr[0]);
	int sum = 99;
	clock_t begin = clock();
	cout << "Without dp " << findMinChange(arr, sum, size) << endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;
    

	begin = clock();
	cout << "With dp " << findMinChangeDP1(sum,arr, size) << endl;
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;

	system("pause");
	return 0;
}
