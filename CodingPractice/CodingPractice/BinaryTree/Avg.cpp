#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* rt;
	Node* left;
	Node(){
		rt = NULL;
		left = NULL;
	}
};


class BinaryTree {
	Node* head;
	int count;
	vector<int> btv;
public:
	BinaryTree(){
		head = NULL;
		count = 0;
	}
	void insert(int x) {
		Node* tmp = new Node;
		tmp->data = x;
		tmp->left = NULL;
		tmp->rt = NULL;
		if (head == NULL) {
			head = tmp;
			return;
		}
		int ch = 0;
		cout << "Pick side of Node:  1 left OR 2 right " << endl;
		cin >> ch;
		Node* tm = new Node;
		tm = head;
		if (ch == 1) {
			while (tm->left != NULL)
				tm = tm->left;
			tm->left = tmp;
			return;
		}
		else if (ch == 2) {
			while (tm->rt != NULL)
				tm = tm->rt;
			tm->rt = tmp;
			return;
		}
	}
	int findAvgUtil(Node* tmp, int sum) {
		if (tmp == NULL)
			return sum;
		sum = sum + tmp->data;
		count++;
		sum = findAvgUtil(tmp->left, sum);
		sum = findAvgUtil(tmp->rt, sum);
		return sum;
	}

	float findAvg() {
		float sum = 0.0;
		Node* tmp = head;
		sum = findAvgUtil(tmp, sum);
		return sum/count;
	}

	void flcp(Node* tmp, int cur, int exp, int& res){
		if (tmp == NULL){
			return;
		}
		if (tmp->data == exp){
			cur++;
		}
		else{
			cur = 1;
		}
		if (res < cur)
			res = cur;
		flcp(tmp->left, cur, tmp->data + 1, res);
		flcp(tmp->rt, cur, tmp->data + 1, res);

	}
	int findLongestConsecutivePath() {
		int res = 0;
		flcp(head,0,head->data,res);
		return res;
	}
};

int main(){
	BinaryTree* bt = new BinaryTree;
	bt->insert(1);
	bt->insert(2);
	bt->insert(3);
	bt->insert(4);
	bt->insert(55);
	bt->insert(6);
	cout << bt->findAvg() << endl;
	cout << bt->findLongestConsecutivePath() << endl;
	system("pause");
	return 0;
}