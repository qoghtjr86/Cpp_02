#ifndef HighCreditAccount_hpp
#define HighCreditAccount_hpp

#include "NormalAccount.hpp"

class HighCreditAccount: public NormalAccount
{
private:
    int rank;
public:
    HighCreditAccount()
    :NormalAccount(), rank(0){}
    HighCreditAccount(int id, char* name, int charges, int rate, int rank)
    :NormalAccount(id, name, charges, rate), rank(rank){}
    
    virtual void SetRate(int per) {NormalAccount::SetRate(per);}
    virtual void SetRank(int init)
    {if(init==1)rank=7; else if(init==2)rank=4; else rank=2;}
    virtual int GetRate() const {return NormalAccount::GetRate();}
    virtual int GetRank() const {return rank;}
};

#endif /* HighCreditAccount_hpp */
