#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

map<string, int> dpMap;
// Edit distance
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
	return ret;
}

int fun(string str1, string str2) {
	if (str1[0] == str2[0])
	   return 0;
	return 1;
}
int findInmap(string str1, string str2) {
	string str = str1 + str2;
	if (dpMap.find(str) == dpMap.end()) {
		return INT_MAX;
	}
	return dpMap.at(str);
}

int editDistance(string str1, string str2) {
	
	if (str1.length() == 0){
		return str2.length();
	}
	if (str2.length() == 0) {
		return str1.length();
	}
	int replace;
	int insert;  // ab bc    bb bc | bab bc |  b bc
	int del;                       //| bab c|  

	replace = editDistance(str1.substr(1), str2.substr(1)) + fun(str1, str2);
	insert = 1 + editDistance(str1, str2.substr(1)) ;
	del = 1 + editDistance(str1.substr(1), str2) ;

	return min(replace, insert, del);
}


int editDistanceDP(string str1, string str2) {
	int val =  INT_MAX;
	if ((val = findInmap(str1, str2)) != INT_MAX) {
		return val;
	}
	if (str1.length() == 0){
		return str2.length();
	}
	if (str2.length() == 0) {
		return str1.length();
	}
	int replace;
	int insert;
	int del;
	
	replace = editDistanceDP(str1.substr(1), str2.substr(1)) + fun(str1, str2);
	insert = 1 + editDistanceDP(str1, str2.substr(1));
	del = 1 + editDistanceDP(str1.substr(1), str2);
	val = min(replace, insert, del);
	string str = str1 + str2;
	dpMap[str] = val;
	return val;
}
int main() {
	
	clock_t begin = clock();
	cout << "Without dp " << editDistance("sunday", "saturday") << endl;
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;

	
	begin = clock();
	cout << "With dp " << editDistanceDP("sunday", "saturday") << endl;
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time taken  " << elapsed_secs << endl;

	system("pause");
	return 0;
}