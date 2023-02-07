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

// recursive + memoization;
  	

//iterative (top-down)

int knapit(int weight[],int value[],int W ,int n){
	int dp[n+1][W+1];
	fo(i,n+1){
		fo(j,W+1){
			if(i==0 || j==0){
			  dp[i][j]=0;
			  // cout<<dp[i][j]<<" ";
			 }

		}
	}


	for(int i = 1;i<n+1 ;i++){
		for(int j=1 ;j<W+1;j++){
			// cout << dp[j][j]<<" ";
			if(weight[i-1]<=j){
				dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]] ,dp[i-1][j]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
			 // cout << dp[i][j]<<" ";
		}
	}
	
	return dp[n][W];
}
	


void solve(){
	// memset(memo ,-1 ,sizeof(memo));
 int n ,W;
 cin >> n >> W;
 int weight[n],value[n];
 fo(i,n){
 	cin >> weight[i];
 }
 fo(i,n){
 	cin >> value[i];
 }
 // cout << knapsack(weight,value,W,n);
 cout << knapit(weight,value,W,n);
}




int main()
{
    ios::sync_with_stdio(0);cin.tie(0);


    //int t;
    //cin>>t;
    //while(t--){
    //}
    solve();
    return 0;
}