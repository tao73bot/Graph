// input
// 3 3
// 1 2
// 2 3
// 3 1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e5 + 5;
vector<int>g[N];
bool vis[N];
int col[N], par[N];
bool cycle;
int st, ed;

void dfs(int u) {
	col[u] = 1;
	for (auto v : g[u]) {
		if (col[v] == 0) {
			par[v] = u;
			dfs(v);
		}
		else if (col[v] == 1) {
			st = v;
			ed = u;
			cycle = 1;
		}
	}
	col[u] = 2;
}

void find_cycle(int n) {
	st = -1;
	cycle = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i] == 0 and cycle == 0) dfs(i);
	}
	if (st == -1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		vector<int>ans;
		ans.push_back(st);
		for (int i = ed; i != st; i = par[i]) {
			ans.push_back(i);
		}
		ans.push_back(st);
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (auto it : ans) {
			cout << it << ' ';
		}
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
		// g[v].push_back(u);
	}
	find_cycle(n);
	return 0;
}