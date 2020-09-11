/*
����һ���ɿո�ָ�ʵľ��� S��ÿ������ֻ������д��Сд��ĸ��
����Ҫ������ת��Ϊ ��Goat Latin����һ�������� �������� - Pig Latin ���鹹���ԣ���
ɽ�������ĵĹ������£�
���������Ԫ����ͷ��a, e, i, o, u�����ڵ��ʺ����"ma"��
���磬����"apple"��Ϊ"applema"��
��������Ը�����ĸ��ͷ������Ԫ����ĸ�����Ƴ���һ���ַ��������ŵ�ĩβ��֮�������"ma"��
���磬����"goat"��Ϊ"oatgma"��
���ݵ����ھ����е��������ڵ�����������������ͬ��������ĸ'a'��������1��ʼ��
���磬�ڵ�һ�����ʺ����"a"���ڵڶ������ʺ����"aa"���Դ����ơ�
���ؽ� S ת��Ϊɽ�������ĺ�ľ��ӡ�
ʾ�� 1:
����: "I speak Goat Latin"
���: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
ʾ�� 2:
����: "The quick brown fox jumped over the lazy dog"
���: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
˵��:
S �н�������Сд��ĸ�Ϳո񡣵��ʼ����ҽ���һ���ո�
1 <= S.length <= 150��
*/

class Solution {
public:
    string toGoatLatin(string S) {
        string ret = "";
        string str = "a";
        istringstream ww(S);
        string w;
        while (ww >> w)
        {
            char ch = tolower(w[0]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                ret += w + "ma" + str;
            else 
                ret += string(w.begin() + 1, w.end()) + w[0] + "ma" + str;
            ret += ' ';
            str += 'a';
        }
        ret.pop_back();
        return ret;
    }
};
