#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkTags(string&);
bool checkBrackets(string&);
void changeAtoA(string&);

void changeLESStoA(string&);
void changeLESSonSLASH(string&);
void changeSLASHonMORE(string&);
void changeLESSonMORE(string&);

void changeMOREtoA(string&);
void changeMOREonSLASH(string&);
void changeSLASHonLESS(string&);
void changeMOREonLESS(string&);

void changeAonSLASH(string&);
void changeSLASHonA(string&);

int main()
{
   string in;
   cin >> in;
   
   if (in[0] != '<')
  {
    in[0] = '<';
    cout << in;
    return 0;
  }
  else if (in[in.length()-1] != '>')
  {
    in[in.length()-1] = '>';
    cout << in;
    return 0;
  }
   
   int countOpen = 0, countClose = 0, countSlash = 0;
   for (unsigned int i = 0; i < in.length(); i++)
   {
      switch (in[i])
      {
        case '<':
          countOpen++;
          break;
          
        case '>':
          countClose++;
          break;
          
        case '/':
          countSlash++;
          break;
      }
   }
  
   if (countOpen == countClose and countOpen == countSlash * 2)
   {
   //cout<<"change latter on latter\n";
   changeAtoA(in);
   }
   else if (countOpen > countClose)
   {
       if (countClose == countSlash * 2)
         //cout << "change < on latter";
         changeLESStoA(in);
       else if(countClose == (countSlash + 1)* 2)
         //cout << "change < on /";
         changeLESSonSLASH(in);
       else if ((countClose + 1) == (countSlash - 1)* 2)
         //cout << "change / on >";
         changeSLASHonMORE(in);
       else if ((countClose + 1) == (countOpen - 1))
         //cout << "change < on >";
         changeLESSonMORE(in);
    }
    else if (countOpen < countClose)
   {
       if (countOpen == countSlash * 2)
         //cout << "change > on latter";
         changeMOREtoA(in);
       else if(countOpen == (countSlash + 1)* 2)
         //cout << "change > on /";
         changeMOREonSLASH(in);
       else if ((countOpen + 1) == (countSlash - 1)* 2)
         //cout << "change / on <";
         changeSLASHonLESS(in);
       else if ((countClose - 1) == (countOpen + 1))
         //cout << "change > on <";
         changeMOREonLESS(in);
         
   } 
   else if (countOpen > countSlash * 2)
   {
     //cout<< "change letter on /";
     changeAonSLASH(in);
   }
   else if (countOpen < countSlash * 2)
   {
     //cout << "change / on letter";
     changeSLASHonA(in);
   }
   
}

bool checkTags(string &in)
{
  stack<string> tags;
  unsigned int start = 0; 
  bool close = false;
  for (unsigned int i = 0; i < in.length(); i++)
   {
      switch (in[i])
      {
        case '<':
          start = i + 1;
          close = false;
          break;
          
        case '>':
          if (start == i)
            return false;
          if (close)
          { 
            if (tags.empty())
              return false;
            if (!(tags.top() == in.substr(start, i-start)))
              return false;
            else tags.pop();
          }
          else
          {
            tags.push(in.substr(start, i-start));
          }
          break;
          
        case '/':
          close = true;
          start = i + 1;
          break;
      }
   }
   return true;
}

bool checkBrackets(string &in)
{
  bool Opened = 0;
  for (unsigned int i = 0; i < in.length(); i++)
  {
    switch (in[i])
    {
      case '<':
        if (Opened)
          return false;
        else
          Opened = true;
      break;
      
      case '>':
        if (Opened)
          Opened = false;
        else
          return false;
        break;
        
      case '/':
        if (!Opened)
          return false;
    }
  }
  
  return true;
}

void changeAtoA(string& in)
{
  string changed = in;
  for (unsigned int i = 0; i < in.length(); i++)
  {
    if (in[i] >= 'a' and in[i] <= 'z')
      for (char ch = 'a'; ch <='z'; ch++)
      {
        changed[i] = ch;
        if (checkTags(changed))
        {  
          cout << changed;
          return;
        }
        else
          changed[i] = in[i];
      }
  }
}

void changeLESStoA(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] == '<' and in[i-1] != '>')
      for (char ch = 'a'; ch <='z'; ch++)
      {
        changed[i] = ch;
        if (checkTags(changed))
        {  
          cout << changed;
          return;
        }
        else
          changed[i] = in[i];
      }
  }
}

void changeLESSonSLASH(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] == '<' and in[i-1] != '>')
    {
      changed[i] = '/';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '<';
     }
  }
}

void changeSLASHonMORE(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] == '/' and in[i-1] != '<')
    {
      changed[i] = '>';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '/';
     }
  }
}

void changeLESSonMORE(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] == '<' and in[i-1] != '>')
    {
      changed[i] = '>';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '<';
     }
  }
}
////////////////////////////////////////////////////////////

void changeMOREtoA(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length() - 1; i++)
  {
    if (in[i] == '>' and in[i+1] != '<')
      for (char ch = 'a'; ch <='z'; ch++)
      {
        changed[i] = ch;
        if (checkTags(changed))
        {  
          cout << changed;
          return;
        }
        else
          changed[i] = in[i];
      }
  }
}

void changeMOREonSLASH(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length() - 1; i++)
  {
    if (in[i] == '>' and in[i+1] != '<')
    {
      changed[i] = '/';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '>';
     }
  }
}

void changeSLASHonLESS(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] == '/' and in[i-1] != '<')
    {
      changed[i] = '<';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '/';
     }
  }
}

void changeMOREonLESS(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length() - 1; i++)
  {
    if (in[i] == '>' and in[i+1] != '<')
    {
      changed[i] = '<';
      if (checkBrackets(changed))
      {  
        cout << changed;
        return;
      }
      else
       changed[i] = '>';
     }
  }
}

void changeAonSLASH(string& in)
{
  string changed = in;
  for (unsigned int i = 0; i < in.length(); i++)
  {
    if (in[i] >= 'a' and in[i] <= 'b')
    { 
      changed[i] = '/';
      if (checkBrackets(changed))
        if (checkTags(changed))
        {  
          cout << changed;
          return;
        }
      changed[i] = in[i];
    }
  }
}

void changeSLASHonA(string& in)
{
  string changed = in;
  for (unsigned int i = 1; i < in.length(); i++)
  {
    if (in[i] >= '/' and in[i] != '<')
      for (char ch = 'a'; ch <='z'; ch++)
      {
        changed[i] = ch;
        if (checkBrackets(changed))
          if (checkTags(changed))
          {  
            cout << changed;
            return;
          }
        changed[i] = in[i];
      }
  }
}



