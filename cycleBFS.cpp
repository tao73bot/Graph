#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e5 + 9;
vector<int>g[N];
bool vis[N];
int par[N];
bool cycle;

void bfs(int node) {
	queue<int>q;
	vis[node] = 1;
	par[node] = -1;
	q.push(node);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : g[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				par[v] = u;
				q.push(v);
			}
			else if (par[u] != v) cycle = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) bfs(i);
	}
	cout << (cycle ? "YES\n" : "NO\n");
	return 0;
}