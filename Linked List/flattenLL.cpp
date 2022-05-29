#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* down, Node* right)
{
    if (down==NULL)
        return right ;
    if (right==NULL)
        return down ;
    
    Node* ans = new Node(-1) ;
    Node* temp = ans ;
    while (down!=NULL && right!=NULL)
    {
        if (down->data < right->data)
        {
            temp->child = down ;
            temp = temp->child ;
            down= down->child ;
        }
        else
        {
            temp ->child = right ;
            temp = temp->child ;
            right = right ->child ;
        }
    }
    while(down!=NULL)
    {
        temp->child = down ;
        temp = temp->child ;
        down= down->child ;
    }
    
    while(right!=NULL)
    {
        temp ->child = right ;
        temp = temp->child ;
        right = right ->child ;
    }
    
    ans = ans->child ;
    return ans ;
    
}
Node* flattenLinkedList(Node* head) 
{
    if (head==NULL || head->next == NULL)
        return head ;
	Node* down = head ;
    Node* temp = down->next ;
    down->next = NULL ;
    
    Node* right = flattenLinkedList(temp) ;
    
    
    Node* ans = merge(down,right) ;
    return ans ;
}
