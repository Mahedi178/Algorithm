#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int n=5;
    int p[]={5,4,6,2,7};
    int m[5][5]={0};
    int s[5][5]={0};
    int j,min,q;
    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){  //when i=1 and d=1 then n-d=5-1=4
            j=i+d;
            min=INT32_MAX;
            for(int k=i;k<=j-1;k++){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min){
                    min=q;
                    s[i][j]=k;
                }

            }
            m[i][j]=min;

        }
    }
    cout<<"Printing the matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<"   ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<s[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<m[1][n-1];    
    return 0;
}