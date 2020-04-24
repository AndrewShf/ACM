/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* start = new Node(head->val);
        start->random = head->random;
        Node* phead = head->next;
        Node* pstart = start;
        // deep copy a normal list first
        Node* mem[1000];
        mem[0] = head->random;
        int len = 1;
        while(phead) {
            Node* tmp = new Node(phead->val);
            tmp->random = phead->random;
            mem[len++] = phead->random;
            pstart->next = tmp;
            pstart = pstart->next;
            phead = phead->next;
        }
        // change the original list's random index
        phead = head;
        pstart = start;
        while(phead) {
            phead->random = pstart;
            phead = phead->next;
            pstart = pstart->next;
        }
        pstart = start;
        while(pstart) {
            if (pstart->random != NULL)
                pstart->random = pstart->random->random;
            pstart = pstart->next;
        }
        phead = head;
        int i = 0;
        while(phead) {
            phead->random = mem[i++];
            phead = phead->next;
        }
        return start;
    }
};



// more formal answer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> old2new;
    Node* copyRandomList(Node* head) {
        if (!head) return 0;
        Node* node = new Node(head->val);
        old2new[head] = node;
        node->next = copyRandomList(head->next);
        if(head->random)
            node->random = old2new[head->random];
        return node;
    }
};
