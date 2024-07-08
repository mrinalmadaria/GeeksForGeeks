//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& a, int key) {
        // complete the function here
        int h= a.size() - 1 , l = 0 , mid ;
        while(l<=h){
            mid = l+(h-l)/2;
            if(key==a[mid]) return mid;
            if(a[mid]>=a[l]&&a[mid]<=a[h]) key<a[mid] ? h= mid-1 : l = mid+1;
            else if(a[mid]>a[h]) key>a[mid]||key<=a[h] ? l = mid+1 :  h= mid-1; 
            else key<a[mid]||key>=a[l] ? h = mid-1 :  l = mid+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends