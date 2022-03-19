#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <cstdarg>
#include <iostream>
#include <cstring>

using namespace std;

Sort::Sort(int nr_elements, int min, int max): nr_of_elem(nr_elements)
{
    this->v = new int[nr_elements];
    for (int i=0;i<nr_elements;i++)
    {
        v[i] = rand() % (max - min) + min;
    }
}

Sort::Sort(const Sort& other) : Sort(other.v,other.nr_of_elem)
{

}

Sort::Sort(int a[], int nr_elements) : nr_of_elem(nr_elements)
{
    this->v = new int[nr_elements];
    for (int i = 0; i < nr_elements; i++)
        v[i] = a[i];
}

Sort::Sort(int count,...) : nr_of_elem(count)
{
    this->v=new int[count];
    va_list arg;
    va_start(arg,count);
    for(int i=0;i<count;i++)
        v[i]=va_arg(arg,int);
    va_end(arg);
}

Sort::Sort(char* string)
{
    int i=0,n=0;
    while (string[i] != '\0')
    {
        if(string[i]==',')
            n++;
        i++;
    }
    n++;
    this->v=new int[n];
    i=0;
    char* p=strtok(string,",");
    while (p != nullptr)
    {
        int nr=0,j=0;
        while (p[j] != '\0')
        {
            nr = nr * 10 + (p[j] - 48);
            j++;
        }
        v[i++]=nr;
        p=strtok(NULL,",");
    }
    this->nr_of_elem=i;
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 1; i < nr_of_elem; i++)
    {
        int j=i-1;
        int temp=v[i];
        if (ascendent == true)
        {
            while (j >= 0 && v[j] > temp)
            {
                v[j+1]=v[j];
                j=j-1;
            }
            if(v[j+1]!=temp)
                v[j+1]=temp;
        }
        else {
            while (j >= 0 && v[j] < temp)
            {
                v[j+1]=v[j];
                j=j-1;
            }
            if(v[j+1]!=temp)
                v[j+1]=temp;
        }

    }
}

void Sort::BubbleSort(bool ascendent)
{
    int last=nr_of_elem-1;
    while (last > 0)
    {
        int nr=last-1;
        last=0;
        for(int i=0;i<=nr;i++)
            if(ascendent==true)
              {  if (v[i] > v[i + 1])
                {
                    int aux=v[i];
                    v[i]=v[i+1];
                    v[i+1]=aux;
                    last=i;
                }
               }
            else
                if (v[i] < v[i + 1])
            {
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                last=i;
            }
    }
}

/*void Sort::QuickSort(bool ascendent, int first, int last)
{

}*/
void Sort::Print()
{
    for(int i=0;i<nr_of_elem;i++)
        cout<<v[i]<<" ";
    cout<<'\n';
}

int Sort::GetElementsCount()
{
    return nr_of_elem;
}

int Sort::GetElementFromIndex(int index)
{
    if(index>=nr_of_elem)
        return -1;
    return v[index];
}