#include <bits/stdc++.h>
using namespace std;
void Test(int x)
{
    if (x == 0)
    {
        throw(0);
    }
    if (x == 1)
    {
        throw('a');
    }
    if (x == -1)
    {
        throw(1.123);
    }
    else
    {
        cout << "Execution completed Successfully without any errors.\n\n";
    }
}
int main()
{
    int x;
    cout << "Enter the value of x" << endl;
    cin >> x;
    try
    {
        Test(x);
    }

    catch (int a)
    {
        cout << "Integer Exception occured!" << endl;
    }
    catch (char a)
    {
        cout << "Character Exception occured!" << endl;
    }
    catch (double a)
    {
        cout << "Double exception occured!" << endl;
    }

    //Default
    catch (...)
    {
        cout << "Some Unknow error has occured!" << endl;
    }

    return 0;
}
