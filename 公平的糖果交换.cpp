/*
����˿�ͱ����в�ͬ��С���ǹ�����A[i] �ǰ���˿ӵ�еĵ� i ���ǵĴ�С��B[j] �Ǳ���ӵ�еĵ� j ���ǵĴ�С��
��Ϊ���������ѣ����������뽻��һ���ǹ������������������Ƕ�����ͬ���ǹ���������һ����ӵ�е��ǹ�����������ӵ�е��ǹ�����С���ܺ͡���
����һ���������� ans������ ans[0] �ǰ���˿���뽻�����ǹ����Ĵ�С��ans[1] �� Bob ���뽻�����ǹ����Ĵ�С��
����ж���𰸣�����Է��������κ�һ������֤�𰸴��ڡ�
ʾ�� 1��
���룺A = [1,1], B = [2,2]
�����[1,2]
ʾ�� 2��
���룺A = [1,2], B = [2,3]
�����[1,2]
ʾ�� 3��
���룺A = [2], B = [1,3]
�����[2,3]
ʾ�� 4��
���룺A = [1,2,5], B = [2,4]
�����[5,4]
��ʾ��
1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
��֤����˿�뱫�����ǹ�������ͬ��
�𰸿϶����ڡ�
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        long long sumA = accumulate(A.begin(), A.end(), 0);
        long long sumB = accumulate(B.begin(), B.end(), 0);
        int difference = (sumA - sumB) / 2;
        
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); i++)
            m[A[i] - difference] = i;
            
        for (int j = 0; j < B.size(); j++)
        {
            if (m.count(B[j]) == 0)
                continue;
            return { A[m[B[j]]], B[j] };
        }
        return {};
    }
};
// ����������ĺ�
// ����ٳ���
// ������
