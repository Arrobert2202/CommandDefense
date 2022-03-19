#pragma once

class Sort

{
    // add data members
    int* v;
    int nr_of_elem;
  public:
    // add constuctors
    Sort(int nr_elements, int min, int max);

    Sort(const Sort& other);

    Sort(int a[], int nr_elements);

    Sort(int count,...);

    Sort(char* string);

    void InsertSort(bool ascendent );

    void QuickSort(bool ascendent, int first, int last );

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);
};