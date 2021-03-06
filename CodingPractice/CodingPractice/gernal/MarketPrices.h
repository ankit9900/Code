#ifndef MARKETPRICES_H
#define MARKETPRICES_H

#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class MarketPrices {
public:
	virtual int OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) = 0;
	virtual int OnOrderDel(char *productId, char *OrderId) = 0;
	virtual int Print() = 0;
};

#endif