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


vector<int> leftView(Node *root)
{
    vector<int> ans;
    // if (!root)
    //     return ans;

    
     queue<Node*>q;
     q.push(root);
     while(!q.empty()){
         int n=q.size();
         for(int i=0;i<n;i++){
             Node* temp=q.front();
             q.pop();
             if(i==0)
               ans.push_back(temp->data);
            
        
          // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
         }
     }
   return ans;
}

  


void solve(vi ans){
    for(auto u: ans){
        cout<<u<<" ";
    }cout<<endl;
}




int main()
{
    // Let's construct the tree as
    // shown in example
 
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // root->right->right->left = newNode(8);
 solve(leftView(root));

   // printLeftView(root);
  
}