#include <iostream>
#include <vector>

using namespace std;

//Interface
class AlarmListener
{
  public:
    virtual void alarm() = 0;
};

// Subject
class SensorSystem
{
    vector < AlarmListener * > listeners;
  public:
    void attach(AlarmListener *al) // adding more observers
    {
        listeners.push_back(al);
    }
    void soundTheAlarm() // notify observers
    {
        for (int i = 0; i < listeners.size(); i++)
          listeners[i]->alarm(); //go through the list of observers and call their update method
    }
};

// observer / listener
class Lighting: public AlarmListener
{
  public:
     /*virtual*/void alarm()
    {
        cout << "lights up" << '\n';
    }
};

// observer / listener
class Gates: public AlarmListener
{
  public:
     /*virtual*/void alarm()
    {
        cout << "gates close" << '\n';
    }
};

class CheckList
{
    virtual void localize()
    {
        cout << "   establish a perimeter" << '\n';
    }
    virtual void isolate()
    {
        cout << "   isolate the grid" << '\n';
    }
    virtual void identify()
    {
        cout << "   identify the source" << '\n';
    }
  public:
    void byTheNumbers() // different pattern
    {
        // Template Method design pattern
        localize();
        isolate();
        identify();
    }
};
// observer / listener
// class inheri.  // type inheritance
class Surveillance: public CheckList, public AlarmListener
{
     /*virtual*/void isolate()
    {
        cout << "   train the cameras" << '\n';
    }
  public:
     /*virtual*/void alarm() 
    {
        cout << "Surveillance - by the numbers:" << '\n';
        byTheNumbers();
    }
};

int main()
{
  SensorSystem ss; //define Subject

  // add listeners
  ss.attach(new Gates());
  ss.attach(new Lighting());
  ss.attach(new Surveillance());

  // notify listeners 
  ss.soundTheAlarm();
}
