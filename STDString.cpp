#include <iostream>
#include <string>
using namespace std;

class String
{
private:
    char* Str;
public:
    String():Str(NULL){}
    String(const char* str)
    {Str=new char[strlen(str)+1];strcpy(Str, str);}
    String(String& ref)
    {Str=new char[strlen(ref.Str)+1];strcpy(Str, ref.Str);}
    ~String(){delete []Str;}
    
    char* GetStr(){return Str;}
    void SetStr(const char* str){Str=new char[strlen(str)+1];strcpy(Str, str);}
    
    String& operator=(String& ref)
    {Str=new char[strlen(ref.Str)+1];strcpy(Str, ref.Str);return *this;}
    
    char* operator+(String& ref)
    {
        char* pStr=new char[strlen(ref.Str)+strlen(this->Str)+2];
        strcpy(pStr, this->Str);
        strcat(pStr, ref.Str);
        return pStr;
    }
    
    String& operator+=(String& ref)
    {strcat(Str, ref.Str);return *this;}
    
    bool operator==(String& ref)
    {
        int result=strcmp(Str, ref.Str);
        if(result==1)return true;
        else return false;
    }
    
    friend ostream& operator<<(ostream& os, String& ref);
    friend istream& operator>>(istream& is, String& ref);
    
};

ostream& operator<<(ostream& os, String& ref)
{printf("%s", ref.GetStr());return os;}

istream& operator>>(istream& is, String& ref)
{char* str=new char[50];scanf("%s", str);ref.Str=str;return is;}

int main(void)
{
    String str1="I like ";
    String str2="string class";
    String str3=str1+str2;
    
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    
    str1+=str2;
    if(str1==str2)
        cout<<"동일 문자열!"<<endl;
    else
        cout<<"동일하지 않은 문자열!"<<endl;
    
    String str4;
    cout<<"문자열 입력: ";
    cin>>str4;
    cout<<"입력한 문자열: "<<str4<<endl;
    return 0;
}
