#ifndef Account_hpp
#define Account_hpp

class Account
{
private:
    int acc_ID;
    char* Name;
    int Charges;
    
public:
    Account();
    Account(Account& copy);
    virtual ~Account();
    
    void SetAcc_ID(int id);
    void SetName(char* name);
    void SetCharges(int charges);
    
    int GetAcc_ID() const;
    char* GetName() const;
    int GetCharges() const;
    
    virtual void SetRate(int per);
    virtual void SetRank(int init);
    virtual int GetRate() const;
    virtual int GetRank() const;
};

#endif /* Account_hpp */
