/*
����һ�׻�����ģ tiles������ÿ����ģ�϶�����һ����ĸ tiles[i]�����������ӡ���ķǿ���ĸ���е���Ŀ��
ע�⣺�����У�ÿ��������ģֻ��ʹ��һ�Ρ�
ʾ�� 1��
���룺"AAB"
�����8
���ͣ����ܵ�����Ϊ "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"��
ʾ�� 2��
���룺"AAABBC"
�����188
��ʾ��
1 <= tiles.length <= 7
tiles �ɴ�дӢ����ĸ���
*/

class Solution {
public:
    int ret;
    int numTilePossibilities(string tiles) {
        vector<int> mp(26, 0);
        for (char& ch : tiles)
            ++mp[ch - 'A'];
        for (int i = 0, j = 0; i < 26; i++)
            if (mp[i] != 0)
                swap(mp[i], mp[j++]);  //��������0����ĸȥ��
        mp.resize(tiles.size());
        dfs(mp);
        return ret;
    }

    void dfs(vector<int>& v)
    {
        for (auto& e : v) 
        {
            if (e != 0) 
            {
                e--;
                ret++;
                dfs(v);
                e++;
            }
        }
    }
};
