#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long mod = 1000000007;
        long ans = 0l;
        int cnt = 1;
        for(int i = 0; i < n; i++){
            ans+=pds(cnt, i);
            cnt+=1+i;
        }
        return ans%mod;
    }
    
    static long pds(int s, int e){
        long mod = 1000000007;
        long pd = 1l;
        for(int i = s; i <= s+e; i++){
            pd = (pd*i) % mod;
        }
        return pd%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends