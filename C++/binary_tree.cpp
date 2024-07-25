// Example binary tree with tree traversals

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int v) {
        value = v;
        left = right = NULL;
    }
};

class Traversals {

    public:

        TreeNode *insert_level_order(vector<int> A, TreeNode *root, int i, int size) {
            if (i < size) {
                TreeNode *tmp = new TreeNode(A[i]);
                root = tmp;

                int l = 2*i + 1;
                int r = 2*i + 2;

                root->left = insert_level_order(A, root->left, l, size);
                root->right = insert_level_order(A, root->right, r, size);
            }
            return root;
        }

        /*TreeNode *insert_level_order(vector<int> A) {
            if (A.empty()) {
                return NULL;
            }

            TreeNode *root = new TreeNode(A[0]);
            vector<TreeNode*> v;
            v.push_back(root);

            int i = 1;
            //int front = 0;
            while (i < A.size()) {
                //TreeNode *node = v[front++];
                TreeNode *node = v.front();
                v.erase(v.begin());
                
                if (i < A.size()) {
                    node->left = new TreeNode(A[i++]);
                    v.push_back(node->left);
                }

                if (i < A.size()) {
                    node->right = new TreeNode(A[i++]);
                    v.push_back(node->right);
                }
            }
            return root;
        }*/

        void preorder_traversal_rec(TreeNode *root) {
            if (root == NULL) {
                return;
            }

            cout << root->value << " ";
            preorder_traversal_rec(root->left);
            preorder_traversal_rec(root->right);
        }

        void inorder_traversal_rec(TreeNode *root) {
            if (root == NULL) {
                return;
            }

            preorder_traversal_rec(root->left);
            cout << root->value << " ";
            preorder_traversal_rec(root->right);
        }

        void postorder_traversal_rec(TreeNode *root) {
            if (root == NULL) {
                return;
            }

            preorder_traversal_rec(root->left);
            preorder_traversal_rec(root->right);
            cout << root->value << " ";
        }

        vector<int> preorder_traversal_iter(TreeNode *root) {
            if (root == NULL) {
                return {-1};
            }
            vector<TreeNode*> v;
            v.push_back(root);
            vector<int> res = {};

            while (!v.empty()) {
                TreeNode *node = v.back();
                res.push_back(node->value);
                v.pop_back();

                if (node->right) {
                    v.push_back(node->right); 
                }

                if (node->left) {
                    v.push_back(node->left); 
                }
            }
            return res;
        }

        vector<int> inorder_traversal_iter(TreeNode *root) {
            if (root == NULL) {
                return {-1};
            }
            vector<TreeNode*> v;
            vector<int> res = {};
            TreeNode *node = root;

            while (true) {
                if (node) {
                    v.push_back(node);
                    node = node->left;
                } else {
                    if (v.empty()) { break; }
                    node = v.back();
                    res.push_back(node->value);
                    v.pop_back();
                    node = node->right;
                }
            }
            return res;
        }

        // Not sure if implementing the post order like this is completely valid but all you need to do is reverse the array after creation
        vector<int> postorder_traversal_iter(TreeNode *root) {
            if (root == NULL) {
                return {-1};
            }
            vector<TreeNode*> v;
            v.push_back(root);
            vector<int> res = {};

            while (!v.empty()) {
                TreeNode *node = v.back();
                res.push_back(node->value);
                v.pop_back();

                if (node->left) {
                    v.push_back(node->left); 
                }

                if (node->right) {
                    v.push_back(node->right); 
                }
            }
            return res;
        }

};

int sum_recur(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return root->value + sum_recur(root->left) + sum_recur(root->right);
}

int sum_iter(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    vector<TreeNode*> v;
    v.push_back(root);
    int sum = 0;
    while (!v.empty()) {
        TreeNode *node = v.back();
        sum += node->value;
        v.pop_back();

        if (node->left) {
            v.push_back(node->left);
        }

        if (node->right) {
            v.push_back(node->right);
        }
    }
    return sum;
}


int main() {
    
    vector<int> arr = {1,2,3,1};
    Traversals tree;
    //TreeNode *root = tree.insert_level_order(arr);
    TreeNode *root = tree.insert_level_order(arr, NULL, 0, arr.size());

    tree.preorder_traversal_rec(root);
    cout << endl;

    tree.inorder_traversal_rec(root);
    cout << endl;

    tree.postorder_traversal_rec(root);
    cout << endl;

    vector<int> x = tree.preorder_traversal_iter(root);
    for (auto it: x){
        cout << it << " ";
    }
    cout << endl;

    x = tree.inorder_traversal_iter(root);
    for (auto it: x){
        cout << it << " ";
    }
    cout << endl;

    x = tree.postorder_traversal_iter(root);
    for (int i=x.size()-1; i>=0; i--) {
        cout << x[i] << " ";
    }
    cout << endl;


    cout << sum_recur(root) << endl;
    cout << sum_iter(root) << endl;

    return 0;
}





