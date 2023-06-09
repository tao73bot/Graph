#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

const int N = 105;
vector<int>g[N];

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

	// degree
	for (int i = 1; i <= n; i++) {
		cout << "Degree of " << i << " is : " << g[i].size() << '\n';
	}
	return 0;
}