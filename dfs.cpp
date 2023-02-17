#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 105;
vector<int>g[N];
bool vis[N];

void dfs(int u) {
	vis[u] = 1;

	for (auto v : g[u]) {
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
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "Disconnected\n";
			return 0;
		}
	}
	cout << "Connected\n";
	return 0;
}