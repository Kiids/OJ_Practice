/*
һ�� ���� ָ����һ�����еĵ����õ����ո������������ҿ�ͷ�ͽ�βû���κοո�ÿ�����ʶ�ֻ����Сд���дӢ����ĸ��
���ǿ��Ը�һ��������� �� 1 ��ʼ�ĵ���λ������ �����ҽ����������е��� ����˳�� ��
�ȷ�˵������ "This is a sentence" ���Ա�����˳��õ� "sentence4 a3 is2 This1" ���� "is2 sentence4 This1 a3" ��
����һ�� ����˳�� �ľ��� s ���������ĵ��ʲ����� 9 �����������¹��첢�õ�ԭ��˳��ľ��ӡ�
ʾ�� 1��
���룺s = "is2 sentence4 This1 a3"
�����"This is a sentence"
���ͣ��� s �еĵ��ʰ��ճ�ʼλ�����򣬵õ� "This1 is2 a3 sentence4" ��Ȼ��ɾ�����֡�
ʾ�� 2��
���룺s = "Myself2 Me1 I4 and3"
�����"Me Myself and I"
���ͣ��� s �еĵ��ʰ��ճ�ʼλ�����򣬵õ� "Me1 Myself2 and3 I4" ��Ȼ��ɾ�����֡�
��ʾ��
2 <= s.length <= 200
s ֻ����Сд�ʹ�дӢ����ĸ���ո��Լ��� 1 �� 9 �����֡�
s �е�����ĿΪ 1 �� 9 ����
s �еĵ����ɵ����ո�ָ���
s �������κ�ǰ�����ߺ�׺�ո�
*/

class Solution {
public:
    string sortSentence(string s) {
        int n = s.size();
        stringstream ss(s);
        string word;
        vector<string> str(9);
        int index = 0;
        while (ss >> word)
        {
            int num = word.back() - '0';
            word.pop_back();
            str[num] = word;
            index = max(index, num);
        }
        string ret;
        for (int i = 1; i <= index; i++)
        {
            ret += str[i];
            if (i != index)
                ret += ' ';
        }
        return ret;
    }
};
