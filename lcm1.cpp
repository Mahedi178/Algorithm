#include <iostream>
#include<vector> 
#include<algorithm>
using namespace std; 
  
int LongestIncreasingSubsequenceLength(vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
    cout<<endl;
    for(int &i:v)cout<<i<<" ";
    cout<<endl; 
    for(int &i:tail)cout<<i<<" ";
    cout<<endl;    
    tail[0] = v[0]; 
    cout<<endl; 
    for(int &i:tail)cout<<i<<" ";
    cout<<endl; 
    for (size_t i = 1; i < v.size(); i++) {
        cout<<i<<" : "<<v[i]<<" "<<tail[length-1]<<" "<<length<<" "<<endl; 
        if (v[i] > tail[length - 1]){
            cout<<length<<" ";
            tail[length++] = v[i];
            cout<<length<<" "<<endl; 
        }else { 
            // TO check whether the element is not present before hand 
            auto it = find(tail.begin(), tail.begin() + length, v[i]); 
            if (it != tail.begin() + length) { 
                continue; 
            } 
            // If not present change the tail element to v[i] 
            it = upper_bound(tail.begin(), tail.begin() + length, v[i]);
            cout<<"\n *it: "<<*it<<endl; 
            *it = v[i]; 
             cout<<"\n *it: "<<*it<<endl; 
        } 
        for(int r:tail)cout<<r<<" ";
        cout<<endl;
    } 
  
    return length; 
} 
  
int main() 
{ 
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 }; 
    cout << "Length of Longest Increasing Subsequence is "
              << LongestIncreasingSubsequenceLength(v); 
    return 0; 
} 