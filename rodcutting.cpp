#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
int t, n;
//int price[9]={0,1,5,8,9,10,17,17,20};
int cnt = 0;
int done[9] = {0};
int value[9] = {0};
int cutrod(int price[], int n)
{
    //++cnt;
    if (n <= 0)
        return 0;
    int maxvalue = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        if (done[n - i])
            temp = value[n - i];
        else
            temp = cutrod(price, n - i), done[n - i] = true, value[n - i] = temp;
        maxvalue = max(maxvalue, price[i] + temp);
    }
    return maxvalue;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int price[n + 1];
        price[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> price[i];
        cout << cutrod(price, n) << endl;
    }

    return 0;
}