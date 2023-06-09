// input:
// 5 3
// 1 2
// 1 3
// 4 5

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e5 + 5;
vector<int>g[N];
bool vis[N];
int col[N];
bool ok;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : g[u]) {
		if (!vis[v]) {
			col[v] = col[u] ^ 1;
			dfs(v);
		}
		else {
			if (col[u] == col[v]) ok = 0;
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
	ok = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	if (ok) {
		for (int i = 1; i <= n; i++) {
			if (col[i] == 0) cout << 2 << ' ';
			else cout << 1 << ' ';
		}
		cout << '\n';
	}
	else cout << "IMPOSSIBLE\n";
	return 0;
}