#include<assert.h>
#include<stdio.h>

void exch(int array[], int index_1, int index_2 );
int less(int v1, int v2 );
int isSorted(int array[], int size );

void printArray(int array[], int size);
void  Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex);
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);


int main(void)
{
	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;
	int temp[12];


	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	MergeSort(array, temp, 0, 11 );
	printf("After  sort: ");	
	printArray(array, size);
	
	//is the array sorted? 
	assert( isSorted(array, size) );
	
	return 0;
}

void MergeSort(int sourceArr[], int tempArr[], int lo, int hi)
{
	if ( lo >= hi )return;
	int mid = (lo+hi)/2;
	MergeSort(sourceArr, tempArr, lo, mid);
	MergeSort(sourceArr, tempArr, mid+1, hi);
	Merge(sourceArr, tempArr, lo, mid, hi);
}



void  Merge(int sourceArr[], int tempArr[], int lo, int mid, int hi)
{
	int i = lo, j = mid+1, k = lo;

	for ( i = lo; i <= hi; i++ )
		tempArr[i] = sourceArr[i];

	for ( i = lo; i <= hi; i++ )
		if ( j > hi )
			sourceArr[i] = tempArr[k++];
		else if ( k > mid )
			sourceArr[i] = tempArr[j++];
		else if ( less(tempArr[k], tempArr[j]) )
			sourceArr[i] = tempArr[k++];
		else 
			sourceArr[i] = tempArr[j++];

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

