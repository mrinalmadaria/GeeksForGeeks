//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int solveTab(string s, vector<string> &dictionary){
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        int ans = 0;
        
        for(int i = dp.size() - 1; i >= 0; i--){
            for(auto it : dictionary){
                if(it == s.substr(i, it.size())){
                    if(i + it.size() > s.size()){
                        continue;
                    }
                    ans = dp[i + it.size()];
                    dp[i] = max(ans, dp[i]);
                }
            }
        }
        return dp[0];
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        return solveTab(s, dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends