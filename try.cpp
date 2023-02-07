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


int unboundedknapsack(int arr[],int sum , int n ){
	int dp[n+1][sum+1];
	fo(i,n+1){
		dp [i][0] = 0 ;
	}
	fo(j,sum+1){
		dp [0][j] = 0 ;
	}

	fo(i,n+1){
		fo(j,sum+1){
			if(arr[i-1]> sum){
				arr[i][j] = arr[i-1][j];
			}
			else{
				max (arr[i][j-arr[i-1]] , arr[i-1][j])
			}
		}
	}
	return dp [n][sum] ;
}

void solve(){
 int n  ;
 cin >> n ;
 int arr[n];
 fo(i,n){
 	cin >> arr[i];
 }
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