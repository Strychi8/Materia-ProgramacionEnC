#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>

struct PersonaE{
    char nombre[40];
    int dni;
    float altura;
    float peso;
    float imc; // p:(a*a) -calculable
};

Persona crearPersonaPorTeclado(){
    //el sizeof nos dice cuantos bytes se necesitan para una struct PersonaE 
    //el comando malloc reserva memoria en la estructura PersonaE
    Persona p = malloc(sizeof(struct PersonaE));

    char aux[40] = " ";

    printf("\nIngrese el dni: ");
    scanf("%d", &p->dni);
    printf("Ingrese la altura: ");
    scanf("%f", &p->altura);
    printf("Ingrese el peso: ");
    scanf("%f", &p->peso);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(aux);

    strcpy(p->nombre, aux);

    p->imc = (p->peso)/((p->altura)*(p->altura)); //funcion que calcule el imc

    return p;
}

Persona crearPersona(char n[40], int d, float a, float pe){
    Persona p = malloc(sizeof(struct PersonaE));

    p->dni = d;
    p->altura = a;
    p->peso = pe;
    strcpy(p->nombre, n);

    p->imc = pe/(a*a);

    return p;
}

void destruirPersona(Persona p){
   free(p);//En vez de reservar memoria esto lo que hace es liberar la memoria
}

void mostrarPersona(Persona p){
    printf("\n---------- PERSONA ----------\n");
    printf("Nombre: %s\n", p->nombre );
    printf("DNI: %d\n", p->dni );
    printf("Altura: %f\n", p->altura );
    printf("Peso: %f\n", p->peso );
    printf("IMC: %f\n", p->imc );
}

int getDni(Persona p){
    return p->dni;
}

float getAltura(Persona p){
    return p->altura;
}

float getImc(Persona p){
    return p->imc;
}

float getPeso(Persona p){
    return p->peso;
}

char* getNombre(Persona p){
    return p->nombre;
}

void setDni(Persona p, int d){
    p->dni = d;
};

void setAltura(Persona p, float a){
    p->altura = a;
    p->imc = (p->peso)/(a*a);
};

void setPeso(Persona p, float pe){
    p->peso = pe;
    p->imc = pe/((p->altura)*(p->altura));
}

void setNombre(Persona p, char n[40]){
    strcpy ( p->nombre, n);
};