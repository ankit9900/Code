#include <iostream>
#include <set>
using namespace std;

int findDS(int arr[], int len) {
	int count = 0;
	set<int> s;
	int all = 0;
	for (int i = 0; i <  len; ++i) {
		all += arr[i];
		if (s.find(arr[i]) == s.end()) {
			count++;
			s.insert(arr[i]);
		}
	}
	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (s.find(arr[i]+arr[j]) == s.end()) {
				count++;
				s.insert(arr[i]+arr[j]);
			}
		}
	}
	if (s.find(all) == s.end()) {
		count++;
		s.insert(all);
	}
	return count;
}

int main() {
	int arr[] = { 1, 2, 3 ,5,3};
	int N = 5;
	cout << findDS(arr, N) << endl;
	system("pause");
	return 0;
}