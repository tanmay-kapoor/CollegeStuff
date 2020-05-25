#include<stdio.h>

int main() {		//start of main
    int m, n, i, j, k = 1, temp;
    printf("Enter no. of rows and columns\n");
    scanf("%d%d",&m, &n);
    int mat[m][n], a[m*n][3], b[m*n][3], c[m*n][3];
    a[0][0] = m;
    a[0][1] = n;
    
    printf("Enter elements\n");		//store elements in compact form in matrix a and store directly in matrix mat
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d",&temp);
            mat[i][j] = temp;
            if(temp != 0) {
                a[k][0] = i;
                a[k][1] = j;
                a[k][2] = temp;
                k++;
            }
        }
    }
    a[0][2] = k - 1;
    int ch;
    
    while(1) {
    printf("1: Display\n2: Compact Form\n3: Simple Transpose\n4: Fast Transpose\n5: Exit\nChoice: ");
    scanf("%d",&ch);
    if(ch == 5)
    	break;
    switch(ch) {
    
    case 1:			//display matrix
    printf("Your entered matrix is:\n"); 
    for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                printf("%d ",mat[i][j]);
            }
            printf("\n");
    }
	break;
	
	case 2:			//display compact form
    printf("The compact form is:\n");
    for(i = 0; i < k; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    break;

	case 3:			//display simple transpose
    printf("The simple transpose is:\n");
    k = 1;
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    for(i = 0; i < b[0][1]; i++) {
	    for(j = 1; j <= b[0][2]; j++) {
		    if(i == a[j][1]) {
		    	b[k][0] = i;
			    b[k][1] = a[j][0];
			    b[k][2] = a[j][2];
			    k++;
		    }
       }
    }
    for(i = 0; i < k; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    break;
    
    case 4:			//display fast transpose
    printf("The Fast transpose is:\n");
    c[0][0] = a[0][1];
    c[0][1] = a[0][0];
    c[0][2] = a[0][2];
    int t = a[0][2], loc;
    int total[n], index[n+1];
    for(i = 0; i < n; i++) {
    	total[i] = 0;
    }
    for(i = 1; i <= t; i++) {
    	j = a[i][1];
    	total[j]++;
    }
    index[0] = 1;
    for(i = 1; i <= n; i++) {
    	index[i] = index[i-1] + total[i-1];
    }
    for(i = 1; i <= t; i++) {
    	j = a[i][1];
    	loc = index[j];
    	index[j]++;
    	c[loc][0] = a[i][1];
    	c[loc][1] = a[i][0];
    	c[loc][2] = a[i][2];
    }
    for(i = 0; i <= t; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    break;
    
    default:
    printf("Enter Valid choice!\n");
   
    }
    }
    
    return 0;
}


/*Output
Enter no. of rows and columns
3
4
Enter elements
4
6
0
0
0
0
6
0
0
0
8
0
1: Display
2: Compact Form
3: Simple Transpose
4: Fast Transpose
5: Exit
Choice: 1
Your entered matrix is:
4 6 0 0 
0 0 6 0 
0 0 8 0 
1: Display
2: Compact Form
3: Simple Transpose
4: Fast Transpose
5: Exit
Choice: 2
The compact form is:
3 4 4 
0 0 4 
0 1 6 
1 2 6 
2 2 8 
1: Display
2: Compact Form
3: Simple Transpose
4: Fast Transpose
5: Exit
Choice: 3
The simple transpose is:
4 3 4 
0 0 4 
1 0 6 
2 1 6 
2 2 8 
1: Display
2: Compact Form
3: Simple Transpose
4: Fast Transpose
5: Exit
Choice: 4
The Fast transpose is:
4 3 4 
0 0 4 
1 0 6 
2 1 6 
2 2 8 
1: Display
2: Compact Form
3: Simple Transpose
4: Fast Transpose
5: Exit
Choice: 5
*/
