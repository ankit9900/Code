#include "MarketPricesImpl.h"

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
		map<char*, unsigned int>::iterator itr2 = ((*m_itr)->getOB())->getbidMap()->begin();
		if ((itr2 = ((*m_itr)->getOB())->getbidMap()->find(OrderId)) != ((*m_itr)->getOB())->getbidMap()->end())  {
			((*m_itr)->getOB())->getbidMap()->erase(itr2);
			(*m_itr)->getNumPro()--;
			found = true;
            } else {
			itr2 = ((*m_itr)->getOB())->getofferMap()->begin();
			if ((itr2 = ((*m_itr)->getOB())->getofferMap()->find(OrderId)) != ((*m_itr)->getOB())->getofferMap()->end())  {
				((*m_itr)->getOB())->getofferMap()->erase(itr2);
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
	cout << "Deleting Product1 and Order1 \n" << endl;
	mp->Print();
	
	system("pause");
}
