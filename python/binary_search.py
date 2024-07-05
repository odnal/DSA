class Binary_Search:
    def bin_seach (self, array, target):
        
        low, high = 0, len(array)-1
        while low <= high:
            mid = low + (high-low)//2
            if array[mid] == target:
                return mid
            elif array[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        return -1

if __name__ == "__main__":
    
    nums = [3, 4, 5, 6, 7, 8, 9]
    target = 8

    print(Binary_Search().bin_seach(nums, target))
