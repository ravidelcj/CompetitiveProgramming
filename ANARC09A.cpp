//http://www.spoj.com/problems/ANARC09A/

#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
char str[2009];
int main()
{
    int count=0;
    scanf("%s",str);
    while(str[0]!='-')
    {
        int ans=0;
        stack<int> s;
        int l=strlen(str);
        count++;
        for(int i=0;i<l;i++)
        {
            if(str[i]=='{')
                s.push(1);
            else
            {
                if(s.empty())
                {
                    s.push(1);
                    ans+=1;
                }
                else
                    s.pop();
            }
        }
        if(!s.empty())
            ans+=s.size()/2;
        printf("%d. %d\n",count,ans);
        scanf("%s",str);
    }

    return 0;

}
