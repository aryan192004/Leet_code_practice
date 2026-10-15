class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<
    tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>> pq;
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    dist[0][0] = 0;
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
    pq.push({0,0,0});
    int drow[]={-1,-1,0,1,1,1,0,-1};
    int dcol[]={0,1,1,1,0,-1,-1,-1};
    while(!pq.empty()){
        int d =get<0>(pq.top());
        int i =get<1>(pq.top());
        int j =get<2>(pq.top());
        pq.pop();
        if(d>dist[i][j])continue;
        for(int k = 0;k<8;k++){
           int nrow = i+drow[k];
            int ncol = j+dcol[k];
            
            if(nrow>n-1 || ncol> n-1|| nrow<0||ncol<0){
                continue;
            }
            if(grid[nrow][ncol] == 1) continue;

            if(d+1<dist[nrow][ncol]){
                dist[nrow][ncol]= d+1;
                pq.push({dist[nrow][ncol],nrow,ncol});
            }
        }
    }
    if(dist[n-1][n-1] == INT_MAX) return -1;
    return dist[n-1][n-1]+1;
    }
};