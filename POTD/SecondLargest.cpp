//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int max_elem = INT_MIN, second_max_elem = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > max_elem){
                second_max_elem = max_elem;
                max_elem = arr[i];
            }else if((arr[i] > second_max_elem) && (arr[i] != max_elem)){
                second_max_elem = arr[i];
            }
        }
        
        if(second_max_elem == INT_MIN){
            return -1;
        }
        
        return second_max_elem;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends