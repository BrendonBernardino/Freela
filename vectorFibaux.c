#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int separarVetor(int vet[], int fibo_primos[], int tamVet, int vetFiboPrimos[], int vetRestante[]) {
  int iter2 = 0;
  int iter3 = 0;
  for(int a = 0; a < tamVet; a++) {
    printf("vet[%d]:%d\n", a, vet[a]);
    for(int b = 0; b < 6; b++) {
      if(vet[a] == fibo_primos[b]) {
        vetFiboPrimos[iter2] = fibo_primos[b];
        //printf("vet[%d]:%d\n", a, vet[a]);
        //printf("fibo_primos[%d]:%d\n", b, fibo_primos[b]);
        iter2++;
      }
      else {
        vetRestante[iter3] = fibo_primos[b];
        iter3++;
      }
    }
  }

  return 0;
}

int fib(int y) { // y mínimo: 5   y máximo: 23    fibonacci = 28657            
  int i, fib1 = 1, fib2 = 1, soma;         
  for (i = 3; i <= y; i++) {                  
    soma = fib1 + fib2;                    
    fib1 = fib2;                           
    fib2 = soma;            
  }                                        
  return fib2;                             
}                                          

int main(void) {
  int n;
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &n);
  int m = n - 6;
  int iter = 0;
  printf("n: %d\n", n);
  int vetor[n]; //vetor principal
  int aux, primo;
  int fibonacci_primos[6]; //vetor auxiliar de primos em fibonacci
  int vetorFiboPrim[6];
  int vetorRestante[m];

  // Seta numeros aleatórios entre 4 e 41237 dentro de um vetor de tamanho n
  for(int i = 0; i < n; i++) {
    aux = 4+(rand()%41233);
    vetor[i] = aux;
  }

  for(int j = 0; j < n; j++) {
    printf("vetor[%d]: %d\n", j, vetor[j]);
  }
  //Fim do preenchimento do vetor principal

  //Preenchimento do vetor de primos em fibonacci
  //A função fib vai setar os valores de fibonacci até 41237, e esse loop vai verificar se o valor é primo ou não. Se for entra no vetor, se não for, não acontece nada.
  for (int x = 5; x <= 23; x++) {
    primo = 1; //considero inicialmente que o número é primo
    aux = fib(x);//x= 6 aux = 8
    for(int z = 2; z < aux; z++) { //tento provar que ele não é primo
      if (aux % z == 0) {
        primo = 0; //consigo provar que ele não é primo
      }
    }
    if (primo == 1) { //aux é primo então entra na lista
      fibonacci_primos[iter] = fib(x);
      iter++;
    }
  }
  //Fim do preenchimento do vetor de primos em fibonacci

  for(int k = 0; k < 6; k++) {
    printf("fibonacci_primos[%d]: %d\n", k, fibonacci_primos[k]);
  }

  separarVetor(vetor, fibonacci_primos, n, vetorFiboPrim, vetorRestante);

  for(int c = 0; c < 6; c++) {
    printf("vetorFiboPrim[%d]: %d\n", c, vetorFiboPrim[c]);
  }

  for(int d = 0; d < m; d++) {
    printf("vetorRestante[%d]: %d\n", d, vetorRestante[d]);
  }
  
  return 0;
}

