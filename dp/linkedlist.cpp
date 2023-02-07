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

class node {
public :
	node* next ;
	int data ;
	node(int val) {
		data = val ;
		next = NULL ;
	}
};

void InsertatTail(node* &head , int val ) {
	node* n = new node(val) ;
	if (head == NULL) {
		head = n ;
		return ;
	}
	node* temp = head ;
	while (temp->next != NULL) {
		temp = temp->next ;
	}
	temp->next = n ;

}

void InsertatHead(node* &head , int val) {
	node* n = new node(val) ;
	n->next = head ;
	head = n ;
}


void printll(node* head) {
	while (head != NULL) {
		cout << head->data << " -> " ;
		head = head->next ;
	} cout << "NULL" << endl ;
}

void DeleteNode(node* &head , int val) {
	node* prev = NULL ;
	node* temp = head ;
	while (temp->data != val) {
		prev = temp ;
		temp = temp->next ;
	}
	if (prev == NULL) {
		head = head->next ;
		return ;
	}
	prev->next = temp->next ;

}
// Iterative
void reversell(node* &head ) {

	node* curr = head ;
	node* prev = NULL ;
	node*  temp ;
	while (curr != NULL  ) {
		temp = curr->next ;
		curr->next = prev ;
		prev = curr ;
		curr = temp ;

	}
	head = prev ;

}
// Recursive
node* reverserecll(node* &head) {

	if (head == NULL || head->next == NULL) {
		return head ;
	}

	node* newhead = reverserecll(head->next);
	head->next->next = head;
	head->next = NULL ;
	return newhead;
}


// Reverse a k list

node* kreverse(node* &head , int k  ) {
	int cnt = 0 ;
	node* curr = head ;
	node* prev = NULL ;
	node* temp ;

	while (curr != NULL && cnt < k) {
		temp = curr->next ;
		curr->next = prev ;
		prev = curr ;
		curr = temp ;
		cnt++;
	}
	if (temp != NULL) {
		head-> next = kreverse(temp , k) ;
	}
	return prev ;


}




void solve() {
	node* head = NULL;
	InsertatTail(head , 1);
	InsertatTail(head , 2);
	InsertatTail(head , 3);
	InsertatTail(head , 4);
	InsertatTail(head , 5);
	// reversell(head);

	// InsertatHead(head , 0);
	// DeleteNode(head , 11);
	printll(head);
	// printll(reverserecll(head));
	printll(kreverse(head , 2));


}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen ("error.txt", "w", stderr);
#endif

	solve();

	return 0;
}