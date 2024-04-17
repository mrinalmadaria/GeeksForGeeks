//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int ans=0;
    vector<int>b;
    void merge(int l,int mid,int r,int arr[]){
        int i=l,j=mid+1;
        int n=sizeof(arr)/sizeof(arr[0]);
        int k=i;
        while(i<=mid and j<=r){
            if(arr[i]>arr[j]){
                ans+=(mid-i+1);
                b[k++]=arr[j];
                j++;
            }
            else {
                b[k++]=arr[i++];
            }
        }
        while(i<=mid)b[k++]=arr[i++];
        while(j<=r)b[k++]=arr[j++];
        
        for(int z=l;z<=r;z++)arr[z]=b[z];
    }
    void mergeSort(int l,int r,int arr[]){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(l,mid,arr);
            mergeSort(mid+1,r,arr);
            merge(l,mid,r,arr);
        }
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for(int i=0;i<n;i++)arr[i]=i*arr[i];
        b=vector<int>(n);
        mergeSort(0,n-1,arr);
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends