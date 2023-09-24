#include <stdio.h>
#include <string.h>
char stack[20];
int top=-1;

void push(char a)
{
    stack[++top]=a;
    stack[top+1]='\0';
}
char pop()
{
    char a=stack[top];
    stack[top--]='\0';
    return a;
}
int dup(char s[])
{
	int count;
	for (int i=0;i<strlen(s);i++)
	{
	    if(s[i]==')')
	    {
	        count=0;
	        while(stack[top]!='(')
	        {
	            count++;
	            pop();
	        }
	        pop();
	        if(count==0)
	        {
	            printf("True");
	            break;
	        }
	    }
	    else
	    {
	        push(s[i]);
	    }
	    
	    
	}

  return 0;
}
