// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int key = numbers[0];
         
        for (int i = 1; i < numbers.size(); i++)
        {
            if(numbers[i] == key)
                count++;
            else
                count--;
             
            if(count == 0)
            {
                key = numbers[i];
                count = 1;
            }
        }
         
        int c = 0;
        for (int i = 0; i < numbers.size(); i++)
            if(numbers[i] == key)
                c++;
         
        if (c > (numbers.size()/2))
            return key;
        else
            return 0;
    }
};

