
#ifndef String_hpp
#define String_hpp

#pragma once
#include "BankingCommonDecl.hpp"
#include <cstring>
#include <string>
#include "stdlib.h"
using namespace std;

class String
{
public:
    char* Str;
    String();
    String(char* str);
    String(String& ref);
    virtual ~String();
    
    virtual char* GetStr() const;
    virtual void SetStr(char* str);
   
    char* operator+(String& ref);
    String& operator=(char* ref);
    String& operator+=(String& ref);
    bool operator==(String& ref);
    
    friend ostream& operator<<(ostream& os, String& ref);
    friend istream& operator>>(istream& is, String& ref);
};

#endif /* String_hpp */
