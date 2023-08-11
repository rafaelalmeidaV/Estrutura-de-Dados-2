#include <stdio.h>

int main()
{
    FILE *fp;

    char nome[50];
    fp = fopen("C:\\Users\\rafap\\www\\estrutura2\\ArquivosScan\\nomes.txt", "w");

    if (fp != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("Escreva um nome ");
            gets(nome);
            fprintf(fp, "Nome %d: %s\n", i + 1, nome);
        }
    }
    fclose(fp);

    fp = fopen("C:\\Users\\rafap\\www\\estrutura2\\ArquivosScan\\nomes.txt", "r");
    if (fp != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%s", nome);
            printf("%s\n", nome);
        }
    }
    fclose(fp);
    return 0;
}