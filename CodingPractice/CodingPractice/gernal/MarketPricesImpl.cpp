#include "MarketPricesImpl.h"

VECTOR_PAIR * OrderBook::getBidVec() {
	return &m_bidVec;
}

VECTOR_PAIR * OrderBook::getOfferVec() {
	return &m_offerVec;
}

OrderBook::OrderBook(char* oid, int type, unsigned int price) {
	if (type == 1) {
		m_bidVec.push_back(make_pair(oid, price));
		sort(m_bidVec.begin(), m_bidVec.end(),
			[](const pair<char*, unsigned int>& lhs, const pair<char*, unsigned int>& rhs) {
			return lhs.second > rhs.second; });

	}
	else {
		m_offerVec.push_back(make_pair(oid, price));
		sort(m_offerVec.begin(), m_offerVec.end(),
			[](const pair<char*, unsigned int>& lhs, const pair<char*, unsigned int>& rhs) {
			return lhs.second < rhs.second; });
	}
}

int OrderBook::updateOrderBook(char* oid, int type, unsigned int price) {
	if (type == 1) {
		m_bidVec.push_back(make_pair(oid, price));
		sort(m_bidVec.begin(), m_bidVec.end(),
			[](const pair<char*, unsigned int>& lhs, const pair<char*, unsigned int>& rhs) {
			return lhs.second > rhs.second; });
	}
	else {
		m_offerVec.push_back(make_pair(oid, price));
		sort(m_offerVec.begin(), m_offerVec.end(),
			[](const pair<char*, unsigned int>& lhs, const pair<char*, unsigned int>& rhs) {
			return lhs.second < rhs.second; });
	}
	return 1;
}

int OrderBook::Print() {
	cout << "Buy:" << endl;
	for (auto itr = m_bidVec.begin(); itr != m_bidVec.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
	cout << "Sell:" << endl;
	for (auto itr = m_offerVec.begin(); itr != m_offerVec.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
	return 1;
}

//------------------------------------------------------------------------------------------------
char* Product::getPID() {
	if (m_PID) {
		return m_PID;
	}
	return nullptr;
}

OrderBook* Product::getOB(){
	return m_OB;
}

int& Product::getNumPro() {
	return numProduct;
}

Product::Product(char* pid , OrderBook* ob){
	m_PID = new char[strlen(pid)];
	strcpy(m_PID, pid);
	m_OB = ob;
	numProduct = 1;
}
int Product::Print() {
	if (numProduct == 0) {
		return 0;
	}
	cout << m_PID << ":" << endl;
	m_OB->Print();
	return 1;
}

//------------------------------------------------------------------------------------------------

int MarketPricesImpl::OnOrderAdd(char *productId, char *OrderId, int BidOrOffer, int Price) {
	if ((productId == nullptr) || (OrderId == nullptr)) {
        return 0;
    }
	vector<Product*>::iterator m_itr = m_ProductVector.begin();
    for (; m_itr != m_ProductVector.end();++m_itr) {
		if (strcmp(((*m_itr)->getPID()), productId) == 0) {
            break;
        }
    }
    if (m_itr ==  m_ProductVector.end()) {
        m_Product = new Product(productId, new OrderBook (OrderId, BidOrOffer, Price));
        m_ProductVector.push_back(m_Product);
    } else {
		(*m_itr)->getOB()->updateOrderBook(OrderId, BidOrOffer, Price);
		(*m_itr)->getNumPro()++;
    }
	return 1;
}

int MarketPricesImpl::OnOrderDel(char *productId, char *OrderId) {
    if ((productId == nullptr) || (OrderId == nullptr)) {
        return 0;
    }
	vector<Product*>::iterator m_itr = m_ProductVector.begin();
    for(m_itr = m_ProductVector.begin(); m_itr != m_ProductVector.end();++m_itr) {
		if (strcmp((*m_itr)->getPID(), productId) == 0 ) {
            break;
        }
    }

    if(m_itr ==  m_ProductVector.end()) {
        return 0;
    } else {
		bool found = false;
		auto itr2 = find_if(((*m_itr)->getOB())->getBidVec()->begin(), ((*m_itr)->getOB())->getBidVec()->end(),
			[OrderId](const std::pair<char*, unsigned int >& element){ return strcmp(element.first, OrderId); });

		if ((itr2 != ((*m_itr)->getOB())->getBidVec()->end())) {
			((*m_itr)->getOB())->getBidVec()->erase(itr2);
			(*m_itr)->getNumPro()--;
			found = true;
        } else {
			itr2 = find_if(((*m_itr)->getOB())->getOfferVec()->begin(), ((*m_itr)->getOB())->getOfferVec()->end(),
				[OrderId](const std::pair<char*, unsigned int >& element){ return strcmp(element.first, OrderId); });
			if ((itr2 != ((*m_itr)->getOB())->getOfferVec()->end()))  {
				((*m_itr)->getOB())->getOfferVec()->erase(itr2);
				(*m_itr)->getNumPro()--;
				found = true;
			}
        }
		
		if (!found) {
                return 0;
            }
		if ((*m_itr)->getNumPro() == 0){
                m_ProductVector.erase(m_itr);
            }
    }
	return 1;
}

int  MarketPricesImpl::Print() {
	vector<Product*>::iterator m_itr = m_ProductVector.begin();
    for(;m_itr != m_ProductVector.end() ;++m_itr) {
		(*m_itr)->Print();
		cout << endl;
    }
	return 1;
}

int main() {
	MarketPrices* mp = new MarketPricesImpl();
	
    mp->OnOrderAdd("product1", "order1", 1, 105);
    mp->OnOrderAdd("product1", "order2", 1, 101);
    mp->OnOrderAdd("product2", "order88", 1, 99);
    mp->OnOrderAdd("product2", "order4", 2, 100);
	mp->OnOrderAdd("product2", "order9", 2, 108);
	mp->OnOrderAdd("product2", "order5", 1, 1003);
	mp->OnOrderAdd("product3", "order6", 1, 103);

    mp->Print();

	mp->OnOrderDel("product1", "order1");
	mp->OnOrderDel("product1", "order2");
	cout << "Deleting Product1 and Order1 \n" << endl;
	mp->Print();
	
	system("pause");
}
