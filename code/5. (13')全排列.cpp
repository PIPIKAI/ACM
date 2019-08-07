/* 相信大家都知道什么是全排列，但是今天的全排列比你想象中的难一点。我们要找的是全排列中，排列结果互不相同的个数。

        比如：aab 的全排列就只有三种，那就是aab,baa,aba。

        代码框中的代码是一种实现，请分析并填写缺失的代码。

【分析】含有重复元素的全排列问题

        关键：去重

【答案】vis[j] && str[i]==str[j]
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
        arrange(0);    //从第1个字符开始搜索
        printf("Total %d\n", total);
    }
    return 0;
}
