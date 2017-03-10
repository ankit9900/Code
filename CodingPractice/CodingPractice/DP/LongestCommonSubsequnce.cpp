#include <iostream>
#include <string>
using namespace std;

// Longest Common Subsequnce

int findLCS(string str1, string str2) {
	if ((str1.length() == 0) || (str2.length() == 0)) {
		return 0;
	}
	if (str1[0] == str2[0]) {
		return 1+ findLCS(str1.substr(1, str1.length()), str2.substr(1, str2.length()));
	}
	else {
		int res1 = findLCS(str1.substr(1, str1.length()), str2);
		int res2 = findLCS(str1, str2.substr(1, str2.length()));
		if (res1 >= res2)
			return res1;
		else
			return res2;
	}
}
int max(int a, int b) {
	return a >= b ? a : b;
}
int findLCSDP(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int** result = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i) {
		result[i] = new int[len2 + 1];
	}

	// If string1 is NULL
	for (int i = 0; i < len1 + 1; ++i) {
		result[i][0] = 0;
	}

	// If string2 is NULL
	for (int i = 0; i < len1 + 1; ++i) {
		result[0][i] = 0;
	}

	for (int i = 1; i < len1 + 1; ++i) {
		for (int j = 1; j < len2 + 1; ++j) {
			if (str1[i-1] == str2[j-1]){
				result[i][j] = result[i-1][j-1] + 1;
			}
			else{
				result[i][j] = max(result[i][j - 1], result[i - 1][j]);
			}
		}
	}
	int res = result[len1][len2];

	for (int i = 0; i < len2 + 1; ++i) {
		delete[]result[i];
	}
	delete[]result;

	return res;
}

int findLCSDPandPrint(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();
	int** result = new int*[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i) {
		result[i] = new int[len2 + 1];
	}

	char** direction = new char*[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i) {
		direction[i] = new char[len2 + 1];
	}
	for (int i = 0; i < len1 + 1; ++i) {
	for (int j = 0; j < len2 + 1; ++j) {
		direction[i][j] = '\0';
	}
	char* resultChar = new char[len1 + len2 +1];
	for (int i = 0; i < len1 + len2 + 1; ++i) {
		resultChar[i] = '\0';
	}

	// If string1 is NULL
	for (int i = 0; i < len1 + 1; ++i) {
		result[i][0] = 0;
	}

	// If string2 is NULL
	for (int i = 0; i < len1 + 1; ++i) {
		result[0][i] = 0;
	}

	for (int i = 1; i < len1 + 1; ++i) {
		for (int j = 1; j < len2 + 1; ++j) {
			if (str1[i - 1] == str2[j - 1]){
				result[i][j] = result[i - 1][j - 1] + 1;
				direction[i][j] = 'NW';
			}
			else{
				result[i][j] = max(result[i][j - 1], result[i - 1][j]);
				if (result[i][j] >= result[i - 1][j]) {
					direction[i][j-1] = 'N';
				}
				else {
					direction[i][j - 1] = 'W';
				}
			}
		}
	}
	int res = result[len1][len2];
	int a = len1;
	int b = len2;
	char answer = '\0';
	char sol = direction[len1][len2];
	while (sol != '\0') {
		if (direction[a][b] == 'NW') {
			sol = str1[a - 1] + answer;
			a--;
			b--;
		}
		else if (direction[a][b] == 'W'){
			b--;
		}
		else if (direction[a][b] == 'N') {
			a--;
		}
		sol = direction[a][b];
	}
	cout << sol << endl;
	for (int i = 0; i < len2 + 1; ++i) {
		delete[]result[i];
	}
	delete[]result;

	return res;
}

int main() {
	cout << findLCS("acbaed", "abcadf")<<endl;
	cout << findLCSDPandPrint("abc", "acbd") << endl;
	system("pause");
	return 0;
}