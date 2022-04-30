/*
�����ƾ����е�����Ԫ�ز��� 0 ���� 1 ��
���������Ĳ�����quadTree1 �� quadTree2������ quadTree1 ��ʾһ�� n * n �����ƾ��󣬶� quadTree2 ��ʾ��һ�� n * n �����ƾ���
���㷵��һ����ʾ n * n �����ƾ�����Ĳ��������� quadTree1 �� quadTree2 ����ʾ�����������ƾ������ ��λ�߼������� �Ľ����
ע�⣬�� isLeaf Ϊ False ʱ������԰� True ���� False ��ֵ���ڵ㣬����ֵ���ᱻ������� ���� ��
�Ĳ������ݽṹ�У�ÿ���ڲ��ڵ�ֻ���ĸ��ӽڵ㡣���⣬ÿ���ڵ㶼���������ԣ�
val������Ҷ�ӽ��������������ֵ��1 ��Ӧ True��0 ��Ӧ False��
isLeaf: ������ڵ���һ��Ҷ�ӽ��ʱΪ True��������� 4 ���ӽڵ���Ϊ False ��
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
���ǿ��԰����²���Ϊ��ά���򹹽��Ĳ�����
�����ǰ�����ֵ��ͬ������ȫΪ 0 ����ȫΪ 1������ isLeaf ��Ϊ True ���� val ��Ϊ������Ӧ��ֵ�������ĸ��ӽڵ㶼��Ϊ Null Ȼ��ֹͣ��
�����ǰ�����ֵ��ͬ���� isLeaf ��Ϊ False�� �� val ��Ϊ����ֵ��Ȼ������ͼ��ʾ������ǰ���񻮷�Ϊ�ĸ�������
ʹ���ʵ���������ݹ�ÿ���ӽڵ㡣
��������˽��������Ĳ��������ݣ����Բο� wiki ��
�Ĳ�����ʽ��
���Ϊʹ�ò���������Ĳ��������л���ʽ������ null ��ʾ·����ֹ���������治���ڽڵ㡣
��������������л��ǳ����ơ�Ψһ�������ǽڵ����б���ʽ��ʾ [isLeaf, val] ��
��� isLeaf ���� val ��ֵΪ True �����ʾ�����б� [isLeaf, val] �е�ֵΪ 1 ����� isLeaf ���� val ��ֵΪ False �����ʾֵΪ 0 ��
ʾ�� 1��
���룺quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
, quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
�����[[0,0],[1,1],[1,1],[1,1],[1,0]]
���ͣ�quadTree1 �� quadTree2 ������ʾ�����Ĳ�������ʾ�Ķ����ƾ���Ҳ�Ѿ�������
������Ƕ�������������а�λ�߼������㣬����Եõ�����Ķ����ƾ�����һ����Ϊ������Ĳ�����ʾ��
ע�⣬����չʾ�Ķ����ƾ��������Ϊ�˸��õ�˵�����⣬�����蹹������ƾ�������ý���Ĳ�����
ʾ�� 2��
���룺quadTree1 = [[1,0]]
, quadTree2 = [[1,0]]
�����[[1,0]]
���ͣ�����������ʾ�ľ����С��Ϊ 1*1��ֵȫΪ 0 
��������СΪ 1*1��ֵȫΪ 0 ��
ʾ�� 3��
���룺quadTree1 = [[0,0],[1,0],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,0],[1,1],[1,1],[1,0],[1,1]]
�����[[1,1]]
ʾ�� 4��
���룺quadTree1 = [[0,0],[1,1],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,0],[1,1],[0,1],[1,1],[1,1],null,null,null,null,[1,1],[1,0],[1,0],[1,1]]
�����[[0,0],[1,1],[0,1],[1,1],[1,1],null,null,null,null,[1,1],[1,0],[1,0],[1,1]]
ʾ�� 5��
���룺quadTree1 = [[0,1],[1,0],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,1],[0,1],[1,0],[1,1],[1,0],[1,0],[1,0],[1,1],[1,1]]
�����[[0,0],[0,1],[0,1],[1,1],[1,0],[1,0],[1,0],[1,1],[1,1],[1,0],[1,0],[1,1],[1,1]]
��ʾ��
quadTree1 �� quadTree2 ���Ƿ�����ĿҪ����Ĳ�����ÿ��������һ�� n * n �ľ���
n == 2^x ������ 0 <= x <= 9.
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf)
            return quadTree1->val ? quadTree1 : quadTree2;
        else if (quadTree2->isLeaf)
            return quadTree2->val ? quadTree2 : quadTree1;

        // ������Ҷ�ӽڵ㣬�ĸ�λ�õݹ�
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        // �ж��Ƿ���Ժϲ�->����Ҷ�ӽڵ㣬��val���
        if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf && quadTree1->bottomLeft->isLeaf  
            && quadTree1->bottomRight->isLeaf 
            && quadTree1->topLeft->val == quadTree1->topRight->val
            && quadTree1->topRight->val == quadTree1->bottomLeft->val
            && quadTree1->bottomLeft->val == quadTree1->bottomRight->val)
        {
            quadTree1->isLeaf = true;
            quadTree1->val = quadTree1->topLeft->val;
            quadTree1->topLeft = nullptr;
            quadTree1->topRight = nullptr;
            quadTree1->bottomLeft = nullptr;
            quadTree1->bottomRight = nullptr;
        }

        return quadTree1;
    }
};
