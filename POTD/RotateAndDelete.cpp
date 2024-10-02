//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rotate(vector<int> &arr){
        int n = arr.size();
        int p = arr[arr.size() - 1];
        
        for(int i = n-1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = p;
    }
    
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int s = arr.size() / 2;
        
        for(int i = 1; i <= s; i++){
            rotate(arr);
            int in = arr.size() - i;
            
            int r = in > arr.size()-1 ? in%arr.size() : in;
            auto it = arr.begin() + r;
            arr.erase(it);
        }
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends