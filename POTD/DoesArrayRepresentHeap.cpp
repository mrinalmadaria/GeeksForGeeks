//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int index = (n)/2-1;
        
        for(index; index >= 0; index--){
            int left = (2*index) + 1;
            int right = (2*index) + 2;
            
            if(left < n){
                if(arr[left] > arr[index]){
                    return 0;
                }
            }
            
            if(right < n){
                if(arr[right] > arr[index]){
                    return 0;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends