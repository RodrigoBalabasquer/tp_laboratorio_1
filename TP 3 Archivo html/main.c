#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main()
{
    ePelicula *Pelicula;
    int i,tam;
    int cantidad = 0, validacion = -1,flag = 0,flag1 =0,opcion;
    char aux[26];
    char decision;
    Pelicula =(ePelicula*)malloc (1 * sizeof(ePelicula));
    if(Pelicula == NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    do
    {
        system("cls");
        printf("1 Agregar pelicula\n");
        printf("2 Borrar pelicula\n");
        printf("3 Modificar pelicula\n");
        printf("4 Generar pagina web\n");
        printf("5 Salir\n");
        printf("\ningrese su opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            flag1 = 1;
            Pelicula =(ePelicula*)realloc(Pelicula,(cantidad+1) * sizeof(ePelicula));
            if(Pelicula == NULL)
            {
                printf("No se consiguio memoria");
                exit(1);
            }
            CargarTitulo(aux);
            tam = strlen(aux)+1;
            validacion = BuscarTitulo(Pelicula,cantidad,aux);
            if(validacion == -1)
            {
                (Pelicula+cantidad)->Titulo = (char*)malloc(tam * sizeof(char));
                if((Pelicula+cantidad)->Titulo == NULL)
                {
                    printf("No se consiguio memoria");
                    exit(1);
                }
                CargarPelicula(Pelicula+cantidad);
                strcpy((Pelicula+cantidad)->Titulo,aux);
                cantidad = cantidad +1;
            }
            else
            {
                printf("El Titulo que usted ingreso ya fue ingresado");
            }
            system("pause");
            break;
        case 2:
            if(flag1 == 1)
            {
                CargarTitulo(aux);
                validacion = BuscarTitulo(Pelicula,cantidad,aux);
                if(validacion == -1)
                {
                     printf("La pelicula que ingreso no se encuentra");
                }
                else
                {
                    printf("esta seguro que desea borrar esta pelicula? s/n: ");
                    fflush(stdin);
                    scanf("%c",&decision);
                    if(decision != 'n')
                    {

                        swapear((Pelicula+validacion),(Pelicula+cantidad-1));
                        cantidad = cantidad -1;
                        if(cantidad == 0)
                        {
                            flag1 = 0;
                        }
                        else
                        {
                            Pelicula =(ePelicula*)realloc(Pelicula,(cantidad) * sizeof(ePelicula));
                            if(Pelicula == NULL)
                            {
                                printf("No se consiguio memoria");
                                exit(1);
                            }
                        }
                    }
                }
            }
            else
            {
                printf("aun no ha ingresado ninguna persona");
            }
            system("pause");
            break;
        case 3:
            if(flag1 == 1)
            {
                CargarTitulo(aux);
                validacion = BuscarTitulo(Pelicula,cantidad,aux);
                if(validacion == -1)
                {
                     printf("La pelicula que ingreso no se encuentra");
                }
                else
                {
                    printf("Seleccione la opcion que prefiera:\n ");
                    printf("1 Genero\n");
                    printf("2 Descripcion\n");
                    printf("3 Link de imagen\n");
                    printf("4 Duracion\n");
                    printf("5 Puntaje\n");
                    scanf("%d",&opcion);
                    ModificarPelicula(Pelicula,opcion,validacion);
                }
            }
            else
            {
                printf("aun no ha ingresado ninguna persona");
            }
            system("pause");
            break;
        case 4:
            if(flag1 == 1)
            {
                GenerarPaginaWeb(Pelicula,cantidad);
                MostrarCarteleras(Pelicula,cantidad);//Esta funcion no la pide el TP pero la hice para que se mas facil ver los cambios en el arrieve
            }
            else
            {
                printf("aun no ha ingresado ninguna persona");
            }
            system("pause");
            break;
        case 5:
            flag = 1;
            break;
        default:
            printf("Ingrese una opcion dentro del menu");
            system("pause");
        }
    }while(flag == 0);
    for(i=0;i<=cantidad;i++)
    {
        free((Pelicula+i)->Titulo);
        free((Pelicula+i)->Genero);
        free((Pelicula+i)->Descripcion);
        free((Pelicula+i)->LinkImagen);
    }
    free(Pelicula);
    return 0;
}


