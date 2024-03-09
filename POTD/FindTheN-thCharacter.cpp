//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        if(r == 0){
            return s[n];
        }
        int i = 0;
        int wordlen = pow(2,r);
        string temp;
        
        while(i < s.length()){
            if(n+1 <= wordlen){
                temp = s[i];
                break;
            } else {
                n = n - wordlen;
            }
            i++;
        }
        while(temp.length() < n+1){
            string make = "";
            for(i = 0; i < temp.length(); i++){
                if(temp[i] == '1'){
                    make += "10";
                }else{
                    make += "01";
                }
            }
            temp = make;
        }
        return temp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends