#include<stdio.h>
void main(){

    int n1,n2;
    printf("Enter size of array1 and array2: ");
    scanf("%d %d",&n1,&n2);
    int arr1[n1],arr2[n2],merge[n1+n2];
    printf("enter elements of array1: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);

    }
    printf("enter array2 elements: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);

    }
    printf("The array1 elements are :");
    for(int i=0;i<n1;i++){
        printf("%d ",arr1[i]);

    }
    printf("\n");
    printf("The array2 elements are :");
    for(int i=0;i<n2;i++){
        printf("%d ",arr2[i]);

    }
    printf("\n");
    printf("Array after merging :");
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
                merge[k]=arr1[i];
                i++;
            }
        else{
                merge[k]=arr2[j];
                j++;
            }
    k++;
    }
    while(i<n1){
        merge[k]=arr1[i];
                i++;
                k++;
    }
    while(j<n2){
        merge[k]=arr2[i];
                j++;
                k++;
    }

    
    for(k=0;k<n1+n2;k++){
        printf("%d ",merge[k]);

    }


}