#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n , m , k ;
    cin >> n >> m >> k ;
    bool adj[n + 1][m];
    bool visited[n + 1] ;
    memset(adj, 1, sizeof(adj));
    memset(visited , 0 , sizeof(visited));
    for (int i = 0 ; i < m ; i++) {
        int a , b ;
        cin >> a >> b ;
        adj[a][b] = 0 ;
        adj[b][a] = 0 ;
    }

    int a_edges = 0 , edges = 0 ;
    for (int i = 1 ; i <= n ; i++) {
        if (adj[1][i])
            a_edges++;
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        visited[x] = true ;
        for (int i = 1 ; i <= n ; i++) {
            if (adj[x][i] && !visited[i]) {
                q.push(i);
                edges++;
            }
        }
    }
    bool connected = true ;
    for (int i = 1 ; i <= n ; i++)
        connected &= visited[i];
    // cout << connected << " " << edges << '\n';
    puts((connected && edges == n - 1 && a_edges == k) ? "possible" : "impossible");
}