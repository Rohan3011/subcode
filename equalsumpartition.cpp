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


bool solve(vector<int> arr,long long sum , int n){
	// int x =sum;


	if(sum==0){
		return true; 
	}
	if(n==0){
		return false;
	}
	return (solve(arr,sum-arr[n-1] , n-1) || solve(arr,sum ,n-1));

}



bool solveit(vector<int>arr,int sum ,int n){
		    

	bool dp[n+1][sum+1];

	for(int j =0 ; j<sum+1 ;j++){
		dp[0][j]=false;
	}
	
	for(int i = 0;i<n+1 ;i++){
		dp[i][0] = true ;
	}

	for(int i = 1 ; i< n+1 ;i++){
		for(int j =1 ;j <sum+1 ; j++){
			if(arr[i-1] >j){
				dp[i][j]= dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];

			}
		}
	}
	// fo(i,n+1){
	// 	fo(j,sum+1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return dp[n][sum];

}


bool canPartition(vector<int>& nums){
sort(nums.begin(), nums.end());
	int sum =0 ,n = nums.size();
	for(int i=0 ;i<n;i++){
		sum+=nums[i];
	}
	

	if(sum&1){
		return false;
	}

	return solveit(nums,sum/2,n);

}






int main()
{
    ios::sync_with_stdio(0);cin.tie(0);


    //int t;
    //cin>>t;
    //while(t--){
    //}
   int n ;
   cin >> n ;
   vi arr(n);
   fo(i,n){
   	cin >> arr[i];
   }
   cout << canPartition(arr);
    return 0;
}