#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

#ifndef Item_H
#define Item_H

class Item{

		public:
			Item(string& name, string& title);
			string GetName();
			string GetTitle();
			Item*  GetiNext();
			void SetINext(Item* next);

		private:
			string m_IName;
			string m_ITitle;
			string m_iNext;


};

#endif
