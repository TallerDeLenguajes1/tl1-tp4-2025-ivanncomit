#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} typedef Tarea;

typedef struct Nodo 
{
    Tarea T;
    Nodo *Siguiente;
}Nodo;

Nodo *CrearNodo(int duracionTarea, int IdentificadorTarea, char * Descripcion);
void InsertarNodo(Nodo *Start, Nodo *Ingreso);

int main()
{
    Nodo * Pendientes = NULL;
    Nodo * Realizadas = NULL;

    int Identificador = 999, auxDuracion;
    int OpcionEscogida=1;
    char auxDescripcion[100];


    do 
    {   Identificador++;
        printf("Ingrese la descripcion de la nueva tarea: ");
        gets(auxDescripcion);
        printf("Ingrese la duracion estimada de la tarea: ");
        scanf("%d", &auxDuracion);
        CrearNodo(auxDuracion, Identificador, auxDescripcion);

        printf("Desea agregar otra tarea? (1 - SI | Cualquier otro - NO): ");
        scanf("%d", &OpcionEscogida);

    } while (OpcionEscogida==1);

    


    return 0;
}

Nodo *CrearNodo(int duracionTarea, int IdentificadorTarea, char * Descripcion)
{
    Nodo *NuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    NuevoNodo->T.Descripcion = Descripcion;
    NuevoNodo->T.Duracion = duracionTarea;
    NuevoNodo->T.TareaID = IdentificadorTarea;
    NuevoNodo->Siguiente = NULL;
    return NuevoNodo;
}

void InsertarNodo(Nodo *Start, Nodo *Ingreso)
{
    Ingreso->Siguiente = Start;
    Start = Ingreso;
}
