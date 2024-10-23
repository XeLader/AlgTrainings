#include <iostream> 
#include <map>
#include <set>

using namespace std;

int toLowercase(string*);

int main()
{
  int N, emph, count = 0;
  string word;
  map<string, set<int>> Dict;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> word;
    emph = toLowercase(&word);
    Dict[word].emplace(emph);
  }
  
  while (cin >> word)
  {
    emph = toLowercase(&word);
    if (emph >= 0)
    {
      if(Dict.contains(word))
        count += !Dict[word].contains(emph);
    }
    else count++;
  }
  cout << count;
}


int toLowercase(string *in)
{
  int emph = -1;
  
  for (int i = 0; i < (int)in->length(); i++)
  {
    if ((*in)[i]<='Z')
    {
      if (emph < 0)
      {
        emph = i;
        (*in)[i] = (*in)[i] + ('a'-'A');
      }
      else return -1;
    }
  }
  
  return emph;
}
