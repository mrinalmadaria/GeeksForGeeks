//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(string& digits, int i, string curr, unordered_set<string>& res) {
        if(i == digits.size()) {
            if(curr.length()) res.insert(curr);
            return;
        }
        int dig = digits[i]-'0';
        if(dig < 1 || dig > 26) return;
        
        curr.push_back('a'+(dig-1));
        solve(digits, i+1, curr, res);
        
        if(i+1 >= digits.size()) return;
        dig = dig*10 + digits[i+1]-'0';
        
        if(dig < 1 || dig > 26) return;
        
        curr.pop_back();
        curr.push_back('a'+(dig-1));
        solve(digits, i+2, curr, res);
    }
    int solve2(string& s, int end) {
        if(end<0) return 1;
        
        
        int res = s[end] != '0' ? solve2(s, end-1) : 0;
        if(end > 0) {
            int last2dig = stoi(s.substr(end-1, 2));
            if(last2dig > 9 && last2dig < 27) res += solve2(s, end-2);
        }
        return res;
        
    }
    
    int solve3(string& s, int st, vector<int>& dp) {
        if(s[st] == '0') return 0;
        if(st >= s.length()-1) return 1;
        if(dp[st] != -1) return dp[st];
        
        int res = solve3(s, st+1, dp), nxt2dig = stoi(s.substr(st, 2));
        if(nxt2dig > 9 && nxt2dig < 27) res += solve3(s, st+2, dp);
        dp[st] = res;
        return dp[st];
        
    }
    
    int countWays(string &digits) {
        int n = digits.length();
        
        vector<int> dp(n, -1);
        return solve3(digits, 0, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends