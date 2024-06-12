//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n){
        int count = 0;
        while(n != 0){
            if(n % 10 == 4){
                count++;
                break;
            }
            n /= 10;
        }
        return count;
    }
    
    int countNumberswith4(int n) {
        // code here
        int total = 0;
        for(int i = 1; i <= n; i++){
            total += solve(i);
        }
        return total;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends