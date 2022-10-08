#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(const char* hisname, int hisage) : age(hisage)
    {
        name=new char[strlen(hisname)+1];
        strcpy(name, hisname);
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
    void ShowMyFriendInfo()
    {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(const char* hisname, int hisage, const char* hisaddr, const char* hisphone)
        : MyFriendInfo(hisname, hisage)
    {
        addr=new char[strlen(hisaddr)+1];
        strcpy(addr, hisaddr);
        phone=new char[strlen(hisphone)+1];
        strcpy(phone, hisphone);
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl<<endl;
    }
};

int main(void)
{
    MyFriendDetailInfo mfdi("Jesus", 33, "Heaven", "814-1004");
    mfdi.ShowMyFriendDetailInfo();
    return 0;
}
