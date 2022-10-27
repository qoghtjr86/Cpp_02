#include "Account.hpp"
#include "BankingCommonDecl.hpp"

Account::Account(){}

Account::Account(int id, const char* name, int charges):acc_ID(id), Charges(charges)
{Name=new char[strlen(name)+1]; strcpy(Name, name);}

Account::Account(Account& copy):acc_ID(copy.acc_ID), Charges(copy.Charges)
{Name=new char[strlen(copy.Name)+1]; strcpy(Name, copy.Name);}

Account& Account::operator=(Account &ref)
{
    this->SetAcc_ID(ref.GetAcc_ID());
    this->SetName(ref.GetName());
    this->SetCharges(ref.GetCharges());
    return *this;
}

void Account::SetAcc_ID(int id) {acc_ID=id;}
void Account::SetName(char* name) {Name=new char[strlen(name)+1]; strcpy(Name, name);}
void Account::SetCharges(int charges) {Charges=charges;}

int Account::GetAcc_ID() const {return acc_ID;}
char* Account::GetName() const {return Name;}
int Account::GetCharges() const {return Charges;}

void Account::SetRate(int per) {}
void Account::SetRank(int init) {}
int Account::GetRate(){return 0;}
int Account::GetRank(){return 0;}
