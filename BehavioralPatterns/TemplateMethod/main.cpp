#include <iostream>
using namespace std;

class Base // Framework
{
    void a()
    {
        cout << "a  ";
    }
    void c()
    {
        cout << "c  ";
    }
    void e()
    {
        cout << "e  ";
    }
    // 2. Steps requiring peculiar implementations are "placeholders" in base class
    virtual void ph1() = 0;
    virtual void ph2() = 0;
  public:
    // 1. Standardize the skeleton of an algorithm in a base class "template method"
    void execute() // template method
    {
      // define the order of the steps
        a();
        ph1();
        c();
        ph2();
        e();
    }
};

//Derived Class
class One: public Base
{
    // 3. Derived classes implement placeholder methods
     /*virtual*/void ph1() //override virtual function
    {
        cout << "b  ";
    }
     /*virtual*/void ph2() //override virtual function
    {
        cout << "d  ";
    }
};
//Derived Class
class Two: public Base
{
     /*virtual*/void ph1() //override virtual function
    {
        cout << "2  ";
    }
     /*virtual*/void ph2() //override virtual function
    {
        cout << "4  ";
    }
};

int main()
{
  // Create 2 instances of the Framework Class defined as variables of the base class
  Base *array[] = { new One(), new Two() };
  for (int i = 0; i < 2; i++)
  {
    array[i]->execute();
    cout << '\n';
  }
}
