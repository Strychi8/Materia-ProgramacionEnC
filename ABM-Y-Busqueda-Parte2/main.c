#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTMEDICOS 30

struct Medico{
   char nombreApellido[30];
   int dni;
   float altura;
};

struct Hospital{
   char nombre[30];
   char direccion [30];
   struct Medico equipoMedico [CANTMEDICOS];
   int enfermerosAgregados;
};

struct Medico cargarMedico ();
struct Hospital cargarHospital ();
void mostrarHospital (struct Hospital h);
void mostrarMedicos (struct Medico v[], int t);
void mostrarMedico (struct Medico medicos);
int busquedaPorDni (struct Medico v[], int t, int dniBuscado);
struct Hospital agregarMedicos (struct Hospital h, struct Medico m);
struct Hospital eliminarMedicos (struct Hospital h, int dni);
struct Hospital modificarMedicos (struct Hospital h, int dni);

int main()
{
    struct Hospital arrayMedicos[CANTMEDICOS];
    struct Medico m1,m2,m3,m4,m5;
    struct Hospital e1;

    printf("\n1) Cargo los datos.... ");
    e1=cargarHospital();
    m1=cargarMedico();
    m2=cargarMedico();
    //m3=cargarMedico();
    //m4=cargarMedico();

    printf("\n2) Agrego y muestro los datos: ");
    e1=agregarMedicos(e1,m1);
    e1=agregarMedicos(e1,m2);
    //e1=agregarMedicos (e1,m3);
    //e1=agregarMedicos (e1,m4);
    mostrarHospital(e1);

    printf("\n3) Eliminando medicos con dni=32 y dni=3.... \n");
    e1=eliminarMedicos(e1,32);
    e1=eliminarMedicos(e1,3);

    printf("\n4) Modifico al medico con dni=2: ");
    e1=modificarMedicos(e1,2);

    printf("\n5) Muestro los datos finales: ");
    mostrarHospital (e1);

    //printf("\n6) Busco si existe el dni=56");
    //printf ("\nLa busqueda sera ----> %d",busquedaPorDni(arrayMedicos, CANTMEDICOS, 56));

    return 0;
}
void mostrarMedico (struct Medico medicos){
   printf ("\nMedico: ");
   printf ("\nNombre y Apellido: %s\nDNI: %d\nAltura: %.2f\n",medicos.nombreApellido,
           medicos.dni,medicos.altura);
}
void mostrarMedicos (struct Medico v[],int t){
   int i;
   for (i=0; i<t; i++){
      if (v[i].dni != -100){
          mostrarMedico(v[i]);
      }
   }
}
struct Medico cargarMedico (){
   struct Medico m;
   char nombreAux[30]= " ";
   printf ("\nIngrese su nombre y apellido: ");
   fflush (stdin);
   gets (nombreAux);
   strcpy (m.nombreApellido,nombreAux);
   printf ("Ingrese su DNI: ");
   scanf ("%d",&m.dni);
   printf ("Ingrese su Altura: ");
   scanf ("%f",&m.altura);

   return m;
};
struct Hospital cargarHospital (){
   struct Hospital h;
   int i;
   h.enfermerosAgregados = 0;
   char nombreH[30] = " ";
   char direAux[30]= " ";
   printf ("\nIngrese el nombre del Hospital: ");
   fflush (stdin);
   gets (nombreH);
   strcpy (h.nombre,nombreH);
   printf ("Ingrese la direccion: ");
   fflush (stdin);
   gets (direAux);
   strcpy (h.direccion,direAux);

   for (i=0; i<CANTMEDICOS; i++){
    h.equipoMedico[i].dni = -100;
    h.equipoMedico[i].altura = -200;
    strcpy (h.equipoMedico[i].nombreApellido,"XXX");
   }

  return h;
};
void mostrarHospital (struct Hospital h){
   printf ("\nHospital: ");
   printf ("\nNombre: %s\nDireccion: %s\n",h.nombre,h.direccion);
   mostrarMedicos (h.equipoMedico, CANTMEDICOS);
}
int busquedaPorDni (struct Medico v[], int t, int dniBuscado){
    int resultado = -1;
    int i;
    for (i=0; i<t; i++){
        if (v[i].dni == dniBuscado){
            resultado = i;
        }
    }
    return resultado;
}
struct Hospital agregarMedicos (struct Hospital h, struct Medico m){
    int i = h.enfermerosAgregados;
    h.equipoMedico[i]=m;
    h.enfermerosAgregados=h.enfermerosAgregados+1;

    return h;
};
struct Hospital eliminarMedicos (struct Hospital h, int dni){
    int i= busquedaPorDni(h.equipoMedico,CANTMEDICOS,dni);
    if (i != -100){
        h.equipoMedico[i].dni = -100;
        h.equipoMedico[i].altura = -200;
        strcpy (h.equipoMedico[i].nombreApellido,"XXX");
    }
    return h;
};
struct Hospital modificarMedicos (struct Hospital h, int dni){
    int i = busquedaPorDni(h.equipoMedico,CANTMEDICOS,dni);
    if (i != -100){
        h.equipoMedico[i]=cargarMedico();
    }
    return h;
};
