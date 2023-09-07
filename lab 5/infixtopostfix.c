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
}
char* infixToPostfix(char* infix)
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
                //printf(") %s %s",op.stack,postfix.stack);
                continue;
            }
            m = compare(peek(&op),*infix);
            if (m>0)
            {
                if(peek(&op)=='(')
                {
                    push(&op,*infix);
                }
                else
                {
                    do{
                        
                        push(&postfix,pop(&op));
                }while(compare(peek(&op),*infix)>0);
                continue;
                }
                
            }
            else if(m==0)
            {
                push(&postfix,pop(&op));
                push(&op, *infix);//pop top and then push operator
            }
            else //m<0
            {
                push(&op,*infix);
            }
            
        }
        
        
        infix++;
        
        
         
    }
    //printf("hhwihwi ");
    while(peek(&op)!='(')
    {
        push(&postfix,pop(&op));
    }//pushing all remaining operators
    pop(&op);
    puts(postfix.stack);
    return postfix.stack;
}
int main()
{
    infixToPostfix("a+b/c*(e+h*f)-g");
    return 0;
}
