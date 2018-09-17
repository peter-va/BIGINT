#include <iostream>
#include <stack>

#ifndef LONGINT_H
#define LONGINT_H

class LongInt {
    public:
      friend std::ostream &operator<<(std::ostream &os, LongInt& x);
      friend std::istream &operator>>(std::istream &os, LongInt& x);
      std::stack<int> digit;
      LongInt operator+(LongInt& y);
    };

#endif