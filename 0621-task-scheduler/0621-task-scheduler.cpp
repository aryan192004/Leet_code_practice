
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        priority_queue<pair<int, char>> pq;

        for (auto c : tasks) {
            freq[c - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push({freq[i], char(i + 'A')});
            }
        }

        queue<tuple<int, int, char>> q;
        int t = 0;

        while (!pq.empty() || !q.empty()) {
            while (!q.empty() && get<1>(q.front()) <= t) {
                pq.push({get<0>(q.front()), get<2>(q.front())});
                q.pop();
            }

            if (!pq.empty()) {
                int f = pq.top().first;
                char c = pq.top().second;
                pq.pop();

                if (f > 1) {
                    q.push({f - 1, t + n + 1, c});
                }
            }

            t++;
        }

        return t;
    }
};
