#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;

map<string, vector<string>> tree;
map<string, int> levelCount;

void deep(string name, int level)
{
  levelCount[name] = level;
  for (int i = 0; i < tree[name].size(); i++)
    deep(tree[name][i], level + 1);
}

int main()
{
  map<string, bool> parentCount;
  
  
  string child, parent, head;
  int N;
  cin >> N;
  for (int i =0 ; i < N-1; i++)
  {
    cin >> child >> parent;
    parentCount[child] = true;
    if (!parentCount.contains(parent))
    {
      parentCount[parent] = false;
    }
    tree[parent].push_back(child);
  }

  for (auto it = parentCount.begin(); it !=  parentCount.end(); it++)
  {
    if (!it -> second)
    {
      head = it->first;
      break;
    }
  }
  deep(head, 0);
  for (auto it = levelCount.begin(); it !=  levelCount.end(); it++)
  {
    cout << it->first << ' ' << it->second << '\n';
  }
}
