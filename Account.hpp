#ifndef Account_hpp
#define Account_hpp

#include "String.hpp"

class Account: public String
{
private:
    int acc_ID;
    String* Name;
    int Charges;
    
public:
    Account();
    Account(char* str, int id, String* name, int charges);
    Account(Account& copy);
    
    virtual void SetStr(char* str);
    virtual void SetAcc_ID(int id);
    virtual void SetName(char* name);
    virtual void SetCharges(int charges);
    virtual void SetRate(int per);
    virtual void SetRank(int init);
    
    virtual char* GetStr() const;
    virtual int GetAcc_ID() const;
    virtual char* GetName() const;
    virtual int GetCharges() const;
    virtual int GetRate() const;
    virtual int GetRank() const;
};

#endif /* Account_hpp */
