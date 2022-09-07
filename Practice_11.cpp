#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[20]="My String";
    char str2[20]="";
    size_t length = strlen(str1);
    int comp=strcmp(str2, str1);
    strcpy(str2, str1);
    strcat(str1, " in C++");

    cout<<"strlen: "<<length<<endl;
    cout<<"strcpy: "<<str2<<endl;
    cout<<"strcmp: "<<comp<<endl;
    cout<<"strcat: "<<str1<<endl;
    return 0;
}
