//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_map<char, int> ans;
	    for(int i = 0; i < str.size(); i++){
	        ans[str[i]]++;
	    }
	    
	    string final = "";
	    
	    for(int i = 0; i < str.size(); i++){
	        if(ans[str[i]] > 0){
	            final += str[i];
	            ans[str[i]] = 0;
	        }
	    }
	    return final;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends