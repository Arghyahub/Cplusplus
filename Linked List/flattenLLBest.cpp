/*
Linked List had next pointer and bottom pointer
Linked List is sorted in bottom direction
Convert the entire LL into a single sorted linkedlist in bottom direction

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50 (BUT USING BOTTOM POINTER)
*/

Node* merge(Node* left, Node* right)
{
    if (!left) return right;
    if (!right) return left;
    
    Node* tmphead , *tmp;
    if (left->data < right->data){
        tmphead = tmp = left;
        left = left->bottom;
    }
    else{
        tmphead = tmp = right;
        right = right->bottom;
    }
    
    
    while (left && right){
        if (left->data < right->data){
            tmp->bottom = left;
            tmp = tmp->bottom;
            left = left->bottom;
        }
        else{
            tmp->bottom = right;
            tmp = tmp->bottom;
            right = right->bottom;
        }
    }
    
    if (right) tmp->bottom = right;
    if (left) tmp->bottom = left;
    
    return tmphead;
}

Node *flatten(Node *root)
{
    if (root==NULL)
        return root;
    
    Node* right = flatten(root->next) ;         // TRAVERSE TO THE RIGHTMOST NODE
    root->next = NULL;                          // CUT THE RELATION BETWEEN CURRENT AND NEXT NODE BECAUSE WE ONLY NEED BOTTOM
    
    return merge(root,right) ;      // MERGE THIS, THIS IS VERY EASY
}