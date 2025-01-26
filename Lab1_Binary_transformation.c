#include <stdio.h>

void TranformDtoB(int decimal,int bit,int Binary[]){

    if(decimal < 0){
        decimal=decimal*-1;
    }

    for(int i=bit-1;i>=0;i--){
        if(decimal == 0){
            for(int j = i;j>=0;j--){
                Binary[j] = 0;
            }
            break;
        }
        Binary[i] = decimal % 2;
        decimal = decimal/2; 
    }
}

void TranformToSignMagnitude(int decimal,int Binary[],int bit){
    if(decimal < 0){
        Binary[0] = 1;
    }
    printf("\nSign and Magnitude's form: ");
    for(int i=0;i<bit;i++){
        printf("%d",Binary[i]);
    }
}

void TranformTo1sComplement(int Binary[],int bit){
    for(int i=0;i<bit;i++){
        if(Binary[i]==0){
            Binary[i] = 1;
        }
        else{
            Binary[i] = 0;
        }
    }
    printf("\n1's complement form: ");
    for(int i=0;i<bit;i++){
        printf("%d",Binary[i]);
    }
    printf("\n");
}

void TranformTo2sComplement(int Binary[],int bit){
    if (bit == 0) return;
    if(Binary[bit-1]==0){
        Binary[bit-1] = 1;
    }
    else{
        TranformTo2sComplement(Binary,bit-1);
        Binary[bit-1] = 0;
    }
}

int main(){

    int bit;
    int decimal;
    printf("bit: ");
    scanf("%d",&bit);
    
    int size = 1;
    for (int i = 0; i < bit-1; i++) {
        size = 2*size; 
    }

    printf("decimal: -%d to %d:",size-1,size-1);
    scanf("%d",&decimal);
    if(decimal > size-1 || decimal < -(size-1)){
        printf("it out of range");
        return 0;
    }
    int Binary[bit];
    

    TranformDtoB(decimal,bit,Binary);
    printf("Binary form: ");
    for(int i=0;i<bit;i++){
        printf("%d",Binary[i]);
    }
    TranformToSignMagnitude(decimal,Binary,bit);
    TranformDtoB(decimal,bit,Binary);
    TranformTo1sComplement(Binary,bit);
    TranformTo2sComplement(Binary,bit);
    
    printf("2's complement form: ");
    for(int i=0;i<bit;i++){
        printf("%d",Binary[i]);
    }

    return 0;
}