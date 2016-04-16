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
	int size = sizeof(array) / sizeof(int) ;


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
	//implement you code here
	int i, j;
	// 还是用i表示有序区这一概念比较好，所以，将i初始化为0，表示一开始有序区长度为0
	// 内循环j第一次循环时，j从1开始，表示将第二个元素插入到最终的位置
	// 因为一开始就是用第二个元素跟第一个元素比较，所以，外循环的次数应该是数组长度减一。
	// 因为如果循环次数是数组长度的话，最后一次循环就是数组最后一个元素的后一个（越界）跟最后一个比较了
	for ( i = 0; i < size - 1 ; i++ )
		for ( j = i + 1; j > 0 && less( array[j], array[j-1] ); j-- )
			exch( array, j, j-1 );

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

