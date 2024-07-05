#include <stdio.h>

// note, binary search only works on sorted array
int binary_search (int array[], int size, int target) {
  int low = 0; int high = size-1;
  while (low <= high) {
    int mid = low + ((high-low)>>1); // same as flooring a divide by 2
    if (array[mid] == target)
      return mid;
    else if (array[mid] < target)
      low = mid+1;
    else 
      high = mid -1; 
  }
  return -1;
}

int main () {

  int nums[] = {1,2,4,5,7,10};
  int size = sizeof(nums)/sizeof(nums[0]);
  printf("%d\n", binary_search(nums, size, 2));

  return 0;
}
