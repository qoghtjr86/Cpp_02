#include "AccountHandler.hpp"
#include "Account.hpp"
#include "AccountArray.hpp"
#include "NormalAccount.hpp"
#include "HighCreditAccount.hpp"
#include "BankingCommonDecl.hpp"

int cnt=0;

AccountHandler::AccountHandler()
{
    AccountArray(10);
}

void AccountHandler::ShowMenu() const
{
    cout<<"-----Menu------"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}
    
void AccountHandler::ShowSubMenu() const
{
    cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl;
}

void AccountHandler::CreateNormal()
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

void AccountHandler::CreateCredit()
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

void AccountHandler::Deposit()
{
    int ID;
    cout<<"계좌ID: ";cin>>ID;
    for(int i=0; i<10; i++)
    {
        if(arr[i]->GetAcc_ID() == ID)
        {
            int money=0;
            int rate=arr[i]->GetRate();
            int rank=arr[i]->GetRank();
            int charges=arr[i]->GetCharges();
            cout<<"입금액: ";cin>>money;
            money+=money*(rate+rank)/100+charges;
            arr[i]->SetCharges(money);
            cout<<"입금완료"<<endl;
            break;
        }
        else
        {
            continue;
        }
    }
}

void AccountHandler::WithDraw()
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

void AccountHandler::ShowInfo() const
{
    cout<<endl<<"[전체 계좌정보]"<<endl;
    for(int i=0; i<10; i++)
    {
        if(arr[i]->GetAcc_ID()>0)
        {
            cout<<"계좌ID: "<<arr[i]->GetAcc_ID()<<endl;
            cout<<"이 름: "<<arr[i]->GetName()<<endl;
            cout<<"잔 액: "<<arr[i]->GetCharges()<<endl;
            cout<<"이자율: "<<arr[i]->GetRate()<<endl;
            cout<<endl;
        }
        else
            break;
    }
}

void AccountHandler::Exit()
{
    for(int i=0; i<10; i++)
    {
        if(arr[i]->GetAcc_ID()>0)
        {
            delete []arr[i]->GetName();
            continue;
        }
        else
            break;
    }
    cout<<"프로그램을 종료합니다."<<endl;
}

void AccountHandler::Error() const
{
    cout<<"잘못 입력하셨습니다."<<endl;
}

