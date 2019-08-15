#include<cstdio>
using namespace std;
int main(void)
{
    int n,q,ti,li,ri,di,a[105][105];

    scanf("%d%d",&n, &q);
    for (int i=0; i<n; i++)//¾ØÕó³õÊ¼»¯
    {
        for (int j=0; j<n; j++)
        {
            a[i][j]=i*n+j;
        }
    }
    while (q--)
    {
        scanf("%d%d%d%d", &ti,&li,&ri,&di);
        if (ti==1 && di)
        {
            for (int i=li;i<=ri;i++)
            {
                int ta[105];
                for (int j=0;j<n;j++)
                {
                    int k=j-di;
                    if(k<0)
                    {
                        k+=n;
                    }
                    ta[k]=a[i][j];
                }
                for (int j=0;j<n;j++)
                {
                    a[i][j]=ta[j];
                }
            }
        }
        else if (di)
        {
            for (int j=li;j<=ri;j++)
            {
                int ta[105];
                for (int i=0; i<n;i++)
                {
                    int k=i-di;
                    if (k<0)
                    {
                        k+=n;
                    }
                    ta[k]=a[i][j];
                }
                for (int i=0;i<n;i++)
                {
                    a[i][j]=ta[i];
                }
            }
        }
    }
    for (int i=0; i<n; i++)//Êä³ö
    {
        printf("%d", a[i][0]);
        for (int j=1; j<n; j++)
        {
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}