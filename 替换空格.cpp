// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int space_num = 0;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
            {
                ++space_num;
            }
        }
         
        int end = length;
        while(end >= 0 && space_num > 0)
        {
            if(str[end] != ' ')
            {
                str[end + 2 * space_num] = str[end];
            }
            else
            {
                --space_num;
                str[end + 2 * space_num] = '%';
                str[end + 2 * space_num+1] = '2';
                str[end + 2 * space_num+2] = '0';
            }
             
            --end;
        }
    }
};
