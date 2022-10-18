#include "Account.hpp"
#include "BankingCommonDecl.hpp"

Account::Account():acc_ID(0), Name(NULL), Charges(0){}

Account::Account(Account& copy):acc_ID(copy.acc_ID), Charges(copy.Charges)
{Name=new char[strlen(copy.Name)+1]; strcpy(Name, copy.Name);}
    
Account::~Account(){delete []Name;}
    
void Account::SetAcc_ID(int id) {acc_ID=id;}
void Account::SetName(char* name) {Name=new char[strlen(name)+1]; strcpy(Name, name);}
void Account::SetCharges(int charges) {Charges=charges;}

int Account::GetAcc_ID() const {return acc_ID;}
char* Account::GetName() const {return Name;}
int Account::GetCharges() const {return Charges;}

void Account::SetRate(int per) {}
void Account::SetRank(int init) {}
int Account::GetRate() const {return 0;}
int Account::GetRank() const {return 0;}
