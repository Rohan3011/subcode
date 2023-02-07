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
   ll ans = 0 ;
   vll arr(32, 0 ) ;
   cin >> n >> k  ;
   int A[n] ;
   fo(i, n) {
      cin >> A[i] ;
   }

   for (auto u : A) {
      fo(i, 32) {
         if (u & (1 << i)) {
            arr[i]++ ;
         }
      }
   }

   for (auto u : arr) {
      if ( u >= 1) {
         ans += (u / k) + (u % k);
      }
   }
   cout << ans << endl ;

   // for (auto u : arr) {
   //    cout << u << " " ;
   // }
}



int main()
{
   ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
   freopen ("error.txt", "w", stderr);
#endif

   int t ;
   cin >> t ;
   while (t--) {
      solve();

   }


   return 0;
}