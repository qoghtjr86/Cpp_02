#include <iostream>

int main()
{
    int dan = 0;
    std::cout<<"구구단 단 수를 입력하세요: ";
    std::cin>>dan;
    for(int i=1; i<10; i++)
        std::cout<<dan<<"X"<<i<<"="<<dan*i<<std::endl;
    
    return 0;
}
