//here we have to find out the maximum contiguous subarray
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int array[]={-2,1,-3,4,-1,2,1,-5,4};
    int s=sizeof(array)/sizeof(array[0]);
    int temp[s]={0};
    temp[0]=array[0];
    for(int i=1;i<s;i++){
        temp[i]=max(array[i],array[i]+temp[i-1]);
    }
    for(int &i:temp)cout<<i<<" ";
    cout<<endl;
    cout<<*max_element(temp,temp+s)<<endl;    
    return 0;
}