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
#define FO(i,a,n) for(int i= a ; i<n ; i++ )
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;

#ifndef ONLINE_JUDGE
#define deb(x) cerr<< #x << "="<< x<<endl
#define deb2(x,y) cerr<< #x << "="<< x<<","<< #y << "="<< y<<endl
#else
#define deb(x)
#define deb2(x,y)
#endif



ll isPrime(ll n ) {
    ll cnt = 0 ;
    for (int i = 1 ; i * i <= n ; i++) {
        deb2(i , n / i) ;
        if (n % i == 0) {
            cnt++ ;
            if (n / i != i)
                cnt++ ;
        }
    }
    return cnt ;
}

const int N = 100000000 ;

bool sieve[N]  ;
void CreateSieve() {
    for (int i = 2 ; i <= N ;  i++) {
        sieve[i] = true ;
    }

    for (ll i =  2 ; i * i <= N ; i++) {
        if (sieve[i]) {
            for (ll j = i * i ; j <= N  ; j += i) {
                sieve[j] = false ;
            }
        }
    }
}

int spf[N] ;
void SmallestPrimeFactor() {
    for (int i = 0 ; i <= N ; i++)
        spf[i] = i;

    for (ll i = 2 ; i * i <= N ; i++) {
        if (spf[i] == i) {
            for (ll j = i * i ; j <= N ; j += i) {
                if (spf[j] == j)
                    spf[j] = i ;
            }
        }
    }
}

void solve() {
    CreateSieve() ;
    // SmallestPrimeFactor() ;

    // ll n ;
    // cin >> n ;
    // cout << (sieve[n] ? "Prime \n" : "Non-prime\n" ) ;
    // cout << isPrime(n) << "\n" ;

    // while (n > 1) {
    //     cout << spf[n] << " " ;
    //     n = n / spf[n] ;
    // }
    ll cnt = 0 ;
    for (ll i = 2 ; i <= N  ; i++) {

        if (sieve[i]) {
            cnt++ ;
            if ( cnt % 100 == 1) {
                cout << i << "\n" ;
            }
        }
    }
    // cout << "\n" ;
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