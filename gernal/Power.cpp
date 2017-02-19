#include <iostream>
#include <string>
using namespace std;
#define int2 long long
int2 pow(int2 x, int2 raise) {
	if (raise == 0)
		return 1;
	
	return x*pow(x, raise - 1);
}
int2 pow2(int2 x, int2 raise){
	if (raise == 0)
		return 1;

	return x/pow2(x, raise - 1);
}
int2 power(int2 x, int2 raise){
	if (raise < 0){
		raise = raise *(-1);
		if (raise % 2 == 0){
			return pow(x, raise / 2) * pow(x, raise / 2);
		}
		else {
			return x* pow(x, raise / 2) * pow(x, raise / 2);
		}
	}
	if (raise % 2 == 0){
		int2 temp = pow(x, raise / 2);
		return temp * temp ;
	}
	else {
		int2 temp = pow(x, raise / 2);
		return x* temp * temp;
	}
	
}

void removeVowels(string& str, int i){
	if (str.length()== 0){
		return;
	}
	if (str.length() == i){
		return ;
	}
	if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')) {
		str.erase(i, 1);
		--i;
	}
	return removeVowels(str, ++i);
}

int main() {
	cout << power(99, 5) << endl;
	string str = "recurseiouvowlmn";
	cout << str << endl;
	removeVowels(str, 0);
	cout << str << endl;
	system("pause");
	return 0;
}