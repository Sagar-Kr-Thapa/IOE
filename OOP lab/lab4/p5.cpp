#include <iostream>
using namespace std;

class Test{
private:
    int num;
public:
    Test(int n=0):num(n){}

    int const_get()const{
        return num;
    }

    int get(){
        return num;
    }
};

int main(){
    const Test obj1(12); //constant object
    Test obj2(23); //non-constant object

    //cout<<"const_object.non_const_mem_function: "<<obj1.get()<<endl;
    cout<<"\"const_object.const_mem_function\" gave the value: "<<obj1.const_get()<<endl;
    cout<<"\"non_const_object.non_const_mem_function\" gave the value: "<<obj2.get()<<endl;
    cout<<"\"non_const_object.const_mem_function\" gave the value: "<<obj2.const_get()<<endl;

    return 0;
}
