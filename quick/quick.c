#include<assert.h>
#include<stdio.h>

void exch(int array[], int index_1, int index_2 );
int less(int v1, int v2 );
int isSorted(int array[], int size );

void printArray(int array[], int size);
void  QuickSort(int array[], int size );
void quick(int array[], int lo, int hi);
int partition(int array[], int lo, int hi);
void quick2(int array[], int lo, int hi);

int main(void)
{
	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;


	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	QuickSort(array, size);
	printf("After  sort: ");	
	printArray(array, size);
	
	//is the array sorted? 
	assert( isSorted(array, size) );
	
	return 0;
}

void QuickSort( int array[], int size)
{
	quick(array, 0, size-1);	
//	quick2(array, 0, size-1);
}
void quick2(int array[], int lo, int hi)
{
	if ( lo > hi ) return;
	int i, m;
	int *a = array;
	int v = a[lo];
	i = lo;
	for ( m = lo+1; m <= hi; m++ ) {
		if ( less( a[m], v ) )
			exch( a, ++i, m );
	}
	exch( a, lo, i );
	quick2(a, lo, i-1);
	quick2(a, i+1, hi);
}



void quick(int array[], int lo, int hi)
{
	if ( lo > hi ) return;
	int pivot = partition(array, lo, hi);
	quick(array, lo, pivot-1);
	quick(array, pivot+1, hi);
}

int partition(int array[], int lo, int hi)
{
	int i, j, v;
	int *a = array;
	v = a[lo];
	i = lo;
	j = hi+1;
	for ( ; ; ) {
		while ( a[++i] < v ) if ( i == hi ) break;
		while ( a[--j] > v ) if ( j == lo ) break;
		if ( i >= j ) break; // 两指针相遇说明遍历完了
		exch( a, i, j);
	}
	exch( a, lo, j );
	return j;

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

