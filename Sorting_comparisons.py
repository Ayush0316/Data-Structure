
# Name - Ayush Kansal
# SID - 21105049
# BRANCH - ECE





# TIME COMPLEXITY OF THIS CODE - O(n^2).
def bubbleSort(input,size):
    count_swaps = 0  #to maintain the count of the no. of swaps 
    count_comparisons = 0
    for j in range(size-1):
        for i in range(size-1):
            if (input[i] > input[i + 1]):
                temp = input[i]
                input[i] = input[i + 1]
                input[i + 1] = temp
                count_swaps += 1

            count_comparisons += 1

    ans = (count_swaps,count_comparisons) #tuple which store the number of swaps and number of comparisons respectively.
    return ans

# TIME COMPLEXITY OF THIS CODE - O(n^2).
def SelectionSort(input,size):
    count_swaps = 0
    count_comparisons = 0
    for i in range(size):
        min_index = i
        for j in range(i+1,size):
            if(input[j]<input[min_index]):
                min_index = j
                count_swaps += 1
            count_comparisons += 1
        temp = input[i]
        input[i] = input[min_index]
        input[min_index] = temp

    ans = (count_swaps,count_comparisons)
    return ans


def main():
    n = int(input("Enter the size of the list/array: "))

    arr = []
    for i in range(n):
        arr.append(input("Enter the element number " + str(i+1) + ": "))

    bubble = bubbleSort(arr,n)
    selection = SelectionSort(arr,n)

    print("COMPARISON BETWEEN INSERTION AND BUBBLE SORT. ")
    print()

    print("1. ON THE BASIS OF NUMBER OF COMPARISONS :  ")
    if(bubble[1] > selection[1]):
        print("MORE COMPARSIONS ARE DONE FOR BUBBLE SORT WHILE SORTING THE GIVEN ARRAY.")
    elif(bubble[1] < selection[1]):
        print("MORE COMPARISONS ARE REQUIRED FOR SELECTION SORT WHILE SORTING THE GIVEN ARRAY.")
    else:
        print("BOTH REQUIRE EQUAL NUMBER OF COMPARISONS WHILE SORTING THE GIVEN ARRAY.")
    print()

    # second comparison

    print("2. ON THE BASIS OF NUMBER OF SWAPS :  ")
    if(bubble[0] > selection[0]):
        print("MORE SWAPS ARE REQUIRED FOR BUBBLE SORT WHILE SORTING THE GIVEN ARRAY.")
    elif(bubble[0] < selection[0]):
        print("MORE SWAPS ARE REQUIRED FOR SELECTION SORT WHILE SORTING THE GIVEN ARRAY.")
    else:
        print("BOTH REQUIRE EQUAL NUMBER OF SWAPS WHILE SORTING THE GIVEN ARRAY.")

    print()

    print("3 . As both BubbleSort and SelectionSort are In-place algorithms, hence both of their Inplace Algorithms have been written above.")
main()