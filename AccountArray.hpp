#ifndef AccountArray_hpp
#define AccountArray_hpp

#include "HighCreditAccount.hpp"
#include "BankingCommonDecl.hpp"

class AccountArray: public HighCreditAccount
{
public:
    Account* arr;
    int arrlen;
    
    AccountArray();
    AccountArray(int len);
    Account& operator[] (int idx);
    AccountArray& operator=(AccountArray &ref);
    
    virtual void SetRate(int per) {NormalAccount::SetRate(per);}
    virtual void SetRank(int init) {HighCreditAccount::SetRank(init);}
    
    virtual int GetRate(){return NormalAccount::GetRate();}
    virtual int GetRank(){return HighCreditAccount::GetRank();}
};

#endif /* AccountArray_hpp */
