#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"
#include "BankingCommonDecl.hpp"

class NormalAccount: public Account
{
private:
    int rate;
public:
    NormalAccount():Account(), rate(0){}
    NormalAccount(int id, const char* name, int charges, int rate)
    :Account(id, name, charges), rate(rate){}
    
    virtual void SetRate(int per) {rate=per;}
    virtual void SetRank(int init) {}
    virtual int GetRate() const {return rate;}
    virtual int GetRank() const {return 0;}
};

#endif /* NormalAccount_hpp */
