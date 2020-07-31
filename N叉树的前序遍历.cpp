/*
����һ�� N ������������ڵ�ֵ��ǰ�������
���磬����һ�� 3���� :
������ǰ�����: [1,3,5,6,2,4]��
˵��: �ݹ鷨�ܼ򵥣������ʹ�õ�������ɴ�����?
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

//����������ǰ���������
//��ͬ�����ڴ���children����
//�������У��ڽ�childrenѹ��ջ��ʱ��Ҫע��˳�򣬴Ӻ���ǰѹ��ջ�С�
//���ݹ鷨���Զ�������ߵ�children��ʼ������
