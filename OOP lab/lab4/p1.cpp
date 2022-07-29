#include <iostream>
using namespace std;

class _time{
private:
    int hour;
    int minutes;
    int seconds;
public:
    _time(int hr=0, int m=0, int sec=0):minutes(m), seconds(sec), hour(hr) {}

    _time add(_time t1){
        _time t;
        t.hour=hour+t1.hour;
        t.minutes=minutes+t1.minutes;
        t.seconds=seconds+t1.seconds;

        return t;
    }
    void display_12(){
        while (seconds >= 60){
                ++minutes;
                seconds -= 60;
        }
        while (minutes >=60){
                ++hour;
                minutes -= 60;
        }
        int temp=hour;
        if (hour%12==0){
            hour = 12;
        }else{
            hour %= 12;
        }
        cout<<"TIME "<< hour<<":"<<minutes<<":"<<seconds;
        hour=temp;
    }

    void display_24(){
        while (seconds >= 60){
                minutes++;
                seconds -= 60;
        }
        while (minutes >=60){
                hour++;
                minutes -= 60;
        }
        int temp=hour;
        if (hour%24==0){
            hour = 24;
        }else{
            hour %= 24;
        }
        cout<<"TIME "<< hour<<":"<<minutes<<":"<<seconds;
        hour=temp;
    }
};

int main(){
    	int hr, m, sec;
    	cout<<"Enter time in [hr:min:sec] format for first time object: ";
    	cin>>hr>>m>>sec;
    	_time t1(hr,m,sec);

    	cout<<"Enter time in [hr:min:sec] format for second time object: ";
    	cin>>hr>>m>>sec;
    	_time t2(hr,m,sec);
	
    	_time t3=t1.add(t2);
    	//displaying sum in 12 hr format
    	cout<<endl;

    	t3.display_12();
    	//displaying sum in 24 hr format
    	cout<<endl;
    	t3.display_24();

    	cout<<endl;
    	return 0;
}
