#include <iostream>
#include <string>

using namespace std;
//abstract base class
class Student{
public:

  virtual void setInfo() = 0;
  virtual void displayInfo() = 0;

protected:
  string name;
};

class Engineering: public Student{
public:
  void setInfo(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter your subject: ";
    cin >> engrS;
  }

  void displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Subject: " << engrS << endl;
  }
private:
  string engrS;
};

class Medicine: public Student{
public:
  void setInfo(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter your subject: ";
    cin >> MedS;
    cout << "Enter duration of course: ";
    cin >> Time;
  }

  void displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Subject: " << MedS << endl;
    cout << "Duration of course: " << Time << " years" << endl;
  }
protected:
  string MedS;
  float Time;
};

class Science: public Student{
public:
  void setInfo(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter your major: ";
    cin >> Sub;
  }

  void displayInfo(){
    cout << "Name: " << name << endl;
    cout << "Major: " << Sub << endl;
  }
protected:
  string Sub;
};

int main(){
  Student* sList[3];
  const char* field[] = {"Engineering", "Medicine" , "Science"};
  sList[0] = new Engineering();
  sList[1] = new Medicine();
  sList[2] = new Science();

  //setting user info
  for(int i = 0; i < 3; i++){
    cout << field[i] << endl;
    sList[i]->setInfo();
  }

  cout << endl << endl;
  //accessing user info
  for(int i = 0; i < 3; i++){
    cout << field[i] << endl;
    sList[i]->displayInfo();
    cout << endl;
  }

  cout << endl;

  delete sList[0];
  delete sList[1];
  delete sList[2];

  return 0;
}