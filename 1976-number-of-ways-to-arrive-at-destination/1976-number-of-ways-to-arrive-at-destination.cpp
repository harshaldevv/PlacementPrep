class Solution {
public:
    
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n);
    for (auto& r : roads) {
        adj[r[0]].emplace_back(r[1], r[2]);
        adj[r[1]].emplace_back(r[0], r[2]);
    }
    
    vector<ll> dist(n, LLONG_MAX);
    vector<ll> cnt(n, 0);
    vector<bool> vis(n, false);
    dist[0] = 0;
    cnt[0] = 1;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto& [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.emplace(dist[v], v);
            } else if (dist[v] == dist[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }
    
    return cnt[n-1];
        
    }
};