/*
����һ�����ǵݼ�˳��������������� A������ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
ʾ�� 1��
���룺[-4,-1,0,3,10]
�����[0,1,9,16,100]
ʾ�� 2��
���룺[-7,-3,2,3,11]
�����[4,9,9,49,121]
��ʾ��
1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A �Ѱ��ǵݼ�˳������
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            ret[i] = A[i] * A[i];
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};

/*
˼·�����ҵ��������ķֽ��ߣ�ͨ��˫ָ�������������Ȼ�������и��ֲ�ͬ�����Խ��
���ο�leedcode�����Ĵ���
    int length = A.size();
    vector<int> ans(length);
    int i = 0, j = length - 1, k = length - 1;
    while (k >= 0) {
        int a = A[i] * A[i];
        int b = A[j] * A[j];
        if (a > b) {
            ans[k] = a;
            i++;
        }
        else {
            ans[k] = b;
            j--;
        }
        k--;
    }
    return ans;
*/
