#include <stdio.h>
#include <stdlib.h>
#include "libreriadeCalculadora.h"
int main()
{
    int x, y, opcion, resultado;
    do
    {
        system("cls");
        printf("CALCULADORA\n\n");
        printf("1 Sumar\n");
        printf("2 Restar\n");
        printf("3 Multiplicar\n");
        printf("4 Dividir\n");
        printf("5 Factorial\n");
        printf("6 Todas las operaciones\n");
        printf("7 Salir\n");
        printf("ingrese su primer valor A: ");
        scanf("%d",&x);
        printf("ingrese su segundo valor B: ");
        scanf("%d",&y);
        printf("ingrese su opcion: ");
        scanf("%d",&opcion);
        while(!validarRango(opcion,1,7))
        {
            printf("error reingrese opcion: \n");
            scanf("%d",&opcion);
        }
        switch (opcion)
        {
            case 1:
                resultado = sumar(x,y);
                printf("El resultado de la suma es %d\n",resultado);
                break;
            case 2:
                resultado = restar(x,y);
                printf("El resultado de la resta es %d\n",resultado);
                break;
            case 3:
                resultado = multiplicar(x,y);
                printf("El resultado de la multiplicacion es %d\n",resultado);
                break;
            case 4:
                if (y == 0)
                {
                    printf("ERROR\n");
                }
                else
                {
                    division(x,y);
                }
                break;
            case 5:
                if (x < 0)
                {
                    printf("ERROR\n");
                }
                else
                {
                    resultado = factorial(x);
                    printf("El resultado del factorial es %d\n",resultado);
                }
                break;
            case 6:
                resultado = sumar(x,y);
                printf("El resultado de la suma es %d\n",resultado);
                resultado = restar(x,y);
                printf("El resultado de la resta es %d\n",resultado);
                resultado = multiplicar(x,y);
                printf("El resultado de la multiplicacion es %d\n",resultado);
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
                    resultado = factorial(x);
                    printf("El resultado del factorial es %d\n",resultado);
                }
                break;
        }
        system("pause");
    } while(opcion != 7);
    return 0;

}



