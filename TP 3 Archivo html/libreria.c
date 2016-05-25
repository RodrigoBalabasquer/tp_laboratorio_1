#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

/** \brief Cargamos el titulo de nuestra pelicula en una variable
 *
 * \param Variable donde cargamos nuestro titulo
 *
 */
void CargarTitulo(char *titulo)
{
    char aux[300];
    printf("Ingrese Titulo: ");
    fflush(stdin);
    gets(aux);
    while(!validarString(aux,3,25))
    {
        printf("Reingrese Titulo: ");
        fflush(stdin);
        gets(aux);
    }
    strcpy(titulo,aux);
}

/** \brief Validamos si el titulo que ingresamos se a ingresado anteriormente
 *
 * \param puntero de arrive de peliculas
 * \param cantidad de peliculas ingresadas
 * \param titulo a validar
 * \return -1 si el titulo no se ingreso previamente y otro valor si ya fue ingresado
 *
 */
int BuscarTitulo(ePelicula *peli,int cant,char* titulo)
{
    int i, indice = -1;
    for(i=0;i<cant;i++)
    {
        if(strcmp((peli+i)->Titulo,titulo) == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Cargamos los campos restane a nuestro arrive de peliculas
 *
 * \param puntero de arrive de peliculas
 *
 */
void CargarPelicula(ePelicula *peli)
{
    char aux[300];
    int length;

    printf("Ingrese genero: ");
    fflush(stdin);
    gets(aux);
    while(!validarString(aux,5,15))
    {
        printf("Reingrese genero: ");
        fflush(stdin);
        gets(aux);
    }
    length = strlen(aux)+1;
    peli->Genero = (char*)malloc(length * sizeof(char));
    if(peli->Genero == NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    strcpy(peli->Genero,aux);

    printf("Ingrese Descripcion: ");
    fflush(stdin);
    gets(aux);
    while(!validarString(aux,15,250))
    {
        printf("Reingrese descripcion: ");
        fflush(stdin);
        gets(aux);
    }
    length = strlen(aux)+1;
    peli->Descripcion = (char*)malloc(length * sizeof(char));
    if(peli->Descripcion == NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    strcpy(peli->Descripcion,aux);

    printf("Ingrese Link de imagen: ");
    fflush(stdin);
    gets(aux);
    while(!validarString(aux,15,150))
    {
        printf("Reingrese link de pagina: ");
        fflush(stdin);
        gets(aux);
    }
    length = strlen(aux)+1;
    peli->LinkImagen = (char*)malloc(length * sizeof(char));
    if(peli->LinkImagen == NULL)
    {
        printf("No se consiguio memoria");
        exit(1);
    }
    strcpy(peli->LinkImagen,aux);

    printf("Ingrese duracion: ");
    scanf("%d",&peli->Duracion);
    while(!validarRango(peli->Duracion,20,200))
    {
        printf("Reingrese duracion: ");
        scanf("%d",&peli->Duracion);
    }
    printf("Ingrese Puntaje: ");
    scanf("%d",&peli->Puntaje);
    while(!validarRango(peli->Puntaje,1,100))
    {
        printf("Reingrese puntaje: ");
        scanf("%d",&peli->Puntaje);
    }
}

/** \brief Validamos la cantidad de caracteres de nuestras variables
 *
 * \param palabra que queremos validar
 * \param limite inferior
 * \param limite superior
 * \return 1 si esta dentrp del rango 0 si esta fuera
 *
 */
int validarString(char *palabra,int inf,int sup)
{
    int valido;
    if(strlen(palabra) >= inf && strlen(palabra) <= sup)
    {
      valido = 1;
    }
    else
    {
      valido = 0;
    }
    return valido;
}

/** \brief Validamos el numero ingresado
 *
 * \param numero que queremos validar
 * \param limite inferior
 * \param limite superior
 * \return 1 si esta dentrp del rango 0 si esta fuera
 *
 */
int validarRango(int x, int inf, int sup)
{
 int valido;
 if (x >= inf && x <= sup)
    {
      valido = 1;
    }
 else
    {
      valido = 0;
    }
 return valido;
}

/** \brief Intercambia de lugares la pelicula que seleccionamos para poder borrarla
 *
 * \param pelicula que queremos borrar
 * \param ultima pelicula del indice
 *
 */
void swapear(ePelicula *peliborrar,ePelicula *pelireubilar)
{
    ePelicula aux;
    aux = *peliborrar;
    *peliborrar = *pelireubilar;
    *pelireubilar = aux;
}

/** \brief Nos permite modificar el campo del arrive que seleccionemos
 *
 * \param puntero de arrive de peliculas
 * \param campo que queremos modificar
 * \param pelicula que queremos modificar
 *
 */
void ModificarPelicula(ePelicula *peli,int option,int indice)
{
    char aux[300];
    int length;
    switch(option)
    {
    case 1:
        printf("Ingrese genero: ");
        fflush(stdin);
        gets(aux);
        while(!validarString(aux,5,15))
        {
            printf("Reingrese genero: ");
            fflush(stdin);
            gets(aux);
        }
        length = strlen(aux)+1;
        (peli+indice)->Genero = (char*)malloc(length * sizeof(char));
        if((peli+indice)->Genero == NULL)
        {
            printf("No se consiguio memoria");
            exit(1);
        }
        strcpy((peli+indice)->Genero,aux);
        break;
    case 2:
        printf("Ingrese Descripcion: ");
        fflush(stdin);
        gets(aux);
        while(!validarString(aux,15,250))
        {
            printf("Reingrese descripcion: ");
            fflush(stdin);
            gets(aux);
        }
        length = strlen(aux)+1;
       (peli+indice)->Descripcion = (char*)malloc(length * sizeof(char));
        if((peli+indice)->Descripcion == NULL)
        {
            printf("No se consiguio memoria");
            exit(1);
        }
        strcpy((peli+indice)->Descripcion,aux);
        break;
    case 3:
        printf("Ingrese Link de imagen: ");
        fflush(stdin);
        gets(aux);
        while(!validarString(aux,15,150))
        {
            printf("Reingrese link de pagina: ");
            fflush(stdin);
            gets(aux);
        }
        length = strlen(aux)+1;
        (peli+indice)->LinkImagen = (char*)malloc(length * sizeof(char));
        if((peli+indice)->LinkImagen == NULL)
        {
            printf("No se consiguio memoria");
            exit(1);
        }
        strcpy((peli+indice)->LinkImagen,aux);
        break;
    case 4:
        printf("Ingrese duracion: ");
        scanf("%d",&(peli+indice)->Duracion);
        break;
    case 5:
        printf("Ingrese Puntaje: ");
        scanf("%d",&(peli+indice)->Puntaje);
        break;
    default:
        printf("Debe ingresar unas de las opciones del menu");
    }
}

/** \brief Genera un archivo html con el listado de las peliculas que hemos ingresado
 *
 * \param puntero de arrive de peliculas
 * \param cantidad de peliculas
 *
 */
void GenerarPaginaWeb(ePelicula *pelicula,int cant)
{
    int i;
    FILE *p;
    p = fopen("Lista de peliculas.html","w");
    if(p==NULL)
    {
        printf("No se puedo abrir el fichero");
        exit(1);
    }
    fprintf(p,"<Html>\n");
    fprintf(p,"<Head>\n");
    fprintf(p,"<Title>Cartelera</Title>");
    fprintf(p,"/<Head>\n");
    fprintf(p,"<Body>\n");
    for(i=0;i<cant;i++)
    {
        fprintf(p,"<article class='col-md-4 article-intro'>\n");
        fprintf(p,"     <a href='#'>\n");
        fprintf(p,"         <img class='img-responsive img-rounded' src=%s'alt=''>\n",(pelicula+i)->LinkImagen);
        fprintf(p,"     </a>\n");
        fprintf(p,"     <h3>\n");
        fprintf(p,"         <a href='#'>%s</a>\n",(pelicula+i)->Titulo);
        fprintf(p,"     </h3>\n");
        fprintf(p,"     <ul>\n");
        fprintf(p,"<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n",(pelicula+i)->Genero,(pelicula+i)->Puntaje,(pelicula+i)->Duracion);
        fprintf(p,"     </ul>\n");
        fprintf(p,"<p>%s.</p>\n",(pelicula+i)->Descripcion);
        fprintf(p,"</article>");
    }
    fprintf(p,"</Body>\n");
    fprintf(p,"</Html>\n");
    fclose(p);
}

/** \brief Muestra una lista de las peliculas ingresadas
 *
 * \param puntero de arrive de peliculas
 * \param cantidad de peliculas
 *
 */
void MostrarCarteleras(ePelicula *pelicula,int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        MostrarPelicula(pelicula+i);
    }
}

/** \brief Muestra los campos de las peliculas
 *
 * \param Pelicula a mostrar
 *
 */
void MostrarPelicula(ePelicula *pelicula)
{
    printf("Titulo: %s\n",pelicula->Titulo);
    printf("Genero: %s\n",pelicula->Genero);
    printf("Duracion: %d\n",pelicula->Duracion);
    printf("Puntaje: %d\n",pelicula->Puntaje);
    printf("Descripcion: %s\n",pelicula->Descripcion);
    printf("Link de imagen: %s\n",pelicula->LinkImagen);
    printf("\n\n\n");
}


