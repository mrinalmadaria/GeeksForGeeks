//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++
class Solution {
public:
    int binarySearch(vector<int>& arr, int key) {
        int ind = 1;
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == key) {
                ind = mid;
                right = mid - 1;
            } else if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ind;
    }

    vector<int> constructLowerArray(vector<int>& arr) {
        vector<int> sorted = arr;
        vector<int> ans(arr.size());
        sort(sorted.begin(), sorted.end());
        for (size_t i = 0; i < arr.size(); ++i) {
            int ind = binarySearch(sorted, arr[i]);
            ans[i] = ind;
            sorted.erase(sorted.begin() + ind);
        }
        return ans;
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
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends