#include <iostream>

int main()
{
  int   a, b, c;
  int   *p1, *p2;
  int  **p;
  /* p es un pun
     tero que apuntará a otro puntero */
  p1 = &a;    /* Paso 1. La dirección de a es asignada a p1 */
  *p1 = 1;    /* Paso 2. p1 (a) es igual a 1. Equivale a a = 1; */
  p2 = &b;    /* Paso 3. La dirección de b es asignada a p2*/
  *p2 = 2;    /* Paso 4. p2 (b
		 ) es igual a 2. Equivale a b = 2; */
  p1 = p2;    /* Paso 5. El valor del p1 = p2 */
  *p1 = 0;    /* Paso 6. b = 0 */
  p2 = &c;    /* Paso 7. La dirección de c es asignada a p2 */
  *p2 = 3;    /* Paso 8. c = 3 */
  std::cout << a << b << c << std::endl;    /* Paso 9.
				     Se imprime 103 */
  p = &p1;    /* Paso 10. p contiene la dirección de p1 */
  *p = p2;    /* Paso 11. p1= p2; */
  *p1 = 1;    /* Paso 12. c = 1 */
  std::cout << a << b << c << std::endl;
  /* Paso 13. Se imprime 101 */
 
}
