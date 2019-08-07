#include <iostream>
#include<stdio.h>
#include <algorithm>
#include <ctime>
using namespace std;

bool cmp(int *p, int *q)
{
  if (p[0] == q[0])
  {
    if (p[1] == q[1])
      {
        return p[2]<q[2];
      }
     else return p[1]<q[1];
  }
  else return p[0]<q[0];
}



int main()
{
srand(time(0));
int b[10] = {3, 2, 1, 4, 5, 5, 7, 8, 9, 10};
int c[10] = {3,10,9, 4, 88, 6, 7, 8, 9, 11 };
int i;
int **a = new int*[10];
for (i = 0; i<10; ++i)
{
a[i] = new int[2];
a[i][0] = b[i];
a[i][1] = c[i];
//a[i][2] = rand() % 100;
//printf("%d\\t%d\\t%d",a[i][0],a[i][1],a[i][2]);
}
sort(a, a + 10, cmp);
//sort(a, a + 10);
cout<<"After sort"<<endl;
for(i=0;i<10;++i)
{
printf("%d    %d\n",a[i][0],a[i][1]);
}
system("pause");
return 0;
}
