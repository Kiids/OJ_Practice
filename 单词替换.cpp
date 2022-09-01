/*
��Ӣ���У�������һ������ �ʸ�(root) �ĸ�����Դʸ������������һЩ�������һ���ϳ��ĵ��ʡ������ǳ������Ϊ �̳д�(successor)�����磬�ʸ�an�������ŵ��� other(����)�������γ��µĵ��� another(��һ��)��
���ڣ�����һ�������ʸ���ɵĴʵ� dictionary ��һ���ÿո�ָ������γɵľ��� sentence������Ҫ�������е����м̳д��ôʸ��滻��������̳д����������γ����Ĵʸ���������̵Ĵʸ��滻����
����Ҫ����滻֮��ľ��ӡ�
ʾ�� 1��
���룺dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
�����"the cat was rat by the bat"
ʾ�� 2��
���룺dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
�����"a a b c"
��ʾ��
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] ����Сд��ĸ��ɡ�
1 <= sentence.length <= 10^6
sentence ����Сд��ĸ�Ϳո���ɡ�
sentence �е��ʵ������ڷ�Χ [1, 1000] �ڡ�
sentence ��ÿ�����ʵĳ����ڷ�Χ [1, 1000] �ڡ�
sentence �е���֮����һ���ո������
sentence û��ǰ����β��ո�
*/

class Solution {
    bool isroot(string &root, string &word)
    {
        for (int i = 0; i <root.size(); i++)
            if (root[i] != word[i])
                return false;
        return true;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end(), [](auto &s1, auto &s2){return s1.size() < s2.size();});
        string ret, word;
        stringstream input(sentence);
        while (input >> word)
        {
            for (auto& root : dictionary)
                if (isroot(root, word))
                {
                    word = root;
                    break;
                }
            ret += word + " ";
        }
        ret.pop_back();
        return ret;
    }
};
