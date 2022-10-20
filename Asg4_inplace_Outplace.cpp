/*
[Ans.1]
In-place algorithms
1. An in-place algorithm transforms the input without using any extra memory.
   As the algorithm executes, the input is usually overwritten by the output,
   and no additional space is needed for this operation.

2. An in-place algorithm may require a small amount of extra memory for its
   operation. However, the amount of memory required must not be dependent on
   the input size and should be constant.

3. Several sorting algorithms rearrange the input into sorted order in-place,
   such as insertion sort, selection sort, quick sort, bubble sort, heap sort, etc.
   All these algorithms require a constant amount of extra space for rearranging the
   elements in the input array.

4. Usually, an algorithm is categorized as an in-place or an out-of-place algorithm
   based on the explicit storage allocated by the algorithm. However, calling a recursive
   algorithm as in-place is highly debatable since extra space is being used by the call
   stack. Although this space required by the call stack technically takes the recursive
   algorithms out of the in-place algorithms category, the algorithms requiring only 
   O(log(n)) additional space is considered to be in-place.
   
5. In-place algorithms are usually used in an embedded system that runs in limited memory.
   They reduce the space requirements to a great extent, but the algorithm time complexity
   increases in some cases.


Out-of-place algorithms
1. An algorithm that is not in-place is called a not-in-place or out-of-place algorithm.
   Unlike an in-place algorithm, the extra space used by an out-of-place algorithm depends
   on the input size.
2. The standard merge sort algorithm is an example of out-of-place algorithm as it requires
   O(n) extra space for merging. The merging can be done in-place, but it increases the
   time complexity of the sorting routine. 
*/

//[Ans.2]

//Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;
//Creating Insertion Sort void function
void Inplace_insertionSort(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){
                arr[0]=temp;
                break;
            }
            if(arr[i]<=temp){
                arr[i+1]=temp;
                break;
            }
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void Outplace_insertionSort(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){
            arr[0]=temp;
            break;
        }
        if(arr[si]<=temp){
            arr[si+1]=temp;
            break;
        }
    }
    Outplace_insertionSort(arr,si+1,ei);
}

// Function to print the array.
void print_arr(int* arr, int n){
    for (int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    cout << endl << endl;
    cout << "Welcome to Inplace and Outplace search Algos." << endl;
    cout << "Submitted by:" << "  ";
    cout << "Ayush kansal (21105049)" << endl << endl;

    cout << "Answer1 and Answer 3 are written as a commented part in code." << endl << endl;
    int n;
    //Taking Input array
    cout<<"Total nunber of elements in the array: ";
    cin>>n;

    int arr[n],arr2[n];//Two array with same size and elements

    cout<<"Enter n elements of the array: ";
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        arr2[i] = tmp;
    }

    cout<<endl;

    cout<<"ARRAY BEFORE SORTING : ";print_arr(arr,n);

    //Calling insertion sort using in-place algorithm.
    Inplace_insertionSort(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    print_arr(arr,n);
    cout<<endl;

    //calling insertiong sort using out-place algorithm.
    Outplace_insertionSort(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    print_arr(arr,n);
    cout<<endl;

}

/*
[ANS.3]
In-place techniques have lesser space complexity but are difficult to 
apply in algorithm whereas out-place techniques are easy to aplly but 
increases the space complexity of algorithm.

For exapmle:
If we want to reverse an array then its in-place algorithm
will be swaping the first and last element of array until we reach the 
middle of array.
If we want to solve the same problem using out-place 
algorithm we have to create one extra array of same size and copy 
elements of original array from back to the front of new array,this 
algorith increases the space complexity to O(n) as we have creaed an 
extra array.

IN-PLACE algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heapsort.
NOT IN-PLACE algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.
*/