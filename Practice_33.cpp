#include <iostream>
using namespace std;

#define LEN 5

template <typename T>
T SumArray(T arr[], T len)
{
    T sum=0;
    for(int i=0; i<len; i++)
        sum+=arr[i];
    return sum;
}

int main(void)
{
    int arr[LEN]={1, 2, 3, 4, 5};
    int result=0;
    result=SumArray<int>(arr, LEN);
    cout<<result<<endl;
}
