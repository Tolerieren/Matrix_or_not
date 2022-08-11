//�Ƿ�Ϊ����
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


    size = sizeof(num) / sizeof(num[0]);   //���������������޸�,��������Ԫ�ص�����

    result = identity_matrix(pt, size);

    if (result)
        puts("It is a identity matrix");
    else
        puts("It is not.");

    return 0;

}

bool identity_matrix(int* pt, int size)
{
    int a = sqrt(size);   //��ƽ����
    int a1 = a;           //�����forѭ�����õ�

    if (a != sqrt(size))   //��ƽ������Ϊ�������򲻳ɵ�λ����
        return false;

    if (!pt[0])            //��Ԫ�ز�Ϊ1����Ϊ��λ����
        return false;

    for (int i = size - 1; i > 0; i = i - (a + 1))   //�ض�λ�õ�Ԫ�ز�Ϊ1����Ϊ����
        if (!pt[i])
            return false;

    int sum = 0;
    for (int j = 0; j < size; j++)    //�����ÿһ�У�����ֻ��һ��Ԫ��Ϊ1
    {
        sum += pt[j];        if��sum > 1)            return false;
        if ((j + 1) == a)     //����ȣ���˵�����е�Ԫ���Ѿ�����
        {
            a += a1;        //sum��0��������һ��Ԫ�ض�ȡ��Χ          
            sum = 0;
        }

    }

    return true;
}