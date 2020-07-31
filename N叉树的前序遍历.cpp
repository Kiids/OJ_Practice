/*
给定一个 N 叉树，返回其节点值的前序遍历。
例如，给定一个 3叉树 :
返回其前序遍历: [1,3,5,6,2,4]。
说明: 递归法很简单，你可以使用迭代法完成此题吗?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
     vector<int> ret;
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return ret;
        ret.push_back(root -> val);
        for (auto i : root -> children)
            preorder(i);
        return ret;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)   return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            stk.pop();
            res.push_back(tmp -> val);
            for(int i = tmp -> children.size()-1; i >= 0; --i){
                stk.push(tmp -> children[i]);
            }
        }
        return res;
    }
};

//跟二叉树的前序遍历相似
//不同点在于处理（children），
//迭代法中，在将children压入栈中时，要注意顺序，从后往前压入栈中。
//而递归法会自动从最左边的children开始遍历。
