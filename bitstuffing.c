#include <stdio.h>
int bitStuffing(int* input, int* output, int inputlength){
    int i,j=0;
    int count = 0;
    int maxConsecutiveOnes = 5;
    for(i=0;i<inputlength; i++){
        if(input[i] == 1){
            count++;
            if(count == maxConsecutiveOnes){
                output[j++] = 0;
                count = 0;
            }
        }
        else{
            count = 0;
        }
      output[j++]  =   input[i];

    }
    return j;

}
void main(){
    int input[50];
    int output[100];
    int outputlength = 0;
    int size;
    printf("Enter the frame length\n");
    scanf("%d", &size);
    printf("Enter input frame ( 0's & 1's only ) : ");
    for(int i=0;i<size; i++)
    scanf("%d", &input[i]);
   outputlength =  bitStuffing(input,output, size);
    printf("After stuffing, the frame is: ");
    for (int i = 0; i < outputlength; i++)
        printf("%d", output[i]);
}