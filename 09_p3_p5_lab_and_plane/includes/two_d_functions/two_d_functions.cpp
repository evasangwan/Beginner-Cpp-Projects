#include "two_d_functions.h"
#include "assert.h"
#include <iomanip>


int array_size(int* sizes){
    int count = 0;                                                //to find the number of rows: first set count to 0 
    int *ptr = sizes;                                             //ptr points to sizes 
    while (*ptr != -1){                                           //end of sizes_array is -1, to know how many rows there are
        count++;                                                  //increment count 
        ptr++;                                                    //increment ptr 
    }
    return count;
}

void print_array(int* a){
    int* a_ptr = a;
    cout << "[";
    int count = array_size(a);
    for (int i = 0; i < count; i++){
        cout << setw(4) << *a_ptr;
        a_ptr++;
    } 
    cout << "]" << endl;
}

bool index_is_valid(int* sizes, int row, int col){
    int numofrows = array_size(sizes);
    int* ptr = sizes;
    if (row > numofrows){
        return false;
    }
    if (row <= numofrows){
        ptr += row;
        if(col <= *ptr){
            return true;
        }
}
    return false;
}