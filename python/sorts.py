# collection of a few different sorting algorithms

class Sorts:

    # shrink inner for loop by len of array -i -1 to not do many pointless iterations once the sorting is finished (can also use boolean as show here - most basic swap/algo
    def bubbleSort(self, nums):
        for i in range(len(nums)):
            swap = False
            for j in range(len(nums)-i-1):
                if nums[j] > nums[j+1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
                    swap = True
            if not swap:
                break
        return nums

    # start inner loop index+1 to len of array and keep track of minimum index throughout each iteration - perform swap after each outter loop iteration
    def selectionSort(self, nums):
        for i in range(len(nums)):
            min_idx = i
            for j in range(i+1, len(nums)):
                if nums[j] < nums[min_idx]:
                    min_idx = j
            nums[i], nums[min_idx] = nums[min_idx], nums[i]
        return nums

    # start at index=1 and compare everything to the left in the array - then swap if condition
    def insertionSort(self, nums):
        for i in range(1, len(nums)):
            temp = nums[i]
            j = i - 1
            while j >= 0 and nums[j] > temp:
                nums[j+1] = nums[j]
                j -= 1
            nums[j+1] = temp
        return nums

    # divide and merge algorithm -
    def mergeSort(self, nums, low, high):

        def merge(nums, low, mid, high):
            temp = [0]*(high+1)
            l, r = low, mid+1
            i = 0
            while l <= mid and r <= high:
                if nums[l] <= nums[r]:
                    temp[i] = nums[l]
                    l += 1
                    i += 1
                else:
                    temp[i] = nums[r]
                    r += 1
                    i += 1

            while l <= mid:
                temp[i] = nums[l]
                l += 1
                i += 1
            while r <= high:
                temp[i] = nums[r]
                r += 1
                i += 1

            for i in range(low, high+1):
                nums[i] = temp[i-low]

        if low >= high: return # base case

        mid = low + (high - low) // 2
        self.mergeSort(nums, low, mid)
        self.mergeSort(nums, mid+1, high)
        merge(nums, low, mid, high)
            
        return nums


    # divide and conquer algorithm -
    def quickSort(self, nums, low, high):

        def partition(nums, low, high):
            pivot = nums[low]
            i = low
            j = high
            while i < j:
                while nums[i] <= pivot and i <= high - 1:
                    i += 1
                while nums[j] > pivot and j >= low + 1:
                    j -= 1
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]

            nums[low], nums[j] = nums[j], nums[low]

            return j
        if low < high:
            p_index = partition(nums, low, high)
            self.quickSort(nums, low, p_index-1)
            self.quickSort(nums, p_index+1, high)
        
        return nums


import random
if __name__ == "__main__":

    nums = [x+1 for x in range(10)]
    random.shuffle(nums)

    print(nums)
    #print(Sorts().bubbleSort(nums))
    #print(Sorts().selectionSort(nums))
    #print(Sorts().insertionSort(nums))
    low, high = 0, len(nums)-1
    print(Sorts().mergeSort(nums, low, high))
    #print(Sorts().quickSort(nums, low, high))
