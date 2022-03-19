#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	int arr[]={3,4,2,1,9,5};

	Sort arr1(5,1,20);
    arr1.BubbleSort(false);
	arr1.Print();

	Sort arr2(arr1);
    arr2.InsertSort(true);
	arr2.Print();

	Sort arr3(arr,6);
	arr3.Print();

	Sort arr4(7,3,4,5,2,6,1,7);
	arr4.Print();

	char string[]="12,9,3,34,71,55";
	Sort arr5(string);
    arr5.BubbleSort(true);
	arr5.Print();

	int n = arr5.GetElementsCount();
    cout << n <<'\n';

	int m = arr2.GetElementFromIndex(4);
    cout << m;

	return 0;
}