#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;
typedef pair<int,string> pis;
typedef vector<pair<int,string>> vpis;
typedef vector<pair<int,int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define INF 0x3f3f3f3f
#define endl "\n"

struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

map<int,vi>m;
void vertical_order_traversal(Node* n, int hd,map<int,vi>&m){
 if(n==NULL)return;
 if(!m.count(hd))
      m[hd].pb(n->data);
 vertical_order_traversal(n->left,hd-1,m);
 vertical_order_traversal(n->right,hd+1,m);
}

void pr(map<int,vi>m){
	for(auto u=m.begin();u!=m.end();u++){
		fo(i,u->S.size()){
			cout<<u->S[i]<<" ";
		}cout<<endl;
	}
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
   
   Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    vertical_order_traversal(root,0,m);
    pr(m);

    return 0;
}