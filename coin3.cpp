#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int coins[]={1,2,5};
    int r=sizeof(coins)/sizeof(coins[0]);
    int amounts=11;
    int dp[amounts+1];
    dp[0]=0;
    for(int i=1;i<=amounts;i++)dp[i]=amounts+1;
    for(int i=1;i<=amounts;i++){
        for(int j=0;j<r;j++){
            if(i>=coins[j]){
                dp[i]=min(dp[i-coins[j]]+1,dp[i]);
            }
            cout<<"After "<<i<<" amounts "<<endl;             
            for(int k=0;k<=amounts;k++)cout<<dp[k]<<" ";
             cout<<endl;
        }
       
    }
    cout<<"The minimum coin needs "<<dp[amounts]<<endl;

    return 0;
}