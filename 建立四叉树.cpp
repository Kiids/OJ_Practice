/*
����һ�� n * n ���� grid ������������ 0 �� 1 ��ɡ��������Ĳ�����ʾ�þ��� grid ��
����Ҫ�����ܱ�ʾ����� �Ĳ��� �ĸ���㡣
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
���룺grid = [[0,1],[1,0]]
�����[[0,1],[1,0],[1,1],[1,1],[1,0]]
���ͣ���ʾ���Ľ������£�
��ע�⣬�������Ĳ�����ͼʾ�У�0 ��ʾ false��1 ��ʾ True ��
ʾ�� 2��
���룺grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
�����[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
���ͣ������е�����ֵ������ͬ�����ǽ����񻮷�Ϊ�ĸ�������
topLeft��bottomLeft �� bottomRight ��������ͬ��ֵ��
topRight ���в�ͬ��ֵ��������ǽ����ٷ�Ϊ 4 ������������ÿ�������񶼾�����ͬ��ֵ��
��������ͼ��ʾ��
ʾ�� 3��
���룺grid = [[1,1],[1,1]]
�����[[1,1]]
ʾ�� 4��
���룺grid = [[0]]
�����[[1,0]]
ʾ�� 5��
���룺grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
�����[[0,1],[1,1],[1,0],[1,0],[1,1]]
��ʾ��
n == grid.length == grid[i].length
n == 2^x ���� 0 <= x <= 6
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
    bool CheckLeaf(int top, int left, int bottom, int right, vector<vector<int>>& grid)
    {
        int same = grid[top][left];
        for (int i = top; i <= bottom; i++)
            for (int j = left; j <= right; j++)
                if (grid[i][j] != same) return false;
        return true;
    }
    Node* Fun(int top, int left, int bottom, int right, vector<vector<int>>& grid)
    {
        Node* ret = new Node();
        if (CheckLeaf(top, left, bottom, right, grid))
        {
            ret->val = grid[top][left];
            ret->isLeaf = true;
            return ret;
        }

        ret->isLeaf = false;
        ret->val = 1;

        ret->topLeft = Fun(top, left, top + (bottom - top) / 2, left + (right - left) / 2, grid);
        ret->topRight = Fun(top, right - (right - left) / 2, top + (bottom - top) / 2, right, grid);
        ret->bottomLeft = Fun(bottom - (bottom - top) / 2, left, bottom, left + (right - left) / 2, grid);
        ret->bottomRight = Fun(bottom - (bottom - top) / 2, right - (right - left) / 2, bottom, right, grid);

        return ret;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return Fun(0, 0, grid.size() - 1, grid.size() - 1, grid);
    }
};
