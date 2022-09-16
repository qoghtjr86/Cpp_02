#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
    char* str;
public:
    void SetString(const char* msg);
    void ShowString();
};

void Printer::SetString(const char* msg)
{
    size_t length=strlen(msg);
    str=new char[length];
    strcpy(str, msg);
}

void Printer::ShowString()
{
    cout<<str<<endl;
}

int main()
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}
