#include <iostream>
#include <string>
#include <cctype>
#include "EncryptedString.h"
using namespace std;

int main()
{
	EncryptedString str1;
	cout << "Empty string not encrypted: " << str1.get() << endl;
	cout << "Empty string     encrypted: " << str1.getEncrypted() << endl << endl;
	
	cout << "abcd not encrypted: " << str1.set("abcd") << endl;
	cout << "abcd     encrypted: " << str1.getEncrypted() << endl << endl;
	
	cout << "Hi Mom not encrypted: " << str1.set("Hi Mom") << endl;
	cout << "Hi Mom     encrypted: " << str1.getEncrypted() << endl << endl;
	
	EncryptedString str2;;
	cout << "Hi#$% Mom!$#% not encrypted: " << str2.set("Hi#$% Mom!$#%") << endl;
	cout << "Hi#$% Mom!$#%     encrypted: " << str2.getEncrypted() << endl;
	cout << " " <<endl;
	cout << "Note: "<<str2.specCheck("Hi#$% Mom!$#%")<<" is illegal and is removed" << endl;
		 
	return 0;
}
