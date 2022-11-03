#ifndef ArrayTemplate_hpp
#define ArrayTemplate_hpp

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename P>
class BoundChechPointPtrArray
{
private:
    P* arr;
    int arrlen;
    
    BoundChechPointPtrArray(const BoundChechPointPtrArray& arr) { }
    BoundChechPointPtrArray& operator=(const BoundChechPointPtrArray& arr) { return *this; }
    
public:
    BoundChechPointPtrArray(int len);
    P& operator[] (int idx);
    P operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundChechPointPtrArray();
};

template <typename P>
BoundChechPointPtrArray<P>::BoundChechPointPtrArray(int len) :arrlen(len)
{
    arr=new P[len];
}

template <typename P>
P& BoundChechPointPtrArray<P>::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename P>
P BoundChechPointPtrArray<P>::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template <typename P>
int BoundChechPointPtrArray<P>::GetArrLen() const { return arrlen; }

template <typename P>
BoundChechPointPtrArray<P>::~BoundChechPointPtrArray() { delete []arr; }

#endif /* ArrayTemplate_hpp */
