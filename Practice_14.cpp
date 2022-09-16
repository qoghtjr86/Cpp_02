#include <iostream>
using namespace std;

class Calculator
{
private:
    int Add_count;
    int Min_count;
    int Mul_count;
    int Div_count;
    double x;
    double y;
    
public:
    void Init();
    double Add(double x, double y);
    double Min(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
    void ShowOpCount();
};

void Calculator::Init()
{
    Add_count=0;
    Min_count=0;
    Mul_count=0;
    Div_count=0;
    x=0.0;
    y=0.0;
}

double Calculator::Add(double x, double y)
{
    Add_count++;
    return x+y;
}

double Calculator::Min(double x, double y)
{
    Min_count++;
    return x-y;
}

double Calculator::Mul(double x, double y)
{
    Mul_count++;
    return x*y;
}

double Calculator::Div(double x, double y)
{
    Div_count++;
    return x/y;
}

void Calculator::ShowOpCount()
{
    cout<<"덧셈: "<<Add_count<<' ';
    cout<<"뺄셈: "<<Min_count<<' ';
    cout<<"곱셈: "<<Mul_count<<' ';
    cout<<"나눗셈: "<<Div_count<<endl;
}

int main()
{
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}
