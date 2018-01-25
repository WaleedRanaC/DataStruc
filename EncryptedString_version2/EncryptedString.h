#ifndef EncryptedString_H
#define EncryptedString_H
using namespace std;

class EncryptedString
{
public:
	EncryptedString();
	EncryptedString(string aString);
	string set(string s);
	string specCheck(string a);
	string get() const;
	string getEncrypted() const;
private:
	string myString;
	string everyString;
	string specString;
};

#include "EncryptedString.cpp"
#endif
