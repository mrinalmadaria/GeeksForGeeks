//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        map<int,vector<int> > mp;
        vector<int> ans ;
       
        for(int i=0;i<n;i++){
           int diff = abs(arr[i] - x);
           if(diff == 0) continue;
           else if(mp[diff].size() !=0){
               mp[diff].push_back(arr[i]);
           }
           
           else mp[diff].push_back(arr[i]);
        }
        for(auto it:mp){
           
            sort(it.second.begin(),it.second.end(),greater<int>());
            for(auto j:it.second){
         
            ans.push_back(j);
            if(ans.size()==k) return ans;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends