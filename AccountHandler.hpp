#ifndef AccountHandler_hpp
#define AccountHandler_hpp

#include "Account.hpp"

class AccountHandler
{
public:
    Account* arr[10];
    int cnt;
    
    AccountHandler();

    void ShowMenu() const;
    void ShowSubMenu() const;
    void CreateNormal();
    void CreateCredit();
    void Deposit();
    void WithDraw();
    void ShowInfo() const;
    void Exit();
    void Error();
};

#endif /* AccountHandler_hpp */
