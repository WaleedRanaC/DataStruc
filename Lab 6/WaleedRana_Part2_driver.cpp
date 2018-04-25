//Waleed Rana
//4/24/2015
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
#include "quickSort.cpp"
#include "linearSearch.cpp"
#include "binarySearch.cpp"

using namespace std;

template<class ItemType>
void scan(ItemType a[], int n)//read from file
{
	ifstream infile;
	ItemType temp;
	int count=0;
	infile.open("LastName2010new.txt");
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



void displayMenu()
{
	cout<<"______________________________________"<<endl;
	cout<<"1)Linear"<<endl;
	cout<<"2)Binary"<<endl;
	cout<<"________________________________________"<<endl;
}//end of displayMenu


void sortNumbers()//sort num
{
	char chPick;
	clock_t timer;
	
	//creating a new array
	cout<<"Sorting Numbers"<<endl;
	long long int n=0;
	cout<<"How many numbers do you want to generate? "<<endl;
	cin>> n;
	int* list = new int[n];
	generate(list, n);
	int numero = 0;
	cout<<"which number would you like to search for?: "<<endl;
	cin>>numero;
	
	//Creating a fixed Size Array
	displayMenu();
	cout<<"Which one would you like to do? : "<<endl;
	cin>>chPick;
	
	
	
	switch (chPick)
	{
		case '1':
			timer = clock();
			cout<<numero<<" is located at "<<linearSearch(list, n, numero)<<endl;
			cout<<"Sorted: "<<endl;
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '2':
			quickSort(list, 0, n-1);
			timer = clock();
			
			cout<<numero<<" is located at "<<binarySearch(list, 0, n, numero)<<endl;
			cout<<"Sorted: "<<endl;
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
	
	string name;
	cout<<"Pick a name: "<<endl;
	cin>>name;
	
	
	switch (chPick)
	{
		case '1':
			timer = clock();
			
			cout<<name<<" was found at "<<linearSearch(a, n, name)<<endl;;
			cout<<"Sorted: "<<endl;
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
		case '2':
			quickSort(a, 0, n-1);
			timer = clock();
			//
			cout<<name<<" was found at "<<binarySearch(a, 0, n, name)<<endl;;
			cout<<"Sorted: "<<endl;
			cout<<"Time Total: "<<(clock()-float(timer))/CLOCKS_PER_SEC << "Seconds" <<endl;
			break;
	}
}
void CallerBaller(long long int n)
{
	string* list = new string[n];
	scan(list, n);
	sorter(list, n);
	
	//Finisher
	delete [] list;
	list=NULL;
}

void sortStrings()//sort string
{
	
	cout<<"Sorting Strings:"<<endl;
	//GET THE TOTAL AMOUNT 
	long long int number_of_lines = 0;
    string line;
    ifstream myfile("LastName2010new.txt");

    while (getline(myfile, line))
        ++number_of_lines;
    cout << "Number of lines in text file: " << number_of_lines<<endl;
	//BAm
	
	CallerBaller(number_of_lines);
}


int main()
{

	char choice=' ';
	char again='y';

	
	while (again=='y')
	{
		cout<<"Sort Integers or Strings? (I/S): "<<endl;
		cin>>choice;
		
		switch (choice)
		{
			case 'S':
				sortStrings();
				break;
			case 'I':
				sortNumbers();
				break;
		}
		cout<<"go again? (y/n): "<<endl;
		cin>>again;
	}

	return 0;
} 
