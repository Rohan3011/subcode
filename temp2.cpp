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
#define eb emplace_back ;
#define F first
#define S second
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;

ll PrimeFactorization(ll n ) {
    ll cnt = 1 ;
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0)
            cnt++ ;
        if (n / i != i)
            cnt++ ;
    }
    return cnt ;
}

void solve() {
    ll n ;
    cin >> n ;
    cout << PrimeFactorization << "\n" ;
}




int main()
{
    ios::sync_with_stdio(0); cin.tie(0);


    //int t;
    //cin>>t;
    //while(t--){
    //}
    solve();
    return 0;
}