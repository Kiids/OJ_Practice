/*
���л���������һ�ַ�����ʹ�� ǰ����� ������������һ���ǿսڵ�ʱ�����ǿ��Լ�¼������ڵ��ֵ���������һ���սڵ㣬���ǿ���ʹ��һ�����ֵ��¼������ #��
���磬����Ķ��������Ա����л�Ϊ�ַ��� "9,3,4,#,#,1,#,#,2,#,6,#,#"������ # ����һ���սڵ㡣
����һ���Զ��ŷָ������У���֤���Ƿ�����ȷ�Ķ�������ǰ�����л�����дһ���ڲ��ع����������µĿ����㷨��
��֤ ÿ���Զ��ŷָ����ַ���Ϊһ��������Ϊһ����ʾ null ָ��� '#' ��
�������Ϊ�����ʽ������Ч��
��������Զ����������������Ķ��ţ����� "1,,3" ��
ע�⣺�������ؽ�����
ʾ�� 1:
����: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
���: true
ʾ�� 2:
����: preorder = "1,#"
���: false
ʾ�� 3:
����: preorder = "9,#,#,1"
���: false
��ʾ:
1 <= preorder.length <= 104
preorder ���Զ��� ������ �ָ��� [0,100] ��Χ�ڵ������� ��#�� ���
*/

class Solution {
    vector<string> split(string& s)
    {
        stringstream ss(s);
        string t;
        vector<string> v;
        while (getline(ss, t, ','))
            v.push_back(t);
        return v;
    }
public:
    bool isValidSerialization(string preorder) {
        vector<string> s = split(preorder);
        int in = 0, out = 0;
        for (int i = 0, m = 0; i < s.size(); i++)
        {
            if (s[i] != "#")
                out += 2;
            if (i != 0)
                in++;
            if (i != s.size() - 1 && out <= in)
                return false;
        }
        return in == out;
    }
};
