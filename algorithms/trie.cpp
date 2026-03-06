#include <vector>
#include <string>


using namespace std;

struct Node {
    vector<Node*> children;
    char value;
    bool isEnd;
};

class Trie {
    public:
        Node* root;
        Trie() {
            root= new Node({}, ' ', false);
        }

        void insert(string word) {
            vector<Node*>* nodes = &root->children;
            Node* parent = root;
            for (char c: word){
                bool flag = false;
                for (Node* node : *nodes){
                    if (node->value == c){
                        nodes = &node->children;
                        flag = true;
                        parent = node;
                        break;
                    }
                }
                // if current node is root - add to root, otherwise use previous node
                if (!flag){
                    // create a new node for character
                    Node* node = new Node({}, c, false);
                    parent->children.push_back(node);
                    parent = node;
                    nodes = &node->children;
                }

            }
            parent->isEnd = true;

        }

        bool search(string word) {

            Node* current = nullptr;
            vector<Node*>* nodes = &root->children;
            for (char c: word){
                bool found = false;
                for (Node* node : *nodes){
                    if (node->value == c){
                        nodes = &node->children;
                        current = node;
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }

            return current!=nullptr && current->isEnd;

        }

        bool startsWith(string prefix) {
            vector<Node*>* nodes = &root->children;
            for (char c: prefix){
                bool found = false;
                for (Node* node : *nodes){
                    if (node->value == c){
                        nodes = &node->children;
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
            }
            return true;
        }
};
