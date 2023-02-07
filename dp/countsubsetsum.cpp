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

/*
Number of possible ways to form 'sum' from given array 

*/

int countsubset(int arr[],int sum, int n){
	
	if(sum==0){
		return 1;
	}
	if(n==0){
		return 0 ;
	}
	if(arr[n-1]>sum){
		return countsubset(arr,sum,n-1);
	}
	// adding possibilities because at last every subet which return '1' 
	// will be added up
	else{
		return countsubset(arr,sum-arr[n-1],n-1) + countsubset(arr,sum,n-1);
	}
}

// dp
int countsubsetdp(int arr[],int sum , int n){
	int dp[n+1][sum+1];

	fo(j,sum+1){
		dp[0][j]=0;
	}
	fo(i,n+1){
		dp[i][0]=1;
	}

	fo2(i,1,n+1){
		fo2(j,1,sum+1){
			if(arr[i-1]>j){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
		}
	}
	// print
	// fo(i,n+1){
	// 	fo(j,sum+1){
	// 		cout << dp[i][j]<<" ";
	// 	}
	// 	cout << endl;
	// }
	return dp[n][sum];
}


//coin change (variation)
// 1 <= n,m <= 103  -> gfg constrains
  long long int coin_change(int arr[],int sum , int n){
    long long int 	dp[n+1][sum+1];
  	for(int j =0 ; j < sum+1 ; j++){
  		dp[0][j] = 0 ; //n = 0
  	}
  	for(int i = 0 ; i < n+1 ;i++){
  		dp[i][0] = 1; // sum = 0
  	}
  	for(int i = 1 ; i < n+1; i++){
  		for(int j =1 ; j< sum+1; j++){
  			if(arr[i-1] > j ){
  				dp[i][j] = dp[i-1][j];
  			}
  			else{
  				dp[i][j] = dp[i][j- arr[i-1]] + dp[i-1][j];
  			}
  		}
  	}
  	return dp[n][sum];
  }


/*Find minimum number of coins that make a given value*/
 // coin change varition
 int mincoins(int arr[],int sum , int n ){
 	int dp[n+1][sum+1];
 	for(int j = 0 ; j< sum +1 ; j++){
 		dp[0][j] = INF;
 	}
  	for(int i = 0 ;i < n+1 ; i++){
 		dp[i][0] = 0 ;
 	}
 	
 	for(int j = 1 ; j < sum +1  ; j++){
 		if( j % arr[0] == 0){
 			dp[1][j] = j /arr[0];
 		}
 		else{
 			dp[1][j]=INF;
 		}
	 	for(int i = 2 ; i < n+1; i++){
  		for(int j =1 ; j< sum+1; j++){
  			if(arr[i-1] > j ){
  				dp[i][j] = dp[i-1][j];
  			}
  			else{
  				dp[i][j] = min(dp[i][j- arr[i-1]] + 1, dp[i-1][j]);
  			}
  		}
  	}	
 	}
 	// print
	// fo(i,n+1){
	// 	fo(j,sum+1){
	// 		if(dp[i][j] == INF){
	// 		cout <<"B" <<" ";
	// 		}
	// 		else{
	// 		cout << dp[i][j]<<" ";
	// 		}
	// 	}
	// 	cout << endl;
	// }
  	return dp[n][sum];
 	
 }

void solve(){
 int n , x;
 cin >> n >> x;
 int arr[n];
 fo(i,n){
 	cin >> arr[i];
 }
 // cout << countsubset(arr,x,n);
 // cout << countsubsetdp(arr,x,n);
 // cout << coin_change(arr,x,n);
 cout << mincoins(arr,x,n);
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