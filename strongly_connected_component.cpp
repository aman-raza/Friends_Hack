#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj, vector<bool>&vis, int node, vector<int>&st)
{
	vis[node] = true;
	for (auto nbr : adj[node])
	{
		if (!vis[nbr])
			dfs(adj, vis, nbr, st);
	}
	st.push_back(node);
}

void dfs_(vector<vector<int>>&adj, vector<bool>&vis, int node)
{
	vis[node] = true;
	cout << node << " ";
	for (auto nbr : adj[node])
	{
		if (!vis[nbr])
			dfs_(adj, vis, nbr);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n), rev_adj(n);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}
	vector<bool>vis(n, false);
	vector<int>st;//use stack

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			dfs(adj, vis, i, st);
	}
	fill(vis.begin(), vis.end(), false);


	char comp_name = 'A';

	for (int i = st.size() - 1; i >= 0; i--)
	{
		int node = st[i];
		if (!vis[node])
		{
			cout << "component " << comp_name << "-->";
			dfs_(rev_adj, vis, node);
			cout << endl;
			comp_name++;
		}
	}

}
