#include "ISubject.h"
#include <algorithm>

void ISubject::subscribe(IObserver* observer) {
	m_vecObservers.push_back(observer);
}

void ISubject::unsuscribe(IObserver* observer) {
	m_vecObservers.erase(remove(m_vecObservers.begin(), m_vecObservers.end(), observer), m_vecObservers.end());
}

void ISubject::notify() {
	for (int i = 0; i < m_vecObservers.size(); ++i) {
		m_vecObservers.at(i)->update("this is subject chnaging");
	}
}