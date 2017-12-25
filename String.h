#ifndef STRING_H_
#define STRING_H_


#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

class String
{
protected:
    mutable char * strVal;
    int length;

public:
    String(){};
    virtual ~String(){};
    String(const String &copy);
    String(const char* copy);
    int Length() const;
    String &operator = (const String &copy);
    const char *CStr() const;
    int Index(const String &a);
};

String::String(const String & copy)
{
	length = strlen(copy.CStr());
	strVal = new char[length + 1];
	strcpy(strVal, copy.strVal);
}

String::String(const char * copy)
{
	length = strlen(copy);
	strVal = new char[length + 1];
	strcpy(strVal, copy);
}

int String::Length() const
{
	return strlen(strVal);
}

String & String::operator=(const String & copy)
{
	delete[] strVal;
	length = strlen(copy.CStr());
	strVal = new char[length + 1];
	strcpy(strVal, copy.CStr());
	return *this;
}

const char * String::CStr() const
{
	return (const char*)strVal;
}



int String::Index(const String& a)
{
	int i = 0, j = 0;
	while (i < this->Length() && j < a.Length())
	{
		if (this->CStr()[i] == a.CStr()[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= a.Length())
		return i - j;
	else
		return -1;
}



#endif // STRING_H_
