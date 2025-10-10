

/**

https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTabValue=PROBLEM

 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int count(Node *curr){
	int ans = 0;
	while (curr) {
		curr = curr->next;
		ans++;
	}
	return ans;
}

Node* solve(Node *curr, int k, int N){
	if (N<k) return curr;
	Node *prev = NULL, *start = curr;
	for (int i=0; i<k; i++){
		Node *nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}

	start->next = solve(curr,k,N-k);
	return prev;
}

Node* kReverse(Node* head, int k) {
	int N = count(head);
	return solve(head,k,N);
}
