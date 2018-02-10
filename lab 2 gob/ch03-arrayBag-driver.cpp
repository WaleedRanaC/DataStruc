//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

string menuChoice()
{
	string choice = "";
	cout<<endl;
	cout<<"Menu: "<<endl;
	cout<<"A) Single Digit Integer"<<endl;
	cout<<"B) Single Digit Char"<<endl;
	cout<<"C) Name Strings"<<endl;
	cout<<endl;
	cin>>choice;
	return choice;
}

template <class T>
void displayBag(ArrayBag<T>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<T> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displayBag

template <class T>
void bagInput(ArrayBag<T>& bag)
{
   //displayBag(bag);
   
   //Getting number of inputs:
   int numberInputs;
   cout<<"How many items would you like to input?"<<endl;
   cin>>numberInputs;
   T items[numberInputs];
	for (int i = 0; i < numberInputs; i++)
   {
   		T pInput;
   		cout<<"Input "<<i<<":"<<endl;
		cin>>items[i];
		bag.add(items[i]);
	}  // end for
   
   displayBag(bag);
   cout<<endl;
   //displayBag(bag);
}  // end bagTester

int main()
{
	string choice = menuChoice();
	
	if(choice == "A" || choice == "a")
	{
		cout<<"Please Input Single Digit Integer"<<endl;
		//bag 1
		cout<<"Bag 1 input"<<endl;
		ArrayBag<int> bag1;
		bagInput(bag1); //get inputs for bag 1
		cout<<endl;
		
		//bag 2
		cout<<"Bag 2 Input"<<endl;
		ArrayBag<int> bag2;
		bagInput(bag2); //get inputs for bag 2

   		cout << "Inputs Completed!" << endl;
	}
	else if(choice == "B" || choice == "b")
	{
		cout<<"Please Input Single Digit Char"<<endl;
		//bag 1
		cout<<"Bag 1 input"<<endl;
		ArrayBag<char> bag1;
		bagInput(bag1); //get inputs for bag 1
		cout<<endl;
		
		//bag 2
		cout<<"Bag 2 Input"<<endl;
		ArrayBag<char> bag2;
		bagInput(bag2); //get inputs for bag 2

   		cout << "Inputs Completed!" << endl;
	}
	else if(choice == "C" || choice == "c")
	{
		cout<<"Please Input Strings: "<<endl;

		//bag 1
		cout<<"Bag 1 input"<<endl;
		ArrayBag<string> bag1;
		bagInput(bag1); //get inputs for bag 1
		cout<<endl;
		
		//bag 2
		cout<<"Bag 2 Input"<<endl;
		ArrayBag<string> bag2;
		bagInput(bag2); //get inputs for bag 2
		
		//result bag
		ArrayBag<string> resultBag;
		
		//bagUnion
		cout<<endl;
		cout<<"Bag Union Test:"<<endl;
		cout<<"---------------"<<endl;
		resultBag = bag1.bagUnion(bag2);
		displayBag(resultBag);
		
		//Clear the result bag
		resultBag.clear();

		//bagIntersection
		cout<<endl;
		cout<<"Bag Intersection Test:"<<endl;
		cout<<"----------------------"<<endl;
		resultBag = bag1.bagIntersection(bag2);
		displayBag(resultBag);
		
		//Clear the result bag
		resultBag.clear();
		
		//bagDifference
		cout<<"Bad Difference Test:"<<endl;
		cout<<"--------------------"<<endl;
		resultBag = bag1.bagDifference(bag2);
		displayBag(resultBag);
		
   		cout << "Inputs Completed!" << endl;
	}
	else
	{
	 cout<<"Invalid Input"<<endl;
	}


   
   return 0;
}  // end main

