//是否为矩阵
# include <stdbool.h>
# include <stdio.h>
# include <math.h>

bool identity_matrix(int*, int);


int main()
{
    /*int num[][5] = {
        {1},
        {0,1},
        {0,0,1},
        {0,0,0,1},
        {0,0,0,0,1}
    };
    int* pt = &num[0][0];*/

    int num[] = { 1,0,0,0,1,0,0,0,1 };
    bool result;
    int size;
    int* pt = &num[0];


    size = sizeof(num) / sizeof(num[0]);   //根据数组类型做修改,计算数组元素的数量

    result = identity_matrix(pt, size);

    if (result)
        puts("It is a identity matrix");
    else
        puts("It is not.");

    return 0;

}

bool identity_matrix(int* pt, int size)
{
    int a = sqrt(size);   //求平方根
    int a1 = a;           //后面的for循环会用到

    if (a != sqrt(size))   //若平方根不为整数，则不成单位矩阵
        return false;

    if (!pt[0])            //首元素不为1，则不为单位矩阵
        return false;

    for (int i = size - 1; i > 0; i = i - (a + 1))   //特定位置的元素不为1，则不为矩阵
        if (!pt[i])
            return false;

    int sum = 0;
    for (int j = 0; j < size; j++)    //矩阵的每一行，有且只有一个元素为1
    {
        sum += pt[j];        
        if(sum > 1)     
            return false;
        if ((j + 1) == a)     //若相等，则说明此行的元素已经读尽
        {
            a += a1;        //sum归0，设置下一次元素读取范围          
            sum = 0;
        }

    }

    return true;
}
