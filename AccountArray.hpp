#ifndef AccountArray_hpp
#define AccountArray_hpp

#include "HighCreditAccount.hpp"
#include "BankingCommonDecl.hpp"

class AccountArray: public HighCreditAccount
{
public:
    Account** arr;
    int arrlen;
    
    AccountArray();
    AccountArray(int len);
    Account& operator[] (int idx);
    Account& operator[] (int idx) const;
    
    virtual void SetStr(char* str) {String::SetStr(str);}
    virtual void SetAcc_ID(int id) {Account::SetAcc_ID(id);}
    virtual void SetName(char* name) {String::SetStr(name);}
    virtual void SetCharges(int charges) {Account::SetCharges(charges);}
    virtual void SetRate(int per) {NormalAccount::SetRate(per);}
    virtual void SetRank(int init) {HighCreditAccount::SetRank(init);}
    virtual char* GetStr() const {return String::GetStr();}
    virtual int GetAcc_ID() const {return Account::GetAcc_ID();}
    virtual char* GetName() const {return String::GetStr();}
    virtual int GetCharges() const {return Account::GetCharges();}
    virtual int GetRate(){return NormalAccount::GetRate();}
    virtual int GetRank(){return HighCreditAccount::GetRank();}
};


#endif /* AccountArray_hpp */
