#include <iostream>
#include <map>

using namespace std;

int main()
{
  string name, name2, operation;
  long long sum1, p;
  map<string,long long> Client;
  map<string,long long>::iterator itr;
  
  
  while (cin >> operation)
  {
    switch(operation[0])
    {
      case 'D':
        cin >> name >> sum1;
        Client[name]+=sum1;
        break;
      
      case 'W':
        cin >> name >> sum1;
        Client[name]-=sum1;
        break;
        
      case 'B':
        cin >> name;
        if (Client.contains(name))
          cout << Client[name]<<'\n';
        else 
          cout << "ERROR\n";
        break;
      
      case 'T':
        cin >> name >> name2 >> sum1;
        Client[name]-=sum1;
        Client[name2]+=sum1;
        break;
        
      case 'I':
        cin >> p;
        for (itr = Client.begin(); itr != Client.end(); itr++) 
        if(itr -> second > 0)
         itr -> second = itr -> second / 100 * (100 + p);
        break;
     }
  }
  
}
