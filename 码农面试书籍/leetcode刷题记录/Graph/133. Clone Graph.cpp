/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<const Node*,Node*> copied;
        clone(node,copied);
        return copied[node];
    }

private:
    static  Node* clone(Node* node,unordered_map<const Node*,Node*>& copied){
        if(copied.find(node)!=copied.end()) return copied[node];//如果找到了，直接返回。
        Node* new_node=new Node(node->val);
        copied[node]=new_node;
        for(auto nbr:node->neighbors){
            new_node->neighbors.push_back(clone(nbr,copied));
        }
        return new_node;
    }
};
