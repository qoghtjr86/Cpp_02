#ifndef HighCreditAccount_hpp
#define HighCreditAccount_hpp

#include "NormalAccount.hpp"

class HighCreditAccount: public NormalAccount
{
public:
    int rank;
    HighCreditAccount()
    :NormalAccount(), rank(0){}
    
    virtual void SetStr(char* str) {String::SetStr(str);}
    virtual void SetAcc_ID(int id) {Account::SetAcc_ID(id);}
    virtual void SetName(char* name) {String::SetStr(name);}
    virtual void SetCharges(int charges) {Account::SetCharges(charges);}
    virtual void SetRate(int per) {NormalAccount::SetRate(per);}
    virtual void SetRank(int init) {if(init==1)rank=7; else if(init==2)rank=4; else rank=2;}
    virtual char* GetStr() const {return String::GetStr();}
    virtual int GetAcc_ID() const {return Account::GetAcc_ID();}
    virtual char* GetName() const {return String::GetStr();}
    virtual int GetCharges() const {return Account::GetCharges();}
    virtual int GetRate() const {return NormalAccount::GetRate();}
    virtual int GetRank() const {return rank;}
};

#endif /* HighCreditAccount_hpp */
