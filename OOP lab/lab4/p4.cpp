#include <iostream>
using namespace std;

class rent_a_car{
private:
    unsigned num_vehicle, hour, rate;
public:
    //copy constructors
    rent_a_car(unsigned nv=1, unsigned hr=1, unsigned r=1000): num_vehicle(nv), hour(hr), rate(r) {}
    rent_a_car(rent_a_car &data1){
        num_vehicle=data1.num_vehicle;
        hour=data1.hour;
        rate=data1.rate;
    }

    void display_total(){
        float total=num_vehicle*hour*rate;
        if (num_vehicle>10)total -= total * 0.1;

        cout<<"Total Charge: "<<total;
    }
};

int main(){
    int nv, hr, r;
    cout<<"Enter number of vehicles to rent: ";
    cin>>nv;
    cout<<"Enter number of hours: ";
    cin>>hr;
    cout<<"Enter rate: ";
    cin>>r;

    rent_a_car data1(nv, hr, r);
    rent_a_car data2=data1;

    //displaying total
    cout<<endl;
    data1.display_total();
    cout<<endl;
    data2.display_total();

    cout<<endl;
    return 0;
}
