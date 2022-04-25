#include<iostream>
#include<vector>
#include<array>
#include<iomanip>
using namespace std; 
// Insertion Sort
// 0  1  2  3  4  5 
// 50 40 80 60 45 30 
// 50|40 80 60 45 30 
// 40 50|80 60 45 30 
// 40 50 80|60 45 30
// 40 50 60 80|45 30 
// 40 45 50 60 80|30
// 30 40 45 50 60 80 
// Done 
// Unsorted array: 50  40  80  60  45  30
// sorted array: 30  40  45  50  60  80
// O(n^2)
template <typename Comparable> 
void insertionSort(vector<Comparable>& a) {
	int size = a.size();
	for (int p = 1; p < size; ++p) {
		Comparable tmp = move(a[p]);
		int j;
	     for (j = p; j > 0 && tmp < a[j - 1]; --j)
	          a[j] = move(a[j - 1]);

		  a[j] = move(tmp);
	} // end for loop 
} // end function 
template <typename T , size_t size >
void insertionSort(array <T, size>& items) {
	int arraysize = items.size();
	// loop over the elements of the array 
	for (size_t next = 1; next < arraysize; ++next) {
		T insert = items[next];  // save value of next item to insert 
		size_t moveIndex = next; // initialize location to place element 

		// search for the location in which to put the current element 
		while ((moveIndex > 0) && (items[moveIndex - 1] > insert)) {
			// shift element one slot to the right 
			items[moveIndex] = items[moveIndex - 1];
			--moveIndex;
		}// end while loop 
		items[moveIndex] = insert; // place insert item back into array 
	} // end for loop 
}// end function 

// __________________________________________________________________________

// selection sort 
// O(n^2)
template <typename T>
void swap(T* xp, T* yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}
template <typename T , int n>
void selectionSort(array <T,n>&arr)
{
	int min_idx;

	// One by one move boundary of unsorted subarray 
	for (int i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]);
	}
}
template <typename T>
void selectionSort(vector<T>& a) {
	int min_idx;

	// One by one move boundary of unsorted subarray 
	for (int i = 0; i < (a.size()) - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (int j = i + 1; j < a.size(); j++)
			if (a.at(j) < a.at(min_idx))
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&a.at(min_idx), &a.at(i));
	}

}

// ____________________________________________________________________________
// Merge Sort 
// O(nlogn) 
/**
 * Mergesort algorithm (driver).
 */
 template < typename Comparable>
 void mergeSort(vector<Comparable> &a){
	 vector<Comparable> tmpArray(a.size());
	  mergeSort(a, tmpArray, 0, a.size() - 1);
 }
 
 /** Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.*/

 template < typename Comparable>
 void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right) {
	 if (left < right) {
		 int center = (left + right) / 2;
		 mergeSort(a, tmpArray, left, center);
		 mergeSort(a, tmpArray, center + 1, right);
		 merge(a, tmpArray, left, center + 1, right);
	 }
 }
 /**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
  template < typename Comparable>
	 void merge(vector<Comparable> &a, vector<Comparable> &tmpArray,
		  int leftPos, int rightPos, int rightEnd)
	  {
	  int leftEnd = rightPos - 1;
	  int tmpPos = leftPos;
	  int numElements = rightEnd - leftPos + 1;
	 
		  // Main loop
		  while (leftPos <= leftEnd && rightPos <= rightEnd)
		  if (a[leftPos] <= a[rightPos])
		  tmpArray[tmpPos++] = std::move(a[leftPos++]);
	      else
		  tmpArray[tmpPos++] = std::move(a[rightPos++]);
	 
		  while (leftPos <= leftEnd) // Copy rest of first half
		  tmpArray[tmpPos++] = std::move(a[leftPos++]);
	 
		  while (rightPos <= rightEnd) // Copy rest of right half
		  tmpArray[tmpPos++] = std::move(a[rightPos++]);
	 
		  // Copy tmpArray back
		  for (int i = 0; i < numElements; ++i, --rightEnd)
		  a[rightEnd] = std::move(tmpArray[rightEnd]);
	 }


// ________________________________________________________________________________


 /* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
 int partition(int arr[], int low, int high)
 {
	 int pivot = arr[low];
	 int i = low; 
	 int j = high; 
	 while (i < j) {
		 do {
			 i++;
		 } while (arr[i] <= pivot);
		 do {
			 j++;
		 } while (arr[j] > pivot);
		 if (i < j)
			 swap(arr[i], arr[j]);
	 }// end outer while loop  
	 swap(arr[low], arr[j]);
	 return j; 
 }
 /* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low --> Starting index,
 high --> Ending index */
 void quickSort(int arr[], int low, int high)
 {
	 if (low < high)
	 {
		 int j = partition(arr, low, high);
		 quickSort(arr, low, j);
		 quickSort(arr, j + 1, high);
	 }
 }


 /**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template < typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right){
	  if (left + 10 <= right)
		  {
		  const Comparable & pivot = median3(a, left, right);
			  // Begin partitioning
			  int i = left, j = right - 1;
		  for (;;)
			  {
			  while (a[++i] < pivot) {}
			  while (pivot < a[--j]) {}
			  if (i < j)
				  swap(a[i], a[j]);
			  else
				  break;
			  }
			  swap(a[i], a[right - 1]); // Restore pivot
		  quicksort(a, left, i - 1); // Sort small elements
		  quicksort(a, i + 1, right); // Sort large elements
		  }
	  else // Do an insertion sort on the subarray
		  insertionSort(a, left, right);
	  }



/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


void main() {
	// test insertionSort
	


	//const size_t arraysize = 6;
	//array <int, arraysize> data = { 50, 40, 80, 60, 45, 30 };
	//cout << "Unsorted array \n";
	//for (int i = 0; i < arraysize; i++) {
	//	cout << setw(4) << data[i];
	//}
	//cout << endl;
	//insertionSort(data); // call the insertionSort function to sort the array 
	//cout << "sorted array \n";
	//for (int i = 0; i < arraysize; i++) {
	//	cout << setw(4) << data[i];
	//}
	//cout << endl;

	/*vector<int> list; 
	list.push_back(50);
	list.push_back(40);
	list.push_back(80);
	list.push_back(60);
	list.push_back(45);
	list.push_back(30);
	insertionSort(list);
	for (int i = 0; i < list.size(); i++) {
		cout << setw(4) << list.at(i);
	}
	cout << endl; */
	
	// _______________________________________________________________________________
	// test selectionSort
	
	
	//const size_t arraysize = 6;
	//array <int, arraysize> data = { 50, 40, 80, 60, 45, 30 };
	//cout << "Unsorted array \n";
	//for (int i = 0; i < arraysize; i++) {
	//	cout << setw(4) << data[i];
	//}
	//cout << endl;
	//selectionSort(data); // call the insertionSort function to sort the array 
	//cout << "sorted array \n";
	//for (int i = 0; i < arraysize; i++) {
	//	cout << setw(4) << data[i];
	//}
	//cout << endl;

	/*vector<int> list;
	list.push_back(50);
	list.push_back(40);
	list.push_back(80);
	list.push_back(60);
	list.push_back(45);
	list.push_back(30);
	selectionSort(list);
	for (int i = 0; i < list.size(); i++) {
		cout << setw(4) << list.at(i);
	}
	cout << endl; */






	system("pause");
}