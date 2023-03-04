#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char **pChar;
    char *buff;
    int cant;

    buff = (char *)malloc(sizeof(char) * 50);
    printf("Ingrese la cantidad de nombres a cargar:");
    scanf("%d", &cant);
    getchar();
    pChar = (char **)malloc(sizeof(char) * cant);
    printf("Modulo para ingreso de nombres:\n");
    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese el %d° nombre:", (i+1));
        gets(buff);
       
        *(pChar + i)= (char *)malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(*(pChar + i), buff);
    }
    printf("*********************************************************\n");
    printf("Los nombre ingresados son:\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%s \n", pChar[i]);
    }
    

    free(buff);
    free(*pChar);
    return 0;
}