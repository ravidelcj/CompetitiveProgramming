//http://www.spoj.com/problems/CPRMT/

#include<iostream>
#include<cstring>
using namespace std;
int arr1[28],arr2[28];
char str1[10000],str2[100000];
int main()
{

    while(scanf("%s%s",str1,str2)!=EOF)
    {
        for(int i=0;i<=27;i++)
        {
            arr1[i]=0;
            arr2[i]=0;
        }
        int l1=strlen(str1);
        int l2=strlen(str2);
        for(int i=0;i<l1;i++)
        {
            arr1[str1[i]-'a']++;
        }
        for(int i=0;i<l2;i++)
        {
            arr2[str2[i]-'a']++;
        }

        for(int i=0;i<=25;i++)
        {

            int k=0;
            if(arr1[i]!=0&&arr2[i]!=0)
            {

                if(arr1[i]==arr2[i])
                    k=arr1[i];
                else if(arr1[i]<arr2[i])
                    k=arr1[i];
                else
                    k=arr2[i];
            }
            while(k--)
            {
                printf("%c",'a'+i);
            }
        }
        printf("\n");

    }
    return 0;
}
