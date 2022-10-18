#include "AccountHandler.hpp"
#include "BankingCommonDecl.hpp"

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
