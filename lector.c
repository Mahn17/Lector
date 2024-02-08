#include <stdio.h>
#include <stdlib.h>


const char *palabras[] = {"False", "await", "else","async", "import", "pass",
                          "None", "break", "except", "in", "raise",
                          "True", "class", "finally", "is", "return",
                          "and", "continue", "for", "lambda", "try",
                          "as", "def", "from", "nonlocal", "while",
                          "assert", "del", "global", "not", "with",
                           "elif", "if", "or", "yield"};
                          
char *arreglo[] = {"","","","","",""};

void agregar_Arreglo(char *a){
    for (int i = 0; i < 10; i++)
    {
        if (arreglo[i]=="")
        {
            arreglo[i]= a;
            return;
        }
    }
}

void q1(char car, char *cadena)
{
    
    for (int i = 0; i < 35; i++)
    {
        if (car == palabras[i][0])
        {

            // q2(cadena[1], cadena);
            agregar_Arreglo(palabras[i]);
            
        }
    }
    for (int i = 0; i <sizeof(arreglo) / sizeof(arreglo[1]); i++){
        printf("arreglo en q1: %s\n",arreglo[i]);    
    }
    if (arreglo[0]!="")
    {
        q2(cadena[1],cadena,1,0);
    }
    
    //printf("no es una cadena reconocible");
}

void q2(char car, char *cadena,int a, int b)
{
    // for (int i = 0; i < sizeof(arreglo) / sizeof(arreglo[1]); i++)
    // {
    //     if (car == arreglo[i][1])
    //     {
    //         //printf("%s\n",arreglo[i]);
    //     }else{
    //         arreglo[i]="";
    //     }
    // }
    if (arreglo[b]!=NULL)
    {
        if (car == arreglo[b][a]){
            if (car==NULL&&arreglo[b][a-1]==cadena[a-1])
            {
                //if ((sizeof(arreglo[b]) / sizeof(arreglo[1][1]))==(sizeof(cadena)/sizeof(cadena[1])))
                //{
                    printf("se identifico: %s\n",arreglo[b]);
                //}
                
                
            }else{
                q2(cadena[a+1], cadena, a+1, b);
            }

        }else{
            arreglo[b]="";
            q2(cadena[a], cadena, a,b+1);
        }
    }else{
        printf("No es una cadena reconocible");
    }
    
    // if (car == arreglo[b][a]){
    //     if (car==NULL)
    //     {
    //         if ((sizeof(arreglo[b]) / sizeof(arreglo[1][1]))==(sizeof(cadena)/sizeof(cadena[1])))
    //         {
    //             printf("se identifico: %s\n",arreglo[b]);
    //         }
            
    //     }else{
    //         q2(cadena[a+1], cadena, a+1, b);
    //     }

    // }else{
    //     arreglo[b]="";
    //     q2(cadena[a], cadena, a,b+1);
    // }
    // q2(cadena[a+1], cadena, a+1,b);
    // for (int i = 0; i < sizeof(arreglo) / sizeof(arreglo[0]); i++)
    // {
    //     printf("arreglo en q",i,"\n", arreglo[i]);
    // }
    
}

int main()
{

    char cadena[] = "an";

    if (isdigit((unsigned char)cadena[0]))
    {
        printf("es numero");
    }
    else
    {
        q1(cadena[0], cadena);
    }
    //printf("%ld\n", sizeof(palabras) / sizeof(palabras[1]));
    
    return 0;
}