#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"


using namespace std;


#ifndef BookContainer_H
#define BookContainer_H


class BookContainer{

		public:
			BookContainer();
			void AddBook(const vector<Book>& new_Books);
			void PrintBooks(const vector<Book>&);
			void DeleteBook();
			vector<Book*> m_Books;

		private:
			Book* m_bHead;

	};

#endif
