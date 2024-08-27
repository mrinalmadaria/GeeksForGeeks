//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int l = 0, r = 1;
        vector<int> la;
        vector<int> ra;
        la.push_back(0);
        int n = arr.size();
        int ans = 0;
        while(l<n && r<n)
        {
            if(arr[l] < arr[r])
            {
                la.push_back(arr[l]);
                l=r;
                r++;
            }
            else
            {
                l--;
                if(l<0)
                {
                    la.push_back(0);
                     l=r;
                     r++;
                }
            }
        }
        l=n-1, r=n-2;
        ra.push_back(0);
        while(l>=0 && r>=0)
        {
            if(arr[l] < arr[r])
            {
                ra.push_back(arr[l]);
                l=r;
                r--;
            }
            else
            {
                l++;
                if(l>n-1)
                {
                    ra.push_back(0);
                    l=r;
                    r--;
                }
            }
        }
        reverse(ra.begin(), ra.end());
        for(int i=0; i<n; i++)
        {
            //cout<<la[i]<<" ";
            ans = max(ans, abs(la[i]-ra[i]));
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends