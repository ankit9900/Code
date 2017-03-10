#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "MarketPrices.h"
#define map unordered_map
using namespace std;

class OrderBook {
	unordered_map<char*, unsigned int> m_bidMap;
	unordered_map<char*, unsigned int> m_offerMap;
	
public:
	void sortBidMap() {
		vector<pair<char*, unsigned int>> pairs(m_bidMap.begin(), m_bidMap.end());
		sort(pairs.begin(), pairs.end(), [=](const std::pair<char*, unsigned int>& a, const std::pair<char*, unsigned int>& b)
		{
			return a.second > b.second;
		});
		m_bidMap.clear();
		//copy(pairs.begin(), pairs.end(), inserter(m_bidMap, m_bidMap.begin()));
		for (auto p : pairs){
			m_bidMap.insert({ p.first, p.second });
		}
	}

	void sortOfferMap() {
		vector<pair<char*, unsigned int>> pairs(m_offerMap.begin(), m_offerMap.end());
		sort(pairs.begin(), pairs.end(), [=](std::pair<char*, unsigned int>& a, std::pair<char*, unsigned int>& b)
		{
			return a.second > b.second;
		});
		m_offerMap.clear();
		copy(pairs.begin(), pairs.end(), inserter(m_offerMap, m_offerMap.begin()));
	}

	map<char*, unsigned int>* getbidMap() {
		return &m_bidMap;
	}

	map<char*, unsigned int>* getofferMap() {
		return &m_offerMap;
	}

	OrderBook(char* oid, int type, unsigned int price) {
		if (type == 1) {
			m_bidMap.insert(make_pair(oid, price));
			sortBidMap();
		}
		else {
			m_offerMap.insert(make_pair(oid, price));
			sortOfferMap();
		}
	}

	int updateOrderBook(char* oid, int type, unsigned int price) {
		if (type == 1) {
			m_bidMap.insert(make_pair(oid, price));
			sortBidMap();
		}
		else {
			m_offerMap.insert(make_pair(oid, price));
			sortOfferMap();
		}
		return 1;
	}
	int Print() {
		cout << "Buy:" << endl;
		for (map<char*, unsigned int>::iterator itr = m_bidMap.begin(); itr != m_bidMap.end(); ++itr) {
			cout << itr->first << " " << itr->second << endl;
		}
		cout << "Sell:" << endl;
		for (map<char*, unsigned int>::iterator itr = m_offerMap.begin(); itr != m_offerMap.end(); ++itr) {
			cout << itr->first << " " << itr->second << endl;
		}
		return 1;
	}
};

class Product {
	char* m_PID;
	OrderBook* m_OB;
	int numProduct;
public:
	char* getPID() {
		if (m_PID) {
			return m_PID;
		}
		return nullptr;
	}

	OrderBook* getOB(){
			return m_OB;
	}

	int& getNumPro() {
		return numProduct;
	}

	Product(char* pid = "", OrderBook* ob = nullptr){
		m_PID = new char[strlen(pid)];
		strcpy(m_PID, pid);
		m_OB = ob;
		numProduct = 1;
	}
	int Print() {
		if (numProduct == 0) {
			return 0;
		}
		cout << m_PID << ":" << endl;
		m_OB->Print();
		return 1;
	}
};

class MarketPricesImpl : public MarketPrices {
	Product* m_Product;
	vector<Product*> m_ProductVector;
public:
	int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) override;
	int OnOrderDel(char *productId, char *OrderId) override;
	int Print() override;
};
