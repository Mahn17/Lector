#include <stdio.h>
#include <stdlib.h>
int TablaTransicion[][2] = {
      //0  1
/*0*/  {1, 2},
/*1*/  {3, 2},
/*2*/  {1, 2},
/*3*/  {4, 5},
/*4*/  {4, 5},
/*5*/  {6, 5},
/*6*/  {4, 5}};

int EstadosAceptacion[] = {0, 0, 0, 1, 1, 1, 1};

int simulaDFA(char *input)
{
    int state = 0;
    for (int i = 0; input[i] != '\0' && EstadosAceptacion[state] != 1; i++)
    {
        int inputIndex = input[i] - '0';
        state = TablaTransicion[state][inputIndex];
    }
    return EstadosAceptacion[state];
}
int main()
{
    char input[] = "111100";
    int result = simulaDFA(input);
    printf("Resultado: %d\n", result);
    return 0;
} //(0 | 1)*00(0 | 1)*