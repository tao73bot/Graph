#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 1e3 + 7;
vector<int>g[N];

int shortest_cycle(int n) {
	int ans = INT_MAX;

	for (int i = 0; i < n; i++) {
		vector<int>dis(n, (int)1e9);
		vector<int>par(n, -1);
		queue<int>q;
		q.push(i);
		dis[i] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (auto v : g[u]) {
				if (dis[v] == (int)1e9) {
					dis[v] = dis[u] + 1;
					par[v] = u;
					q.push(v);
				}
				else if (par[v] != v and par[u] != v) {
					ans = min(ans, dis[u] + dis[v] + 1);
				}
			}
		}
	}
	if (ans == INT_MAX)
		return -1;
	else return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u++, v++;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int ans = shortest_cycle(n);

	if (ans == -1) cout << "No Cycle\n";
	else cout << ans << '\n';


	return 0;
}