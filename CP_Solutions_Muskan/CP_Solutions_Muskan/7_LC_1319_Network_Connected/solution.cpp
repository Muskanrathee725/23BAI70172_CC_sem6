/*
================================================================================
  Problem  : LC 1319 — Number of Operations to Make Network Connected
  Platform : LeetCode
  Topic    : Union-Find (Disjoint Set Union / DSU)
  Verdict  : Accepted | 15 ms | 46.60 MB | Beats 61.05% Runtime
  Date     : Apr 20, 2026
  Profile  : muskan_rathee

  Approach :
  - Need at least (n-1) edges to connect n computers.
  - If total edges < n-1, return -1 (impossible).
  - Otherwise: count connected components C using DSU.
  - Answer = C - 1  (need exactly C-1 moves to connect all components).
  - Extra cables (total_edges - (n-1)) are always enough when edges >= n-1,
    since each extra edge can be repurposed to bridge a component.
  - Time: O(E * alpha(n)) ~ O(E)
================================================================================
*/

class Solution {
public:
    vector<int> par, rnk;

    int find(int x){
        if(par[x] != x) par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() < n-1) return -1;

        par.resize(n);
        rnk.resize(n, 0);
        iota(par.begin(), par.end(), 0);

        for(auto& e : connections) unite(e[0], e[1]);

        int components = 0;
        for(int i = 0; i < n; i++)
            if(find(i) == i) components++;

        return components - 1;
    }
};
