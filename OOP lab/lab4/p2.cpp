#include <iostream>
#include <cstring>
using namespace std;

class String{
private:
    int len;
    char *data = NULL;
public:
    String(const char *str = " "){
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
        data[len + 1] = '\0';
    }

    ~String(){
        delete [] data;
    }

    void join(const String &, const String &);
    void display(){
        cout << data << endl;
    }
};

void String::join(const String &s1, const String &s2){
    len = strlen(s1.data) + strlen(s2.data);
    if (data) delete [] data;
    data = new char[len + 1];
    strcpy(data, s1.data);
    strcat(data, s2.data);
    data[len + 1] = '\0';
}

int main(){
    String s1("Engineers are ");
    String s2("Creatures of logic");
    String s3;

    //concatenate two strings
    s3.join(s1, s2);
    //displaying the concatenated string
    s3.display();

    cout << endl;
    return 0;
}
