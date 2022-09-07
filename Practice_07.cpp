#include <iostream>
using namespace std;

void Add(int &ref)
{
    ref++;
}

void Reverse(int &ref)
{
    ref=-ref;
}

int main()
{
    int num1=10;
    int num2=20;
    
    Add(num1);
    Reverse(num2);
    
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;
    return 0;
}
