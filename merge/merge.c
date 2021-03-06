#include<assert.h>
#include<stdio.h>

void exch(int array[], int index_1, int index_2 );
int less(int v1, int v2 );
int isSorted(int array[], int size );

void printArray(int array[], int size);
void MergeSort(int array[], int temp[], int lower, int upper );
void Merge(int array[], int temp[], int lower, int mid, int upper);



int main(void)
{
	int array[] = {3, 8, 5, 9, 1, 4, 6, 7, 2, 12, 90, 33};
	int size = 12;
	int temp[12];

	printf("Before sort: ");
	printArray(array, size);
	//sort the array
	MergeSort(array, temp, 0, size-1);
	printf("After  sort: ");	
	printArray(array, size);
	
	//is the array sorted? 
	assert( isSorted(array, size) );
	
	return 0;
}

void MergeSort(int array[], int temp[], int lower, int upper )
{

	if ( lower >= upper )
		return ;
	int mid = (lower+upper) / 2;
	MergeSort(array, temp, lower, mid);
	MergeSort(array, temp, mid+1, upper);
	Merge(array, temp, lower, mid, upper);
}
void Merge(int array[], int temp[], int lower, int mid, int upper)
{
	int *a = array;
	int i = lower, j = mid+1, k = lower;

	for ( ; i <= upper; i++ )
		temp[i] = a[i];


	for ( i = lower; i <= upper; i++ )
		if ( j > upper ) // 右边取尽
			a[i] = temp[k++];
		else if ( k > mid ) // 左边取尽
			a[i] = temp[j++];
		else if ( less(temp[k], temp[j]) ) // 左边的元素小
			a[i] = temp[k++];
		else				// 右边元素小
			a[i] = temp[j++];
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

