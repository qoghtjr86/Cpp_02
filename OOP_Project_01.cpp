#include <iostream>
using namespace std;

struct Account
{
    int acc_ID = 0;
    char name[30] = "";
    int charges = 0;
};

Account arr[100] = {};
int num = 0;

enum {ERROR, CREATE, DEPOSIT, WITHDRAW, SHOWINFO, EXIT};

void ShowMenu()
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
    Account a;
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";cin>>a.acc_ID;
    cout<<"이 름: ";cin>>a.name;
    cout<<"입금액: ";cin>>a.charges;
    cout<<"입금완료"<<endl;
    arr[num] = a;
    num++;
}

void Deposit()
{
    int ID;
    cout<<"계좌ID: ";cin>>ID;
    for(int i=0; i<10; i++)
        if(arr[i].acc_ID == ID)
        {
            int money;
            cout<<"입금액: ";cin>>money;
            arr[i].charges += money;
            cout<<"입금완료"<<endl;
            break;
        }
        else
        {
            continue;
        }
}

void WithDraw()
{
    int ID;
    cout<<"계좌ID: ";cin>>ID;
    for(int i=0; i<10; i++)
        if(arr[i].acc_ID == ID)
        {
            int money;
            cout<<"출금액: ";cin>>money;
            arr[i].charges -= money;
            cout<<"출금완료"<<endl;
            break;
        }
        else
        {
            continue;
        }
}

void ShowInfo()
{
    cout<<endl<<"[전체 계좌정보]"<<endl;
    for(int i=0; i<10; i++)
        if(arr[i].acc_ID != 0)
        {
            cout<<"계좌ID: "<<arr[i].acc_ID<<endl;
            cout<<"이 름: "<<arr[i].name<<endl;
            cout<<"잔 액: "<<arr[i].charges<<endl;
            cout<<endl;
        }
        else
            break;
}

void Exit()
{
    cout<<"프로그램을 종료합니다."<<endl;
}

void Error()
{
    cout<<"잘못 입력하셨습니다."<<endl;
}

int main()
{
    int select = 0;
    while(select != 5)
    {
        ShowMenu();
        cout<<"선택: ";cin>>select;
        switch (select) {
            case CREATE:
                Create();
                break;
            case DEPOSIT:
                Deposit();
                break;
            case WITHDRAW:
                WithDraw();
                break;
            case SHOWINFO:
                ShowInfo();
                break;
            case EXIT:
                Exit();
                break;
            default:
                Error();
                break;
        }
    }
}
