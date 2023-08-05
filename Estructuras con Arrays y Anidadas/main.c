#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDADEMPLEADO 2

struct Fecha{
    int dia;
    int mes;
    int anio;
};
//estructura para almacenar los atributos de un empleado,anidado con dos fechas
//nacimiento del empleado e Ingreso a la Empresa
struct Empleado{
    char nombreYApellido[40];
    float sueldo;
    char dni[8];
    char sexo;//m o f
    char cuit[11];
    struct Fecha nacimientoEIngreso[2];
};
struct Empresa {
      char direccion [20];
      char nombreEmpresa [20];
      //struct Empleado duenio; //Un solo empleado
      struct Empleado empleados[CANTIDADEMPLEADO]; //MUCHOS EMPLEADOS//El numero tiene que tener una variable global
};

void mostrarEmpleado (struct Empleado e);
struct Empleado cargarEmpleadoPorTeclado();
//ARRAY
//PRE: Se necesita crear un vector de Empleado y conocer el tamaño del vector
//POST: Se cargan todos los empleados del vector. Las fechas son enteras y no estan validadas
void cargarEmpleados (struct  Empleado v[], int t);
//PRE: Se necesita crear un vector de Empleado y conocer el tamaño del vector
//POST: Se muestran todos los empleados por consola
void mostrarEmpleados (struct Empleado v[], int t);
//Empresa
void cargarEmpresas (struct Empresa empresas[], int t);
void mostrarEmpresas (struct Empresa empresas[], int t);
void ordenarEmpresasPorNombre (struct Empresa empresas[], int t);
void mostrarEmpresa (struct Empresa empresa);
struct Empresa cargarEmpresaPorTeclado();
//Ordenamiento
//PRE: Se necesita crear un vector de Empleado y conocer el tamaño del vector
//POST: Se ordena el vector por nombre, el nombre sera un char[]
//no se podra comparar con < o >, se utiliza el strcmp que devuelve
//-1,0 o 1 segun el orden alfabetico
void ordenarEmpleadosPorNombre (struct Empleado v[], int t);
//PRE: Se necesita crear un vector de Empleado y conocer el tamaño del vector
//POST: Se ordena el vector por sueldo de menor a mayor
void ordenarEmpleadosPorSueldo (struct Empleado v [], int t);
//PRE: Se necesita un char[] como parametro de entrada
//POST: Devuelve -1 si no es m o f, devuelve 1 si lo es
int verificarSexo (char s);
//PRE: Se necesitan las dos cadenas de caracteres y conocer como
//es el funcionamiento de un cuit
//El DNI esta compuesto por numeros como: n0,n1,n2,n3,n4,n5,n6,n7
//El CUIT esta formado por n-2,n-1/n0,n1,n2,n3,n4,n5,n6,n6/n8
//Los numeros del 0 al 7 deben coincidir con el DNI
//El numero -2 y -1,lo define el sexo,20 para m y 27 f
//El numero 8 es el verificador y se saca de la siguiente cuenta:
//SUMA=n-2*2 + n-1*3 + n0*4 + n1*5 + n2*6 + n3*7 + n4*2 + n5*3 + n6*4 + n7*5
//Luego se calcula el resto de la division por 11 de SUMA..resto=suma/11
//el resto es el n8
//POST: Devuelve -1 si esta mal el cuit y 1 si esta bien el cuit
int verificarCuit (char dni[8], char cuit, char sexo);

int main()
{
    struct Empleado vectorEmpleados [CANTIDADEMPLEADO];
    cargarEmpleados (vectorEmpleados,CANTIDADEMPLEADO);

    ordenarEmpleadosPorNombre(vectorEmpleados,CANTIDADEMPLEADO);
    //ordenamientoSeleccion (vectorEmpleados,CANTIDADEMPLEADO);
    mostrarEmpleados (vectorEmpleados,CANTIDADEMPLEADO);

    ordenarEmpleadosPorSueldo (vectorEmpleados,CANTIDADEMPLEADO);
    mostrarEmpleados (vectorEmpleados,CANTIDADEMPLEADO);

    int cant = 2;
    struct Empresa vectorEmpresas [cant];
    cargarEmpresas (vectorEmpresas, cant);
    mostrarEmpresas (vectorEmpresas, cant);

    ordenarEmpresasPorNombre (vectorEmpresas, cant);
    mostrarEmpresas (vectorEmpresas, cant);
    //struct Empresa empresa1 = cargarEmpresaPorTeclado();
    //mostrarEmpresa(empresa1);

    printf ("\n\n");
    return 0;
}
void mostrarEmpleado (struct Empleado e){
     printf ("Nombre y Apellido: %s\nSueldo: %.2f\n",e.nombreYApellido,e.sueldo);
     printf ("DNI: %s\nGenero: %c\nCUIT: %s\n",e.dni,e.sexo,e.cuit);
     printf ("Anio de su nacimiento: %d\n",e.nacimientoEIngreso[0].anio);
     printf ("Mes de su nacimiento: %d\n",e.nacimientoEIngreso[0].mes);
     printf ("Dia de su nacimiento: %d\n",e.nacimientoEIngreso[0].dia);
     printf ("Anio de ingreso a la Empresa: %d\n",e.nacimientoEIngreso[1].anio);
     printf ("Mes de ingreso a la Empresa: %d\n",e.nacimientoEIngreso[1].mes);
     printf ("Dia de ingreso a la Empresa: %d\n",e.nacimientoEIngreso[1].dia);

}
struct Empleado cargarEmpleadoPorTeclado(){
     struct Empleado e; //BASURA
     char nombreAux[40]= " ";
     char dniAux[8]= " ";
     char cuitAux[11]= " ";

     printf ("\nIngrese su nombre y apellido: ");
     fflush (stdin);
     gets(nombreAux);
     strcpy(e.nombreYApellido,nombreAux);
     printf ("Ingrese su genero: ");
     fflush (stdin);
     scanf ("%c",&e.sexo);
     printf ("\nDevuelve un ----> %d\n\n",verificarSexo(e.sexo));

     printf ("\nIngrese su DNI: ");
     fflush (stdin);
     gets(dniAux);
     strcpy(e.dni,dniAux);
     printf ("Ingrese su CUIT: ");
     fflush (stdin);
     gets(cuitAux);
     strcpy(e.cuit,cuitAux);

     printf ("Ingrese su sueldo: ");
     scanf ("%f",&e.sueldo);

     printf ("Ingrese el anio de su nacimiento: ");
     scanf ("%d",&e.nacimientoEIngreso[0].anio);
     printf ("Ingrese el mes de su nacimiento: ");
     scanf ("%d",&e.nacimientoEIngreso[0].mes);
     printf ("Ingrese el dia de su nacimiento: ");
     scanf ("%d",&e.nacimientoEIngreso[0].dia);
     printf ("Ingrese el anio de ingreso a la Empresa: ");
     scanf ("%d",&e.nacimientoEIngreso[1].anio);
     printf ("Ingrese el mes de ingreso a la Empresa: ");
     scanf ("%d",&e.nacimientoEIngreso[1].mes);
     printf ("Ingrese el dia de ingreso a la Empresa: ");
     scanf ("%d",&e.nacimientoEIngreso[1].dia);

     return e;

};
void cargarEmpleados (struct  Empleado v[], int t){
     int i;
     for (i=0; i<t; i++){
        v[i] = cargarEmpleadoPorTeclado();
     }
}
void mostrarEmpleados (struct Empleado v[], int t){
     int i;
     for (i=0; i<t; i++){
        printf ("\nDatos del Empleado %d:\n",i+1);
        //printf ("%d",v[i]);
        mostrarEmpleado(v[i]);
     }
}
void mostrarEmpresa (struct Empresa empresa){
     printf ("---------- EMPRESA ----------");
     printf ("\nNombre: %s\nDireccion: %s\n",empresa.nombreEmpresa,empresa.direccion);
     mostrarEmpleados(empresa.empleados,2);
}
struct Empresa cargarEmpresaPorTeclado(){
     struct Empresa empre;
     char aux[20]= " ";
     char aux1[20]= " ";
     printf ("\nIngrese el nombre de la empresa: ");
     fflush (stdin);
     gets(aux);
     strcpy(empre.nombreEmpresa,aux);

     printf ("Ingrese la direccion: ");
     fflush(stdin);
     gets(aux1);
     strcpy(empre.direccion,aux1);

     //Me falta cargar los empleados
     cargarEmpleados(empre.empleados,2);

     return empre;
};
void cargarEmpresas (struct Empresa empresas[], int t){
    int i;
    for (i=0; i<t; i++){
        empresas[i] = cargarEmpresaPorTeclado();
    }
}
void mostrarEmpresas (struct Empresa empresas[], int t){
    int i;
    for (i=0; i<t; i++){
        printf ("\nDatos de la Empresa %d\n",i+1);
        mostrarEmpresa(empresas[i]);
    }
}
void ordenarEmpresasPorNombre (struct Empresa empresas[], int t){
    struct Empresa aux;
    int i,j;
    printf ("\n-------- Ordenamiento por Nombre de la Empresa ---------\n");
    for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (strcmp(empresas[j].nombreEmpresa, empresas[j+1].nombreEmpresa) == 1){
                aux = empresas[j];
                empresas[j] = empresas[j+1];
                empresas[j+1] = aux;
            }
        }
    }
}
void ordenarEmpleadosPorNombre (struct Empleado v[], int t){
    //strcmp (n1,n2)
    //----> 0 si son iguales
    //----> 1 si n1 esta dps de n2
    //----> -1 si n1 esta antes que n2
    struct Empleado aux;
    int i,j;
    printf ("\n--------Ordenamiento por Nombre---------\n");
    for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (strcmp(v[j].nombreYApellido, v[j+1].nombreYApellido) == 1){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void ordenarEmpleadosPorSueldo (struct Empleado v[], int t){
    struct Empleado aux;
    int i,j;
    printf ("\n--------Ordenamiento por Sueldo---------\n");
    for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (v[j].sueldo > v[j+1].sueldo){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
int verificarSexo(char s){
  struct Empleado sexo;
  int verificacion = -1;

  if (s=='m' || s=='M' || s=='f' || s=='F'){
    verificacion = 1;
  }

  return verificacion;
}