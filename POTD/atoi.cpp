#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int n = s.size();
        int result = 0;
        int j = 0;
        
        if(s[0] == '-') j = 1;
        
        for(int i = j; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                result = result * 10 + int(s[i] - '0');
            } else {
                result = -1;
                break;
            }
        }
        if(s[0] == '-' && result != -1){
            return -1 * result;
        } else {
            return result;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}