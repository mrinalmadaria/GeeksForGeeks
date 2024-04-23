//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1000000007;
        vector<int> v;
        
        int x=1, y=2;
        v.push_back(1);
        v.push_back(2);
        
        for(int i = 0; i < n-2; i++){
            int x = v.back();
            int y = v[v.size()-2];
            int z = (x+y) % mod;
            
            v.push_back(z);
        }
        return v[v.size()-2];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends