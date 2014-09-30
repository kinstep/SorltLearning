// SortLearning.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define random(x) (rand()%x)

typedef int KeyType;
typedef struct
{
    KeyType key;
} RedType;//key words
typedef struct
{
    RedType r[21];
    int length;

} SqList;
void InsertSort(SqList &q)
{
    for(int i = 2; i < q.length; ++i)//�ӵڶ�����ʼ�Ƚϣ������һ��Ϊ��������
    {
        if(q.r[i].key < q.r[i - 1].key)//�������Ľ�С,���������Ҫ����
        {
            q.r[0]  = q.r[i];//����ǰ���
            q.r[i] = q.r[i - 1];//������Ƶ�ǰ����
            // ��ʱ�õ�һ������Ϊһ����������
            //��ν�����0��Ԫ�ز���������е����λ��
            //�Ӻ���Ƚ�,���С�������
            int j = i - 2;//��õ�ǰ�����򴮵ĳ��ȣ���βλ��

            for(j; q.r[0].key < q.r[j].key; --j)//�ҵ���ǰ�����ʺϵ�λ�ò���  �������
                q.r[j + 1] = q.r[j];//��ǰ���е��ƶ�

            //��ֹ�������ǵ��ƶ�����β������ĵ�һ��С�ڵ�Ԫ��ʱ���J��ֵ
            q.r[j + 1] = q.r[0];
        }
    }
}

void QuestionOne()//���������֮��
{
    int c[10] = {1, - 2, 3, 10, -4, 7, 2, -5};
    int currentMax = 0, resultMax = 0;

    for(int i = 0; i < 10; i++)
    {
        currentMax = (c[i] > currentMax + c[i]) ? c[i] : currentMax + c[i];
        resultMax = (resultMax > currentMax) ? resultMax : currentMax;
    }
}

void QuickSort(int *s, int l, int r)//��������
{
    if(l < r)
    {
        int i = l;
        int j = r;
        int listener = s[l];

        while(i != j)
        {
            while(i < j && s[j] >= listener)
            {
                j--;
            }//ֱ��������һ��Ԫ����С��listener

            if(i < j)
                s[i++] = s[j];//�����Ԫ�طŵ����λ��

            while(i < j && s[i] <= listener)
            {
                i++;
            }//ֱ���и�Ԫ���Ǵ���listener

            if(i < j)
                s[j--] = s[i];//�Ͱ����Ԫ�طŵ����棬λ�þ���ǰ�汻�Ƴ�Ԫ�ص�λ��
        }

        s[i] = listener;//���Ԫ�ص�����λ�ñ�ȷ����
        QuickSort(s, l, j - 1);
        QuickSort(s, j + 1, r);
    }
}

void BubbleSort(int *c, int n)
{
    for(int i = 0; i < 100 ; i++)
    {
        for(int j = 1; j < 100 - i  ; j++)
        {
            if(c[j - 1] > c[j ])
            {
                int temp = c[j ];
                c[j ] = c[j - 1];
                c[j - 1] = temp;
            }
        }
    }
}

void SelectSort(int *c, int n)
{
    int temp = 0;

    for(int i = 0; i < n; i++)
    {
        temp = c[i] ;
        int key = i;

        for(int j = i + 1; j < n  ; j++)
        {
            if(c[j] < temp)
            {
                temp = c[j];
                key = j;
            }
        }

        c[key--] = c[i];
        c[i] = temp;
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    SqList *q = (SqList*)malloc(sizeof(SqList));
    q->length = 21;

    for(int i = 1; i < q->length; i++)
    {
        q->r[i].key = random(100);
        printf("%d_", q->r[i].key);
    }

    QuestionOne();
    InsertSort(*q);
    int c[100] = {};
    int b[100] = {};

    for(int i = 0; i < 100; i++)
    {
        c[i] = b[i] = random(100);
    }

    // QuickSort(p, 0, 99);
    // BubbleSort(c, 100);
    SelectSort(c, 100);
    getchar();
    return 0;
}

