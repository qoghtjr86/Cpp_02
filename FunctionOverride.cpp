#include <iostream>
using namespace std;

class First
{
public:
    void MyFunc() { cout<<"FirstFunc"<<endl; }
};

class Second
{
public:
    void MyFunc() { cout<<"SecondFunc"<<endl; }
};

class Third
{
public:
    void MyFunc() { cout<<"ThirdFunc"<<endl; }
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
