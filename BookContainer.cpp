#include "Book.h"
#include "BookContainer.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <cctype>
BookContainer::BookContainer():
		m_bHead(0)

{}



void BookContainer::AddBook(const vector<Book>& new_Books)
		{

			cout<<"Enter Books*****************"<<endl;
			cout<<"Enter Book Title:";
			char title[256];
			cin>>title;			
			cin.getline(title, 256);
			cout<<"You added the book:"<<title<<endl;
			Book* bNewBook = new Book(title);
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
		}


void BookContainer::DeleteBook()
		{
			int index;
			cout<<"Select the Book you will like to delete from the Book manager"<<endl;
			cin>>index;
			m_Books.erase(m_Books.begin()+(index-1));

		}


void BookContainer::PrintBooks(const vector<Book>& new_Books)
		{
				system("clear");
				cout<<"Here is a list of all our Books in the book manager:"<<endl;
				for(int i=0; i<m_Books.size(); i++)
				{

					cout<<"["<<i+1<<"]\t"<<m_Books[i]->GetTitle()<<endl;

				}
		}
