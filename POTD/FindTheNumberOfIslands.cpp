//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n, m;
    int row[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int col[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    bool exist(int x, int y, vector<vector<char>>& grid){
        return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1');
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        grid[i][j] = '0';
        q.push({i, j});
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto front = q.front(); q.pop();
                for(int k=0;k<8;k++){
                    int x = front.first + row[k], y = front.second + col[k];
                    if(exist(x, y, grid)){
                        q.push({x, y});
                        grid[x][y] = '0';
                    }
                }
            }
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    res++;
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends