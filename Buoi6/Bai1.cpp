#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;

class MyString
{
	char s[100];
	int n;
public:
	MyString()
	{
	}
	MyString(char *str);
	MyString(const MyString& str);
	MyString operator = (const MyString& str);
	MyString operator + (const MyString& str);
	int operator > (const MyString& str);
	int operator < (const MyString& str);
	int operator == (const MyString& str);
	int operator != (const MyString& str);
	friend istream& operator >>(istream & in, MyString &str);
	friend ostream& operator <<(ostream & out, const MyString &str);
	
};
int main()
{
	MyString s("abc");
	MyString s1("abcd");
	//MyString s2;
	//s2= s+s1;
	//cout<<"Nhap chuoi: ";
	//cin>>s;
	//cout<<"Xuat chuoi: "<<s2;
	if(s>s1)
		cout<<"Hai chuoi bang nhau";
	else
		cout<<"Hai chuoi khong bang nhau";
	return 0;
}
MyString::MyString (char *str)
{
	strcpy(s,str);
}
MyString::MyString(const MyString& str)
{
	strcpy(s,str.s);
}
MyString MyString::operator = (const MyString& str)
{
	strcpy(s,str.s);	
}
MyString MyString::operator + (const MyString& str)
{
	MyString s3("");
	strcat(s3.s,s);
	strcat(s3.s,str.s);
	return s3;
}
int MyString::operator > (const MyString& str)
{
	return strcmp(s,str.s)==1;
}
int MyString::operator < (const MyString& str)
{
	return strcmp(s,str.s)==-1;
}
int MyString::operator == (const MyString& str)
{
	return strcmp(s,str.s)==0;
}
int MyString::operator != (const MyString& str)
{
	return strcmp(s,str.s)!=0;
}

istream& operator >>(istream & in, MyString &str)
{
	in.getline(str.s,100);
	return in;
}
ostream& operator <<(ostream & out, const MyString &str)
{
	out<<str.s;
	return out;
}
