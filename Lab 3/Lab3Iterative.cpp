//Waleed Rana
//lab 3 Iterative

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


long long int getNumber()
{
	long long int number;
	cout<<"What Number would you like to input?: "<<endl;
	cin>>number;
	
	return number;
}  // gets the number


void triangleNumber(long long int number)
{
	long long int sum;
	
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


int main()
{
	//getting the number
	long long int number;
	number = getNumber();

	triangleNumber(number);

	return 0;
}
