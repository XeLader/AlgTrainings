#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  string ling;
  int NStudents, NLang;
  
  cin >> NStudents;
  
  unordered_set<string> AllStud= {};
  unordered_set<string> CurrentStud= {};
  unordered_set<string> Intersect= {};
  
  auto Inter = [&CurrentStud](auto const& x) { return !(CurrentStud.contains(x)); };
  
  cin >> NLang;
  for (int j = 0; j < NLang; j ++)
    {
      cin >> ling;
      AllStud.emplace(ling);
      Intersect.emplace(ling);
    }
  
  for (int i = 1; i < NStudents; i++)
  {
    cin >> NLang;
    for (int j = 0; j < NLang; j ++)
    {
      cin >> ling;
      AllStud.emplace(ling);
      CurrentStud.emplace(ling);
    }
    
    erase_if(Intersect, Inter);
    CurrentStud.clear();
  }
  
  cout<<Intersect.size()<<'\n';
  for (const string& elem : Intersect)
    cout << elem<<'\n';
   
  cout<<AllStud.size()<<'\n';
  for (const string& elem : AllStud)
    cout << elem<<'\n';   
  
}
