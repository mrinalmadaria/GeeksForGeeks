//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string s) {
        // Your code goes here
        vector<int> z(s.size());
        int l=0, r=0, ans = 0;
        for(int i=1; i<s.size(); i++){
            if(i<r) z[i] = min(z[i-l], r-i);
            while(i+z[i]<s.size() and s[z[i]] == s[i+z[i]]) z[i]++;
            if(i+z[i]>r) l=i, r=i+z[i];
            if(i+z[i]==s.size()) return z[i];
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends