#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string> v;
	    
	    void f(string &s, int i, string x){
	        if(i == s.size()){
	            v.push_back(x);
	            return;
	        }
	        f(s, i + 1, x + s[i]), f(s, i + 1, x);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    f(s, 0, "");
		    return sort(v.begin(), v.end()), v.erase(v.begin()), v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends