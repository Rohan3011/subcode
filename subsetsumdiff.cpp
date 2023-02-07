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

//dp
 int subset_sum(int arr[], int sum , int n){
    vi ans;
    int mn = INT_MAX,range =sum;
 	bool dp[n+1][sum+1];
    fo(j,sum+1){
        dp[0][j]=false;
    }
 	fo(i,n+1){
 		dp[i][0]=true;
 	}
 
 	fo2(i,1,n+1){
 		fo2(j,1,sum+1){
 			if(arr[i-1]<=j){
 				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
 			}
 			else if(arr[i-1]>j){
 				dp[i][j]=dp[i-1][j];
 			}
 		}
 	}


// print dp
     	fo(j,(sum+1)){
            if(dp[n][j])
     		ans.pb(j);
     	}
        for(auto u : ans){
            cout << u <<" ";
        }cout<<endl;
  fo(i,ans.size()){
    mn = min(mn , abs(range-2*ans[i]));
    deb2(mn,ans[i]);
  }

 	return mn;
 }

void solve(){
 int n,sum ;
 cin >> n >> sum ;
 int arr[n];
 fo(i,n){
 	cin>>arr[i];
 }
 // cout << subsetsum(arr,sum,n)<<endl;
 cout << subset_sum(arr,sum,n);
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