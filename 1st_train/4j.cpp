#include <iostream> 
#include <string>
#include <map>
#include <set>

using namespace std;

void toLowercase(string*);

int main()
{
  int N, j=0, start, stop, freq = 0, ord = 0;
  bool caseSens, digitSt, onlyDgt;
  string line, word, topWord;
  char C[4], D[4];
  
  map<string, int[2]> ident;
  set<string> keyWords;
  
  
  
  cin >> N >> C >> D;
  
  caseSens = (C[0] == 'y');
  digitSt = (D[0] == 'y');
  
  for (int i = 0; i < N; i++)
  {
    cin >> word;
    
    if (!caseSens) toLowercase(&word);
    
    keyWords.emplace(word);
  }
  
  while (getline(cin, line))
  {
    j = 0;
    while(j <(int)line.length())
    {
        if (isalpha(line[j]) or line[j] == '_' or isdigit(line[j]))
        {
          start = j;
          onlyDgt = isdigit(line[j]);
          j++;
          while(j < (int)line.length() and (isalpha(line[j]) or line[j] == '_' or isdigit(line[j])))
          {
            onlyDgt &= isdigit(line[j]);
            j++;
          }
          
          if (!onlyDgt and !isdigit(line[start])|digitSt)
          {
            stop = j - start;
            word = line.substr(start, stop);
          
            if (!caseSens) toLowercase(&word);
          
            if (!keyWords.contains(word))
            {
              if(!ident.contains(word))
                ident[word][0] = ord;
              
              ident[word][1] ++;
              ord++;
              if (ident[word][1] > freq) freq = ident[word][1];
            }
          }    
        }
        j++;
    }
  }
  map<string, int[2]>::iterator itr;
  
  for (itr = ident.begin(); itr != ident.end(); itr++)
    if ((itr -> second)[1] == freq and (itr -> second)[0] < ord)
    {
      ord = (itr -> second)[0];
      topWord = itr -> first;
    }
  cout << topWord;
}


void toLowercase(string *in)
{
  for (int i = 0; i < (int)in->length(); i++)
    if ((*in)[i]<='Z' and (*in)[i]>='A')
        (*in)[i] = (*in)[i] + ('a'-'A');  
}
