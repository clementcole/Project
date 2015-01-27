//Function Definition
#include "Patron.h"
#include "Library.h"
//#include "Book.h"
//#include "Book.cpp"
#include <vector>
#include <iomanip>
Patron::Patron(  string& fname,   string& lname,   string& address):
	m_FName(fname), m_LName(lname), m_Address(address),
	m_pNext(0),  n_bHead(0)
{}

string Patron::GetFName()
	{
		return m_FName;
		

	}
void Patron::EditFName(string efname)
	{
		m_FName = efname;
	}

void Patron::EditLName(string elname)
	{
		m_LName = elname;
	}
void Patron::EditAddress(string eaddress)
	{
		m_Address = eaddress;
	}
string Patron::GetLName() 
	{
		return m_LName;

	}
string Patron::GetAddress()
	{
		return m_Address;

	}


Patron* Patron::GetNext() 
	{
		return m_pNext;

	}
void Patron::SetNext(Patron* next) 
	{

		m_pNext = next;

	}
//The following block of code is reserved for the adding/deleting and printing books for each patron
void Patron::AddBooks(Book* newbooks) 
	{
			
		m_PBooks.push_back(newbooks);
	}

void Patron::PrintBooks(){
	    cout<<"ID\t"<<"TITLE\t"<<"ITEM DESCRIPTION"<<endl;
	for(int i=0; i<m_PBooks.size(); i++)
	    cout<<"["<<i+1<<"]\t"<<m_PBooks[i]->GetTitle()<<"\t"<<m_PBooks[i]->GetItem()<<endl; 	



}
int Patron::NumberOfBooks(){
		return m_PBooks.size();
	}

int Patron::DeleteBook(){
	int x, y;
	if(m_PBooks.size() == 0){
		cout<<m_FName<<" "<<m_LName<<" has no books in our records"<<endl;
		getchar();
		
		}
	else{
	cout<<"******************************************************"<<endl;
	cout<<"********* CHOOSE THE ITEM PATRON RETURNED         ****"<<endl;
	cout<<"******************************************************"<<endl;
	for(int i=0; i<m_PBooks.size(); i++){
		cout<<"["<<i+1<<"]\t"<<m_PBooks[i]->GetTitle()<<endl;
		}
		cout<<"Select id that was returned:";
		cin>>x;
		m_PBooks.erase(m_PBooks.begin()+(x-1));
		}
	return x;
}

int  Patron::IfPatronHasBooks(Book* randomBook){
	int x=0;
	for(int i=0; i<m_PBooks.size(); i++)
	{
		if(randomBook->GetTitle() == m_PBooks[i]->GetTitle())
			return 1;
					
	}
	
}

double Patron::PatronHasFines(int x){
	if( m_PBooks.size() == 0)
		{	
			cout<<"PRESS ENTER TO EXIT TO MENU"<<endl;
			return sum;
			getchar();
		}
	else{
		string item;
		double fines;
		item = m_PBooks[x-1]->GetItem();
		
		      if(item ==  "Book")
					fines = 10;
					
		      else if(item == "DVD")
				
					fines = 40;
					
		      else if(item == "Book-On-Tape")
					fines = 35;
					
			
		sum = sum + fines;
	return sum;
	}
	
}

void  Patron::PatronFines()
{	cout<<setprecision(2)<<fixed;
	cout<<"$"<<sum<<endl;
}

double Patron::PayFines(double payment){

	sum = sum - payment;
	return sum;
}
