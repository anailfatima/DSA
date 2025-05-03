#include <iostream>
using namespace std;

class Employee{

public:
    virtual float calculateSalary(float s) = 0;
};




class FullTimeEmployee:public Employee{
    
public:
float calculateSalary(float s)
{
    return s;
}
};



class PartTimeEmployee:public Employee{

private:
    float r = 20;

public:
    float calculateSalary(float h)
    {
        float s = h * r;
        return s;
}
};

int main()
{
    FullTimeEmployee f;
    cout << "Full time employee salary : " << f.calculateSalary(2000) << endl;
    PartTimeEmployee p;
    cout << "Part time employee salary : " << p.calculateSalary(5) << endl;

    return 0;
}