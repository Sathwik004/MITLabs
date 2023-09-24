//NO MAIN FUNCTIONS OR HEADER
#define max 20
char stack[30];
int top = -1;

void push(char a)
{
    //printf("  top %d",top);
    stack[++top]=a;
    stack[top+1]='\0';
}
char pop()
{
    char a=stack[top];
    stack[top--]='\0';
    return a;
}
int isop(char op)
{
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
    case ')':
        return 4;
    default:
        return -1;
    }
}
int compare(char ch1,char ch2)
{
    int op1=isop(ch1),op2=isop(ch2);
    
    return (op1-op2);
}

void infixToPost(char infix[])
{
    //puts(infix);
    //printf("DONE");
    char temp[3],ch,res[20];
    res[0]='\0';
    temp[1]='\0';
    push('(');
    int m;
    for(int i=0;i<strlen(infix);i++)
    {
       ch = infix[i];
       if (isop(ch)==-1)//is ooperator
       {
           temp[0]=ch;
           strcat(res,temp);
           continue;
       }
       if(stack[top]=='(')
        {
           push(ch);
           continue;
        }
        if(ch==')')
        {
            while(stack[top]!='(')
            {
               temp[0]=pop();
               strcat(res,temp);
            }
            pop();
            continue;
        }//if +ve or 0 pop till neg then push
        if(compare(stack[top],ch)>=0 )
        {
           while(stack[top]!='(' && compare(stack[top],ch)>=0){
                temp[0]=pop();
                strcat(res,temp);
            }
            if(top>0)
                pop();
        }
        push(ch);
    } 
    while(stack[top]!='(')
    {
       temp[0]=pop();
       strcat(res,temp);
    }
   
    //puts(stack);
    puts(res);
}
