#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>v{2 ,5,6,7,8,9,0 ,0 ,0 ,0 ,0 ,0, 0};
    for(int &i:v)cout<<i<<" ";
    cout<<endl;
    vector<int>::iterator low_b,upper_b;

    low_b=lower_bound(v.begin(),v.end(),5);
    upper_b=upper_bound(v.begin(),v.end(),5);
    cout<<low_b-v.begin()<<" "<<upper_b-v.begin()<<endl;
    
    low_b=lower_bound(v.begin(),v.end(),2);
    upper_b=upper_bound(v.begin(),v.end(),2);
    cout<<*low_b<<" "<<*upper_b<<" "<<endl;
    
    low_b=lower_bound(v.begin(),v.end(),1);
    upper_b=upper_bound(v.begin(),v.end(),1);
    cout<<low_b-v.begin()<<" "<<upper_b-v.begin()<<endl;
    return 0;
}