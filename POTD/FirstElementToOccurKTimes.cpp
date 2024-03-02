//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int> mp;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            mp[a[i]]++;
            ans[i] = mp[a[i]];
        }
        int index = -1;
        for(int i = 0; i<ans.size(); i++){
           if(ans[i] == k){
               index = i;
               break;
           }
        }
        if(index == -1){
            return -1;
        }
        return a[index];
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends