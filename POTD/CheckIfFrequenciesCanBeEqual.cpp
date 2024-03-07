//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int count[26]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
         sort(count,count+26);
         bool flag=false;
         int i=0;
         bool one =false;
         int n=26;
         while(i<26){
             if(count[i]==0||(i==n-1&&count[i]==count[i-1])||i==n-1&&count[i-1]==0)
             i++;
             else if(count[i]==count[i+1]&&flag ==false)
             i++;
             else if(count[i]==1&&count[i+1]!=1&&count[i-1]!=1){
                one=true;
                  i++;
                  if(i==n-1)
                  i++;
             }
             else if(abs(count[i]-count[i+1])==1&&flag==false&one==false){
                 one =true;
                  flag=true;
                  i++;
                  if(i==n-1)
                  i++;
             }
             else 
             return 0;
         }
         return 1;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}

// } Driver Code Ends