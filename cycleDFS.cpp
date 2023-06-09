#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e5 + 5;
vector<int>g[N];
int par[N];
bool vis[N];
bool cycle;
int st, ed;

// bool dfs(int u, int parent) {
// 	vis[u] = 1;

// 	for (auto v : g[u]) {
// 		if (v == parent) continue;
// 		if (vis[v]) {
// 			st = v;
// 			ed = u;
// 			return 1;
// 		}
// 		par[v] = u;
// 		if (dfs(v, u)) return 1;
// 	}
// 	return 0;
// }

void dfs(int u, int parent = -1) {
	vis[u] = 1;

	for (auto v : g[u]) {
		if (!vis[v]) {
			par[v] = u;
			dfs(v, u);
		}
		else if (par[u] != v) {
			st = u;
			ed = v;
			cycle = 1;
		}
	}
}

void find_cycle(int n) {
	st = -1;
	cycle = 0;
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i] and dfs(i, -1)) {
	// 		break;
	// 	}
	// }
	for (int i = 1; i <= n; i++) {
		if (!vis[i] and cycle == 0) dfs(i);
	}
	if (st == -1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		// cout << "YES\n";
		vector<int>ans;
		ans.push_back(st);
		for (int i = ed; i != st; i = par[i]) {
			ans.push_back(i);
		}
		ans.push_back(st);
		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it << ' ';
		cout << '\n';
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
	find_cycle(n);
	return 0;
}