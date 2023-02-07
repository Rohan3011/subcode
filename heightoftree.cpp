#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;
typedef pair<int,string> pis;
typedef vector<pair<int,string>> vpis;
typedef vector<pair<int,int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define size() sz
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define INF 0x3f3f3f3f
#define endl "\n"


int n;
vi adj[2001];
int visited[2001];
int cnt=0;

void dfs(int x){
	if(visited[x]){
		return;
	}
	visited[x]=1;
	for (auto u : adj[x])
	{
		dfs(u);
		cnt++;
	}

}

void solve(){
 int i,j,sum=0,ans=0;
 cin>>n;
 int arr[n+1];
 for(int i=1;i<=n;i++){
 	cin>>arr[i];
 }

  for(int i=1;i<=n;i++){
  	if(arr[i]==-1){
  		adj[0].pb(i);
  	}
  	adj[arr[i]].pb(i);
  }
  dfs( arr[1]);
  deb(cnt);


//  fo( i,n+1){
//  	if(adj[i].empty()) break;
//  	else{
//  		cnt++;
//  	}

//  }
// cout<<cnt<<endl;

// fo(i,n+1){
//  	cout<<i<<":";
// 	 	 for(auto u : adj[i]){

//  	 cout<<u<<" ";
//  	 }
//  	 	cout<<endl;
// }
}




int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    string s;
    //int t;
    //cin>>t;
    //while(t--){
    // 
    //}
    solve();
    return 0;
}