#include "Item.h"

Item::Item(string& itemName, string& title):

	m_IName(itemName), m_ITitle(title), m_iNext(0)

{}
string Item::GetName()
{
	return m_IName;

}
string Item::GetTitle()
{
	return m_ITitle;
}

Item* Item::GetiNext()
{
	return m_iNext;
}

void Item::SetINext(Item* next)
{
	m_iNext = next;

}
