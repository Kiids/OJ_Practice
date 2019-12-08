// 请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
// 给定两个int A和B。请返回A＋B的值
// 测试样例：
// 1,2
// 返回：3

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while (A)
        {
            int t = B;
            B = A ^ B;
            A = A & t;
            A <<= 1;
        }
        return B;
    }
};
// A为进位，B是结果 

class Solution 
{ 
public: 
	int Add(int num1,int num2) 
	{ 
		while( num2 != 0 )
		{ 
			int sum = num1 ^ num2; //得到相加后不包含进位的数据 
			int carray = (num1 & num2) << 1; //得到两数相加的进位 
			num1 = sum; //两个结果相加，直到进位为0 
			num2 = carray; 
		}
		return num1; 
	} 
};

