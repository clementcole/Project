//Header ==> Function Declaration


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"

using namespace std;

#ifndef Patron_H
#define Patron_H


class Patron{
	public:
		//Patron Stuff
		Patron(string& fname,  string& lname,  string& address);
		string GetFName();
		string GetLName();
		string GetAddress();
		void EditFName(string efname);
		void EditLName(string elname);
		void EditAddress(string eaddress);
		int NumberOfBooks();
		Patron* GetNext();
		void SetNext(Patron* next);
		int IfPatronHasBooks(Book* randomBook);
		double PatronHasFines(int x);
		double PayFines(double payment);
		void PatronFines();
		double sum;
		//Book Stuff

		void AddBooks(Book*  newbooks);
		void PrintBooks();
		int DeleteBook();
		vector<Book*> m_PBooks;
		
	private:
		//Patron Stuff
		string m_FName;
		string m_LName;
		string m_Address;
		Patron* m_pNext; //pointer to next patron in list
		
		//Book Stuff
		Book* n_bHead;


};

#endif
