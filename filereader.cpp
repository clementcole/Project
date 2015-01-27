#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	
	ofstream myfile;
	ifstream inputfile("readstuff.txt");
	myfile.open("example.txt");
	myfile<<"Writing this to a file.\n";
	myfile<<"Hello Hello  Hello"<<endl;
	myfile.close();
	myfile.open("example.txt");
	myfile<<"RED FLAG.\n";
	myfile.close();

	string line;
	if(inputfile.is_open() ){
		while(getline(inputfile, line))
		{
			cout<<line<<'\n';

		}
		inputfile.close();
		}
	return 0;



}
