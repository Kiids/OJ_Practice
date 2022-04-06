/*
����һ���ַ��� s ��ʾһ������Ƕ���б�ʵ��һ�����������﷨�����������ؽ����Ľ�� NestedInteger ��
�б��е�ÿ��Ԫ��ֻ����������������Ƕ���б�
ʾ�� 1��
���룺s = "324",
�����324
���ͣ���Ӧ�÷���һ�� NestedInteger ��������ֻ��������ֵ 324��
ʾ�� 2��
���룺s = "[123,[456,[789]]]",
�����[123,[456,[789]]]
���ͣ�����һ�� NestedInteger �������һ��������Ԫ�ص�Ƕ���б�
1. һ�� integer ����ֵ 123
2. һ����������Ԫ�ص�Ƕ���б�
    i.  һ�� integer ����ֵ 456
    ii. һ������һ��Ԫ�ص�Ƕ���б�
         a. һ�� integer ����ֵ 789
��ʾ��
1 <= s.length <= 5 * 10^4
s �����֡������� "[]"������ '-' ������ ','���
������֤ s �ǿɽ����� NestedInteger
�����е�����ֵ�ķ�Χ�� [-10^6, 10^6]
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.size() == 0)
            return NestedInteger();
        if (s[0] != '[')
            return NestedInteger(stoi(s));
        string num;
        stack<NestedInteger> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                st.push(NestedInteger());
            else if (s[i] == ',')
            {
                if (!num.empty())
                    st.top().add(NestedInteger(stoi(num)));
                num.clear();
            }
            else if (s[i] == ']')
            {
                if (!num.empty())
                {
                    st.top().add(NestedInteger(stoi(num)));
                    num.clear();
                }
                if (st.size() > 1)
                {
                    auto now = st.top();
                    st.pop();
                    st.top().add(now);
                }               
            }
            else num += s[i];
        }
        return st.top();
    }
};
