#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef vector<pair<int, string>> vpis;
typedef vector<pair<int, int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define fo2(i,a,n) for(int i= a ; i<n ; i++ )
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define endl "\n"

#ifndef ONLINE_JUDGE
#define deb(x) cerr<< #x << "="<< x<<endl
#define deb2(x,y) cerr<< #x << "="<< x<<","<< #y << "="<< y<<endl
#else
#define deb(x)
#define deb2(x,y)
#endif



void solve() {
	int n , k ;
	cin >> n >> k ;
	int arr[n];
	int temp = k , ans = INT_MIN , sum = 0 ;
	fo(i, n) {
		cin >> arr[i];
	}
	fo(i, k) {
		sum += arr[i];
	}
	for (int i = 0 ; i + k < n ; i++) {
		sum = sum - arr[i] + arr[k + i];
		ans = max (sum , ans);
		deb2(ans, sum);
	}
	cout << ans ;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen ("error.txt", "w", stderr);
#endif


	//int t;
	//cin>>t;
	//while(t--){
	//}
	solve();

	return 0;
}
