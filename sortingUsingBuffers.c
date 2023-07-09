#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 5
struct frame{
    int fslno;
    char finfo[50];
};
void sortFrames(struct frame* arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j].fslno > arr[j+1].fslno){
                struct frame temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void main(){
      int n;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    struct frame* arr = (struct frame*)malloc(n * sizeof(struct frame));

    for (int i = 0; i < n; i++) {
        arr[i].fslno = rand() % 50;
        printf("Enter the frame contents for sequence number %d: ", arr[i].fslno);
        scanf("%s", arr[i].finfo);
    }

    sortFrames(arr, n);

    printf("\nThe frames in sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", arr[i].fslno, arr[i].finfo);
    }

    free(arr);

}