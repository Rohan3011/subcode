#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef vector<pair<int,string>> vpis;
typedef vector<pair<int,int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define fo2(i,a,n) for(int i= a ; i<n ; i++ )
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define INF 0x3f3f3f3f
#define endl "\n"



void solve(){
 int n , m ;
 cin >> n >> m ;
 char arr[n][m];
 vpi red ;
 vpi white ;

 fo(i,n){
 	fo(j,m){
 		cin >> arr[i][j];
 		if(arr[i][j] == 'R'){
 			red.pb({i,j});
 		}
 		if(arr[i][j] == 'W'){
 			white.pb({i,j});
 		}
 	}
 }
 for(auto u : red){
 	int x = u.F ,y = u.S;
 		if( arr[x+1][y]=='R'||  arr[x-1][y]=='R'|| arr[x][y+1]=='R' ||  arr[x][y-1]=='R'){
 		cout <<"NO\n";
 		return;
 	}
 	// others cases

 	if( x+1<n and  arr[x+1][y]=='.'){
 		// deb2(x+1 ,y);
 		arr[x+1][y]='W';
 	}
 	if( x-1>=0 and  arr[x-1][y]=='.'){
 		// deb2(x-1 ,y);
 		arr[x-1][y]='W';
 	}
 	if(y+1<m and arr[x][y+1]=='.'){
 		// deb2(x ,y+1);
 		arr[x][y+1]='W';
 	}
 	if(y-1>=0 and arr[x][y-1]=='.'){
 		// deb2(x ,y-1);
 		arr[x][y-1]='W';
 	}


 }


  for(auto u : white){
 	int x = u.F ,y = u.S;
 	if( arr[x+1][y]=='W'||  arr[x-1][y]=='W'|| arr[x][y+1]=='W' ||  arr[x][y-1]=='W'){
 		cout <<"NO\n";
 		return;
 	}
 
 }
  cout<<"YES\n";
  fo(i,n){
  	fo(j,m){
  		cout << arr[i][j]<<" ";
  	}
  	cout <<endl;
  }
}




int main()
{
    ios::sync_with_stdio(0);cin.tie(0);


    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}