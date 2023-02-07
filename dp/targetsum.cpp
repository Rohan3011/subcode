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
given a target sum return the no. of combination sum is equal to target.
create combination by assigning '+' or '-' operator before the 
values so that there total sum should be equal to target .
e.g.
 arr = {1 , 2, 3, 1} ,target = 1;
output : +1 -2 +3 -1 = 1 

*/
int targetsum(int arr[],int sum , int n){
	if()

}


void solve(){
 int n ,sum;
 cin >> n >> sum ;
 int arr[n];
 fo(i,n){
 	cin >> arr[i];
 }
 targetsum(arr,sum,n);
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