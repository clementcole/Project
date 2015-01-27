#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


#ifndef Book_H
#define Book_H

class Book{
	public:
		Book(string& item, string& title);
		 string GetTitle();
		 string GetItem();
		 Book* GetBNext();
			void  EditTitle(string eTitle);
			void EditItem(string eItem);
		virtual void SetBNext(Book* next);
		 string m_BTitle;
		 Book* m_bNext;
		 string m_BItem;		

};

#endif
