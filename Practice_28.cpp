#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    int GetBullet() const { return bullet; }
    void SetBullet(int bnum) { bullet=bnum; }
    void Shot()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if(bnum>0)
            pistol=new Gun(bnum);
        else
            pistol=NULL;
    }
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot()
    {
        if(pistol==NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shot();
    }
    Police& operator=(Police &ref)
    {
        handcuffs=ref.handcuffs;
        pistol->SetBullet(ref.pistol->GetBullet());
        return *this;
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    Police pman2(1, 3);
    pman2=pman1;
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}
