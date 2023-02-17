#include <bits/stdc++.h>
using namespace std;
#define ll long long

// n=4,m=5
// (1,2),(1,3),(2,3),(2,4),(3,4)

const int N = 105;
int g[N][N];

// @author: __Taohid

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	if (g[4][3]) {
		cout << "YES\n";
	}
	else cout << "NO\n";
	return 0;
}