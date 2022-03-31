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
 /**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
 template < typename Comparable>
 void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right) {
	 if (left < right){
		 int center = (left + right) / 2;
		 mergeSort(a, tmpArray, left, center);
		 mergeSort(a, tmpArray, center + 1, right);
		 merge(a, tmpArray, left, center + 1, right);
	 }
 }

 /* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
 int partition(int arr[], int low, int high)
 {
	 int pivot = arr[high]; // pivot
	 int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	 for (int j = low; j <= high - 1; j++)
	 {
		 // If current element is smaller than the pivot
		 if (arr[j] < pivot)
		 {
			 i++; // increment index of smaller element
			 swap(&arr[i], &arr[j]);
		 }
	 }
	 swap(&arr[i + 1], &arr[high]);
	 return (i + 1);
 }
 /* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low --> Starting index,
 high --> Ending index */
 void quickSort(int arr[], int low, int high)
 {
	 if (low < high)
	 {
		 /* pi is partitioning index, arr[p] is now
		 at right place */
		 int pi = partition(arr, low, high);

		 // Separately sort elements before
		 // partition and after partition
		 quickSort(arr, low, pi - 1);
		 quickSort(arr, pi + 1, high);
	 }
 }
 /* Function to print an array */
 void printArray(int arr[], int size)
 {
	 int i;
	 for (i = 0; i < size; i++)
		 cout << arr[i] << " ";
	 cout << endl;
 }
 // Driver Code



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