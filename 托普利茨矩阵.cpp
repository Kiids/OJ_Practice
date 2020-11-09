/*
如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
给定一个 M x N 的矩阵，当且仅当它是托普利茨矩阵时返回 True。
示例 1:
输入: 
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
输出: True
解释:
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是True。
示例 2:
输入:
matrix = [
  [1,2],
  [2,2]
]
输出: False
解释: 
对角线"[1, 2]"上的元素不同。
说明:
 matrix 是一个包含整数的二维数组。
matrix 的行数和列数均在 [1, 20]范围内。
matrix[i][j] 包含的整数在 [0, 99]范围内。
进阶:
如果矩阵存储在磁盘上，并且磁盘内存是有限的，因此一次最多只能将一行矩阵加载到内存中，该怎么办？
如果矩阵太大以至于只能一次将部分行加载到内存中，该怎么办？
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

//当每行的元素只有1个时，必定是
//当每行的元素只有两个时，保存上一行的第一个，进行比较
//当每行的元素多于两个时，保存每行元素两两对应的异或结果，既保证顺序又保证拥有全部相同数量的各数字，
//每次比较完成后，只需要再在结果上去掉第一个异或结果，增加最后一个异或结果即可，每次只处理一行元素
//例如
//[1,2,3,4],
//[5,1,2,3],
//[9,5,1,2]
//
//第一行异或: 保存结果result = 12 ^ 23 
//第二行异或: 12^23 等于result,更新result = result ^ 51 ^ 23， result = 51^12
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
