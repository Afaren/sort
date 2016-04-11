/*************************************************************************
	> File Name: select.c
	> Author: Afar
	> Mail: 550047450@qq.com 
	> Created Time: Sun 10 Apr 2016 06:09:05 PM PDT
 ************************************************************************/

#include<stdio.h>


void printArray(int array[], int size);
void  SelectSort(int array[], int size );


int main(void)
{



	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;


	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	SelectSort(array, size);
	printf("After  sort: ");	
	printArray(array, size);
	return 0;
}


void printArray(int array[], int size)
{
	int i;
	for ( i = 0; i < size; i++ ) {
		printf("%d  ", array[i] );
	}
	printf("\n");
}

void SelectSort( int array[], int size)
{
	int min;
	int i, j, temp;
	for ( i = 0; i < size; i++ ) {
		min = i;
		for ( j = i + 1; j < size; j++ ) 
			if ( array[min] > array[j] ) {
				min = j;
			}
		if ( min != i ){
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

