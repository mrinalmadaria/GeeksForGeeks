//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_map<int, int> mp;
        
        for(int i = 0; i < k; i++){
            if(mp.find(arr[i]) != mp.end()){
                if(mp[arr[i]] - i < k){
                    return true;
                }
            }
            mp[arr[i]] = i;
        }
        
        for(int i = k; i < arr.size(); i++){
            if(mp.find(arr[i]) != mp.end()){
                if(mp[arr[i]] - i < k && mp[arr[i]] - i >= (-k)){
                    return true;
                }
            }
            mp[arr[i]] = i;
        }
        return false;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends