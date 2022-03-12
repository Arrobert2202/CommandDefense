#include "Math.h"
#include <iostream>
#include <cstdarg>
#include <cstring>


int Math::Add(int a, int b)
{
    return a + b;
}
int Math::Add(int a, int b, int c)
{
    return a + b + c;
}
int Math::Add(double a, double b)
{
    return (int)(a + b);
}
int Math::Add(double a, double b, double c)
{
    return (int)(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return (int)(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return (int)(a * b * c);
}

int Math::Add(int count, ...)
{
    int sum = 0;
    va_list elements;
    va_start (elements, count);
    while (count>0)
    {
        int a = va_arg(elements,int);
        sum   = Add(sum,(int)a);
        count--;
    }
    va_end(elements);
    return sum;
}

char* Math::Add(const char* a, const char* b)
{
    if (a == nullptr) 
        return nullptr;
    if (b == nullptr) 
        return nullptr;

    char* new_word = new char[strlen(a)+strlen(b)+1];

    for (int i = 0; i < strlen(a); i++)
        new_word[i] = a[i];
    for (int i = 0; i < strlen(b); i++)
        new_word[i+strlen(a)] = b[i];

    new_word[strlen(a) + strlen(b)] =  NULL;

    return new_word;
}
