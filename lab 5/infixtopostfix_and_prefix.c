#include <stdio.h>
#define max 20

//Stack Operations using pass by reference
struct Stack{
    int top;
    char stack[max];
};
void push(struct Stack *s,char item)
{
    if(s->top==max-1)
    return;
    s->stack[++(s->top)]=item;
    s->stack[s->top+1]='\0';
    //printf("\t\t%c\t\t",s->stack[s->top]);
}
char pop(struct Stack *s)
{
    
    if(s->top==-1)
    {printf("Empty\n");
    return '\0';}
    char item = s->stack[s->top];
    s->stack[s->top--] = '\0';
    return item;
    
}
char peek(struct Stack *s)
{
    return s->stack[s->top];
}
void display(struct Stack *s)
{
    puts(s->stack);
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
}char* infixToPostfix(char* infix)
{
    struct Stack op={-1},postfix={-1};
    push(&op,'(');
    int n,m;//int i=0;
    while(*infix!='\0')
    {
        //printf("%d %c\n",++i,*infix);
        n = isop(*infix);
        if (n==-1)
        {push(&postfix,*infix);}
        else
        {
            if (*infix==')')
            {
                while(peek(&op)!='(')
                {
                    push(&postfix,pop(&op));
                }
                pop(&op);
                *infix++;
                //printf(") %s %s",op.stack,postfix.stack);
                continue;
            }
            m = compare(peek(&op),*infix);
            if (m>=0)
            {
                if(peek(&op)=='(')
                {
                    push(&op,*infix);
                }
                else
                {
                    do{
                        
                        push(&postfix,pop(&op));
                }while(compare(peek(&op),*infix)>0&&peek(&op)!='(');
                continue;
                }
                
            }
            /*else if(m==0)
            {
                push(&postfix,pop(&op));
                push(&op, *infix);//pop top and then push operator
            }*/
            else //m<0
            {
                push(&op,*infix);
            }
        }
        //printf("%s\t %s\n",op.stack,postfix.stack);
        infix++;
    }
    //printf("hhwihwi ");
    //printf("%s",op.stack);
    while(peek(&op)!='('&&op.top>0)
    {
        push(&postfix,pop(&op));
    }//pushing all remaining operators
    pop(&op);
    puts(postfix.stack);
    return postfix.stack;
}
char* infixToPrefix(char* str)
{
    //infix=strrev(infix); not working....gives error
    char revinfix[strlen(str)+1];//infix will stores revrsed expression
    strcpy(revinfix,str);
    char* start = revinfix;
    char* end = revinfix + strlen(revinfix) - 1;
    
    for (int i=0;i<=strlen(revinfix)/2;i++) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
   
    //printf("\n%s \n",revinfix);
    struct Stack op={-1},prefix={-1};
    push(&op,')');
    int n,m;
    char *infix=revinfix;//&
    while(*infix!='\0')
    {
        //printf("%d %c\n",++i,*infix);
        //printf("here1");
        n = isop(*infix);
        if (n==-1)
        {   push(&prefix,*infix);
            //("here2");
        }
        else
        {
            if (*infix=='(')
            {
                //printf("here3");
                while(peek(&op)!=')')
                {
                    //printf("here4");
                    push(&prefix,pop(&op));
                    //printf("STACK %s\t %s\n",op.stack,prefix.stack);
                }
                pop(&op);
                //printf("\t\t%s\n",op.stack);
                *infix++;
                //printf(") %s %s",op.stack,postfix.stack);
                continue;
            }
            m = compare(peek(&op),*infix);
            if (m>0)
            {
                //printf("here5");
                if(peek(&op)==')')
                {
                    push(&op,*infix);
                }
                else
                {
                    do{
                        push(&prefix,pop(&op));
                    }while(compare(peek(&op),*infix)>0 && op.stack[op.top]!=')');
                //printf("after %d..%s\n",op.top,op.stack);
                continue;
                }
            }
            else //m<0
            {
                push(&op,*infix);
            }
        }
        //printf("STACK %s\t %s\n",op.stack,prefix.stack);
        infix++;
    }
    
    while(peek(&op)!=')')
    {
        push(&prefix,pop(&op));
    }//pushing all remaining operators
    pop(&op);
    
    char result[strlen(prefix.stack)+1];
    int i=0;
    while(prefix.top!=-1)
    {
        result[i]=pop(&prefix);
        i++;
    }
    result[i]='\0';
    puts(result);
    return result;
    
}
int main()
{
    infixToPostfix("a+b/c*(e+h*f)-g");
    return 0;
}
