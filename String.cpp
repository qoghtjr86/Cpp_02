#include "String.hpp"

String::String():Str(nullptr){}

String::String(char* str)
{
    Str=str;
}

String::String(String& ref)
{
    Str=ref.Str;
}

String::~String()
{
    delete []Str;
    
}

char* String::GetStr() const
{
    return Str;
}

void String::SetStr(char* str)
{
    Str=new char[strlen(str)+1];
    strcpy(Str, str);
}

String& String::operator=(char* str)
{
    Str=new char[strlen(str)+1];
    strcpy(Str, str);
    return *this;
}

char* String::operator+(String& ref)
{
    char* pStr=new char[strlen(ref.Str)+strlen(this->Str)+2];
    strcpy(pStr, this->Str);
    strcat(pStr, ref.Str);
    return pStr;
}

String& String::operator+=(String& ref)
{
    strcat(Str, ref.Str);
    return *this;
}
    
bool String::operator==(String& ref)
{
    int result=strcmp(Str, ref.Str);
    if(result==1)return true;
    else return false;
}

ostream& operator<<(ostream& os, String& ref)
{
    os<<ref.GetStr()<<endl;
    return os;
}
istream& operator>>(istream& is, String& ref)
{
    char* str=new char[50];
    is>>str;
    ref.SetStr(str);
    return is;
}

