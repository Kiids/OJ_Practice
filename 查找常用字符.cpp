/*
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。
示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]
提示：
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ret;
        int num[100][26] = {0};                       //建立一个二维数组，标记所有出现的字母次数
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[i].size(); j++)
                num[i][(A[i][j] - 'a')]++;
        
        for (int j = 0; j < 26; j++)                  //将所有列的最小值存到第一行
            for (int i = 1; i < A.size(); i++)
                num[0][j] = min (num[0][j], num[i][j]);
                    
        string str;                                   //按照第一行保存的次数输出相应字母
        for (int i = 0; i < 26; i++)
        {
            while (num[0][i]--)
            {
                str.clear();
                str.push_back((char)('a' + i));
                ret.push_back(str);
            }
        }
        return ret;
    }
};
