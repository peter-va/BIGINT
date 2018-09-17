#include <iostream>
#include <stack>
#include <queue>
#include "LongInt.h"
using namespace std;
LongInt LongInt::operator+(LongInt& y)
{
  LongInt z;
  int a, b, c=0, temp;
  while(!this->digit.empty() || !y.digit.empty())
  {
    if(this->digit.empty())
    {
      temp=y.digit.top()+c;
      y.digit.pop();
      z.digit.push(temp);
      c=0;
    }
    else if(y.digit.empty())
    {
      temp=this->digit.top()+c;
      this->digit.pop();
      z.digit.push(temp);
      c=0;
    }
    else {
      a=this->digit.top();
      this->digit.pop();
      b=y.digit.top();
      y.digit.pop();
      z.digit.push((a+b+c)%10);
      if((a+b+c)/10==1)
        c=1;
      else
        c=0;
    }
  }
  if(c==1)
    z.digit.push(c);
return z;
}

ostream& operator<<(ostream& os, LongInt& x)
{
  std::queue <int> n;
  while(!x.digit.empty()){
    n.push(x.digit.top());
    x.digit.pop();
    }
  while(!n.empty()){
    os<<n.front();
    n.pop();
    }
  return os;
}

istream& operator>>(istream& is, LongInt& x)
{
  int y;
  std::queue <int> n;
  while(is) {
    char t=is.get();
    if(isdigit(t))
{
    y=t-'0';
    n.push(y);
}
else
break;
  }
  while(!n.empty()) {
    x.digit.push(n.front());
    n.pop();
  }
  return is;
}