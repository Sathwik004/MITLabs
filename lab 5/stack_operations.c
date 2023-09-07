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
