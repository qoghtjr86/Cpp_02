#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
enum {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard
{
private:
    char* Name;
    char* cName;
    char* pNum;
    int Rank;
    
public:
    NameCard(const char* name, const char* cname, const char* pnum, int rank)
        :Name(NULL), cName(NULL), pNum(NULL), Rank(rank)
    {
        size_t len=strlen(name);
        Name=new char[len];
        strcpy(Name, name);
        
        size_t len2=strlen(cname);
        cName=new char[len2];
        strcpy(cName, cname);
        
        size_t len3=strlen(pnum);
        pNum=new char[len3];
        strcpy(pNum, pnum);
    }
    NameCard(NameCard& copy)
    {
        size_t len=strlen(copy.Name)+1;
        Name=new char[len];
        strcpy(Name, copy.Name);
        
        size_t len2=strlen(copy.cName)+1;
        cName=new char[len2];
        strcpy(cName, copy.cName);
        
        size_t len3=strlen(copy.pNum)+1;
        pNum=new char[len3];
        strcpy(pNum, copy.pNum);
        
        Rank=copy.Rank;
    }
    
    void rank_func(int rank)
    {
            switch (rank)
            {
                case 0:
                    cout<<"사원"<<endl;
                    break;
                case 1:
                    cout<<"주임"<<endl;
                    break;
                case 2:
                    cout<<"대리"<<endl;
                    break;
                case 3:
                    cout<<"과장"<<endl;
                    break;
                default:
                    break;
            }
    }
    
    
    void ShowNameCardInfo()
    {
        cout<<"이름: "<<Name<<endl;
        cout<<"회사: "<<cName<<endl;
        cout<<"전화번호: "<<pNum<<endl;
        cout<<"직급: ";
        rank_func(Rank);
        cout<<endl;
    }
    
    ~NameCard()
    {
        delete[] Name;
        delete[] cName;
        delete[] pNum;
    }
    
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1=manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2=manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}
