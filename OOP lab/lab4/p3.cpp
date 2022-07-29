#include <iostream>
#include <string>
using namespace std;

class Department{
private:
    int id;
    string name;
public:
    Department(int i=0, string n="Civil"):id(i)
    {
        name=n;
        cout << "Object "<< name << " has been constructed"<< endl;
    }
    ~Department()
    {
        cout << "Object "<< name << " goes out of scope" << endl;
    }
};

int main()
{
    //construction
    Department one(1,"Computer Science");
    Department two(2,"Electrical");
    Department three(3,"Mechanical");

    cout<<endl;

    //destruction at the end of the program
    return 0;
}
