/*
�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
ʾ����
���룺S = "ababcbacadefegdehijhklij"
�����[9,7,8]
���ͣ�
���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"��
ÿ����ĸ��������һ��Ƭ���С�
�� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�
��ʾ��
S�ĳ�����[1, 500]֮�䡣
Sֻ����Сд��ĸ 'a' �� 'z' ��
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ends(26, -1);
        for (int i = 0; i < S.size(); i++)
            ends[S[i] - 'a'] = i;

        vector<int> ret;
        int i = 0;
        while (i < S.size())
        {
            int r = ends[S[i] - 'a'];
            for (int j = i + 1; j <= r; j++)
                r = max(r, ends[S[j] - 'a']);
            ret.push_back(r - i + 1);
            i = r + 1;
        }
        return ret;
    }
};
