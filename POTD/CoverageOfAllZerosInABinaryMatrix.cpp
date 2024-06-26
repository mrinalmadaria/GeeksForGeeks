//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int n=matrix.size(),m=matrix[0].size();
        int count=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<4;k++)
                    {
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol]==1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends