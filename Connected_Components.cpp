#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 105;
vector<int>g[N];
bool vis[N];

void dfs(int node) {
	vis[node] = 1;

	for (auto v : g[node]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << "Connected Components = " << ans << '\n';
	return 0;
}