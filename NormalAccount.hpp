#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"

class NormalAccount: public Account
{
private:
    int rate;
public:
    NormalAccount():rate(0){}
    NormalAccount(int id, const char* name, int charges, int rate)
    :Account(id, name, charges), rate(rate){}
    
    NormalAccount& operator=(NormalAccount &ref)
    {
        this->SetAcc_ID(ref.GetAcc_ID());
        this->SetName(ref.GetName());
        this->SetCharges(ref.GetCharges());
        this->SetRate(ref.GetRate());
        return *this;
    }
    
    virtual void SetRate(int per) {rate=per;}
    virtual void SetRank(int init) {}
    
    virtual int GetRate(){return rate;}
    virtual int GetRank(){return 0;}
};

#endif /* NormalAccount_hpp */
