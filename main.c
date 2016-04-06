#include <stdio.h>
#include <stdlib.h>
#include "libreriadeCalculadora.h"
int main()
{
    int X, opcion,flag1 = 1, flag2 = 1, flag3 = 1;
    float x, y, resultado;
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
        {
            printf("\ningrese su opcion: ");
            scanf("%d",&opcion);
            while(!validarRango(opcion,1,9))
                {
                    printf("error reingrese opcion: ");
                    scanf("%d",&opcion);
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
                    {
                        resultado = multiplicar(x,y);
                        printf("El resultado de la multiplicacion es %f\n",resultado);
                        flag3 = 0;
                    }
                    else
                    {
                        printf("no se puede operar hasta que halla ingresado los operando");
                    }
                    break;
                case 6:
                    if( flag1 == 0 && flag2 ==0)
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
        flag1 = 1;
        flag2 = 1;
        flag3 = 1;
        system("pause");
    }while(opcion != 9);
    return 0;

}



