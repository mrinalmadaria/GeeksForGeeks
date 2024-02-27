#include<bits/stdc++.h>
using namespace std;

void miniMaxSum(vector<int> arr) {
    int n=arr.size();
    long double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    long double max=arr[0];
    long double min=arr[0];
    for (int i=0;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    for (int i=0;i<n;i++)
    {
        if(min>arr[i])
        min=arr[i];
        
    }
cout<<sum-max<<" "<<sum-min;
}