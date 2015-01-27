#include "Book.h"

Book::Book(string& item,string& title):
		m_BTitle(title), m_BItem(item),
		m_bNext(0)
{}

		string Book::GetTitle()
	{
		return m_BTitle;
	}
	void Book::EditTitle(string eTitle)
	{
		m_BTitle = eTitle;
	}
	void Book::EditItem(string eitem)
	{
		m_BItem = eitem;
	}
   		 string Book::GetItem()
	{
		return m_BItem;
	}

		 Book* Book::GetBNext()
	{
		return m_bNext;
	}

		void Book::SetBNext(Book* next)
	{
		m_bNext = next;
	}
