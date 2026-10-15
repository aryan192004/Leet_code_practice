class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,0,0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            int mindiff = get<0>(pq.top());
            int i = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
              if (mindiff > dist[i][j]) continue;

            if (i == m - 1 && j == n - 1) {
                return mindiff;
            }
            for(int k = 0; k < 4 ;k++){
                int nrow = i+drow[k];
                int ncol = j+dcol[k];
                if(nrow>m-1||ncol>n-1||nrow<0||ncol<0){
                    continue;
                    }
                int diff = abs(
                    heights[nrow][ncol] - heights[i][j]
                );
                 int newEffort = max(mindiff, diff);
                 if (newEffort < dist[nrow][ncol]) {
                    dist[nrow][ncol] = newEffort;

                    pq.push({
                        newEffort,
                        nrow,
                        ncol
                    });
                }
               
            }
            }
            return 0;
    }
};