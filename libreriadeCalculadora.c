/** \brief validamos si el entero esta dentro del rango 1-7
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


/** \brief realizamos la operacion de la suma
 *
 * \param primer entero a sumar
 * \param segundo entero a sumar
 * \return resultado de la suma
 *
 */
 int sumar(int num1, int num2)
 {
     return num1 + num2;
 }

/** \brief realizamos la operacion de la resta
 *
 * \param primer entero a restar
 * \param segundo entero a restar
 * \return resultado de la resta
 *
 */
 int restar(int num1, int num2)
 {
     return num1 - num2;
 }

/** \brief realizamos la operacion de la multiplicacion
 *
 * \param primer entero a multiplicar
 * \param segundo entero a multiplicar
 * \return resultado de la multiplicacion
 *
 */
 int multiplicar(int num1, int num2)
 {
     return num1 * num2;
 }

/** \brief realizamos la operacion del factorial
 *
 * \param entero a factorizar
 * \return resultado del factorial del entero
 *
 */
 int factorial(int num1)
 {
     int rta;
     if (num1 > 0)
     {
          if (num1 == 1)
            { rta = 1;}
          else
            { rta = num1 * factorial( num1 - 1);}
     }
     if (num1 < 0)
     {
          if (num1 == -1)
          { rta = 1;}
          else
          { rta = num1 * factorial( num1 + 1);}
              if (rta < 0)
                { rta = rta * -1;}
     }
     if (num1 == 0)
        { rta = 0;}
     return rta;
 }

/** \brief realizamos la operacion de la division
 *
 * \param entero divdendo
 * \param entero divisor
 * \return resultado de la division
 *
 */
 int division(int num1,int num2)
{
    printf("El resultado de la division es %.2f\n",(float)num1/num2);
    return num1 + num2 + 1;
}
