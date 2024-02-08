#include <stdio.h>

#define SIZE 5
#define Ignorado -1

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
} BufferCircular;

int comentario=0;
int bloquecomen=0;
int comillas=0;
void initBuffer(BufferCircular *cbuf) {
    cbuf->head = 0;
    cbuf->tail = 0;

}

int BufferVacio(const BufferCircular *cbuf) {
    return (cbuf->head == cbuf->tail);
}

int BufferLleno(const BufferCircular *cbuf) {
    return ((cbuf->tail + 1) % SIZE == cbuf->head);
}

int enqueue(BufferCircular *cbuf, int value) {
    
    if (BufferLleno(cbuf)) {
        printf("Buffer lleno. No se puede encolar.\n");
    }
    if (value=='#'){
       comentario=1;
       //return Ignorado;
    }
    if (value=='"')
    {
        comillas++;
        if (comillas==3)
        {
            bloquecomen= !bloquecomen;
            comillas=0;
            return Ignorado;
        }
        return Ignorado;
    }else if (comillas>0)
    {
        comillas=0;
    }
    
    if (bloquecomen==1)
    {
        return Ignorado;
    }
    
    if (comentario==1)
    {   
        if(value=='\n'){
            comentario=0;
        }
        return Ignorado;
    }
    // if (bloquecomen==1)
    // {
    //     if (value=="'''"||value=='"""')
    //     {
    //         bloquecomen=0;
    //     }
    //     return Ignorado;
    // }
    
    else if (value==' '||value=='\n')
    {
        return Ignorado;
        
    }
    else{
        //printf("valor ignorado\n");
        cbuf->buffer[cbuf->tail] = value;
        cbuf->tail = (cbuf->tail + 1) % SIZE;
        return value;
    }
    
   
    // }else if (value=='"""'||value=="'''")
    // {
    //     return Ignorado;
    // }
}

int dequeue(BufferCircular *cbuf) {
    int value = 0;

    if (!BufferVacio(cbuf)) {
        value = cbuf->buffer[cbuf->head];
        cbuf->head = (cbuf->head + 1) % SIZE;
    } else {
        printf("Buffer vacío. No se puede desencolar.\n");
    }

    return value;
}

int main() {
    BufferCircular cbuf;
    initBuffer(&cbuf);

    FILE *file = fopen("archivo.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (BufferLleno(&cbuf)) {
            while (!BufferVacio(&cbuf)) {
                printf("Desencolando: %c\n", dequeue(&cbuf));
            }
        }
        int resultado= enqueue(&cbuf, ch);
        if(resultado==Ignorado){
            printf("Valor ignorado\n");
        }
        else{
        printf("Encolando: %c\n",resultado);
        }//enqueue(&cbuf, ch);
    }

    while (!BufferVacio(&cbuf)) {
        printf("Desencolando: %c\n", dequeue(&cbuf));
    }

    fclose(file);
    return 0;
}

//{-|+|e}{1-9}^+{0|2|4|6|8} expresion regular para pares
//{0|1}*{00}{0|1}* er para cadenas con alfabeto {0,1} que tengan la cadena 00
//(0|1){4} para todas las cadenas de 4 digitos alfabeto {0,1}
//(a(a|b)*a)|a todas las que empiezan y terminan con a alf{a,b}
//(aa|aba|b)*a(aa|b|aba)* todas las que tengan impar de a
//b*(a?b)*
//
//
//  (a-z|A-Z)|_)+ (0-9|a-z|A-Z|_)* ( )*=   
//  !(if|while|for|...)( )*=


/*
    /+
    /-
    /*
    //
    /=
    /(
    /)
    /[
    /]
    /<
    />
    /,
    /:
    /!=
    /==

*/