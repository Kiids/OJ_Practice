// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Sum
{
public:
    Sum()
    {
        sum += i;
        i++;
    }
    static void Init()
    {
        sum = 0;
        i = 1;
    }
    static int GetSum()
    {
        return sum;
    }
private:
    static int sum;
    static int i;
};
int Sum::sum = 0;
int Sum::i = 1;
 
class Solution {
public:
    int Sum_Solution(int n) {
        Sum::Init();
        Sum a[n];
        return Sum::GetSum();
    }
};
 
/*  // 方法二：利用内置类
class Solution {
public:
    class Sum
    {
    public:
        Sum()
        {
            _sum += _i;
            ++_i;
         }
    };
    int Sum_Solution(int n) {
        _sum = 0;
        _i = 1;
        Sum a[n];
        return _sum;
    }
     
private:
    static int _sum;
    static int _i;
};
 
int Solution::_sum = 0;
int Solution::_i = 1;
*/
