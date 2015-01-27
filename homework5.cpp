#include <iostream>
//#include <windows.h>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "Library.h"
#include "Patron.h"
#include "Book.h"

#include "Library.cpp"
#include "Book.cpp"
#include "Patron.cpp"



using namespace std;
int main(){


string fname, lname;
int num=0, num1=0, choice=0, choice2=0, choice3=0, choice4 =0, choice5 = 0;


vector<Patron> newPatrons;
vector<Book> newBooks;
Library myPatron;
Library tempPatron;

system("clear");






	do{	
		system("clear");
		cout<<"********************************************************************\n";
		cout<<"*                       MAIN   MENU                                *\n";
		cout<<"********************************************************************\n";
		cout<<"********[0] --- CLEAR SCREEN                                    ****\n";
		cout<<"********[1] --- PATRON MANAGER                                  ****\n";
		cout<<"********[2] --- ITEM MANAGER                                    ****\n";
		cout<<"********[3] --- EXIT OUT OF PROGRAM                             ****\n";
		cout<<"********************************************************************\n";
		cout<<"		ENTER THE NUMBER THAT CORRESPONDS TO YOUR CHOICE:";
		cin >> choice;
		getchar();
		switch (choice){
				case 0: 
					system("clear");
					break;
				case 1:
					
							system("clear");
							do{	system("clear");
								cout<<"******************************************************************"<<endl;
								cout<<"****         PATRON MANAGER->->->->->EDIT/ADD PATRON MENU    *****"<<endl;
								cout<<"******************************************************************"<<endl;
								cout<<"****   [1]--ADD NEW PATRON                                   *****"<<endl;
								cout<<"****   [2]--EDIT EXISTING PATRON's BASIC INFORMATION         *****"<<endl;
								cout<<"****   [3]--ADD ITEM TO PATRON's ACCOUNT                     *****"<<endl;
								cout<<"****   [4]--DELETE PATRON's MEMBERSHIP                       *****"<<endl;
								cout<<"****   [5]--EDIT EXISTING PATRON's FINANCIAL INFORMATION     *****"<<endl;
								cout<<"****   [6]--PRINT A LIST OF ALL PATRONS                      *****"<<endl;
								cout<<"****   [7]-PRINT MAILING ADDRESS LABELS                     *****"<<endl;
								cout<<"******************************************************************"<<endl;
								cout<<"****              [8]--BACK TO MAIN MENU                    *****"<<endl;
								cout<<"******************************************************************"<<endl;
								cout<<"		ENTER THE NUMBER THAT CORRESPONDS TO YOUR CHOICE:";
								cin >> choice2;
								getchar();
								
				
									if( choice2 ==  1){
												system("clear");
												myPatron.AddPatron(newPatrons);
											}
									else if( choice2 == 2)	{
												
												system("clear");
												myPatron.EditPatron(newPatrons);
												}
									else if( choice2 == 3){
												system("clear");
												myPatron.AddBooksPatrons();
												}
									else if( choice2 == 4){
												system("clear");	
												myPatron.PrintPatrons(newPatrons);
												myPatron.DeletePatron();
												}
									else if( choice2 == 5){
										
										do{	choice4 = 0;
											system("clear");
											cout<<"*******************************************************************"<<endl;
											cout<<"******               EDIT FINANCIAL INFORMATION MENU         ******"<<endl;
											cout<<"*******************************************************************"<<endl;
											cout<<"******            [1]--RECORD OVERDUE ITEMS                  ******"<<endl;
											cout<<"******            [2]--PRINT PATRON's ACCOUNT's BALANCE      ******"<<endl;
											cout<<"******            [3]--PRINT ITEMS ON PATRON'S ACCOUNT       ******"<<endl;
											cout<<"******            [4]--RECORD RETURNED ITEMS FOR PATRON      ******"<<endl;
											cout<<"******		 [5]--RECORD PAYMENT OF FINES               ******"<<endl;
											cout<<"*******************************************************************"<<endl;
											cout<<"******                 [6]--BACK TO MAIN MENU                ******"<<endl; 
											cout<<"*******************************************************************"<<endl;
											cout<<"******            ENTER THE NUMBER THAT CORRESPONDS TO YOUR SELECTION:";
											cin>>choice4;     
											
											if(choice4 == 1){
												system("clear");
												myPatron.AddFinesPatron();	
												cout<<"PRESS ENTER TO RETURN TO MENU!!"<<endl;
												getchar();
												getchar();
												}
										
											else if(choice4 == 2){
												system("clear");
												myPatron.PrintFines();
												cout<<"PRESS ENTER TO RETURN TO MENU!!"<<endl;
												getchar();
												getchar();
												}
											else if(choice4 == 3){
												system("clear");
												myPatron.PrintBooksPatrons();
												cout<<"PRESS ENTER TO RETURN TO MENU!!"<<endl;
												getchar();
												getchar();			
												}
											else if(choice4 == 4){
												system("clear");
												myPatron.ReturnBooksPatron();
												}
											else if(choice4 == 5){
												system("clear");
												myPatron.PayFines();
												}
										}while(choice4 != 6);
										}
					
									else if(choice2 == 6){
												system("clear");
												myPatron.PrintPatrons(newPatrons);
												cout<<"PRESS ENTER TO RETURN TO MENU"<<endl;
												getchar();
												}
									else if(choice2 == 7){
												system("clear");
												myPatron.PrintAddress();
												cout<<"PRESS ENTER TO RETURN TO MENU!!!"<<endl;
												getchar();
									}
									
								
						
					}while(choice2 != 8);
					break;
			
				case  2:
						do{
						system("clear");
						cout<<"***********************************************************"<<endl;
						cout<<"*****	    ITEM  MANAGER->->->EDIT ITEMS MENU        ****"<<endl;
						cout<<"***********************************************************"<<endl;
						cout<<"***          [1]--ADD A ITEM TO ITEM MANAGER           ****"<<endl;
						cout<<"***          [2]--REMOVE AN ITEM  FROM ITEM MANAGER    ****"<<endl;
						cout<<"***          [3]--RECORD LOST OR STOLEN ITEMS          ****"<<endl;
						cout<<"***          [4]--PRINT LIST OF ITEMS IN LIBRARY       ****"<<endl;
						cout<<"***********************************************************"<<endl;
						cout<<"***               [5]--EXIT TO MAIN MENU               ****"<<endl;
						cout<<"***********************************************************"<<endl;
						cout<<"***          ENTER A NUMBER FOR SELECTION:";
						cin>>choice3;
							switch(choice3)
							{
							
							case 1:	
								myPatron.AddBook(newBooks);
								break;
							case 2:
								myPatron.DeleteBook();
								break;
							case 3:
								do{
								system("clear");
								cout<<"************************************************"<<endl;
								cout<<"***          CHOOSE A CONDITION BELOW        ***"<<endl;
								cout<<"************************************************"<<endl;
								cout<<"*****  [1]---RECORD ITEM LOST BY PATRON      ***"<<endl;
								cout<<"*****  [2]---RECORD ITEM STOLEN FROM LIBRARY ***"<<endl;
								cout<<"************************************************"<<endl;
								cout<<"*****   [3]---EXIT BACK TO ITEM MANAGER      ***"<<endl;
								cout<<"*****  ENTER YOUR SELECTION:";
								cin>>choice5;
									if(choice5 == 1)
									{
									myPatron.LostBooksPatron();
									
									}
									else if(choice5 == 2)
									{

									cout<<"Working on it"<<endl;
									}
								}while(choice5 != 3);	
									break;
							
							case 4:
								myPatron.PrintBooks(newBooks);
								cout<<"PRESS ENTER TO RETURN TO  MENU!!!"<<endl;
								getchar();
								getchar();
								break;
							default:
								cout<<"WRONG INPUT EXITING TO MAIN MENU!!"<<endl;
								break;
							}
						}while(choice3 != 5);
						break;

				
				default:
						system("clear");
						cout<<"EXITING OUT OF PROGRAM!!!"<<endl;
						break;
					
		
				}

	}while(choice != 3);

return 0;
}




