#include "AccountArray.hpp"

AccountArray::AccountArray(){}

AccountArray::AccountArray(int len):arrlen(len)
{
    arr=new Account*[arrlen];
}
Account& AccountArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    else
        return *arr[idx];
}
Account& AccountArray::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    else
        return *arr[idx];
}
