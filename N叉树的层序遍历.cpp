/*
����һ�� N ������������ڵ�ֵ�Ĳ�������� (�������ң�������)��
���磬����һ�� 3���� :
������������:
[
     [1],
     [3,2,4],
     [5,6]
]
˵��:
������Ȳ��ᳬ�� 1000��
���Ľڵ��������ᳬ�� 5000��
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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;

        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                Node* t = q.front();
                q.pop();
                v.push_back(t->val);
                for (int j = 0; j < t->children.size(); j++)
                    q.push(t->children[j]);
            }
            ret.push_back(v);
        }
        return ret;
    }
};
