#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
#include <cstring>

int Number::ConvertTo10(const char* value, int base)
{
    int power = 1;
    int v     = 0;
    for (int i = strlen(value) - 1; i >= 0; i--)
    {
        int c;
        if (value[i] >= 'A' && value[i] <= 'F')
            c = value[i] - 'A' + 10;
        else
            c = value[i] - '0';
        v     = v + c * power;
        power = power * base;
    }
    return v;
}

char* Number::ConvertFrom10(int value, int base)
{
    int length = 0, v = value;
    while (v != 0)
    {
        printf("%d %d", v, base);
        v = v / base;
        length++;
    }
    int l   = length;
    char* c = new char[length + 1];
    length--;
    do
    {
        int a = (value % base);
        if (a >= 10)
            c[length] = a + 'A' - 10;
        else
            c[length] = a + '0';
        value = value / base;
        length--;
    } while (length >= 0);
    c[l] = '\0';
    return c;
}

Number::Number(const char* value, int base)
{
    this->base  = base;
    this->value = new char[100];
    strcpy(this->value, value);
}
Number::Number(int value)
{
    this->base = 10;
    strcpy(this->value, ConvertFrom10(value, this->base));
}

Number::Number(const char* value)
{
    strcpy(this->value, value);
}

Number::~Number()
{
    delete this->value;
}

char& Number::operator[](int index)
{
    return this->value[index];
}

//Number& Number::operator=(int value)
//{
//    printf("%d\n", value);
//    this->setBase(10);
//    printf("%d", this->base);
//    strcpy(this->value, ConvertFrom10(value, this->getBase()));
//    return *this;
//}

Number& Number::operator+=(const Number& n2)
{
    int max_base = this->base;
    if (n2.base > this->base)
        max_base = n2.base;
    int a  = ConvertTo10(this->value, this->base);
    int b   = ConvertTo10(n2.value, n2.base);
    int sum = a + b;
    strcpy(this->value, ConvertFrom10(sum, max_base));
    this->base = max_base;
    return *this;
}

Number& Number::operator-=(const Number& n2)
{
    int max_base = this->base;
    if (n2.base > this->base)
        max_base = n2.base;
    int a  = ConvertTo10(this->value, this->base);
    int b   = ConvertTo10(n2.value, n2.base);
    int dif = a - b;
    strcpy(this->value, ConvertFrom10(dif, max_base));
    this->base = max_base;
    return *this;
}
Number& Number::operator--()
{
    for (int i = 0; i <= strlen(this->value)-1; i++)
        this->value[i] = this->value[i + 1];
    this->value[strlen(this->value)] = '\0';
    return *this;
}
Number& Number::operator--(int)
{
    this->value[strlen(this->value)-1] = '\0';
    return *this;
}
void Number::SwitchBase(int newBase)
{
    int v      = ConvertTo10(this->value, this->base);
    this->base = newBase;
    strcpy(this->value, ConvertFrom10(v, this->base));
}

void Number::Print()
{
    std::cout << this->value << '\n';
}

int Number::GetDigitsCount()
{
    int length = strlen(this->value);
    if (value[0] == '-')
        return length - 1;
    return length;
}
int Number::GetBase()
{
    return this->base;
}
