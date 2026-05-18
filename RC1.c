#include <stdio.h>
#include <string.h>

#define MAX 5

int main(){
    char especies[MAX][50];
    float pesos[MAX];
    int cuidadores[MAX];
    int dias[MAX];
    int total = 0;
    int op;
    float alimento;
    int personal;

    printf("=== REFUGIO DE ANIMALES SILVESTRES ===\n");
    printf("ingrese el alimento disponible (kg): ");
    scanf("%f", &alimento);
    printf("ingrese el personal disponible: ");
    scanf("%d", &personal);

    do {
        scanf("%d", &op);
    } while(op != 6);

    return 0;
}