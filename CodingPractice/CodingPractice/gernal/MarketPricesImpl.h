#ifndef MARKETPRICESIMPL_H
#define MARKETPRICESIMPL_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "MarketPrices.h"

using namespace std;
typedef vector<pair < char*, unsigned int > >  VECTOR_PAIR;
typedef multiset<unsigned int, char*> MSET;

class OrderBook {
	VECTOR_PAIR m_bidVec;
	VECTOR_PAIR m_offerVec;

	MSET m_bidSet;
	MSET m_offerSet;
public:
	VECTOR_PAIR * getBidVec();
	VECTOR_PAIR * getOfferVec();
	OrderBook(char* oid, int type, unsigned int price);

	int updateOrderBook(char* oid, int type, unsigned int price);
	int Print();
};

class Product {
	char* m_PID;
	OrderBook* m_OB;
	int numProduct;
public:
	char* getPID();
	OrderBook* getOB();
	int& getNumPro();
	Product(char* pid = "", OrderBook* ob = nullptr);
	int Print();
};

class MarketPricesImpl : public MarketPrices {
	Product* m_Product;
	vector<Product*> m_ProductVector;
public:
	int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) override;
	int OnOrderDel(char *productId, char *OrderId) override;
 	int Print() override;
};

#endif