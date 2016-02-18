//DIEHARD

#include<iostream>

using namespace std;



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,a;
        scanf("%d%d",&h,&a);
       int ans=1;
        h+=3;
        a+=2;

        while(true)
        {

            if(h>20&&a<=10)
            {
                h-=17;
                a+=7;
                ans+=2;
            }
            else if(h>5&&a>10)
            {
                h-=2;
                a-=8;
                ans+=2;
            }
            else
            {
                printf("%d\n",ans);
                break;
            }

        }

     //   printf("%d\n",ans);
    }
    return 0;
}
