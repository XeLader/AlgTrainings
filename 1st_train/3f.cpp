#include <stdio.h>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
  string a = "  ";
  int count = 0;
  
  unordered_multiset<string> Gen1 = {};
  unordered_set<string> Gen2 = {};
  
  a[0] = getchar();
  a[1]= getchar();
  while ( a[1] != '\n')
  {
    Gen1.emplace(a);
    a[0]=a[1];
    a[1] = getchar();
  }
  a[0] = getchar();
  a[1]= getchar();
  while ( a[1] != '\n')
  {
    Gen2.emplace(a);
    a[0]=a[1];
    a[1] = getchar();
  }
                 
  for (const string& elem : Gen2)
    {
      count += Gen1.count(elem);
    }    
  printf("%d", count);
  
  
}
