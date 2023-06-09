#include <bits/stdc++.h>
using namespace std;
#define ll long long

// @author: __Taohid

class DSU {
	vector<int>rank, parent, size;
public:
	DSU(int n) {
		rank.resize(n + 1, 1);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int findPar(int node) {
		if (node == parent[node]) return node;

		return parent[node] = findPar(parent[node]);
	}

	void unionByRank(int u, int v) {
		u = findPar(u);
		v = findPar(v);
		if (u != v) {
			if (rank[u] < rank[v]) {
				swap(u, v);
			}
			parent[v] = u;
			rank[u] += rank[v];
		}
	}

	void unionBySize(int u, int v) {
		u = findPar(u);
		v = findPar(v);
		if (u != v) {
			if (size[u] < size[v]) {
				swap(u, v);
			}
			parent[v] = u;
			size[u] += size[v];
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	DSU ds(7);
	ds.unionBySize(1, 2);
	ds.unionBySize(2, 3);
	ds.unionBySize(4, 5);
	ds.unionBySize(6, 7);
	ds.unionBySize(5, 6);
	// if 3 and 7 same or not
	if (ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else cout << "Not Same\n";
	ds.unionBySize(3, 7);
	if (ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else cout << "Not Same\n";
	return 0;
}