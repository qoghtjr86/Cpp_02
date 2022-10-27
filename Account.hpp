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
    Account(int id, const char* name, int charges);
    Account(Account& copy);
    Account& operator=(Account &ref);
    
    void SetAcc_ID(int id);
    void SetName(char* name);
    void SetCharges(int charges);
    
    int GetAcc_ID() const;
    char* GetName() const;
    int GetCharges() const;
    
    virtual void SetRate(int per);
    virtual void SetRank(int init);
    virtual int GetRate();
    virtual int GetRank();
    
};

#endif /* Account_hpp */
