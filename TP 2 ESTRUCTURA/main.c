#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define T 20

int main()
{
    ePersonas Persona[T];
    int indice,flag1 = 0,flag2 = 0, opcion, validacion, contador1 = 0, contador2 = 0, contador3 = 0;
    char AUX[50]={"0"};
    char decision;
    Inicializar(Persona,T);
    do
    {
        system("cls");
        printf("Inscripciones\n\n");
        printf("1 Agregar una persona\n");
        printf("2 Borrar una persona\n");
        printf("3 Imprimir lista ordenada por nombre\n");
        printf("4 Imprimir grafico de edades\n");
        printf("5 Salir\n");
        printf("\ningrese su opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                flag1 = 1;
                indice = ObtenerLugar(Persona,T);
                if(indice == -1)
                {
                    printf("Todos los puestos estan ocupados");
                }
                else
                {
                    CargarDNI(AUX);
                    validacion = BuscarxDNI(Persona,T,AUX);
                    if(validacion == -1)
                    {
                        Persona[indice] = cargarPersona();
                        strcpy(Persona[indice].DNI,AUX);
                    }
                    else
                    {
                        printf("El DNI que usted ingreso ya esta ingresado");
                    }
                }
                break;
            case 2:
                if(flag1 == 1)
                {
                    CargarDNI(AUX);
                    indice = BuscarxDNI(Persona,T,AUX);
                    if(indice == -1)
                    {
                         printf("El DNI que ingreso no se encuentra");
                    }
                    else
                    {
                        printf("esta seguro que desea modificar este producto? s/n: ");
                        fflush(stdin);
                        scanf("%c",&decision);
                        if(decision == 's')
                        {
                            Persona[indice].estado = 0;
                            indice = BuscarLugar(Persona,T);
                            if(indice == -1)
                            {
                                flag1 = 0;
                            }
                        }
                    }
                }
                else
                {
                    printf("aun no ha ingresado ninguna persona");
                }
                break;
            case 3:
                if(flag1 ==1)
                {
                    ordenarPersona(Persona,T);
                    mostrarListaPersonas(Persona,T);
                }
                else
                {
                    printf("aun no ha ingresado ninguna persona");
                }
                break;
            case 4:
                if(flag1 ==1)
                {
                    contador1 = ContarPersonas(Persona,T,1,18);
                    contador2 = ContarPersonas(Persona,T,19,35);
                    contador3 = ContarPersonas(Persona,T,36,100);
                    GraficarPersonas(contador1,contador2,contador3);
                }
                else
                {
                    printf("aun no ha ingresado ninguna persona");
                }
                break;
            case 5:
                flag2 = 1;
                break;
            default:
                printf("La opcion que ingreso no esta disponible");
        }
        system("pause");
    }while(flag2 == 0);
    return 0;
}


