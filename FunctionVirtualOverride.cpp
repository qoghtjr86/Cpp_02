#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() { cout<<"FirstFunc"<<endl; }
};

class Second
{
public:
    virtual void MyFunc() { cout<<"SecondFunc"<<endl; }
};

class Third
{
public:
    virtual void MyFunc() { cout<<"ThirdFunc"<<endl; }
};

int main(void)
{
    Third* tptr=new Third();
    Second* sptr=(Second*)(tptr);
    First* fptr=(First*)(sptr);
    
    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
}
