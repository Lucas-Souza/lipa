#include <stdio.h>
void insertion (int vet[], int tamanho);

void main()
{
     /*
     n -> Quantidade de entradas para a lista
     vetor -> Vetor utilizado para armazenar os dados da lista
     i -> Variável auxiliar para o trabalho com índices do vetor
     frequencia_atual -> Variável para contar a frequência de determinado número quando se percorre o vetor
     maior_frequencia -> Variável para armazenar a maior frequencia encontrada no vetor
     quantidade_maior_frequencia -> Variável tilizada para armazenar quantos elementos existem com a maior frequência do vetor
     */
     int n = 0;
     while(n<1){
         scanf("%d", &n);
     }
     int * vetor = (int *) malloc(n * sizeof(int));
     int i = 0;
     for(i=0; i<n; i++){
          scanf("%d", &vetor[i]);
     }
     
     insertion(vetor, n); //chama a função de ordenação do tipo Insertion
     
     int maior_frequencia = 0, frequencia_atual = 1, quantidade_maior_frequencia = 0;
     
     //Após a lista estar ordenada, procure-se a maior frequência de elementos do vetor
     for(i=0; i<n; i++){
        frequencia_atual = 1;
        while(vetor[i+1] == vetor[i]){
            frequencia_atual++;
            i++;
        }
        if(frequencia_atual > maior_frequencia){
            maior_frequencia = frequencia_atual;
            quantidade_maior_frequencia = 1;
        }else if(frequencia_atual == maior_frequencia){
            quantidade_maior_frequencia++;
        }
        
     }
     //Após encontrar a maior frequência, percorre-se o vetor novamente imprimindo os elementos com esse valor de frequência
     for(i=0; i<n; i++){
        frequencia_atual = 1;
        while(vetor[i+1] == vetor[i]){
            frequencia_atual++;
            i++;
        }
        if(frequencia_atual == maior_frequencia){
            printf("%d ", vetor[i]);
        }
        
     }
     
  
  getch();
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
