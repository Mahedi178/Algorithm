#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void knapsack(int p[],int w[],int m,int n)
{
    int k[n+1][m+1];
    cout<<"Profits are given for each weight"<<endl;
    for(int i=0;i<n;i++)cout<<p[i]<<" ";
    cout<<endl;
    cout<<"Weight of each bag is "<<endl;
    for(int i=0;i<n;i++)cout<<w[i]<<" ";
    cout<<endl;
    cout<<"Tabulation method is: "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)k[i][j]=0;
            else if(j>=w[i-1])k[i][j]=max(k[i-1][j],k[i-1][j-w[i-1]]+p[i-1]);
            else k[i][j]=k[i-1][j];
        }
        for(int t=0;t<=m;t++){
            cout<<k[i][t]<<" ";
        }
        cout<<endl;
    }

    int res=k[n][m];
    int j=m;
    stack<int>q;
    for(int i=n;i>0&res>0;i--){
        if(res==k[i-1][j])continue;
        else {
            q.push(w[i-1]);
            res=res-p[i-1];
            cout<<res<<" "<<endl;
            j=j-w[i-1];

        }
    }
    cout<<"Printing the weights for which the profit is maximum: "<<endl;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    } 

   
}



int main()
{
    int p[]={1,4,4,5,7};//this are profits
    int w[]={1,2,3,4,5};//this are weights
    int m=9,n=5;   
    knapsack(p,w,m,n); 
    return 0;
}