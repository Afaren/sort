
//Tue Apr 12 16:02:58 CST 2016


#include<assert.h>
#include<stdio.h>

void exch(int array[], int index_1, int index_2 );
int less(int v1, int v2 );
int isSorted(int array[], int size );


void printArray(int array[], int size);
void InsertSort(int array[], int size );



int main(void)
{



	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;


	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	InsertSort(array, size);
	printf("After  sort: ");	
	printArray(array, size);

	
	//is the array sorted? 
	assert( isSorted(array, size) );
	return 0;
}



void InsertSort( int array[], int size)
{
	int i, j;

	for ( i = 1; i < size; i++ ) {
		//将a[i]插入到a[i-1]、a[i-2]、a[i-3]...之中
		for( j = i; j > 0 ; j-- )
			if ( less(array[j], array[j-1]) )
				exch(array, j, j-1);
	}

}


void printArray(int array[], int size)
{
	int i;
	for ( i = 0; i < size; i++ ) {
		printf("%d  ", array[i] );
	}
	printf("\n");
}

int isSorted(int array[], int size )
{

	int i;
	for ( i = 1; i < size; i++ ){
		if ( less ( array[i], array[i-1] ) ) 
			return 0;
	}
	return 1;
}

int less(int v1, int v2 )
{
	return v1 <= v2;
}

void exch(int array[], int index_1, int index_2 )
{
	int temp = array[index_1];
	array[index_1] = array[index_2];
	array[index_2] = temp;
}

