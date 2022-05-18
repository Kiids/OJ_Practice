/*
完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。
实现 CBTInserter 类:
CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
CBTInserter.get_root() 将返回树的头节点。
示例 1：
输入
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
输出
[null, 1, 2, [1, 2, 3, 4]]
解释
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
提示：
树中节点数量范围为 [1, 1000] 
0 <= Node.val <= 5000
root 是完全二叉树
0 <= val <= 5000 
每个测试用例最多调用 insert 和 get_root 操作 10^4 次
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        // 只要当前节点存在左右子节点，它就是满的，将左右子节点入栈
        // 直到遇见一个子节点不满的节点为止，此时退出循环，它就是要找的父节点
        while (q.front()->left != nullptr && q.front()->right != nullptr)
        {
            auto tmp = q.front();
            q.pop();
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
    
    int insert(int val) {
        TreeNode* parent = q.front();        // 取队首节点，它的子节点不满
        TreeNode* node = new TreeNode(val);
        if (parent->left == nullptr)         // 若没有左子节点，直接挂到左边
            parent->left = node;
        else                                 // 若没有右子节点，直接挂到右边
        {
            parent->right = node;
            q.pop();                         // 此时该节点已满，出队
            q.push(parent->left);            // 它的左右子节点继续入队
            q.push(parent->right);
        }

        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
 
 // 层序遍历找到最后一层应该插入的节点位置的父节点
 
