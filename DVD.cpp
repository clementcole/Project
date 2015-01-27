#include "DVD.h"

DVD::DVD(string& item, string& title):Book(item, title)
	m_DTitle(title), m_BItem(item), m_bNext(0)
{}

	string DVD::GetTitle()
	{
		return m_DTitle;
	}
	string DVD::GetItem():
	{
		return m_DItem;
	}
	DVD* DVD::GetDNext()
	{
		return m_dNext;
		
	}
	void DVD::SetDNext(DVD* next)
	{
		m_bNext = next;
	}
