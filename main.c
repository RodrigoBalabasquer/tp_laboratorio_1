#include <stdio.h>
#include <stdlib.h>
#include "libreriadeCalculadora.h"
#include <string.h>
#include "libreria.h"
#define T 20

int main()
{
    int X, opcion,flag1 = 1, flag2 = 1, flag3 = 1;
    float x, y, resultado;
    ePersonas Persona[T];
    int indice,flag1 = 0,flag2 = 0, opcion, validacion, contador1 = 0, contador2 = 0, contador3 = 0;
    char AUX[50]={"0"};
    char decision;
    Inicializar(Persona,T);
    do
    {
        system("cls");
        printf("CALCULADORA\n\n");
        printf("1 ingresar primer operando A\n");
        printf("2 ingresear segundo operando B\n");
        printf("3 Sumar\n");
        printf("4 Restar\n");
        printf("5 Multiplicar\n");
        printf("6 Dividir\n");
        printf("7 Factorial\n");
        printf("8 Todas las operaciones\n");
        printf("9 Salir\n");
        while(flag1 == 1 || flag2 == 1 || flag3 == 1)
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
            printf("\ningrese su opcion: ");
            scanf("%d",&opcion);
            while(!validarRango(opcion,1,9))
            case 1:
                flag1 = 1;
                indice = ObtenerLugar(Persona,T);
                if(indice == -1)
                {
                    printf("error reingrese opcion: ");
                    scanf("%d",&opcion);
                    printf("Todos los puestos estan ocupados");
                }
            switch (opcion)
            {
                case 1:
                    printf("ingrese su primer valor A: ");
                    scanf("%f",&x);
                    flag1 = 0;
                    break;
                case 2:
                    printf("ingrese su segundo valor B: ");
                    scanf("%f",&y);
                    flag2 = 0;
                    break;
                case 3:
                    if( flag1 == 0 && flag2 ==0)
                    {
                        resultado = sumar(x,y);
                        printf("El resultado de la suma es %f\n",resultado);
                        flag3 = 0;
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 4:
                    if( flag1 == 0 && flag2 ==0)
                    {
                        resultado = restar(x,y);
                        printf("El resultado de la resta es %f\n",resultado);
                        flag3 = 0;
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 5:
                    if( flag1 == 0 && flag2 ==0)
                else
                {
                    CargarDNI(AUX);
                    validacion = BuscarxDNI(Persona,T,AUX);
                    if(validacion == -1)
                    {
                        resultado = multiplicar(x,y);
                        printf("El resultado de la multiplicacion es %f\n",resultado);
                        flag3 = 0;
                        Persona[indice] = cargarPersona();
                        strcpy(Persona[indice].DNI,AUX);
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                        printf("El DNI que usted ingreso ya esta ingresado");
                    }
                    break;
                case 6:
                    if( flag1 == 0 && flag2 ==0)
                }
                break;
            case 2:
                if(flag1 == 1)
                {
                    CargarDNI(AUX);
                    indice = BuscarxDNI(Persona,T,AUX);
                    if(indice == -1)
                    {
                        if (y == 0)
                        {
                            printf("ERROR\n");
                        }
                        else
                        {
                            division(x,y);
                        }
                        flag3 = 0;
                         printf("El DNI que ingreso no se encuentra");
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 7:
                    if( flag1 == 0 && flag2 ==0)
                    {
                        if (x < 0)
                        printf("esta seguro que desea modificar este producto? s/n: ");
                        fflush(stdin);
                        scanf("%c",&decision);
                        if(decision == 's')
                        {
                            printf("ERROR\n");
                            Persona[indice].estado = 0;
                            indice = BuscarLugar(Persona,T);
                            if(indice == -1)
                            {
                                flag1 = 0;
                            }
                        }
                        else
                        {
                            X = (int)x;
                            resultado = factorial(X);
                            printf("El resultado del factorial es %f\n",resultado);
                        }
                        flag3 = 0;
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 8:
                    if( flag1 == 0 && flag2 ==0)
                    {
                        resultado = sumar(x,y);
                        printf("El resultado de la suma es %2f\n",resultado);
                        resultado = restar(x,y);
                        printf("El resultado de la resta es %f\n",resultado);
                        resultado = multiplicar(x,y);
                        printf("El resultado de la multiplicacion es %f\n",resultado);
                        if (y == 0)
                        {
                            printf("ERROR\n");
                        }
                        else
                        {
                            division(x,y);
                        }
                        if (x < 0)
                        {
                            printf("ERROR\n");
                        }
                        else
                        {
                            X = (int)x;
                            resultado = factorial(X);
                            printf("El resultado del factorial es %f\n",resultado);
                        }
                        flag3 = 0;
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 9:
                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                    break;
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
        flag1 = 1;
        flag2 = 1;
        flag3 = 1;
        system("pause");
    }while(opcion != 9);
    }while(flag2 == 0);
    return 0;

}



