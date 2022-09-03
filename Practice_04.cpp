#include <iostream>

int main()
{
    int val = 0;
    double pay = 0.0;
    while(true)
    {
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>val;
        if(val == -1)
            break;
        pay = 50 + (val*0.12);
        std::cout<<"이번 달 급여: "<<pay<<"만원"<<std::endl;
    }
    std::cout<<"프로그램을 종료합니다."<<std::endl;
    return 0;
}
