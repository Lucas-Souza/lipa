#include <stdio.h>
void insertion (int vet[], int tamanho);

void main()
{
  /*
   n -> Quantidade de entradas
   vetor -> Vetor para armazenar os n�meros
   i -> Vari�vel usada para aux�lio no trabalho com os �ndices do vetor
  */
  int n = 0;
  
        while(n<2){
            scanf("%d", &n);
        }
        
  int * vetor = (int *) malloc(n * sizeof(int));
  int i = 0;
  for(i=0; i<n; i++){
           scanf("%d", &vetor[i]); //Faz a leitura do vetor com os n�meros da lista
  }
  insertion(vetor, n); //Chama a fun��o de ordena��o por Insertion
  
  
  //Ap�s o vetor estar ordenado, percorre-se a lista para verificar os elementos �nicos
  for(i = 0; i<n; i++){
        if(vetor[i+1] != vetor[i])
             printf("%d ", vetor[i]);
        else{
             while(vetor[i+1] == vetor[i]){
                   i++;
             }
        }
  }
  getch();
}

void insertion (int vet[], int tamanho){
     //M�todo para ordena��o do tipo Insertion
      int i, j, aux;
      for (i = 1; i < tamanho; i++){
          aux = vet[i];
          j = i - 1;
          
          while ((j>=0) && (aux < vet[j])) {
             vet[j+1] = vet[j];
             j--;
         }
         
         if (i != j + 1){
            vet[j+1] = aux;                                        
         }
      } 
}
