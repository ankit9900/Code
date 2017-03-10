#include "MarketPrices.h"

class MarketPricesImpl : public MarketPrices {
	Product* m_Product;
	vector<Product*> m_ProductVector;
	vector<Product*>::iterator m_itr;
public:
	int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) override;
	int OnOrderDel(char *productId, char *OrderId) override;
	int Print() override;
};

class OrderBook {
	map<char*, unsigned int> m_bidMap;
	map<char*, unsigned int> m_offerMap;
public:
	OrderBook(char* oid, unsigned int price, int type) {
		if(type == 1) {
			m_bidMap.insert(make_pair(oid, price));
		} else {
			m_offerMap.insert(make_pair (oid, price));
		}
	}
	int updateOrderBook(char* oid, unsigned int price, int type) {
		if(type == 1) {
			m_bidMap.insert(make_pair(oid, price));
		} else {
			m_offerMap.insert(make_pair(oid, price));
		}
	}
	int Print() {
       cout<<"Buy:"<<endl;
	   for (map<char*, unsigned int>::iterator itr = m_bidMap.begin(); itr != m_bidMap.end(); ++itr) {
		   cout<<itr->first <<" "<<itr->second;
	   }
	   cout<<"Sell:"<<endl;
	   for (map<char*, unsigned int>::iterator itr = m_offerMap.begin(); itr != m_offerMap.end(); ++itr) {
		   cout<<itr->first <<" "<<itr->second;
	   }
	}
};

class Product {
	char* m_PID;
	OrderBook* m_OB;
	int numProduct;
public:
	Product(char* pid = "", OrderBook* ob = nullptr){
		m_PID = new char[strlen(pid)];
   		strcpy(m_PID, pid);
        m_OB = ob;
		numProduct = 1;
	}
	int Print() {
		if(numProduct == 0) {
			return 0;
		}
		cout<<m_PID<<":"<<endl;
		m_OB->Print();
	}
};