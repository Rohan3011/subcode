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
 ll n , m , j , i ;
 cin >> n >> m >> j >> i;

  ll x1 , y1 , x2 , y2;

  	x1 = i ;
  
   if (i <= n-i){
  	x1 = n ;
  }
 
  	y1 = j;
  
  if(j <= m-j){
  	y1 = m;
  }
  // if(x1-i >= 1-i && 1-j >= y1-1){
  // 		x2 = x1;
  // 		y2 = 1;
  // }
  // else{
  // 	x2 = 1 ;
  // 	y2 = y1;
  // }
  // << " " << x2 << " " <<y2 
   cout << x1 << " " << y1 << endl; 

   

//   1 2 2 3
// 4 1 4 4
// 3 1 1 5
// 5 1 1 1
// 1 1 2 1
// 1 1 1 1
// 50 1 1 1000000000

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