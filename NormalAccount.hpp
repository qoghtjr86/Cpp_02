#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"

class NormalAccount: public Account
{
private:
    int rate;
public:
    NormalAccount()
    :Account(), rate(0){}
    
    virtual void SetRate(int per) {rate=per;}
    virtual void SetRank(int init) {}
    
    virtual int GetRate() const {return rate;}
    virtual int GetRank() const {return 0;}
};

#endif /* NormalAccount_hpp */
