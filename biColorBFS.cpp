// 1.Linear Graph with no cycle is always bipartite graph.
// 2.Any Graph with even cycle lenght is also bipartite graph.
// 3.Any Graph with odd cycle lenght can never be bipartite.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e5 + 7;
vector<int>g[N];
int col[N];
bool vis[N];
bool ok;

void bfs(int vertex) {
	queue<int>q;
	q.push(vertex);
	col[vertex] = 1;
	vis[vertex] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v : g[u]) {
			if (!vis[v]) {
				col[v] = col[u] ^ 1;
				vis[v] = 1;
				q.push(v);
			}
			else {
				if (col[u] == col[v]) ok = 0;
			}
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
			bfs(i);
		}
	}
	if (ok) {
		for (int i = 1; i <= n; i++) {
			cout << col[i] << ' ';
		}
		cout << '\n';
	}
	else cout << "IMPOSSIBLE\n";
	return 0;
}