
# QUESTION - APPLY BINARY SEARCH WHEN THE SIZE OF AN ARRAY IS UNKNOWN.

def linear_search(arr,x):
    i = 0
    while(True):
        if (arr[i] == x):
            return i

        i = i+1


def binary_search_helper(arr, x, low, high):
    mid = int((low + high)/2)
    while(low <= high):
        if (arr[mid] > x):
            high = mid -1
            mid = int((low + high)/2)
        elif (arr[mid] < x):
            low = mid + 1
            mid = int((low + high)/2)
        else:
            return mid

def binary_search(arr,x):
    low = 0
    high = 1

    while(arr[high] < x):
        low = high
        high *= 2

    return binary_search_helper(arr, x, low, high)


arr = eval(input("Enter arr: "))
x = int(input("Enter the element you want to search: "))

print("Index of the element you want to search using linear search is: ", linear_search(arr, x))
print("Index of the element you want to search using binary search is: ", binary_search(arr, x))


