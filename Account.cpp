#include "Account.hpp"
#include "BankingCommonDecl.hpp"

Account::Account():String(NULL), acc_ID(0), Name(NULL), Charges(0){}
Account::Account(Account& copy)
:acc_ID(copy.acc_ID), Charges(copy.Charges)
{Name->SetStr(copy.Name->GetStr());}

void Account::SetStr(char* str) {String::SetStr(str);}
void Account::SetAcc_ID(int id) {acc_ID=id;}
void Account::SetName(char* name) {String::SetStr(name);}
void Account::SetCharges(int charges) {Charges=charges;}
void Account::SetRate(int per) {}
void Account::SetRank(int init) {}

char* Account::GetStr() const {return String::GetStr();}
int Account::GetAcc_ID() const {return acc_ID;}
char* Account::GetName() const {return String::GetStr();}
int Account::GetCharges() const {return Charges;}
int Account::GetRate() const {return 0;}
int Account::GetRank() const {return 0;}
