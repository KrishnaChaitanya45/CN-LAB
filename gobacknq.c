#include <stdio.h>
void main(){
    int w, f, frames[50], i;
    printf("enter the size of the window\n");
    scanf("%d", &w);
    printf("Enter the number of frames to transmit\n");
    scanf("%d", &f);
    printf("Enter the frames to transmit\n");
    for(i=1;i<=f;i++){
        printf("Enter %d frame : \t", i);
        scanf("%d", &frames[i]);
    }
    printf("with the sliding window protocal the frames will be sent in this manner\n");
    for(i=1;i<=f;i++){
        if(i % w == 0){
            printf("%d\n",  frames[i]);
            printf("Acknowledgement for the above frames are recieved\n");
        }
        else{
            printf("%d\n", frames[i]);
        }
    }
    if(f%w != 0){
        printf("Ack for the above frames are recieved..!\n");
    }
}