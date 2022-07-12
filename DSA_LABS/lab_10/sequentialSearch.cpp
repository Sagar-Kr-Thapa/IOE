#include <iostream>
using namespace std;
const int N = 16;

int sequential1(int, int [], int);

int main()
{
    int Recs[N+1] = {0, 503, 87, 512, 061, 908, 170, 275, 653, 426, 154, 509, 612, 677, 90, 765, 703};
    int K = Recs[7];

    cout << sequential1(N, Recs, K);

}
int sequential1(int N, int Recs[], int K)
{
    int i = 1;
    do
    {
        if (Recs[i] == K)
        {
            return i;
        }
        ++i;
    } while (i <= N);
    cout << "not found";
    return 0;
}