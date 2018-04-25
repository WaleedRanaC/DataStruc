//Waleed Rana
//4/18/2018
//
#include <iostream>	
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
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
void scan(ItemType a[], int n)//read from file
{
	ifstream infile;
	ItemType temp;
	int count=0;
	infile.open("LastName2010.txt");
	infile>>temp;
	while(infile && count<n)
	{
		a[count]=temp;;
		count++;
		infile>>temp;
	}
	infile.close();
}//end of scan

template<class ItemType>
void generate(ItemType a[], int n)//random number generator
{
	for (long int i=0; i<n; i++)
	{
		a[i] = (rand());
	}
}

template<class ItemType>
void displaySort(ItemType sorted[], int size)
{
	ofstream outfile;
	outfile.open("resultpart2.txt");
	for (int i=0; i<size; i++)
	{
		outfile<<i+1<<". "<<sorted[i]<<endl;
	}
	outfile.close();
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

void displayStringMenu()
{
	cout<<"______________________________________"<<endl;
	cout<<"1)100k"<<endl;
	cout<<"2)250k"<<endl;
	cout<<"3)450K"<<endl;
	cout<<"________________________________________"<<endl;	
}

void sortNumbers()//sort num
{
	char chPick;
	clock_t timer;
	
	//creating a new array
	long long int n=0;
	cout<<"How many numbers do you want to generate? "<<endl;
	cin>> n;
	int* list = new int[n];
	generate(list, n);
	//Creating a fixed Size Array
	cout<<"Sorting Numbers"<<endl;
	displayMenu();
	cout<<"Which one would you like to do? : "<<endl;
	cin>>chPick;
	
	switch (chPick)
	{
		case '1':
			timer = clock();
			insertionSort(list,n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '2':
			timer = clock();
			mergeSort(list, 0, n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '3':
			timer = clock();
			selectionSort(list,n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '4':
			timer = clock();
			quickSort(list, 0, n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '5':
			timer = clock();
			bubbleSort(list,n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '6':
			timer = clock();
			shellSort(list,n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '7':
			timer = clock();
			radixsort(list,n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '8':
			timer = clock();
			heapSort(list-1,n);
			cout<<"Sorted: ";
			displaySort(list,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '9':
			timer = clock();
			sort(list,list+n);
			displaySort(list,n);
			cout<<"Sorted: ";
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
	}
	//Finisher
	delete [] list;
	list=NULL;
}

template<class ItemType>
void sorter(ItemType a[], int n)
{
	clock_t timer;
	char chPick;

	cout<<"Sorting Strings"<<endl;
	displayMenu();
	cout<<"Which one would you like to do? : "<<endl;
	cin>>chPick;
	
	switch (chPick)
	{
		case '1':
			timer = clock();
			insertionSort(a,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '2':
			timer = clock();
			mergeSort(a, 0, n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '3':
			timer = clock();
			selectionSort(a,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '4':
			timer = clock();
			quickSort(a, 0, n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '5':
			timer = clock();
			bubbleSort(a,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '6':
			timer = clock();
			shellSort(a,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '7':
			timer = clock();
			radixsort(a,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '8':
			timer = clock();
			heapSort(a-1,n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '9':
			timer = clock();
			sort(a,a+n);
			cout<<"Sorted: ";
			displaySort(a,n);
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
	}
}
void CallerBaller(long long int n)
{
	cout<<"inside the callerballer"<<endl;
	string* list = new string[n];
	cout<<"list Created"<<endl;
	scan(list, n);
	sorter(list, n);
	
	//Finisher
	delete [] list;
	list=NULL;
}

void sortStrings()//sort string
{
	char chPick;
	
	cout<<"Sorting Strings:"<<endl;
	displayStringMenu();
	cout<<"Pick an Ammount : "<<endl;
	cin>>chPick;
	
	switch(chPick)
	{
		case '1':
			CallerBaller(100000);
			break;
		case '2':
			CallerBaller(250000);
			break;
		case '3':
			CallerBaller(435000);
			break;
			
	}

}


int main()
{
	char choice=' ';
	char again='y';

	
	while (again=='y')
	{
		cout<<"Sort Numbers or Strings? (N/S): "<<endl;
		cin>>choice;
		
		switch (choice)
		{
			case 'S':
				sortStrings();
				break;
			case 'N':
				sortNumbers();
				break;
		}
		cout<<"go again? (y/n): "<<endl;
		cin>>again;
	}

	return 0;
} 

