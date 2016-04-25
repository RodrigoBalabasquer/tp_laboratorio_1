#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
#define T 20
/** \brief Validamos si el entero esta dentro del rango
 *
 * \param entero a validar
 * \return retorna 1 si esta dentro del rango o 0 si esta fuera del rango
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

/** \brief Inicializamos todas las vacantes en cero
*
* \param vector de personas
* \param cantidad del vector de personas
*
*
*/
void Inicializar(ePersonas vec[],int cant)
 {
    int i;
    for(i = 0;i < cant; i++)
    {
        vec[i].estado = 0;/*el 0 significa que la vacante esta disponible*/
    }
}

/** \brief Buscamos una vacante que este en 0(osea que este libre para poder cargar una persona
 *
 * \param vector de personas
 * \param cantidad del vector de personas
 * \return retorna -1 si no hay lugar o retorna el numero del indice del vector donde cargaremos a nuestra persona
 *
 */
int ObtenerLugar(ePersonas vec[],int cant)
{
    int i, indice = -1;
    for(i = 0;i < cant;i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Despues de borrar a una persona verificamos que la lista no este vacia
 *
 * \param vector de personas
 * \param cantidad del vector de personas
 * \return retorna -1 si todos los lugares estan vacios o retorna otro valor si hay al menos una persona cargada
 *
 */
int BuscarLugar(ePersonas vec[],int cant)
{
    int i, indice = -1;
    for(i = 0;i < cant;i++)
    {
        if(vec[i].estado != 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Cargamos una cadena de caracteres con el valor del DNI, le sacamos los puntos para convertirla a entero y asi validar si esta dentro de rango y luego le volvemos a poner los puntos
 *
 * \param cadena de caracteres de la variable DNI
 *
 *
 */
void CargarDNI(char DNI[])
{
    int i, puntos, valido = 0;
    long int NUMERO;
    printf("Ingrese DNI: ");
    while(valido == 0)
    {
        puntos = 0;
        fflush(stdin);
        gets(DNI);
        for(i=0;i<10;i++)
        {
            if(DNI[i+puntos] == '.')
            {
                puntos++;
            }
            DNI[i] = DNI[i+puntos];
        }
        NUMERO = atol(DNI);
        if(NUMERO <= 99999999 && NUMERO >= 1000000)
        {
            sprintf(DNI,"%ld",NUMERO);
            if(strlen(DNI) == 7)
            {
                for(i = 8;i < 48;i++)
                {
                    DNI[i+1] = ' ';
                }
                DNI[8]=DNI[6];
                DNI[7]=DNI[5];
                DNI[6]=DNI[4];
                DNI[5] = '.';
                DNI[4]=DNI[3];
                DNI[3]=DNI[2];
                DNI[2]=DNI[1];
                DNI[1] = '.';
            }
            if(strlen(DNI) == 8)
            {
                for(i = 9;i < 48;i++)
                {
                    DNI[i+1] = ' ';
                }
                DNI[9]=DNI[7];
                DNI[8]=DNI[6];
                DNI[7]=DNI[5];
                DNI[6] = '.';
                DNI[5]=DNI[4];
                DNI[4]=DNI[3];
                DNI[3]=DNI[2];
                DNI[2] = '.';
            }
            valido = 1;
        }
        else
        {
            printf("ingrese DNI correctamente: ");
        }
    }
}

/** \brief Validamos si el DNI ingresado no se ingreso anteriormente
 *
 * \param vector de persona
 * \param cantidad del vector de persona
 * \param DNI que cargamos anteriormente
 * \return retorna -1 si es la primera vez que ingresamos este DNI, caso contrario retorna otro valor que indica que el ya se ha ingresado anteriormente
 *
 */
int BuscarxDNI(ePersonas vec[],int cant,char DNI[])
{
    int i, indice = -1;
    for(i=0;i < cant;i++)
    {
        if(strcmp(vec[i].DNI,DNI) == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Cargamos los demas valores a nuestra variable Persona
 *
 *
 * \return Retorna la variable Persona con los valores cambiados
 *
 */
ePersonas cargarPersona(void)
{
    ePersonas Persona;
    char aux[100];
    printf("Ingrese edad: ");
    scanf("%d", &Persona.edad);
    while(!validarRango(Persona.edad,1,100))
    {
        printf("error reingrese edad: ");
        scanf("%d",&Persona.edad);
    }
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)> 24)
    {
        printf("\nERROR nombre demasiado largo. Reingrese: ");
        fflush(stdin);
        gets(aux);
    }
    strcpy(Persona.nombre,aux);
    Persona.estado = 1;
    return Persona;
}

/** \brief Mostramos la lista de todas las personas cargadas
 *
 * \param vector de Personas
 * \param cantidad de Personas
 *
 *
 */
void mostrarListaPersonas(ePersonas vec[],int cant)
{
    int i;
    for(i = 0; i < cant; i++)
        {
            if(vec[i].estado == 1)
            {
                mostrarPersona(vec[i]);
            }
        }
}

/** \brief Mostramos los datos que le ingresamos a cada persona
 *
 * \param variable de tipo ePersonas con los datos cargados
 *
 *
 */
void mostrarPersona(ePersonas UnaPersona)
{
    printf("\nNombre: %s",UnaPersona.nombre);
    printf("\nEdad: %d",UnaPersona.edad);
    printf("\nDNI: %s",UnaPersona.DNI);
    printf("\n\n");
}

/** \brief Ordenamos la lista de personas segun el nombre en orden alfabertico
 *
 * \param vector de Personas
 * \param cantidad de Personas
 *
 *
 */
void ordenarPersona(ePersonas Persona[],int cant)
{
    int i, j;
    ePersonas aux;
    for(i = 0; i < cant-1; i++)
    {
        for(j = i+1; j < cant; j++)
        {
            if(strcmp(Persona[i].nombre,Persona[j].nombre) > 0)
            {
                aux = Persona[i];
                Persona[i] = Persona[j];
                Persona[j] = aux;
            }
        }
    }
}

/** \brief Contamos la cantidad de Personas que estan entre los limites de edad
 *
 * \param vector de Personas
 * \param cantidad de Personas
 * \param limite inferior de edad
 * \param limite superior de edad
 * \return cantidad de personas dentro de los limites
 *
 */
int ContarPersonas(ePersonas vec[],int cant, int inf, int sup)
{
    int i, cont = 0;
    for(i = 0;i < cant;i++)
    {
        if(vec[i].estado == 1)
        {
            if(vec[i].edad <= sup && vec[i].edad >= inf)
            {
                cont = cont + 1;
            }
        }
    }
    return cont;
}

/** \brief Hace un grafico donde podremos ver la cantidad de personas dentro de los rangos de edades
 *
 * \param cantidad de Personas menores o iguales a 18
 * \param cantidad de Personas entre 19 y 35
 * \param cantidad de Personas mayores a 35
 *
 */
void GraficarPersonas(int A, int B, int C)
{
    while(A != 0 || B != 0 || C != 0)
    {
        if(A > B && A > C)
        {
            printf("  *\n");
            A = A - 1;
        }
        else if(B > A && B > C)
        {
            printf("         *\n");
            B = B - 1;
        }
        else if(C > A && C > B)
        {
            printf("                 *\n");
            C = C - 1;
        }
        else if(A == B && A > C)
        {
            printf("  *       *\n");
            A = A - 1;
            B = B - 1;
        }
        else if(A == C && A > B)
        {
            printf("  *              *\n");
            A = A - 1;
            C = C - 1;
        }
        else if(C == B && B > A)
        {
            printf("         *       *\n");
            C = C - 1;
            B = B - 1;
        }
        else
        {
            printf("  *      *       *\n");
            A = A - 1;
            B = B - 1;
            C = C - 1;
        }
    }
    printf(" <18   19-35    >35");
}
