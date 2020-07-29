/*
����һ�� N ������������ڵ�ֵ�ĺ��������
���磬����һ�� 3���� :
������������: [5,6,3,2,4,1].
˵��: �ݹ鷨�ܼ򵥣������ʹ�õ�������ɴ����� 
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
//�ݹ鷨�У��ȱ���children���ٱ���root
//�������У��ȱ���root��Ȼ�����children�����ҵ��� ʹ��stack��LIFO���ʡ����ת���顣
