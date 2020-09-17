#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define rows 5
#define cols 5

//1
void fillMatrix(int matrix[rows][cols]){
srand(time(0));
for(int i=0;i<5;i++){
	for(int j=0;j<5;j++){
		matrix[i][j]=rand()%100+1;
	}
}
}

//2
void printMatrix(int matrix[rows][cols])
{
	for(int i=0;i<5;i++){
		if(i==0){
			printf("[");
		}
		printf("[");
		for(int j=0;j<5;j++){
			printf("%d \t",matrix[i][j]);
		}
		if(i==4){
			printf("]]\n");
		}else{
			printf("]\n");
		}
	}
}

//3
void transposeMatrix(int matrix[rows][cols])
{
	for(int i=0;i<5;i++){
		for(int j=0;j<i;j++){
                int temp=*(*(matrix+i)+j);
		*(*(matrix+i)+j)=*(*(matrix+j)+i);
		*(*(matrix+j)+i)=temp;
		}
	}
}


//4
void multiplyMatrix(int m1[2][cols],int m2[rows][cols],int resultMatrix[rows][cols])
{
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			int sum=0;
			for(int k=0;k<5;k++){
				sum=sum+(*(*(m1+i)+k))*(*(*(m2+k)+j));
			}
                         *(*(resultMatrix+i)+j)=sum;
		}
	}
	for(int a=2;a<5;a++){
		for(int b=0;b<5;b++){
			*(*(resultMatrix+a)+b)=0;
		}
	}
}



int main()
{
	int matrix[rows][cols];
	fillMatrix(matrix);//Q1
	printMatrix(matrix);//Q2
        transposeMatrix(matrix);//Q3
	printMatrix(matrix);
	int matrix2[2][cols]={0,1,2,3,4,5,6,7,8,9};
	int matrixResult[rows][cols];
	multiplyMatrix(matrix2,matrix,matrixResult);//Q4
	printMatrix(matrixResult);
	return 0;
}

