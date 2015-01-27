//Header ==> Function definition

#include "Library.h"
#include "Patron.h"
#include "sstream"
Library::Library():

	m_pHead(0), m_bHead(0)

{}


void Library::AddPatron(const vector<Patron>& new_Patrons)
{	cout<<"WARNING: FOR ADDRESSES INPUT WHICHEVER WAY IT APPEARS FOR PATRON!!!!"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<< "Enter First Name:";
	string fname;
	getline(cin, fname);
	cout<< "Enter Last Name: ";
	string lname;
	getline(cin, lname);
	cout<< "Enter Address: ";
	string address;
	getline(cin, address);
	Patron* pNewPatron = new Patron(fname, lname, address);

	if(m_pHead == 0)
	{
		m_pHead = pNewPatron;
	}

	else
	{
		Patron* pIter = m_pHead;
		while(pIter -> GetNext() != 0)
		{
			pIter =  pIter -> GetNext();
		}
		pIter->SetNext(pNewPatron);

	}
	m_Patrons.push_back(pNewPatron);
	
}
void Library::EditPatron(const vector<Patron>& new_Patrons)
{

	if(m_Patrons.size() == 0){
		cout<<"THERE ARE CURRENTLY NO PATRONS IN OUR DATABASE GO BACK TO THE MAIN MENU AND ADD PATRONS"<<endl;	
		getchar();
		}
	else{
	int i;
	cout<<"***********************************************************"<<endl;
	cout<<"****        SELECT THE PATRON YOU WILL LIKE TO EDIT   *****"<<endl;
	cout<<"***********************************************************"<<endl;
	cout<<"Index\t"<<"First Name\t"<<" "<<"Last Name"<<endl;
	for(int i=0; i<m_Patrons.size(); i++)
	cout<<"["<<i+1<<"]\t\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
	cout<<"Select id of patron you will like to edit:";
	cin>>i;
	getchar();
	cout<<"Enter First Name:";
	string fname;
	getline(cin, fname);
	cout<<"Enter Last Name:";
	string lname;
	getline(cin, lname);
	cout<<"Enter Address:";
	string address;
	getline(cin, address);
	m_Patrons[i-1]->EditFName(fname);
	m_Patrons[i-1]->EditLName(lname);
	m_Patrons[i-1]->EditAddress(address);
	}

}

void Library::DeletePatron()
{	
	int index;
	cout<<"Select the Patron you will like to delete by entering their index:";
	cin>>index;
	if( m_Patrons[index-1]->NumberOfBooks() <  1){
					m_Patrons.erase(m_Patrons.begin()+(index-1));
					}
	else 	{
		cout<<"THIS PATRON CANNOT BE DELETED FROM OUR DATABASE DUE TO ITEMS OWED TO THE LIBRARY"<<endl;
		getchar();
		getchar();
		}
}



void Library::PrintPatrons(const vector<Patron>& new_Patrons) 
	{		system("clear");
			if(m_Patrons.size() == 0){
				cout<<"THERE ARE CURRENTLY NO PATRONS IN OUR LIBRARY SYSTEM GO BACK TO THE MAIN MENU AND ADD PATRONS"<<endl;
				getchar();
			}
			else{
				cout<<"******************************************"<<endl;
				cout<<"**     HERE IS A LIST OF ALL PATRONS    **"<<endl;
				cout<<"******************************************"<<endl;
				cout<<"Index\t"<<"First Name\t"<<" "<<"Last Name"<<endl;
					for(int i=0; i<m_Patrons.size(); i++){
			
				cout<<"["<<i+1<<"]\t\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
				}
			 }
	}


//Book Methods
void Library::AddBook(const vector<Book>& new_Books)
	{	
		int x;
		string title;
		string item;
		cout<<"***************************************"<<endl;
		cout<<"CHOOSE FROM THE CATEGORY OF ITEMS BELOW"<<endl;
		cout<<"***************************************"<<endl;
		cout<<"Code"<<"\t"<<"Item"<<endl;
		cout<<"[1]"<<"\t"<<"BOOKS"<<endl;
		cout<<"[2]"<<"\t"<<"DVDs"<<endl;
		cout<<"[3]"<<"\t"<<"Book-On-Tape"<<endl;
		cout<<"Enter item's code to select item to add to Library's database:";
		cin>>x;
		getchar();
		if( x == 1){
				item = "Book";
				cout<<"Enter Book's Title:";
				getline(cin, title);
				cout<<"You added the book:"<<title<<endl;
		
				Book* bNewBook = new Book(item, title);
				if(m_bHead == 0)
				{
				m_bHead = bNewBook;

				}
				else
				{
				Book* bIter = m_bHead;
				while(bIter -> GetBNext() != 0)
				{
				bIter = bIter -> GetBNext();

				}
				bIter->SetBNext(bNewBook);
				}	
				m_Books.push_back(bNewBook);
				

		}//End of Book's conditional statement
	      else  if( x == 2){
				 item = "DVD";
				 cout<<"Enter DVD's Title:";
				 getline(cin, title);
				 cout<<"You added the DVD "<<title<<endl;
				 
				 Book* bNewBook = new Book(item, title);
				 if(m_bHead == 0)
				 {

				 m_bHead = bNewBook;
			      	}
				 else
				{
				Book* bIter = m_bHead;
				while (bIter -> GetBNext() != 0)
					{
						bIter = bIter -> GetBNext();
					}
					  	bIter->SetBNext(bNewBook);
				}
						m_Books.push_back(bNewBook);

		}//End of DVD's conditional clause
		else if (x == 3){
				item = "Book-On-Tape";
				cout<<"Enter Book-on-Tape's Title:";
				getline(cin, title);
				cout<<"You add the Book-on-Tape "<<title<<endl;
				
				Book* bNewBook = new Book(item, title);
				if(m_bHead == 0)
				{

					m_bHead = bNewBook;
				}
				else
				{

					Book* bIter = m_bHead;
					while(bIter -> GetBNext() != 0)
					{
						bIter = bIter -> GetBNext();
					}
						bIter->SetBNext(bNewBook);
				}
						m_Books.push_back(bNewBook);

			}//End of Book-on-tape's conditional clause
	

		
	}



void Library::DeleteBook()
	{
		if(m_Books.size() == 0){
			cout<<"THERE ARE CURRENTLY NO BOOKS IN OUR DATA BASE GO BACK TO THE MAIN MENU TO ADD BOOKS"<<endl;
			getchar();
		}
		else{
			int index;
			cout<<"*************************************************************"<<endl;
			cout<<"*****                LIST OF ALL                         ****"<<endl;
			cout<<"*************************************************************"<<endl;
			cout<<"ID Number\tItem  \tItem Title                                "<<endl;
			for(int i=0; i<m_Books.size(); i++)
			{
			cout<<"["<<i+1<<"]\t"<<m_Books[i]->GetTitle()<<endl;
			}
			cout<<"Select the Book you will like to delete from the Book manager"<<endl;
			cin>>index;
			for(int i=0; i<m_Patrons.size(); i++)
			{
			if(m_Patrons[i]->IfPatronHasBooks(m_Books[index-1]) == 1){
				cout<<"THIS BOOK CANNOT BE REMOVED CURRENTLY IN POSSESSION OF A PATRON!!"<<endl;
				getchar();
				return;
				}


			}
			m_Books.erase(m_Books.begin()+(index-1));
			cout<<m_Books[index-1]->GetTitle()<<" HAS BEEN DELETED FROM OUR RECORDS"<<endl;
			getchar();
			}
	}

void Library::PrintBooks(const vector<Book>& new_Books)
	{	
		system("clear");
		if(m_Books.size() == 0){
					cout<<"THERE ARE CURRENTLY NO BOOKS IN OUR DATA BASE GO BACK TO THE MAIN MENU TO ADD BOOKS"<<endl;
					getchar();
					}
		else{
		cout<<"*******************************************"<<endl;
		cout<<"HERE IS A LIST OF ALL ITEMS IN OUR DATABASE"<<endl;
		cout<<"*******************************************"<<endl;
		cout<<"\n";
		cout<<"**********************"<<endl;
		cout<<"******   BOOKS   *****"<<endl;
		cout<<"**********************"<<endl;
		for(int i=0; i<m_Books.size(); i++)
		{	
		
			
			if(m_Books[i]->GetItem() == "Book")
			cout<<"["<<i+1<<"]\t"<<m_Books[i]->GetTitle()<<endl;

		}
		cout<<"\n";
		cout<<"*********************"<<endl;
		cout<<"****    DVDS    *****"<<endl;
		cout<<"*********************"<<endl;
		for(int i=0; i<m_Books.size(); i++)
		{
			
			if(m_Books[i]->GetItem() == "DVD")
			cout<<"["<<i+1<<"]\t"<<m_Books[i]->GetTitle()<<endl;
	
		}
		cout<<"\n";
		cout<<"*******************************"<<endl;
		cout<<"****     Book-On-Tape       ***"<<endl;
		cout<<"*******************************"<<endl;
		for(int i=0; i<m_Books.size(); i++)
		{
			
			if(m_Books[i]->GetItem() == "Book-On-Tape")
			cout<<"["<<i+1<<"]\t"<<m_Books[i]->GetTitle()<<endl;
		}
		}//end of else statement

	}


void Library::AddBooksPatrons()
	{
	
		int x,y;
		if(m_Books.size() == 0){
			cout<<"THERE ARE CURRENTLY NO BOOKS TO ADD TO PATRONS IN THIS LIBRARY RETURN TO MAIN MENU"<<endl;
			cout<<"PRESS ENTER TO RETURN TO MAIN MENU"<<endl;
			getchar();	
		}
		else{
		cout<<"***************************************************************************"<<endl;
		cout<<"***      HERE IS A LIST OF ALL PATRONS ADDED TO OUR LIBRARY'S DATA BASE  **"<<endl;
		cout<<"***************************************************************************"<<endl;
		cout<<"ID Number\tFirst Name\tLast Name"<<endl;
		for(int i=0; i<m_Patrons.size(); i++){
			cout<<"["<<i+1<<"]\t\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
			
			}//End of for loop

			cout<<"ENTER ID NUMBER:";
			cin>>x;


		system("clear");
		cout<<"***************************************************************************"<<endl;
		cout<<"******         HERE IS A LIST OF ALL ITEMS IN THE LIBRARY             *****"<<endl;
		cout<<"***************************************************************************"<<endl;   
		cout<<"ID Number\tBook Title"<<endl;
		for(int i=0; i<m_Books.size(); i++){
							cout<<"["<<i+1<<"]"<<m_Books[i]->GetTitle()<<endl;
						}


			cout<<"Enter the id number attached to the item and press Enter>>:";
			cin>>y;
			system("clear");
			cout<<m_Books[y-1]->GetTitle()<<" is been added to "<<m_Patrons[x-1]->GetFName()<<" 's list of books one moment please...."<<endl;
			m_Patrons[x-1] -> AddBooks(m_Books[y-1]);
			cout<<"DONE!! HIT ENTER TO CONTINUE..."<<endl;
			getchar();
		}
			
		}

void Library::PrintBooksPatrons()
	{
				int x;
				cout<<"*******************************************************"<<endl;
				cout<<"                  LIST OF  PATRONS                 ****"<<endl;
				cout<<"*******************************************************"<<endl;
				cout<<"ID Number\tFirst Name\tLast Name"<<endl;
				for(int i=0; i<m_Patrons.size();i++)
				{
					cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<m_Patrons[i]->GetLName()<<endl;
				}
				cout<<"Enter ID Number:";
				cin>>x;
				m_Patrons[x-1]->PrintBooks();

	}

void Library::ReturnBooksPatron()
	{

			int x;
			cout<<"************************************************"<<endl;
			cout<<"***        LIST OF PATRONS                   ***"<<endl;
			cout<<"************************************************"<<endl;
			cout<<"ID Number\tFirst Name\tLast Name"<<endl;
			for(int i=0; i<m_Patrons.size(); i++)
			{
				     cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
			}
			cout<<"Enter ID Number:";
			cin>>x;
			m_Patrons[x-1]->DeleteBook();

	}

void Library::PrintAddress(){
			cout<<"***************************************************"<<endl;
			cout<<"******   MAILING ADDRESS LIST              ********"<<endl;
			cout<<"***************************************************"<<endl;
			
			for(int i=0; i<m_Patrons.size(); i++)
			{	cout<<"Id\t"<<"Full Name"<<endl;
				cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
				cout<<"Address:"<<endl;
				cout<<m_Patrons[i]->GetAddress()<<endl;
				
			}

			getchar();


}


void Library::LostBooksPatron()
	{	
		if(m_Patrons.size() == 0){
			cout<<"THERE ARE CURRENTLY NO PATRONS IN THE DATABASE"<<endl;
			cout<<"PRESS ENTER TO GO BACK TO MENU"<<endl;
			getchar();
			getchar();

			}
		else{
		int x;
		cout<<"************************************************************"<<endl;
		cout<<"******      LIST OF PATRONS                            *****"<<endl;
		cout<<"************************************************************"<<endl;
		cout<<"ID Number\tFirst Name\tLast Name"<<endl;
		for(int i=0; i<m_Patrons.size(); i++)
			{
				cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t\t"<<m_Patrons[i]->GetLName()<<endl;
			}
			cout<<"Enter ID Number:";
			cin>>x;
			int y=	m_Patrons[x-1]->DeleteBook();
			m_Patrons[x-1]->PatronHasFines(y);
		}
	}

void Library::AddFinesPatron(){
		
		int x, y;
		double amount;
		string title;
		cout<<"*****************************************************"<<endl;
		cout<<"****    LIST OF PATRONS                        ******"<<endl;
		cout<<"*****************************************************"<<endl;
		cout<<"ID Number\tFirst Name\tLast Name"<<endl;
		for(int i=0; i<m_Patrons.size(); i++)
		{
			cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t"<<m_Patrons[i]->GetLName()<<endl;

		}
		cout<<"Enter ID Number:";
		cin>>x;
		if(m_Patrons[x-1]->NumberOfBooks() == 0){
			cout<<"THIS PATRON CURRENTLY DOESN'T HAVE ANY BOOK CHECKED OUT"<<endl;
			getchar();
		}
		else{
		cout<<"******************************************************************************"<<endl;
		cout<<"****CHOOSE FROM THE ITEMS BELOW" <<m_Patrons[x-1]->GetFName()<<" OWES A FINE****"<<endl;
		cout<<"******************************************************************************"<<endl;
		m_Patrons[x-1]->PrintBooks();
		cout<<"Enter ID of item:";
		cin>>y;
		m_Patrons[x-1]->PatronHasFines(y);
		}
	

}	


void Library::PrintFines(){

	int x;
	cout<<"*********************************************************"<<endl;
	cout<<"**           LIST OF PATRONS                       ******"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"ID Number\tFirst Name\tLast Name\tAmount Owed"<<endl;
	for(int i=0; i<m_Patrons.size(); i++)
	{
		cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t"<<m_Patrons[i]->GetLName()<<"\t";
		m_Patrons[i]->PatronFines();
		cout<<"\n";
		
	}
	
	}

void Library::PayFines(){
	int x;
	double payment;
	cout<<"**********************************************************"<<endl;
	cout<<"*****          LIST OF PATRONS                       *****"<<endl;
	cout<<"**********************************************************"<<endl;
	cout<<"ID Number\tFirst Name\tLast Name\t"<<endl;
	for(int i=0; i<m_Patrons.size(); i++)
	{

		cout<<"["<<i+1<<"]\t"<<m_Patrons[i]->GetFName()<<"\t"<<m_Patrons[i]->GetLName()<<endl;
	}
	cout<<"Enter ID Number:";
	cin>>x;
	cout<<"Enter Payment:";
	cin>>payment;
	m_Patrons[x-1]->PayFines(payment);

}
