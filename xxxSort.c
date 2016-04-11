
#include<stdio.h>


void printArray(int array[], int size);
void  xxxSort(int array[], int size );


int main(void)
{



	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;


	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	// xxxSort(array, size);
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

void xxxSort( int array[], int size)
{

}
