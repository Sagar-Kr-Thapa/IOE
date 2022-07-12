#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    unsigned int n;
    cout << "Enter size of dataset: ";
    cin >> n;

    float data[n][2];
    cout << "Enter data [x, y]\n";
    for (int i=0; i<n; ++i)
        cin >> data[i][0] >> data[i][1];

    float sumx = 0;
    float sumx2 = 0;
    float sumy = 0;
    float sumxy = 0;

    for (int i = 0; i < n; ++i) {
        sumx += data[i][0];
        //sumy += data[i][1];
        sumy += log(data[i][1]);

        sumx2 += data[i][0] * data[i][0];

        //sumxy += data[i][0] * data[i][1];
        sumxy += data[i][0] * log(data[i][1]);
    }

    float a = (sumy * sumx2 - sumx * sumxy) / ( n* sumx2 - sumx * sumx);
    float b = (sumxy *n - sumx * sumy) / ( n* sumx2 - sumx * sumx);

    a=exp(a);

    //cout << "Linear fit is y = " << a << " + (" << b << "x)" << endl;

    cout << "Exponential fit is y = " << a << " * e^(" << b << "x)" << endl;

}
