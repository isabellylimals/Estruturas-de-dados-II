#include <stdio.h>

int cont = 0;

int fibonacci(int n) {
    if (n == 5) {
        cont++;
    }
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    fibonacci(15);
    printf("Número de vezes que f(5) é chamado: %d\n", cont);
    return 0;
}

    /* 
a) Depure o código para descobrir quantas vezes o fibonacci(5) é calculado (requisitado). 89 vezes
Comandos: 
     b fibonacci if n==5
     run
     info f
     ignore (linha do bp) 1000
     info b



     omandos: 
      command
      set var count=0
      commands 1
      silent
	
      end
      run, next, next, c
      print $count
b)cle

c) Depure o código até o momento que o primeiro fibonacci(14) é calculado e o executável irá começar
   a calcular o fibonacci(13) (usei dois steps).
*/
