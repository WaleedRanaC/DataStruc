//Waleed Rana
//lab 3 Iterative

#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>				//included for color and sleep
#include <time.h>

using namespace std;

void Color(int x)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);			//create (temp)standard output handle called hConsole
	SetConsoleTextAttribute(hConsole, x);						//change console color to x
}

unsigned long long int getNumber()
{
	unsigned long long int number;
	cout<<"What Number would you like to input?: "<<endl;
	cin>>number;
	

	return number;

}  // gets the number


void triangleNumber(unsigned long long int number)
{
	unsigned long long int sum;
	
	if(number == 1)
	{
		cout<<"The Triangular Number is 1"<<endl;
	}
	else if(number>1)
	{
		for (int i = 1; i < number; i++)
	   {
	     sum+=(number-i);
	   }  
	
		cout<<"The Triangular Number is "<<sum<<endl;
	}
	else
	{
		cout<<"Invalid Entry"<<endl;
	}
	
}



void triangleVisual(unsigned long long int number)
{
	unsigned long long int space, rows;
	
	space = number;
	rows = number;

    for(int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            cout <<" ";
        }

        while(k != i)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }    
    
}

int main()
{
	//time start
	clock_t tStart = clock();		
    
    
	Color(11);	
	//getting the number
	unsigned long long int number;
	number = getNumber();

	//gives us the triangular number
	triangleNumber(number);

	//just for fun
	if(number <= 40)
	{
		Color(13);
		triangleVisual(number);
		Color(10);
	}
	
	//timestamp
	
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	Color(12);

	
	return 0;
}
