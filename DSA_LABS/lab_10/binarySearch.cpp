#include <iostream>
using namespace std;

int binarySearch(int, int [], int);
int binarySearch_Recursive(int [], int , int, int);

int main()
{
    const int N = 16;
    int Records[N+1] = {0, 11, 87, 51, 61, 90, 170, 275, 353, 426, 554, 609, 612, 677, 690, 765, 806};
    int Km = Records[7];

    cout << binarySearch(N, Records, Km);
    cout << endl << endl;
    cout << binarySearch_Recursive(Records, 0, N-1, Km );

}

int binarySearch(int N, int Records[], int Km)
{
    int l = 1; 
    int u = N;
    
    while (u >= l)
    {
        int i = (u+l)>>1;
        if (Records[i] == Km)
        {
            return i;
        }
        else
        {
            if (Records[i] > Km)
            {
                u = i+1;
            }
            else
            {
                l = i-1;
            }
        }
    }
}

int binarySearch_Recursive(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch_Recursive(arr, l, mid - 1, x);

        return binarySearch_Recursive(arr, mid + 1, r, x);
    }
  
    return -1;
}