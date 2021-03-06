// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) { 
        int row = (int)array.size(); 
        int col = (int)array[0].size(); 
        if (row == 0 || col == 0) 
            return false;
        if (target < array[0][0] || target > array[row - 1][col - 1])
            return false;
        int i = 0;
        int j = col - 1;
        while (i < row && j >= 0)
        {
            if (array[i][j] > target)
                j--;
            else if (array[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};
