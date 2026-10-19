class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        map<int, int> mp;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }

        int rank = 1;
        int lasta = INT_MIN;

        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();

            if (a != lasta) {
                mp[a] = rank;
                rank++;
            }

            lasta = a;
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};