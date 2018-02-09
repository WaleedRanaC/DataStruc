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
void bagTester(ArrayBag<T>& bag)
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
   
   cout<<"Finshed one bag"<<endl;
   cout<<endl;
   //displayBag(bag);
}  // end bagTester

int main()
{
	string choice = menuChoice();
	
	if(choice == "A" || choice == "a")
	{
		cout<<"A was selected"<<endl;
	}
	else if(choice == "B" || choice == "b")
	{
		cout<<"B was selected"<<endl;
		ArrayBag<char> bag;
	}
	else if(choice == "C" || choice == "c")
	{
		cout<<"C was selected"<<endl;
		
		//bag 1
		cout<<"Bag 1 input"<<endl;
		ArrayBag<string> bag1;
		bagTester(bag1); //get inputs for bag 1
		//bag1.bagUnion
		//bag1.bagIntersection
		//bag1.bagDifference
		cout<<endl;
		
		//bag 2
		cout<<"Bag 2 Input"<<endl;
		ArrayBag<string> bag2;
		bagTester(bag2); //get inputs for bag 2
		//bag2.bagUnion
		//bag2.bagIntersection
		//bag2.bagDifference
		
   		cout << "All done!" << endl;
	}
	else
	{
	 cout<<"Invalid Input"<<endl;
	}


   
   return 0;
}  // end main

