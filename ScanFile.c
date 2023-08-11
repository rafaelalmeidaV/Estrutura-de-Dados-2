#include <stdio.h>

int main(){
    char str[80];
    float f;
    FILE *pFile=NULL;

    pFile = fopen("C:\\Users\\rafap\\www\\estrutura2\\myfile.txt", "r");
    if(pFile!=NULL){
        fscanf(pFile, "%f", &f);
        fscanf(pFile, "%s", str);
        fclose(pFile);
        printf("Li: %f e %s \n",f,str);
    }
    return 0;
}