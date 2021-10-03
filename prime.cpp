#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool checkPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            return false;
    }
    return true;
}
void sieveOfEran(int n)
{   // time complexity
    // n * log(log(n))
    bool arr[n + 1];
    memset(arr, true, n + 1);

    for (int i = 2; i * i <= n; i++)
    {
        cout << " i" << i << ":" << arr[i] << endl;
        if (arr[i] == true)
        {
            for (int j = 2 * i; j <= n; j = j + i)
            {
                arr[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << ":" << arr[i];
        cout << "\n";
    }
}
int main()
{
    int n = 12;
    sieveOfEran(10);
}
