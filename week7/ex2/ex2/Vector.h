#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector
{
    T* v;
    int count;
    int size;
    void Resize()
    {
        T* a = new T[size * 2];
        for (int i = 0; i <= size; i++)
            a[i] = v[i];
        delete[] this->v;
        this->v    = a;
        this->size = this->size * 2;
    }

  public:
    Vector() : count(0), size(1)
    {
        v = new T[size];
    }
    Vector(int x) : count(0), size(x)
    {
        v = new T[x];
    }
    void push(T value)
    {
        if (count >= size)
            Resize();
        v[count++] = value;
    }
    T pop()
    {
        return T(v[--count]);
    }
    void delete_element(int index)
    {
        for (int i = index; i < count - 1; i++)
            v[i] = v[i + 1];
        count--;
    }
    void insert(T value, int index)
    {
        if (count >= size)
            Resize();
        for (int i = count; i > index; i--)
            v[i] = v[i - 1];
        v[index] = value;
    }
    void sort()
    {
        for (int i = 0; i < count - 1; i++)
            for (int j = i + 1; j < count; j++)
                if (compare(this->v[j], this->v[i]))
                {
                    T aux = v[j];
                    v[j]  = v[i];
                    v[i]  = aux;
                }
    }
    const T& get(int index)
    {
        return this->v[index];
    }

    void set(const T& value, int index)
    {
        v[index] = value;
    }
    int countt()
    {
        return count;
    }
    int firstindexOf(const T& value)
    {
        int i = 0;
        while (i < count && !equal(this->v[i], value))
            i++;
        if (this->v[i] == value)
            return i;
        return NULL;
    }

    bool compare(T v1, T v2)
    {
        if (v1 < v2)
            return true;
        return false;
    }
    bool equal(T v1, T v2)
    {
        if (v1 == v2)
            return true;
        return false;
    }
    void print()
    {
        for (int i = 0; i < count; i++)
            cout << this->v[i] << " ";
        cout << endl;
    }
};
