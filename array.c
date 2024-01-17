#include <stdio.h>


int main(){
int arr[50];
    int n, num, pos;
    
    printf("enter the size of the array : ");
scanf("%d",&n);



for(int i=0; i<n; i++){
    printf("enter the %dth term of array : ",i);
    scanf("%d",&arr[i]);
}

printf("enter the element you want to insert : ");
scanf("%d",&num);

printf("enter the postion you want to insert the data : ");
scanf("%d",&pos);

for(int i=n-1; i>=pos-1; i--){
    arr[i+1] = arr[i] ;
}
arr[pos-1] = num;
n++ ;
printf("elements in array are : ")
for(int i=0; i<=n-1; i++){
    printf("%d\t",arr[i]);
}
return 0;
}