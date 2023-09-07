#include <stdio.h>
#define max 20
//EMPTY main method in the END 
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
    int n,m;
    while(*infix!='\0')
    {
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
            else //m<0
            {
                push(&op,*infix);
            }
        }
        infix++;
    }
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
    //infix=strrev(str); this method does not work bcz str is a pointer....gives error..any fixes??
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
   
    struct Stack op={-1},prefix={-1};
    push(&op,')');
    int n,m;
    char *infix=revinfix;
    while(*infix!='\0')
    {
        n = isop(*infix);
        if (n==-1)
        {   push(&prefix,*infix);
        }
        else
        {
            if (*infix=='(')
            {
                while(peek(&op)!=')')
                {
                    push(&prefix,pop(&op));
                }
                pop(&op);
                *infix++;
                continue;
            }
            m = compare(peek(&op),*infix);
            if (m>0)
            {
                if(peek(&op)==')')
                {
                    push(&op,*infix);
                }
                else
                {
                    do{
                        push(&prefix,pop(&op));
                    }while(compare(peek(&op),*infix)>0 && op.stack[op.top]!=')');
                continue;
                }
            }
            else //m<0
            {
                push(&op,*infix);
            }
        }
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
    return 0;
}
