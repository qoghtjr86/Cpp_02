#ifndef AccountHandler_hpp
#define AccountHandler_hpp

#include "Account.hpp"
#include "AccountArray.hpp"

class AccountHandler: public AccountArray
{
public:
    int cnt;
    
    AccountHandler();
    
    Account& operator=(NormalAccount* ref);
    Account& operator=(HighCreditAccount* ref);

    void ShowMenu() const;
    void ShowSubMenu() const;
    void CreateNormal();
    void CreateCredit();
    void Deposit();
    void WithDraw();
    void ShowInfo();
    void Exit();
    void Error();
};

#endif /* AccountHandler_hpp */
