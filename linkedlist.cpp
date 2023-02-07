#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<int, string> pis;
typedef vector<pair<int, string>> vpis;
typedef vector<pair<int, int>> vpi;

#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define INF 0x3f3f3f3f
#define endl "\n"

class node
{
public:
	int data;
	node *next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

void insertattail(node *&head, int val)
{
	node *n = new node(val);
	if (head == NULL)
	{
		head = n;
		return;
	}
	node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void insertathead(node *&head, int val)
{
	node *n = new node(val);
	n->next = head;
	head = n;
}

void display(node *head)
{
	while (head != NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL" << endl;
}

// void delnode(node* &head,int key){
//       node* temp=head;
//       while(temp!=NULL){
//       	if((temp->next)->data==key){
//       		temp->next=(temp->next)->next;
//       		return;
//       	}
//       temp=temp->next;
//       }
// }

void solve()
{
	node *head = NULL;
	insertathead(head, 3);
	insertathead(head, 2);
	insertathead(head, 1);
	insertattail(head, 33);
	// delnode(head,33);
	display(head);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	//int t;
	//cin>>t;
	//while(t--){
	//
	//}
	solve();
	return 0;
}