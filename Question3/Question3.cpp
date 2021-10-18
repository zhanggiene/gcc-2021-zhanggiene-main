#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    //write your code here
    int result=0;
    for(int i=1;i<a.size();i++)
    {
        a[i]=a[i]+a[i-1];
    }

    for(int i=1;i<b.size();i++)
    {
        b[i]=b[i]+b[i-1];
    }
    for(int i=0;i<a.size();i++)
    {
        int otherSide=maxSum-a[i];
        if (otherSide<0) break;
        int index=upper_bound(b.begin(),b.end(),otherSide)-b.begin();
        result=max(result,i+index+1);
    }
    return result;

    
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}