/*
��������ǵ��������򵥵��ݼ��ģ���ô���ǵ����ġ�
����������� i <= j��A[i] <= A[j]����ô���� A �ǵ��������ġ� ����������� i <= j��A[i]> = A[j]����ô���� A �ǵ����ݼ��ġ�
������������ A �ǵ�������ʱ���� true�����򷵻� false��
ʾ�� 1��
���룺[1,2,2,3]
�����true
ʾ�� 2��
���룺[6,5,4,4]
�����true
ʾ�� 3��
���룺[1,3,2]
�����false
ʾ�� 4��
���룺[1,2,4,5]
�����true
ʾ�� 5��
���룺[1,1,1]
�����true
��ʾ��
1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2) {
            return true;
        }

        bool flag1 = false;
        bool flag2 = false;  
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                flag1 = true;
            } else if (A[i] < A[i-1]) {
                flag2 = true;
            }

            if (flag1 == true && flag2 == true) {
                return false;
            }  
        }
        return true;
    }
};
