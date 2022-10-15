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
    
public:
    Account():acc_ID(0), Name(NULL), Charges(0){}

    Account(Account& copy):acc_ID(copy.acc_ID), Charges(copy.Charges)
    {Name=new char[strlen(copy.Name)+1]; strcpy(Name, copy.Name);}
    
    virtual ~Account(){delete []Name;}
    
    void SetAcc_ID(int id) {acc_ID=id;}
    void SetName(char* name) {Name=new char[strlen(name)+1]; strcpy(Name, name);}
    void SetCharges(int charges) {Charges=charges;}
    
    int GetAcc_ID() const {return acc_ID;}
    char* GetName() const {return Name;}
    int GetCharges() const {return Charges;}
    
    virtual void SetRate(int per) {}
    virtual void SetRank(int init) {}
    virtual int GetRate() const {return 0;}
    virtual int GetRank() const {return 0;}
};


class NormalAccount: public Account
{
private:
    int rate;
public:
    NormalAccount()
    :Account(), rate(0){}
    
    virtual void SetRate(int per) {rate=per;}
    virtual void SetRank(int init) {}
    
    virtual int GetRate() const {return rate;}
    virtual int GetRank() const {return 0;}
};

class HighCreditAccount: public NormalAccount
{
private:
    int rank;
public:
    HighCreditAccount()
    :NormalAccount(), rank(0){}
 
    virtual void SetRank(int init)
    {if(init==1)rank=7; else if(init==2)rank=4; else rank=2;}
    virtual int GetRank() const {return rank;}
};

class AccountHandler
{
public:
    Account* arr[10];
    int cnt;
    
    AccountHandler():cnt(0){}

    void ShowMenu() const
    {
        cout<<"-----Menu------"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;
    }
    
    void ShowSubMenu() const
    {
        cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl;
    }
    
    void CreateNormal()
    {
        int id=0;
        char name[20]="";
        int charges=0;
        int per=0;
        Account* na=new NormalAccount();
        cout<<"[보통예금계좌 개설]"<<endl;
        cout<<"계좌ID: ";cin>>id;na->SetAcc_ID(id);
        cout<<"이 름: ";cin>>name;na->SetName(name);
        cout<<"입금액: ";cin>>charges;na->SetCharges(charges);
        cout<<"이자율: ";cin>>per;na->SetRate(per);
        cout<<"입금완료"<<endl;
        arr[cnt]=na;
        cnt++;
    }
    
    void CreateCredit()
    {
        int id=0;
        char name[20]="";
        int charges=0;
        int per=0;
        int init=0;
        Account* hca=new HighCreditAccount();
        cout<<"[신용신뢰계좌 개설]"<<endl;
        cout<<"계좌ID: ";cin>>id;hca->SetAcc_ID(id);
        cout<<"이 름: ";cin>>name;hca->SetName(name);
        cout<<"입금액: ";cin>>charges;hca->SetCharges(charges);
        cout<<"이자율: ";cin>>per;hca->SetRate(per);
        cout<<"신용등급(1toA, 2toB, 3toC): ";cin>>init;hca->SetRank(init);
        cout<<"입금완료"<<endl;
        arr[cnt]=hca;
        cnt++;

    }
    
    void Deposit()
    {
        int ID;
        cout<<"계좌ID: ";cin>>ID;
        for(int i=0; i<10; i++)
        {
            if(arr[i]->GetAcc_ID() == ID)
            {
                int money=0;
                int result=0;
                cout<<"입금액: ";cin>>money;
                if(arr[i]->GetRank()!=0)
                    result=(money/100)*(arr[i]->GetRate()+arr[i]->GetRank())+money+arr[i]->GetCharges();
                else
                    result=(money/100)*arr[i]->GetRate()+money+arr[i]->GetCharges();
                arr[i]->SetCharges(result);
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
            if(arr[i]->GetAcc_ID() == ID)
            {
                int money=0;
                int result=0;
                cout<<"출금액: ";cin>>money;
                result=arr[i]->GetCharges()-money;
                arr[i]->SetCharges(result);
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
            if(arr[i]->GetName()!=nullptr)
            {
                cout<<"계좌ID: "<<arr[i]->GetAcc_ID()<<endl;
                cout<<"이 름: "<<arr[i]->GetName()<<endl;
                cout<<"잔 액: "<<arr[i]->GetCharges()<<endl;
                cout<<"이자율: "<<arr[i]->GetRate()<<endl;
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
            if(arr[i]->GetAcc_ID()!=0)
                delete []arr[i]->GetName();
            else
                break;
        }
        cout<<"프로그램을 종료합니다."<<endl;
    }

    void Error()
    {
        cout<<"잘못 입력하셨습니다."<<endl;
    }
};

int main()
{
    int mainsel=0;
    int subsel=0;
    while(mainsel!=5)
    {
        AccountHandler a;
        a.ShowMenu();
        cout<<"선택: ";cin>>mainsel;
        switch (mainsel) {
            case CREATE:
            {
                a.ShowSubMenu();
                cout<<"선택: ";cin>>subsel;
                if(subsel==1)
                    a.CreateNormal();
                else
                    a.CreateCredit();
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
