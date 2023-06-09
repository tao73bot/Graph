#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 105;
vector<int>g[N];
bool vis[N];
int dis[N], paths[N];

void bfs(int vertex) {
	queue<int>q;
	q.push(vertex);
	dis[vertex] = 0;
	vis[vertex] = 1;
	paths[vertex] = 1;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (auto v : g[cur_v]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = 1;
			}
			if (dis[v] > dis[cur_v] + 1) {
				dis[v] = dis[cur_v] + 1;
				paths[v] = paths[cur_v];
			}
			else if (dis[v] == dis[cur_v] + 1) {
				paths[v] += paths[cur_v];
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
	for (int i = 1; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	bfs(1);

	for (int i = 1; i <= n; i++) {
		cout << dis[i] << ' ' << paths[i] << '\n';
	}
	return 0;
}