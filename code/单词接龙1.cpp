    #include<iostream>
    #include<cstring>
    using namespace std;
    int n,maxl;
    struct ss
    {
        char word[10000];
        int len;
        int v;
    };
    struct ss s[21];
    void dfs(int x,int len)
    {
        int i,j,k;
        for(i=1;i<=n;i++)//�������е���
        {
            if(s[i].v<2)// ����Ƿ��ù�
            for(j=0;j<s[x].len;j++)
            {
                if(s[x].word[j]==s[i].word[0])// �����ӵĵ��ʵ�ͷ��������ĳһ��ʱ����ʼѭ��
                {
                    int a=j+1,b=1;
                    bool flag=true;
                    for(;a<s[x].len&&b<s[i].len;b++,a++)
                    {
                        if(s[i].word[b]!=s[x].word[a])
                        {
                            flag=false;
                            break;
                        }

                    }
                    if(flag)
                    {
                        s[i].v++;
                        dfs(i,len+s[i].len-b);
                        s[i].v--;//����
                    }
                }
            }
        }
        if(len>maxl)
            maxl=len;

    }


    int main()
    {
        int i;
        cin>>n;
        for( i=1;i<=n;i++)
        {
            cin>>s[i].word;
            s[i].len=strlen(s[i].word);
        }
         cin>>s[0].word;
         s[0].len=strlen(s[0].word);
        dfs(0,s[0].len);
        cout<<maxl;
        return 0;
    }
