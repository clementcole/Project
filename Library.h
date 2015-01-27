//Library Declaration


#pragma once

#ifndef Library_H
#define Library_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Patron.h"
#include "Book.h"
#include "BookContainer.h"
#include "DVD.h"
#include "Book_on_Tape.h"

using namespace std;






class Library{
		
		//	friend ostream& operator<<(ostream& os, const Library& aLibrary);
		public:
			Library();
			void AddPatron(const vector<Patron>& new_Patrons);
			void EditPatron(const vector<Patron>& new_Patrons);
			void PrintPatrons(const vector<Patron>& new_Patrons);
			void DeletePatron();
			void AddBooksPatrons();
			void PrintBooksPatrons();
			void ReturnBooksPatron();
			void EditBook();
			void PrintAddress();
			void LostBooksPatron();
			void PatronHasBooks();
			void AddFinesPatron();
			void PrintFines();
			void PayFines();
			//Books
			void AddBook(const vector<Book>& new_Books);
			void DeleteBook();
			void PrintBooks(const vector<Book>& new_Books);
			vector<Patron*> m_Patrons;
			vector<Book*> m_Books;
			vector<DVD*> m_DVDs;
			vector<Book_on_Tape*> m_BOTs;
			Book* addedbook;
			Patron* aPatron;
	//		void clear();

		private:
			
			Patron* m_pHead;
			Book* m_bHead;
			DVD* m_dHead;
			//	vector<Patron> m_Patrons;

	};
#endif
