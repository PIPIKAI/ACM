/* ���Ŵ�Ҷ�֪��ʲô��ȫ���У����ǽ����ȫ���б��������е���һ�㡣����Ҫ�ҵ���ȫ�����У����н��������ͬ�ĸ�����

        ���磺aab ��ȫ���о�ֻ�����֣��Ǿ���aab,baa,aba��

        ������еĴ�����һ��ʵ�֣����������дȱʧ�Ĵ��롣

�������������ظ�Ԫ�ص�ȫ��������

        �ؼ���ȥ��

���𰸡�vis[j] && str[i]==str[j]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char str[N], buf[N];
int vis[N], total, len;

void arrange(int num) {
    int i, j;
    if (num == len) {
        printf("%s\n", buf);
        total++;
        return;
    }
    for (i = 0; i < len; ++i)
    {
        if (0==vis[i])
        {
            for (j = i + 1; j < len; ++j)
            {
                if (vis[j]!=0&&str[i]==str[j])
                 {    //blank
                    break;
                }
            }
            if (j == len)
            {
                vis[i] = 1;
                buf[num] = str[i];
                arrange(num + 1);
                vis[i] = 0;
            }
        }
    }
}
int main() {
    while (~scanf("%s", str)) {
        len = strlen(str);
        int i, j;
        for (i = 0; i < len; ++i)
        {
            for (j = i + 1; j < len; ++j)
            {
                if (str[i] > str[j])
                {
                    char tmp = str[i];
                    str[i] = str[j];
                    str[j] = tmp;
                }
            }
        }
        total = 0;
        buf[len] = '\0';
        arrange(0);    //�ӵ�1���ַ���ʼ����
        printf("Total %d\n", total);
    }
    return 0;
}
