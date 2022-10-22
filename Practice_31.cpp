#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheck2DIntArray
{
private:
    int** arr2d;
    int* arr;
    int xlen, ylen;
    int xidx, yidx;

public:
    BoundCheck2DIntArray(int x=0, int y=0) : xlen(x), ylen(y), xidx(x), yidx(y)
    {
        arr2d=new int*[xlen];
        arr=new int[ylen];
        for(int i=0; i<x; i++)
            arr2d[i]=arr;
    }
    BoundCheck2DIntArray& operator[] (int xidx)
    {
        return *this;
    }
    BoundCheck2DIntArray& operator=(int num)
    {
        int idx=xidx+yidx;
        arr[yidx]=idx;
        return *this;
    }
    int GetXlen() { return xlen; }
    int GetYlen() { return ylen; }
    int GetXidx() { return xidx; }
    int GetYidx() { return yidx; }
    void SetXidx(int x) { xidx=x; }
    void SetYidx(int y) { yidx=y; }
    
    friend ostream& operator<<(ostream& os, BoundCheck2DIntArray &ref);
    
    ~BoundCheck2DIntArray() { delete []arr2d; }
};

ostream& operator<<(ostream& os, BoundCheck2DIntArray &ref)
{
    os<<ref.xidx+ref.yidx<<endl;
    return os;
}

int main(void)
{
    BoundCheck2DIntArray arr2d(3, 4);
    
    for(int n=0; n<arr2d.GetXlen(); n++)
    {

        for(int m=0; m<arr2d.GetYlen(); m++)
        {
            arr2d.SetXidx(n);
            arr2d.SetYidx(m);
            ((arr2d.operator[](n)).operator[](m)).operator=(n+m);
        }
    }
    for(int n=0; n<arr2d.GetXlen(); n++)
    {

        for(int m=0; m<arr2d.GetYlen(); m++)
        {
            arr2d.SetXidx(n);
            arr2d.SetYidx(m);
            cout<<arr2d[n][m]<<' ';
        }
        cout<<endl;
    }
}
