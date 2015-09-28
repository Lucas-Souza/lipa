#include <stdio.h>

void insertion (int vet[], int tamanho);

void main()
{
  /*
  n -> Quantidade de entradas para a minha lista
  vetor -> Vetor usado para armazenar as entradas
  i -> Variável auxiliar para o trabalho com os índices do vetor
  menor_diferenca -> Variável auxiliar para armazenar a menor diferença enquanto se percorre o vetor
  numero1 e numero2 -> Variáveis para armazenar os dois números do par com a menor diferença
  */   
     
  int n = 0;
  
  while(n<2){
  scanf("%d", &n); 
  }
  
  int * vetor = (int *) malloc(n * sizeof(int));
  int i = 0;
  for(i=0; i<n; i++){
           scanf("%d", &vetor[i]);
  }
  insertion(vetor, n); //Chama a função de ordenação
  
  int menor_diferenca, numero1, numero2;
  
  menor_diferenca = vetor[1] - vetor[0];
  numero1 = vetor[0];
  numero2 = vetor[1];
  
  //Após o vetor estar ordenado, percorre-se a lista para encontrar a menor diferença
  for(i = 1; i< n-1; i++){
        if((vetor[i+1] - vetor[i]) < menor_diferenca){
             menor_diferenca = vetor[i+1] - vetor[i];
             numero1 = vetor[i];
             numero2 = vetor[i+1];
        }
  }
  free(vetor);  
  printf("\n\n(%d , %d)", numero1, numero2); //Imprime o par com a menor diferença
  getch();
  return 0;
}

void insertion (int vet[], int tamanho){
     //Método para ordenação do tipo Insertion
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
