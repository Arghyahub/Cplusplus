/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* newNode(Node* node) {
        if (!node) return NULL;
        return new Node(node->data);
    }
    Node* nextNode(Node* node){
        if (!node) return NULL;
        return node->next;
    }
  public:
    Node* cloneLinkedList(Node* head) {
        Node* main = head;
        // 1. inserting nodes in between
        while (main) {
            Node* mainNext = main->next;
            main->next = newNode(main);
            main->next->next = mainNext;
            main = mainNext;
        }
        
        main = head;
        Node* ans = main->next;
        // 2. Copy Random Pointers
        while (main) {
            Node* image = main->next;
            Node* mainRandom = main->random;
            Node* imageRandom = nextNode(mainRandom);
            
            image->random = imageRandom;
            main = image->next;
        }
        
        main = head;
        // 3. Break the lists
        while (main) {
            Node* image = main->next;
            Node* mainNext = nextNode(image);
            Node* imageNext = nextNode(mainNext);
            
            main->next = mainNext;
            main = main->next;
            image->next = imageNext;
        }
        
        return ans;
    }
};
