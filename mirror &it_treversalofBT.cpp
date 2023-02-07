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


class node
{
public:
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


 void itinorder(node*n){
 	stack<node*>st;
 	node*curr=n;
 	// st.push(curr);
 	while(!st.empty()|| curr!=NULL){
 		if(curr){
 			st.push(curr);
 			curr=curr->left;
 		}
 		else{
 			curr=st.top();
 			st.pop();
 			cout<<curr->data<<" ";
 			curr=curr->right;
 		}
 	}
 	return;
 }


 void itpreorder(node*n){
 	stack<node*>st;
 
 	st.push(n);
 	// st.push(curr);
 	while(!st.empty()){
	     node*curr=st.top();
	     st.pop();
	     cout<<curr->data<<" ";
 		if(curr->right){
 			st.push(curr->right);
 			
 		}
 		if(curr->left){
 			st.push(curr->left);
 		}
 	}
 	
 }


 void itpostorder(node*n){
 	stack<node*>st;
     stack<int>t;
 	st.push(n);
 	// st.push(curr);
 	while(!st.empty()){
	     node*curr=st.top();
	     st.pop();
	     t.push(curr->data);
	     if(curr->left){
 			st.push(curr->left);
 		}
 		if(curr->right){
 			st.push(curr->right);
 			
 		}
 		
 	}

 	while(!t.empty()){
 		cout<<t.top()<<" ";
 		t.pop();
 	}
 	
 }

node* mirror(node* root){
     
     if(root==NULL)return root;
	swap(root->left,root->right);
	if(root->left)
		mirror(root->left);
	if(root->right)
		mirror(root->right);
    
    return root;

}




int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    string s;
    
    node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    // inorder(tree);
    // itinorder(tree);
    itpostorder(tree);
    cout<<endl;
    // itinorder(mirror(tree));
   
    return 0;
}