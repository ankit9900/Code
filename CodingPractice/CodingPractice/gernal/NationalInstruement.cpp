// Name:
// USN:
// Summary:

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> E;
// Remove additional cin/cout/printf/scanf before submission

// Note: The function is being passed n, the dimension of the battlefield is n x n.
string SimulationWinner(int *sectorArray, int n)
{
	
	// -1 A
	// -2 E
	// Your code goes here

	return "";
}

int main()
{
	int n;
	cin >> n;
	int *sectorArray = new int[n*n];


	for (int i = 0; i < (n*n); i++)
	{
		cin >> sectorArray[i];
		if (i % 2 == 0){
			A.push_back(sectorArray[i]);
		}
		else {
			E.push_back(sectorArray[i]);
		}
	}
	sort(A.begin(), A.end());
	sort(E.begin(), E.end());
	cout << SimulationWinner(sectorArray, n);
	delete[] sectorArray;
}

