#ifndef AccountHandler_hpp
#define AccountHandler_hpp

#include "Account.hpp"
#include "AccountArray.hpp"

class AccountHandler: public AccountArray
{
public:
    //int cnt;
    
    AccountHandler();
    
    void ShowMenu() const;
    void ShowSubMenu() const;
    void CreateNormal();
    void CreateCredit();
    void Deposit();
    void WithDraw();
    void ShowInfo() const;
    void Exit();
    void Error() const;
};

#endif /* AccountHandler_hpp */
