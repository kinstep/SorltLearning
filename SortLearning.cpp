// SortLearning.cpp : 定义控制台应用程序的入口点。
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
    for(int i = 2; i < q.length; ++i)//从第二个开始比较，假设第一个为有序序列
    {
        if(q.r[i].key < q.r[i - 1].key)//如果后面的较小,就是如果需要调整
        {
            q.r[0]  = q.r[i];//保存前面的
            q.r[i] = q.r[i - 1];//后面的移到前面来
            // 此时得到一个长度为一的有序序列
            //其次将放入0的元素插入这个序列的相对位置
            //从后面比较,如果小于则插入
            int j = i - 2;//求得当前的有序串的长度，结尾位置

            for(j; q.r[0].key < q.r[j].key; --j)//找到当前串中适合的位置插入  倒序查找
                q.r[j + 1] = q.r[j];//当前串中的移动

            //终止条件就是当移动到从尾部结算的第一个小于的元素时候的J的值
            q.r[j + 1] = q.r[0];
        }
    }
}

void QuestionOne()//求最长子数组之和
{
    int c[10] = {1, - 2, 3, 10, -4, 7, 2, -5};
    int currentMax = 0, resultMax = 0;

    for(int i = 0; i < 10; i++)
    {
        currentMax = (c[i] > currentMax + c[i]) ? c[i] : currentMax + c[i];
        resultMax = (resultMax > currentMax) ? resultMax : currentMax;
    }
}

void QuickSort(int *s, int l, int r)//快速排序
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
            }//直到后面有一个元素是小于listener

            if(i < j)
                s[i++] = s[j];//将这个元素放到这个位置

            while(i < j && s[i] <= listener)
            {
                i++;
            }//直到有个元素是大于listener

            if(i < j)
                s[j--] = s[i];//就把这个元素放到后面，位置就是前面被移除元素的位置
        }

        s[i] = listener;//这个元素的最终位置被确定了
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

