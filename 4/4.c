#include <stdio.h>
#include <math.h>
struct coordenada{ int x, y, pertence_fecho;};

void insertionY (struct coordenada vet[], int tamanho);
int buscar_menor_x (struct coordenada vet[], int tamanho);

int main(void){
  int n = 0;
  while(n<3){
        scanf("%d", &n);
  }
  struct coordenada * vetor = (struct coordenada *) malloc(n * sizeof(struct coordenada));
  
  int i = 0;
  for(i = 0; i<n; i++){
        scanf("%d %d", &vetor[i].x, &vetor[i].y);
        vetor[i].pertence_fecho = 0;
  }
  
  insertionY(vetor, n);
  
  float dAB = 0, dBC = 0, dAC = 0, angulo = 0, maior_angulo = 0, distancia_maior = 0;
  int pos_maior_angulo = 0;
  int coord_anterior = buscar_menor_x(vetor, n), coord_atual = 0, nova_coord;
  
  while(vetor[0].pertence_fecho == 0){
        printf("%d, %d e %d , %d\n\n", vetor[coord_anterior].x, vetor[coord_anterior].y, vetor[coord_atual].x, vetor[coord_atual].y);
        maior_angulo = 0;
        for(i=0; i<n; i++){
        angulo = 0;
               if((vetor[i].x != vetor[coord_atual].x || vetor[i].y != vetor[coord_atual].y) && (vetor[i].x != vetor[coord_anterior].x || vetor[i].y != vetor[coord_anterior].y)){
                      dAB = sqrt((powf(vetor[coord_atual].x - vetor[coord_anterior].x,2) + powf(vetor[coord_atual].y - vetor[coord_anterior].y,2)));
                      dAC = sqrt((powf(vetor[coord_atual].x - vetor[i].x,2) + powf(vetor[coord_atual].y - vetor[i].y,2)));
                      dBC = sqrt((powf(vetor[i].x - vetor[coord_anterior].x,2) + powf(vetor[i].y - vetor[coord_anterior].y,2)));
                      angulo = acos(( (powf(dAB,2) + powf(dAC, 2) - powf(dBC,2))/(2*dAB*dAC)));
                      angulo = (angulo/ (2 * M_PI))*360;
                      printf("| %d e %d | - Ang: %f\n", vetor[i].x, vetor[i].y, angulo);
                      if(angulo > maior_angulo){
                                maior_angulo = angulo;
                                nova_coord = i;
                      }
               }
        }
        printf("\nPEGUEI: | %d e %d | - Ang: %f\n\n", vetor[nova_coord].x, vetor[nova_coord].y, maior_angulo);
        vetor[nova_coord].pertence_fecho = 1;
        coord_anterior = coord_atual;
        coord_atual = nova_coord;
        if(coord_atual == 0){
               vetor[0].pertence_fecho = 1;
        }
  }
  
  for(i=0; i<n; i++){
           if(vetor[i].pertence_fecho == 1)
                printf("( %d , %d ) \n", vetor[i].x, vetor[i].y);                 
  }
  
  
  
  
  
  
  free(vetor);
  getch();
  return 0;
}

void insertionY (struct coordenada vet[], int tamanho){
     //Método para ordenação das cordenadas em relação ao eixo Y
      int i, j, auxy, auxx;
      for (i = 1; i < tamanho; i++){
          auxy = vet[i].y;
          auxx = vet[i].x;
          j = i - 1;
          
          while ((j>=0) && (auxy < vet[j].y)) {
             vet[j+1].y = vet[j].y;
             vet[j+1].x = vet[j].x;
             j--;
         }
         
         if (i != j + 1){
            vet[j+1].y = auxy;
            vet[j+1].x = auxx;
         }
      } 
}

int buscar_menor_x (struct coordenada vet[], int tamanho){
    int i, pos_menor = 1;
    for(i = 1; i<tamanho-1; i++){
          if(vet[i].x < vet[pos_menor].x){
                 pos_menor = i;
          }
    }
    return  pos_menor;
}
