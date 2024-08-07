#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* Char2int(char *input){
    int len = strlen(input);
    int* output = (int*)malloc(sizeof(int)*len);
    for(int i = 0;i<len;i++){
        if (input[i] == '1'){
            output[i] = 1;
        } else{
            output[i] = 0;
        }
    }
    return output;
}

char* Int2char(int *result,int len){
    char* output = (char*) malloc(sizeof(char)*len);
    for (int i = 0;i<len;i++){
        if (result[i] == 0){
            output[i] = '0';
        } else{
            output[i] = '1';
        }
    }
    return output;

}

char* addBinary(char *a, char* b){
    int flag = 0;
    if(strlen(a)< strlen(b)){
        char *c = a;
        a = b;
        b = c;
    }
    int len = strlen(b);
    int *num_a = Char2int(a);
    int *num_b = Char2int(b);

    int *result = (int*) malloc(sizeof(int)* strlen(a));
    int j = strlen(a)-1;
    for (int i = len-1;i>=0;i--){
//        printf("%d\n",result[i]);
        if (result[j] == 1 && num_a[j] == 1 || result[j] == 1 && num_b[i] == 1 || num_a[j] == 1 && num_b[i] == 1){
            result[j-1] = 1;
//            printf("%d %d\n",result[j-1],result[j]);
        }
        result[j] = result[j] ^ num_a[j] ^ num_b[i];
        j -= 1;
    }
//    printf("%d %d %d %d\n",result[0],result[1],result[2],result[3]);
//    for(int i =0;i< strlen(a);i++){
//        printf("N%d",result[i]);
//    } // '0001'

    for (int i = j;i>0;i--){
        if (result[i] == 1 && num_a[i] == 1){
            result[i-1] = 1;
        }
        result[i] = result[i] ^ num_a[i];
    }
//    printf("N%d %d\n",result[0],num_a[0]);
    if (result[0] == 1 && num_a[0] == 1){
        flag = 1;
        int *newresult = (int*) malloc(sizeof(int )* (strlen(a)+1));
        for (int i = strlen(a);i>=1;i--){
//            printf("i%d r%d\n",i,result[i-1]);
            newresult[i] = result[i-1];
        }
//        printf("%d %d %d %d\n",newresult[0],newresult[1],newresult[2],newresult[3]);
        newresult[0] = 1;
        newresult[1] = 0;
        free(result);
        result = newresult;
//        printf("%d %d %d\n",result[0],result[1],result[2]);
    } else{
        result[0] = num_a[0];
    }
    int len_out = strlen(a);
    if (flag == 1){
        len_out += 1;
    }
//    for (int i = 0;i< len_out;i++){
//        printf("%d",result[i]);
//    }
    char* output = Int2char(result,len_out);
    return output;
}



int main(void){
    char c1[] = "11101";
    char c2[] = "1001";
    char* output = addBinary(c1,c2);
    printf("%s",output);
}