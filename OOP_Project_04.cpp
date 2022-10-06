#include <iostream>
#include <cstring>
using namespace std;

enum {ERROR, CREATE, DEPOSIT, WITHDRAW, SHOWINFO, EXIT};

class Account
{
private:
    int acc_ID;
    char* Name;
    int Charges;
    size_t len;

public:
    static Account arr[10];
    static int cnt;
    Account()
    : acc_ID(0), Name(NULL), Charges(0), len(0)
    {
    }
    
    Account(Account& copy)
    :acc_ID(copy.acc_ID), Charges(copy.Charges)
    {
        len=strlen(copy.Name)+1;
        Name=new char[len];
        strcpy(Name, copy.Name);
    }
    
    void ShowMenu() const
    {
        cout<<"-----Menu------"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;
    }
    
    void Create()
    {
        char name[20]="";
        cout<<"[계좌개설]"<<endl;
        cout<<"계좌ID: ";cin>>acc_ID;
        cout<<"이 름: ";cin>>name;
        char* pstr = name;
        len=strlen(pstr)+1;
        Name=new char[len];
        strcpy(Name, pstr);
        cout<<"입금액: ";cin>>Charges;
        cout<<"입금완료"<<endl;
        Account::arr[cnt]=*this;
        cnt++;
    }
    
    void Deposit()
    {
        int ID;
        cout<<"계좌ID: ";cin>>ID;
        for(int i=0; i<10; i++)
        {
            if(Account::arr[i].acc_ID == ID)
            {
                int money;
                cout<<"입금액: ";cin>>money;
                Account::arr[i].Charges += money;
                cout<<"입금완료"<<endl;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    
    void WithDraw()
    {
        int ID;
        cout<<"계좌ID: ";cin>>ID;
        for(int i=0; i<10; i++)
        {
            if(Account::arr[i].acc_ID == ID)
            {
                int money;
                cout<<"출금액: ";cin>>money;
                Account::arr[i].Charges -= money;
                cout<<"출금완료"<<endl;
                break;
            }
            else
            {
                continue;
            }
        }
    }
  
    void ShowInfo() const
    {
        cout<<endl<<"[전체 계좌정보]"<<endl;
        for(int i=0; i<10; i++)
        {
            if(Account::arr[i].Name != NULL)
            {
                cout<<"계좌ID: "<<Account::arr[i].acc_ID<<endl;
                cout<<"이 름: "<<Account::arr[i].Name<<endl;
                cout<<"잔 액: "<<Account::arr[i].Charges<<endl;
                cout<<endl;
                continue;
            }
            else
                break;
        }
    }
    
    void Exit()
    {
        for(int i=0; i<10; i++)
        {
            if(Account::arr[i].acc_ID != 0)
            {
                delete []Account::arr[i].Name;
            }
            else
            {
                cout<<"프로그램을 종료합니다."<<endl;
                break;
            }
        }
    }

    void Error()
    {
        cout<<"잘못 입력하셨습니다."<<endl;
    }
};
Account Account::arr[10]={};
int Account::cnt=0;

int main()
{
    int select=0;
    while(select!=5)
    {
        Account a;
        a.ShowMenu();
        cout<<"선택: ";cin>>select;
        switch (select) {
            case CREATE:
            {
                a.Create();
                break;
            }
            case DEPOSIT:
            {
                a.Deposit();
                break;
            }
            case WITHDRAW:
            {
                a.WithDraw();
                break;
            }
            case SHOWINFO:
            {
                a.ShowInfo();
                break;
            }
            case EXIT:
            {
                a.Exit();
                break;
            }
            default:
            {
                a.Error();
                break;
            }
        }
    }
}
