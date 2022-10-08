#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int n) : gasolineGauge(n){}
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int n, int m) : Car(n), electricGauge(m){}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int n, int m, int j) : HybridCar(n, m), waterGauge(j){}
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main(void)
{
    HybridWaterCar hwc(10, 50, 100);
    hwc.ShowCurrentGauge();
    return 0;
}
