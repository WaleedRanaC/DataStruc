//Waleed Rana
//4/18/2018
//
#include <iostream>	
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "selectionSort.cpp"
#include "quickSort.cpp"
#include "bubbleSort.cpp"
#include "shellSort.cpp"
#include "RadixSort.cpp"
#include "HeapSort.cpp"

using namespace std;
template<class ItemType>
void displaySort(ItemType sorted[], int size)
{
	for (int i = 0; i < size; i++)
	cout<< sorted[i] << " ";
	
	cout<< endl;
}
void displayMenu()
{
	cout<<"______________________________________"<<endl;
	cout<<"1)insertion"<<endl;
	cout<<"2)merge"<<endl;
	cout<<"3)selection"<<endl;
	cout<<"4)quick"<<endl;
	cout<<"5)bubble"<<endl;
	cout<<"6)shell"<<endl;
	cout<<"7)radix"<<endl;
	cout<<"8)heap"<<endl;
	cout<<"9)STL Sort"<<endl;
	cout<<"________________________________________"<<endl;
}//end of displayMenu


int main()
{
	string a[6] = {"Z", "X", "R", "K", "F", "B"};
	int b [10] = { 654, 18, 81, 4, 92, 68, 145, 8, 99, 36}; 
	
	char choice=' ';
	char menuAns=' ';
	char again='y';
	char chPick;
	
	while (again=='y')
	{
		cout<<"Sort Numbers or Strings? (N/S): ";
		cin>>choice;
		switch (choice)
		{
			case 'S':
				cout<<"Sorting Strings"<<endl;
				displayMenu();
				cout<<"Which one would you like to do? : "<<endl;
				cin>>chPick;
				switch (chPick)
				{
					case '1':
						insertionSort(a,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '2':
						mergeSort(a, 0, 5);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '3':
						selectionSort(a,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '4':
						quickSort(a, 0, 5);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '5':
						bubbleSort(a,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '6':
						shellSort(a,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '7':
						radixsort(a,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '8':
						heapSort(a-1,6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
					case '9':
						sort(a,a+6);
						cout<<"Sorted: ";
						displaySort(a,6);
						break;
				}
				break;
			case 'N':
				cout<<"Sorting Numbers"<<endl;
				displayMenu();
				cout<<"Which one would you like to do? : "<<endl;
				cin>>chPick;
				switch (chPick)
				{
					case '1':
						insertionSort(b,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '2':
						mergeSort(b, 0, 10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '3':
						selectionSort(b,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '4':
						quickSort(b, 0, 10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '5':
						bubbleSort(b,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '6':
						shellSort(b,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '7':
						radixsort(b,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '8':
						heapSort(b-1,10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
					case '9':
						sort(b,b+10);
						cout<<"Sorted: ";
						displaySort(b,10);
						break;
				}
				break;
		}
		cout<<"go again? (y/n): "<<endl;
		cin>>again;
	}

	return 0;
} 

