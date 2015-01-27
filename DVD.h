



#ifndef DVD_H
#define DVD_H
#include "Book.h"


class DVD : public Book{
	public:
		 DVD(string& item, string& title);
		 string GetTitle();
		 string GetITem();
		 Book* GetDNext();
		 void  SetDNext(Book* next);
		 string m_DTitle;
		 DVD* m_dNext;
		 string m_DItem;	

};
#endif
