#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_set<string> words{};
    string word;
    while (cin>>word)
    {
      words.emplace(word);
    }
    cout << words.size();
    
}
