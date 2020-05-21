/*
���һ���������ҳ�����ָ��������һ�����еĳ���Ƶ�ʡ�
���ʵ��Ӧ��֧�����²�����
WordsFrequency(book)���캯��������Ϊ�ַ������鹹�ɵ�һ����
get(word)��ѯָ�����������г��ֵ�Ƶ��
ʾ����
WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
wordsFrequency.get("you"); //����0��"you"û�г��ֹ�
wordsFrequency.get("have"); //����2��"have"����2��
wordsFrequency.get("an"); //����1
wordsFrequency.get("apple"); //����1
wordsFrequency.get("pen"); //����1
��ʾ��
book[i]��ֻ����Сд��ĸ
1 <= book.length <= 100000
1 <= book[i].length <= 10
get�����ĵ��ô������ᳬ��100000
*/

class WordsFrequency {
    unordered_map<string, int> m;
public:
    WordsFrequency(vector<string>& book) {
        for (auto word : book)
            m[word]++;
    }
    
    int get(string word) {
        return m[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
