/*
һ�� �������ַ���������Ϊ��
������Сд��ĸ ['a', 'b', 'c'].
�������� 1 �� s.length - 1 ֮��� i ������ s[i] != s[i + 1] ���ַ������±�� 1 ��ʼ����
�ȷ�˵���ַ��� "abc"��"ac"��"b" �� "abcbabcbcb" ���ǿ����ַ��������� "aa"��"baa" �� "ababbc" �����ǿ����ַ�����
������������ n �� k ������Ҫ������Ϊ n �����п����ַ������ֵ�������
���㷵�������ĵ� k �������ַ������������Ϊ n �Ŀ����ַ������� k ������ô���㷵�� ���ַ��� ��
ʾ�� 1��
���룺n = 1, k = 3
�����"c"
���ͣ��б� ["a", "b", "c"] ���������г���Ϊ 1 �Ŀ����ַ����������ֵ��������������ַ���Ϊ "c" ��
ʾ�� 2��
���룺n = 1, k = 4
�����""
���ͣ�����Ϊ 1 �Ŀ����ַ���ֻ�� 3 ����
ʾ�� 3��
���룺n = 3, k = 9
�����"cab"
���ͣ�����Ϊ 3 �Ŀ����ַ����ܹ��� 12 �� ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"] ���� 9 ���ַ���Ϊ "cab"
ʾ�� 4��
���룺n = 2, k = 7
�����""
ʾ�� 5��
���룺n = 10, k = 100
�����"abacbabacb"
��ʾ��
1 <= n <= 10
1 <= k <= 100
*/

class Solution {
public:
    string getHappyString(int n, int k) {
        char abc[3] = {'a', 'b', 'c'};
        char ch[3][2] = {{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
        int state[3][2] = {{1, 2}, {0, 2}, {0, 1}};
        if (k > (int)pow(2, n - 1) * 3)
            return "";
        string s;
        k--;
        int p = k / (int)pow(2, n - 1);
        k %= (int)pow(2, n - 1);
        s.push_back(abc[p]);
        for (int i = n - 1; i > 0; i--)
        {
            int tmp = (int)pow(2, i - 1);
            s.push_back(ch[p][k / tmp]);
            p = state[p][k / tmp];
            k %= tmp;
        }
        return s;
    }
};

//�൱�������Ŷ������У�ͨ�������������⡣
//��Ҫע�����ڵ������ַ�����ͬ����������ʹ�ö���״̬�ķ���


class Solution {
    vector<string> v;
    void DFS(int n, int cur, string t)
    {
		if (cur == n)
        {
			v.push_back(t);
			return;
		}			
		if (check(t, 'a'))DFS(n, cur + 1, t + 'a');
		if (check(t, 'b'))DFS(n, cur + 1, t + 'b');
		if (check(t, 'c'))DFS(n, cur + 1, t + 'c');
	}
	bool check(string &t, char a)
    {
		if (t.empty())
            return true;
		return t[t.size() - 1] != a;
	}
public:
    string getHappyString(int n, int k) {
		DFS(n, 0, "");
		if (v.size() < k)
            return "";
		else return v[k - 1];
    }
};

//����
//�ж�Ҫ��ӵ��ַ��뵱ǰ�ַ����Ĺ�ϵ������ǰ�ַ���Ϊ�ջ�ǰ�ַ������һ���ַ���Ҫ����ַ���ͬ���������ַ�������������ַ���
//��Ϊ�ݹ�˳����a,b,c������ӵģ�������ӵ��ַ����������ǰ��ֵ����С������������ģ�����ж�����Ĵ�С�Ƿ����k��
//�����ڣ��򷵻������е�k���ַ��������򷵻ؿ��ַ�����

