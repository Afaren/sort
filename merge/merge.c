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

void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	
	if (  endIndex<= startIndex ) return;
	int	midIndex = (startIndex + endIndex) / 2;
	MergeSort(sourceArr, tempArr, startIndex, midIndex);
	MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
	Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);


}
void  Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex+1, k = startIndex;

	for ( ; k <= endIndex; k++ )
		tempArr[k] = sourceArr[k];

	for ( k = startIndex; k <= endIndex; k++ )
		if (i > midIndex)
			sourceArr[k] = tempArr[j++];
		else if (j > endIndex)
			sourceArr[k] = tempArr[i++];
		else if (less(tempArr[j], tempArr[i]))
			sourceArr[k] = tempArr[j++];
		else
			sourceArr[k] = tempArr[i++];
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

