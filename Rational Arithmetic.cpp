/*
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference,
product and quotient.
ÊäÈëÃèÊö:
Each input file contains one test case, which gives in one line the two rational numbers in the format "a1/b1 a2/b2". 
The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in 
front of the numerator. The denominators are guaranteed to be non-zero numbers.
Êä³öÃèÊö:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each 
line is "number1 operator number2 = result". Notice that all the rational numbers must be in their simplest form "k a/b", where k is 
the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the 
denominator in the division is zero, output "Inf" as the result. It is guaranteed that all the output integers are in the range of long int.
Ê¾Àı1
ÊäÈë
5/3 0/6
Êä³ö
1 2/3 + 0 = 1 2/3<br/>1 2/3 - 0 = 1 2/3<br/>1 2/3 * 0 = 0<br/>1 2/3 / 0 = Inf
*/

#include<iostream>
#include<cstdio>
using namespace std;

long long getFenshuInt(long long x, long long y)
{
    return y ? getFenshuInt(y, x % y) : x;
}

void fun(long long x, long long y)
{
    if (y < 0)
    {
        x = -x;
        y = -y;
    }
    
    long long z = 0;
    if (x < 0)
        z = getFenshuInt(-x, y);
    else
        z = getFenshuInt(x, y);
    x = x / z;
    y = y / z;
    
    if (x == 0)
    {
        cout << 0;
        return;
    }
    
    bool fuShu = false;
    if (x < 0)
    {
        fuShu = true;
        cout << "(-";
        x = -x;
    }
    
    bool daYuYi = false;
    if (x / y)
    {
        printf("%lld", x / y);
        daYuYi = true;
    }
    if (x % y)
    {
        if (daYuYi)
            cout << ' ';
        printf("%lld/%lld", x % y, y);
    }
    if (fuShu)
        cout << ')';
}

int main()
{
    long long a1, a2, b1, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    
    fun(a1, b1);
    cout << " + ";
    fun(a2, b2);
    cout << " = ";
    fun(a1 * b2 + b1 * a2, b1 * b2);
    cout << endl;
    
    fun(a1, b1);
    cout << " - ";
    fun(a2, b2);
    cout << " = ";
    fun(a1 * b2 - b1 * a2, b1 * b2);
    cout << endl;
    
    fun(a1, b1);
    cout << " * ";
    fun(a2, b2);
    cout << " = ";
    fun(a1 * a2, b1 * b2);
    cout << endl;
    
    fun(a1, b1);
    cout << " / ";
    fun(a2, b2);
    cout << " = ";
    if (a2)
        fun(a1 * b2, a2 * b1);
    else
        cout << "Inf";
    cout << endl;
    
    return 0;
}

