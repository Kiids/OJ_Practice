/*
���������ÿһ�������ϵ����µĶԽ����ϵ�Ԫ�ض���ͬ����ô��������� �������ľ��� ��
����һ�� M x N �ľ��󣬵��ҽ��������������ľ���ʱ���� True��
ʾ�� 1:
����: 
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
���: True
����:
������������, ��Խ���Ϊ:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"��
�����Խ����ϵ�����Ԫ�ؾ���ͬ, ��˴���True��
ʾ�� 2:
����:
matrix = [
  [1,2],
  [2,2]
]
���: False
����: 
�Խ���"[1, 2]"�ϵ�Ԫ�ز�ͬ��
˵��:
 matrix ��һ�����������Ķ�ά���顣
matrix ���������������� [1, 20]��Χ�ڡ�
matrix[i][j] ������������ [0, 99]��Χ�ڡ�
����:
�������洢�ڴ����ϣ����Ҵ����ڴ������޵ģ����һ�����ֻ�ܽ�һ�о�����ص��ڴ��У�����ô�죿
�������̫��������ֻ��һ�ν������м��ص��ڴ��У�����ô�죿
*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 1 || matrix[0].size() == 1)
            return true;
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix[0].size(); j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};

//��ÿ�е�Ԫ��ֻ��1��ʱ���ض���
//��ÿ�е�Ԫ��ֻ������ʱ��������һ�еĵ�һ�������бȽ�
//��ÿ�е�Ԫ�ض�������ʱ������ÿ��Ԫ��������Ӧ����������ȱ�֤˳���ֱ�֤ӵ��ȫ����ͬ�����ĸ����֣�
//ÿ�αȽ���ɺ�ֻ��Ҫ���ڽ����ȥ����һ����������������һ����������ɣ�ÿ��ֻ����һ��Ԫ��
//����
//[1,2,3,4],
//[5,1,2,3],
//[9,5,1,2]
//
//��һ�����: ������result = 12 ^ 23 
//�ڶ������: 12^23 ����result,����result = result ^ 51 ^ 23�� result = 51^12
//.....

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int result = 0;
        int n = matrix[0].size();
        if(n==1)
            return true;
        if(n==2){
            result = matrix[0][0];
            for(int i = 1;i<matrix.size();i++){
                if(matrix[i][1] != result)
                    return false;
                result = matrix[i][0];
            }
        }
        else{
             for(int i=1;i<n-1;i++)
                result = result ^ (matrix[0][i-1] *10 + matrix[0][i]);
            for(int i = 1;i<matrix.size();i++){
                int now = 0;
                for(int j=2;j<n;j++)
                    now = now ^ (matrix[i][j-1]*10 + matrix[i][j]);
                if(now!=result)
                    return false;
                result = result ^ (matrix[i][0]*10 + matrix[i][1]) ^ (matrix[i][n-2] *10 + matrix[i][n-1]);          
            }
        }
       
        return true;
    }
