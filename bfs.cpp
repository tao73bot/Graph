// input
// 6 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 105;
vector<int>g[N];
bool vis[N];
int dis[N];
int par[N];

void bfs(int vertex) {
	queue<int>q;
	q.push(vertex);
	vis[vertex] = 1;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (auto v : g[cur_v]) {
			if (!vis[v]) {
				q.push(v);
				par[v] = cur_v;
				vis[v] = 1;
				dis[v] = dis[cur_v] + 1;
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
	bfs(1);

	// shortest path
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << '\n';
	}
	// path printing
	int x;
	cin >> x;
	vector<int>path;
	path.push_back(x);
	while (par[x]) {
		path.push_back(par[x]);
		x = par[x];
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}
	cout << '\n';
	return 0;
}