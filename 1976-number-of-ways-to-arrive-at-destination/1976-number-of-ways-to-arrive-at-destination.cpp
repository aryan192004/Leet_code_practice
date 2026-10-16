
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<vector<pair<int, int>>> adj(n);

        for (auto& x : roads) {
            int u = x[0];
            int v = x[1];
            int t = x[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (t > dist[node]) continue;

            for (auto it : adj[node]) {
                int next = it.first;
                long long newTime = t + it.second;

                if (newTime < dist[next]) {
                    dist[next] = newTime;
                    ways[next] = ways[node];
                    pq.push({newTime, next});
                }
                else if (newTime == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
