#include <stdio.h>

void bubbleSort (int nums[], int size) {
  int swap = 0;
  for (int i=0; i<size; i++) {
    for (int j=0; j<size-i-1; j++) {
      if (nums[j] > nums[j+1]) {
        int tmp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = tmp;
        swap = 1;
      }
    }
    if (!swap) {
      break;
    }
  }
}

void selectionSort (int nums[], int size) {
  for (int i=0; i<size; i++) {
    int min_idx = i;
    for (int j=i+1; j<size; j++) {
      if (nums[j] < nums[min_idx]) {
        min_idx = j;
      }
    }
    int tmp = nums[i];
    nums[i] = nums[min_idx];
    nums[min_idx] = tmp;
  }
}

void insertionSort (int nums[], int size) {
  for (int i=1; i<size; i++) {
    int tmp = nums[i];
    int j = i-1;
    while (j>=0 && nums[j] > tmp) {
      nums[j+1] = nums[j];
      j--; 
    }
    nums[j+1] = tmp;
  }
}

void merge (int nums[], int low, int mid, int high) {
    
    int temp[high+1];
    int left = low;
    int right = mid+1;
    int i = 0;
    // [low..mid]
    // [mid+1..high]
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp[i++] = nums[left++];
        } else {
            temp[i++] = nums[right++];
        }
    }

    while (left <= mid) {
        temp[i++] = nums[left++];
    }
    
    while (right <= high) {
        temp[i++] = nums[right++];
    }

    // copy temp to original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i-low];
    }
}

void mergeSort (int nums[], int low, int high) {

    // base case
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

int partition (int nums[], int low, int high) {

    int pivot = nums[low]; // chosen pivot
    int i = low;
    int j = high;
    while (i < j) {
        while (nums[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (nums[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // swap pivot to correct place
    int temp = nums[low];
    nums[low] = nums[j];
    nums[j] = temp;

    return j;
}

void quickSort (int nums[], int low, int high) {

    if (low < high) {
        int p_index = partition(nums, low, high);
        quickSort(nums, low, p_index - 1);
        quickSort(nums, p_index + 1, high);
    }
}

void print_array(int array[], int size) {
  for (int i=0; i<size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main () {

  int nums[10] = {4,6,5,1,3,2,7,9,10,8};
  int size = sizeof(nums)/sizeof(nums[0]);

  print_array(nums, size);
  //bubbleSort(nums, size);
  //selectionSort(nums, size);
  //insertionSort(nums, size);
  int low = 0; int high = size-1;
  mergeSort(nums, low, high);
  //quickSort(nums, low, high);
  print_array(nums, size);

  return 0;
}
