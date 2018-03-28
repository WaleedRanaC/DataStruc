/*
 * Postfix Evaluation
 * Language: C++
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "LinkedStack.h"
#include <string.h>

using namespace std;

bool isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}


int performOperation(int op1, int op2, char op)
{
    int ans;
    switch(op){
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}

void postfixer()
{
	char exp[1000], buffer[15];
    int i,op1, op2, len, j, x;
    LinkedStack<int> s;
    printf("Enter a Postfix Expression: ( e.g. 2 3 + 4 * )\n");
    gets(exp);
    len = strlen(exp);
    j = 0;
    bool errorFound=false;
    
    for(i=0; i<len;i++){

        if(exp[i]>='0' && exp[i]<='9'){
            buffer[j++] = exp[i];
        }
        else if(exp[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }

        else if(isOperator(exp[i])){
            op1 = s.peek();
            s.pop();
            op2 = s.peek();
            s.pop();
            s.push(performOperation(op1, op2, exp[i]));
        }
        
        else if(!isOperator(exp[i]))
        {
        	cout<<"Invalid character found"<<endl;
        	errorFound=true;
        	break;
		}
    }

    if (!errorFound)
	{
		if (s.isEmpty())
		{
			cout<<"Empty Stack"<<endl;
		}
		else
		{
			printf("Answer is %d\n", s.peek());	
		}
	}

}

int main()
{
    string doAgain="y";
    while(doAgain == "y" || doAgain == "Y")
    {
    	postfixer();
		cin.clear();
		cout<<"More Expressions (Y/N)?: ";
		cin>>doAgain;
		cin.ignore();
	}
    

    return 0;
}
