#include<bits/stdc++.h>
using namespace std;


bool visited[10001] = {false} ;
vector<int> adj[10001] ;


void dfs(int s) {
	if (visited[s])
		return ;
	visited[s] = true;
	for (auto u : adj[s]) {
		cout << u << " " ;
		dfs(u) ;
	} cout << '\n';
}

int main() {

	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[4].push_back(1);
	dfs(1) ;

}