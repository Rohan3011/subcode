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

int part(int arr[], int low , int high) {
	int pivot = arr[high] ;
	int i = (low - 1); // right most index of smaller value so far
	for (int j = low ; j <= high - 1  ; j++) {
		if (arr[j] < pivot) {
			i++ ;
			swap(arr[i] , arr[j]) ;
		}
	}
	swap(arr[i + 1] , arr[high]);
	return i + 1 ;
}


void quicksort(int arr[], int low, int high) {
	if (low <  high) {
		int pi = part(arr, low, high);
		quicksort(arr, low, pi - 1) ;
		quicksort(arr, pi + 1, high);
	}
}



void solve() {
	int n ;
	cin >> n ;
	int arr[n] ;
	fo(i, n) {
		cin >> arr[i] ;
	}
	quicksort(arr, 0, n - 1) ;

	for (auto u : arr) {
		cout << u << " " ;
	}

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

#ifndef ONLINE_JUDGE
	cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}