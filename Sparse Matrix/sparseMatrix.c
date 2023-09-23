// Transpose and fast transpose using array of objects-struct
#include <stdio.h>

typedef struct{
    int row,col,val;
}element;

int main() {
    int trows=5,tcols=5,nz=5,p=0;//declaring size m x n and num of non zero elements
    element a[nz],b[nz];
  
    for(int i=0;i<nz;i++)//Input
    {
        scanf("%d", &a[i].row);
        scanf("%d", &a[i].col);
        scanf("%d", &a[i].val);
        printf("\n");
    }
  
    printf("\nMATRIX\n");//Display before
    printf("Row Col Val\n");
    for(int i=0;i<nz;i++)
    printf("%d\t\t%d\t\t%d\n",a[i].row,a[i].col,a[i].val);
    
    /*for(int i=0;i<tcols;i++)// TRANSPOSE
    {
        for(int j=0;j<nz;j++)
        {
            if(a[j].col==i)
            {
                b[p].row=a[j].col;
                b[p].col=a[j].row;
                b[p].val=a[j].val;
                p++;
            }
        }
    }*/
    
    int count[tcols],index[tcols],pos;//FAST Transpose
    for(int j=0;j<tcols;j++)
    {
        count[j]=0;index[j]=0;
    }
    for(int i=0;i<nz;i++)
    {
        count[a[i].col]++;
    }
    for(int i=1;i<nz;i++)
    {
        index[i]=index[i-1]+count[i-1];
    }
    
    for(int i=0;i<nz;i++)
    {
        pos=index[a[i].col]++;
        b[pos].row=a[i].col;
        b[pos].col=a[i].row;
        b[pos].val=a[i].val;
    }
    
    //display b
    //printf("TRANSPOSE\n");
    printf("Row Col Val\n");
    for(int i=0;i<nz;i++)
    printf("%d\t\t%d\t\t%d\n",b[i].row,b[i].col,b[i].val);

    return 0;
}
/*
INPUT
0 0 5
0 4 5
1 4 4
2 4 4
3 3 1

OUTPUT
MATRIX
Row	Col	Val
0		0		5
0		2		5
1		4		4
2		1		4
3		3		1
TRANSPOSE
Row	Col	Val
0		0		5
1		2		4
2		0		5
3		3		1
4		1		4
*/
