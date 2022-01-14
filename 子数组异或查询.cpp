/*
��һ������������ arr���ָ���һ����Ӧ�Ĳ�ѯ���� queries������ queries[i] = [Li, Ri]��
����ÿ����ѯ i���������� Li �� Ri �� XOR ֵ���� arr[Li] xor arr[Li+1] xor ... xor arr[Ri]����Ϊ���β�ѯ�Ľ����
������һ������������ѯ queries ���н�������顣
ʾ�� 1��
���룺arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
�����[2,7,14,8] 
���ͣ�
������Ԫ�صĶ����Ʊ�ʾ��ʽ�ǣ�
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
��ѯ�� XOR ֵΪ��
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
ʾ�� 2��
���룺arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
�����[8,0,4,4]
��ʾ��
1 <= arr.length <= 3 *?10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre_xor(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pre_xor[i] = arr[i-1] ^ pre_xor[i-1];
        
        vector<int> v;
        for(auto &query : queries) {
            int L = query[0], R = query[1];
            v.push_back(pre_xor[R + 1] ^ pre_xor[L]);
        }
        return v;
    }
};
