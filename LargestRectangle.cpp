//Find the largest rectangle in a histogram.
#include <bits/stdc++.h>

using namespace std;

int max_area(vector<int> a)
{
    stack<int> st;
    int n = a.size(), i = 0, ans = 0;
    a.push_back(0);
    while (i < n)
    {
        while (!st.empty() and a[st.top()] > a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();
            if (st.empty())
            {
                ans = max(ans, h * i);
            }
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    vector<int> a = {2, 1, 5, 6, 2, 3};
    cout << max_area(a);

    return 0;
}