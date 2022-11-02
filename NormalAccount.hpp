#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"
#include "BankingCommonDecl.hpp"

class NormalAccount: public Account
{
public:
    int rate;
    NormalAccount():Account(), rate(0){}
    
    virtual void SetStr(char* str) {String::SetStr(str);}
    virtual void SetAcc_ID(int id) {Account::SetAcc_ID(id);}
    virtual void SetName(char* name) {String::SetStr(name);}
    virtual void SetCharges(int charges) {Account::SetCharges(charges);}
    virtual void SetRate(int per) {rate=per;}
    virtual void SetRank(int init) {}
    virtual char* GetStr() const {return String::GetStr();}
    virtual int GetAcc_ID() const {return Account::GetAcc_ID();}
    virtual char* GetName() const {return String::GetStr();}
    virtual int GetCharges() const {return Account::GetCharges();}
    virtual int GetRate() const {return rate;}
    virtual int GetRank() const {return 0;}
};

#endif /* NormalAccount_hpp */
