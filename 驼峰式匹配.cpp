/*
������ǿ��Խ�Сд��ĸ����ģʽ�� pattern �õ�����ѯ�� query����ô����ѯ�������ģʽ��ƥ�䡣�����ǿ������κ�λ�ò���ÿ���ַ���Ҳ���Բ��� 0 ���ַ�����
��������ѯ�б� queries����ģʽ�� pattern�������ɲ���ֵ��ɵĴ��б� answer��ֻ���ڴ����� queries[i] ��ģʽ�� pattern ƥ��ʱ�� answer[i] ��Ϊ true������Ϊ false��
ʾ�� 1��
���룺queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
�����[true,false,true,true,false]
ʾ����
"FooBar" �����������ɣ�"F" + "oo" + "B" + "ar"��
"FootBall" �����������ɣ�"F" + "oot" + "B" + "all".
"FrameBuffer" �����������ɣ�"F" + "rame" + "B" + "uffer".
ʾ�� 2��
���룺queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
�����[true,false,true,false,false]
���ͣ�
"FooBar" �����������ɣ�"Fo" + "o" + "Ba" + "r".
"FootBall" �����������ɣ�"Fo" + "ot" + "Ba" + "ll".
ʾ�� 3��
�����queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
���룺[false,true,false,false,false]
���ͣ� 
"FooBarTest" �����������ɣ�"Fo" + "o" + "Ba" + "r" + "T" + "est".
��ʾ��
1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
�����ַ��������ɴ�д��СдӢ����ĸ��ɡ�
*/

class Solution {
    bool Fun(string &target, string &pattern)
    {
        int i = 0, j = 0;
        while (i < target.size() || j < pattern.size())
        {
            if (target[i] == pattern[j])
                i++, j++;
            else if (target[i] >= 'a' && target[i] <= 'z')
                i++;
            else
                return false;
        }
        return true;
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> v(n);
        for (int i = 0; i < n; i++)
            v[i] = Fun(queries[i], pattern);
        return v;
    }
};
