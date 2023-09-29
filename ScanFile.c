#include <stdio.h>

int main(){
    char str[80];
    FILE *pFile=NULL;

    pFile = fopen("myfile.txt", "r");
    if(pFile!=NULL){
        fscanf(pFile, "%s", str);
        fclose(pFile);
        printf("Li: %s \n",str);
    }
    


    return 0;
}