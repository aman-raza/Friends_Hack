#include <iostream>
using namespace std;
double newtonRapsonMethod(double n)
{
    //! root=1/2 *  x+n/x
    // x is closest to ans so abs root-x is error
    // error should be low so error<1
    // |x-root| <1
    // so the value where the error is low is ans

    double root = 0.0;
    for (int x = 1; x < n; x++)
    {
        root = 0.5 * (x + n / x);
        if (abs(root - x) < 1)
            return root;
    }

    return -1;
}
int squareRoot(int n)
{
    int low = 1;
    int high = n;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // if (mid * mid == n)
        // {
        //     return mid;
        // }
        if (mid * mid > n)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    double n = 40;
    cout << newtonRapsonMethod(n);
}