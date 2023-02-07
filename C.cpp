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



void solve(){
 int n , m , d ,sum =0,cnt=0;
 cin >> n >> m >> d;
 int arr[n][m];
 fo(i,n){
    fo(j,m){
        cin >> arr[i][j];
        sum+=arr[i][j];
    }
 }
 int x = sum/(n*m);
 if(sum%(n*m)!=0){
    cout << -1 <<endl;
    return;
 }
 fo(i,n){
    fo(j,m){
        if(arr[i][j]!=x){
            if( (arr[i][j]+d==x) || (arr[i][j]-d==x) ){
               cnt++;
            }
            else{
                 cout << -1 <<endl;
                return;
            }
        }
    }
 }
 cout << cnt <<endl;
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