#include <iostream>
#include <string>

using namespace std;

// same interface for both classes
class Interface //pure virtual
{
  public:
    virtual void retrieve(string s) = 0; 
};

// Real object
class DB: public Interface
{
  public:
    void retrieve(string s) 
    {
      //compose a message to return to the client
        cout << "connecing to Database..." << '\n';
        int num = s.find_first_of(' ');
        string key = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        key = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_last_of(' ');
        string table = s.substr(num+1, s.size());
        cout << "retrieve " << key << " from " << table << ":" << endl;
        cout << "01 10 00 11 10 01 11 00 11 01 10 11 00" << endl;
    }
};

// Proxy
class ODBC: public Interface 
{
    string url, query;
    DB *ptr; // direct reference to the real object
  public:
    ODBC()
    {
        ptr = new DB(); //real object
    }
    ~ODBC()
    {
        delete ptr;
    }
    void connect(string s)
    {
        if(s != "https://csusm.edu:3306") {
            cout << "incorrect url, cannot connect to db at " << s << endl;
            url = "";
        } else {
            url = s;
        }
    }
    void retrieve(string s)
    {
        if(url == "") {
            cout << "cannot retrieve data due to disconnection" << endl;
            return;
        }
        query = s;
        cout << query << endl;
        ptr->retrieve(s); // redirects the request to the real object to get final result
    }
};

int main()
{
    ODBC db; // client only interacts with proxy
    db.connect("https://csusm.edu:3306");
    db.retrieve("select name from Table1");
}
