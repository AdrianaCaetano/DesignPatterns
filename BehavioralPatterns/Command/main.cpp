#include <iostream>
#include <string>

using namespace std;

class Person;

class Command
{
    // 1. Create a class that encapsulates an object and a member function
    // a pointer to a member function (the attribute's name is "method")
    Person *object; //   targetObject
    void(Person:: *method)(); //targetMethod declaration (which method should be executed) = encapsulate method of receiver object
    // return type (name of the parameter: pointer to member fucntion) (parameters of returning function)
    // How to define a pointer to function in C++
    // void (Person:: *pmf) () = & Person::passOn; // target method initialized
  public:
  //special constructor (pointer to person object, pointer to member fucntion of that person object)
    Command(Person *obj = 0, void(Person:: *meth)() = 0) // = 0 not linked to any specific object
    {
        object = obj; // the argument's name is "meth"
        method = meth;
    }
    void execute()
    {
        (object->*method)(); // invoke the method on the corresponding object
    }
}; // end Command class

class Person //represents the receiver class (who does the real work)
{
    string name;

    // cmd is a "black box", it is a method invocation
    // promoted to "full object status"
    Command cmd;  // data member of type Command
  public:
    Person(string n, Command c): cmd(c)
    {
        name = n;
    }
    void talk()
    {
        // "this" is the sender, cmd has the receiver
        cout << name << " is talking" << endl;
        cmd.execute(); // ask the "black box" to callback the receiver
    }
    void passOn()
    {
        cout << name << " is passing on" << endl;
        
        // 4. When the sender is ready to callback to the receiver,
        // it calls execute()
        cmd.execute(); 
    }
    void gossip()
    {
        cout << name << " is gossiping" << endl;
        cmd.execute();
    }
    void listen()
    {
        cout << name << " is listening" << endl;
    }
};

int main()
{
  // Fred will "execute" Barney which will result in a call to passOn()
  // Barney will "execute" Betty which will result in a call to gossip()
  // Betty will "execute" Wilma which will result in a call to listen()
  Person wilma("Wilma", Command()); //create Wilma object (instance of Person) with Command that is not linked to any specific command
  // 2. Instantiate an object for each "callback"
  // 3. Pass each object to its future "sender"
  // Betty, Barney, and Fred have differnt Command parameters
  Person betty("Betty", Command(&wilma, &Person::listen)); // &Person::listen gets the address of the method = pointer to a member fucntion // Betty command is linked to Wilma listen command
  Person barney("Barney", Command(&betty, &Person::gossip));
  Person fred("Fred", Command(&barney, &Person::passOn));
  fred.talk();
}


   // How to define a pointer to function in C++
   int calc(int a, int b) {
     return a+b;
   }

   
  /*
  inside the class:
  int *pf(int a, int b) = &calc;
  */
