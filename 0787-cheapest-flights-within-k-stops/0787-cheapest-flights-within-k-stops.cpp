
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {cost, node, stops}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({0, src, 0});

        // Minimum cost to reach a node using a given number of flights
        vector<vector<int>> dist(
            n, vector<int>(k + 2, INT_MAX)
        );

        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) {
                return cost;
            }

            if (stops == k + 1) {
                continue;
            }

            if (cost > dist[node][stops]) {
                continue;
            }

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int price = it.second;
                int newCost = cost + price;
                int newStops = stops + 1;

                if (newCost < dist[nextNode][newStops]) {
                    dist[nextNode][newStops] = newCost;

                    pq.push({
                        newCost, nextNode, newStops
                    });
                }
            }
        }

        return -1;
    }
};
