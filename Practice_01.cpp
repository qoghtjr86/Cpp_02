#include <iostream>

int main(void)
{
    int num = 0;
    int sum = 0;
    
    for(int i=1; i<6; i++)
    {
        std::cout<<i<<"번째 정수 입력: ";
        std::cin>>num;
        sum += num;
    }
    std::cout<<"합계: "<<sum<<std::endl;
    
    return 0;
}
