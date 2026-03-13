/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c]
represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west
if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an
ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to
both the Pacific and Atlantic oceans.

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
*/

//Method 1
//TLE
class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int r, int c){
        int m=heights.size(), n=heights[0].size();
        if (visited[r][c]) return;
        int dx[]={-1, 0 ,1, 0};
        int dy[]={0, 1, 0, -1};
        queue<pair<int,int>> q;
        q.push({r,c});
        visited[r][c] = 1;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            visited[x][y] = 1;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && heights[x][y]<=heights[nx][ny] && 
                    !visited[nx][ny] ){
                    q.push({nx, ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n,0));
        vector<vector<int>> alt(m, vector<int>(n,0));
        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            bfs(heights, pac, i, 0);
            bfs(heights, alt, i, n-1);
        }
        for(int i=0;i<n;i++){
            bfs(heights, pac, 0, i);
            bfs(heights, alt, m-1, i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && alt[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

//Method
//Pass
class Solution {
public:
    void multiSourceBFS(vector<vector<int>>& heights, vector<vector<int>>& visited, queue<pair<int, int>>& q) {
        int m = heights.size(), n = heights[0].size();
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                // 逆流：鄰居比我高 (heights[nx][ny] >= heights[x][y])
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0)), alt(m, vector<int>(n, 0)), ans;
        queue<pair<int, int>> qPac, qAtl;

        // 1. 一次把「所有起點」找齊
        for (int i = 0; i < m; i++) {
            qPac.push({i, 0}); pac[i][0] = 1;      // 左邊界
            qAtl.push({i, n - 1}); alt[i][n - 1] = 1; // 右邊界
        }
        for (int j = 0; j < n; j++) {
            if(!pac[0][j]) { qPac.push({0, j}); pac[0][j] = 1; }      // 上邊界
            if(!alt[m - 1][j]) { qAtl.push({m - 1, j}); alt[m - 1][j] = 1; } // 下邊界
        }

        // 2. 只跑兩次大型 BFS
        multiSourceBFS(heights, pac, qPac);
        multiSourceBFS(heights, alt, qAtl);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && alt[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};