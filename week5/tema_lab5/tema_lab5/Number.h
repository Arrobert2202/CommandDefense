#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstring>
#include <iostream>
class Number

{
    // add data members
  private:
    char* value;
    int base=10;
    static int ConvertTo10(const char* value, int base);
    static char* ConvertFrom10(int value, int base);

  public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int value);
    Number(const char* value);
    ~Number();
    // add operators and copy/move constructor
    char& operator[](int);
    Number& operator+=(const Number& second);
    friend Number operator+(Number n1, const Number& n2)
    {
        n1 += n2;
        return n1;
    }

    Number& operator-=(const Number& n2);
    friend Number operator-(Number n1, const Number& n2)
    {
        n1 -= n2;
        return n1;
    }

    friend bool operator>(Number const& n1, Number const& n2)
    {
        int a1 = ConvertTo10(n1.value, n1.base);
        int a2 = ConvertTo10(n2.value, n2.base);
        return a1 > a2;
    }
    Number& operator--();
    Number& operator--(int);

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase();        // returns the current base
};
