#include <iostream>
using namespace std;

struct client
{
    int account_num = 0;
    char name[30] = "";
    int charges = 0;
};

client Create()
{
    client a;
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>a.account_num;
    cout<<"이 름: ";
    cin>>a.name;
    cout<<"입금액: ";
    cin>>a.charges;
    cout<<"입금완료"<<endl;
    return a;
}

void Add(client arr[], int idx)
{
    int money;
    cout<<"입금액: ";
    cin>>money;
    arr[idx].charges += money;
    cout<<"입금완료"<<endl;
}

void Take(client arr[], int idx)
{
    int money;
    cout<<"출금액: ";
    cin>>money;
    arr[idx].charges -= money;
    cout<<"출금완료"<<endl;
}

void Info(client arr[])
{
    for(int i=0; i<10; i++)
        if(arr[i].account_num != 0)
        {
            cout<<"계좌ID: "<<arr[i].account_num<<endl;
            cout<<"이 름: "<<arr[i].name<<endl;
            cout<<"잔 액: "<<arr[i].charges<<endl;
        }
        else
            break;
}

int main()
{
    client arr[10] = {};
    int sel = 0;
    
    while(sel != 5)
    {
        cout<<"-----Menu------"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;
        cout<<"선택: ";
        cin>>sel;
        switch (sel) {
            case 1:
                {
                cout<<"계좌를 개설합니다."<<endl;
                for(int i=0; i<10; i++)
                    if(arr[i].account_num == 0)
                    {
                        arr[i] = Create();
                        break;
                    }
                    else
                        continue;
                }
                break;
            case 2:
                {
                cout<<"입금 화면입니다."<<endl;
                cout<<"계좌ID: ";
                int id;
                cin>>id;
                for(int i=0; i<10; i++)
                    if(arr[i].account_num == id)
                        Add(arr, i);
                }
                break;
            case 3:
                {
                cout<<"출금 화면입니다."<<endl;
                cout<<"계좌ID: ";
                int id;
                cin>>id;
                for(int i=0; i<10; i++)
                    if(arr[i].account_num == id)
                        Take(arr, i);
                }
                break;
            case 4:
                {
                cout<<"전체 계좌정보입니다."<<endl;
                Info(arr);
                }
                break;
            case 5:
                cout<<"프로그램을 종료합니다."<<endl;
                break;
            default:
                break;
        }
    }
    
}
