#include <iostream>
#include <map>

using namespace std;

int main()
{
  string name, prod;
  int count;
  map<string,map<string,int>> Consumer;
  
  while (cin >> name >> prod >> count)
  {
    Consumer[name][prod] += count;
  }
  
   map<string,map<string,int>>::iterator itr;
   map<string,int>::iterator ptr;
   for (itr = Consumer.begin(); itr != Consumer.end(); itr++)
   { 
        cout << itr -> first <<":\n";
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
          cout << ptr -> first <<' '<<ptr -> second << '\n'; 
   }   
}
