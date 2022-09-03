#include <iostream>

int main(void)
{
    char name[30] = "";
    char pNum[12] = "";
    std::cout<<"이름을 입력하세요: ";
    std::cin>>name;
    std::cout<<"전화번호를 입력하세요: ";
    std::cin>>pNum;
    std::cout<<"이름은 "<<name<<"이고, 전화번호는 "<<pNum<<"입니다."<<std::endl;
    
    return 0;
}
