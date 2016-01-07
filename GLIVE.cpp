//http://www.spoj.com/problems/GLJIVE/


#include<iostream>

int main()
{
    int x,sum=0,prevSum=0;
int flag=0;
    int t=9;
    scanf("%d",&x);
        sum+=x;
    while(t--)
    {
        if(sum>=100)
        {
            flag=1;
        }
        scanf("%d",&x);
        if(!flag){
           prevSum=sum;
           sum+=x;
        }

    }
    if((100-prevSum)==(sum-100))
        printf("%d",sum);
    else if((100-prevSum)<(sum-100))
        printf("%d",prevSum);
    else
        printf("%d",sum);
    return 0;
}
