#include <iostream>

using namespace std;

//ORIGINAL interface
class I {
  public:
    virtual ~I(){}
    virtual void do_it() = 0; //only method
};

//base class window
class A: public I {
  public:
    void do_it() { //example fucntion that we want to improve on the decorator classes
        cout << "Hello ";
    }
};

// optional wrapper, window decorator
class D: public I {
  public:
    D(I *inner) {//maintains a reference to the original interface
        m_wrappee = inner; //all following classes assign wrapper to interface
    }
    ~D() {
        delete m_wrappee;
    }
    void do_it() { 
        m_wrappee->do_it(); 
    }
  private:
    I *m_wrappee; //can be any of the classes
};

//optional 1 - concrete  decorator for window objects
class X: public D { //inherits D
  public:
  //derived classes only inherits the parent default constructor 
    X(I *core): D(core){} //constructor using the parameter parent constructor
    void do_it() { //do method
        D::do_it(); //first calls D do method taht calls the fucntion of the wrappee first, than do something else on next line
        cout << "Dear "; // addition, decoration
    }
};

//optional 2- concrete decorator for  window objects
class Y: public D {
  public:
  //the parameter represents the object that is beign wrapped
    Y(I *core): D(core){} // call the parent constructor with parameter
    void do_it() {
        D::do_it(); // first calls the 
        cout << "Miss ";// addition, decoration
    }
};

//optional 3 - concrete decorator for window objects
class Z: public D {
  public:
    Z(I *core): D(core){}
    void do_it() {
        D::do_it();
        cout << "Kate ";
    }
};

//X, Y. Z are independent and can be composed together in many different ways, but all of them implemnt the same interfacee

int main() { 
  //wrapps objects
  I *anX = new X(new A); //wrapps A inside X // call constructor of calling class X and in the parameter it calls the constructor of the correspondly class D//wrappee is an instance of A
  I *anXY = new Y(new X(new A)); // wrapps A inside X, and X inside Y // X knows it needs a wrappee, but it does not matter which one
  I *anXYZ = new Z(new Y(new X(new A))); // wrapps A inside X, wrapps X inside Y, wrapps Y inside Z
  anX->do_it(); //Hello(from A) Dear (from X)
  cout << '\n';
  anXY->do_it(); // Hello Dear Miss
  cout << '\n';
  anXYZ->do_it(); // Hello Dear Miss Kate 
  // calling do_it calls wrappee do_it first in the do_it implementation. 
  // Z is called, that calls Y, that calls X, that calls A, then run A, run X, run Y, finally run Z
  cout << '\n';
  delete anX;
  delete anXY;
  delete anXYZ;
}
