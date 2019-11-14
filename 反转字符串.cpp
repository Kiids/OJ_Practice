// ��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������ 
// ��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
// ����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
// ʾ�� 1��
// ���룺["h","e","l","l","o"]
// �����["o","l","l","e","h"]
// ʾ�� 2��
// ���룺["H","a","n","n","a","h"]
// �����["h","a","n","n","a","H"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty())
            return;
        
        size_t first = 0;
        size_t last = s.size() - 1;
        
        while (first < last)
        {
            swap(s[first], s[last]);
            first++;
            last--;
        }
        
    }
};

