#include <stdio.h>
#include <stdlib.h>


float det2(float A[100][100], int start, int end);
int reduce(float a[100][100], int start, int n);
float printm(float A[100][100], int n);
float det(float A[100][100], int start, int n);


int main(void){
    float A[100][100], res;
    int i,j,k,n;

    printf("Enter the order of the matrix: \n");
    scanf("%d",&n);

    printf("\nEnter the elements of the matrix one by one: \n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            scanf("%f",&A[i][j]);
        }
    }
    printf("Entered matrix:\n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            printf("%f\t",A[i][j]);
        }
        printf("\n");
    }

    // ****************** Test ********************
    // reduce(A, 0, n);
    // printm(A, n);
    // reduce(A, 1, n);
    // printm(A, n);
    // ****************** End ********************

    // calculation
    printf("Calculating, please wait...\n");
    if(n == 1)
        res = A[0][0];
    else if(n == 2)
        res = det2(A, 0, 1);
    else
        res = det(A, 0, n);

    // display Result
    printf("%f\n",res);

    return 0;
}


float det2(float A[][100], int start, int end){
        float determinant = 0;
        determinant = A[start][start]*A[end][end]-A[start][end]*A[start][end];
        return determinant;
}


float det(float A[100][100], int start, int n){
    if((n - start) == 2)
        return det2(A, start, n-1);
    else{
        int flag = reduce(A, start, n);
        if(flag == 1)
            return -A[start][start] * det(A, start + 1, n);
        else if(flag == 2)
            return 0;
        else
            return A[start][start] * det(A, start + 1, n);
        }
}


int reduce(float A[][100], int start, int n){
        float a;
        int i,j;
        int flag = 0;
        for(i=start+1; i<n; i++){
            if(A[start][start] == 0){
                flag = 1;
                int k = start + 1;
                while(A[k][start] == 0){
                    k++;
                    if(k == n){
                        flag = 2;
                        break;
                    } 
                }
                printf("Exchanging %d with %d\n", k, start);
                int temp;
                for(j = 0; j<n; j++){
                    temp = A[k][j]; 
                    A[k][j] = A[start][j];
                    A[start][j] = temp; 
                }
                printm(A, n);
            }
            a = A[start][i] / A[start][start];
            for(j=start; j<n; j++){ 
                A[j][i] -= A[j][start] * a;
            }
        }
    return flag;
}


/****************** For DEBUGGING *******************/
float printm(float A[][100], int n){
        int i,j;
        printf("Entered matrix:\n");
        for(i = 0 ; i < n ; i++)
        {
            for(j = 0 ; j < n ; j++)
            {
                printf("%f\t",A[i][j]);
            }
            printf("\n");
        }
}

