#include<stdio.h>
#include<math.h>

#define SIZE_ARR 50


void shift_element(int* arr, int i){
    for(int j=i; j>0; j--){
        *(arr+j+1)= *(arr + j);
    }

}

void print_array(int *arr, int len) {

	for(int i = 0; i<len-1; i++) {
        
		printf("%d,", *arr);
		arr++;
        
	}
    printf("%d" , *arr); 
	printf("\n");
}

// void main(){

// int arr[6]= {10,20,30,40,50};
// int size = sizeof(arr)/sizeof(int);
// shift_element(&arr[1],3);
// print_array(&arr[0],size);

// }

void insertion_sort(int* arr, int len){

    int count = 0;

    for(int j=0; j<len; j++){

        while ((arr+j)<(arr+j-count-1) && (count!=j)){
       
                count++;
            }

            int temp = *(arr+j);
              
            
           shift_element(arr+j-count-1, count);

            *(arr+j-count)=temp;

            count=0;
                      
        }
        
    }


int main(){

    int number[SIZE_ARR];
    
    for (int i = 0; i < SIZE_ARR; i++)
    {
       //printf("Enter a number: ");
       scanf("%d",&number[i]);


       
    }
    insertion_sort(&number[0],SIZE_ARR);
    
    print_array(&number[0],SIZE_ARR);

  return 0;

}

    


//3
// 42
// 28
// 42
// 29
// 28
// 70
// 6
// 76
// 79
// 23
// 46
// 96
// 81
// 26
// 26
// 2
// 64
// 40
// 66
// 21
// 78
// 55
// 58
// 13
// 9
// 32
// 1
// 56
// 14
// 5
// 44
// 64
// 8
// 14
// 31
// 77
// 46
// 40
// 25
// 70
// 8
// 67
// 32
// 38
// 49
// 48
// 93