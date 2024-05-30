//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod = 1e9 + 7;
    int countWays(string s1, string s2) {
        // code here
        int m = s2.size();
        vector<int> ways(m+1, 0);
        ways[0] = 1;
        map<char, vector<int>> lookup;
        for(int i = m; i > 0; i--) lookup[s2[i-1]].push_back(i);
        for(auto c : s1)
            for(int i : lookup[c]) ways[i] = (ways[i] + ways[i-1]) % mod;
        return ways[m];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends