#include<stdio.h>

void bubble_sort(int arr[], int n);
int main(){
int n;
printf("enter the size of array : ");
scanf("%d",&n);

int arr[n];

for(int i=0; i<=n-1; i++){
    printf("enter the %dth element of array : ",i);
    scanf("%d",&arr[i]);
}
bubble_sort(arr, n);
printf("sorted array are : ");
for(int i=0; i<=n-1; i++){
    printf("%d\t",arr[i]);
}
return 0;
}

void bubble_sort(int arr[], int n){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}