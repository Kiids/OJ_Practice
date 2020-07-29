/*
给定一个 N 叉树，返回其节点值的后序遍历。
例如，给定一个 3叉树 :
返回其后序遍历: [5,6,3,2,4,1].
说明: 递归法很简单，你可以使用迭代法完成此题吗 
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
    vector<int> postorder(Node* root) {
        if (!root)
            return ret;
        for (auto i : root->children)
            postorder(i);
        
        ret.push_back(root->val);
        return ret;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root)   return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* tmp = stk.top();
            stk.pop();
            res.push_back(tmp -> val);
            for(auto i : tmp -> children){
                stk.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//递归法中，先遍历children，再遍历root
//迭代法中，先遍历root，然后遍历children（从右到左） 使用stack，LIFO性质。最后翻转数组。
