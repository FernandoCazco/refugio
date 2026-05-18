#include <stdio.h>
#include <string.h>

#define MAX 5

void menu();

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
        menu();
        scanf("%d", &op);
    } while(op != 6);

    return 0;
}

void menu(){
    printf("\n1- registrar animal\n");
    printf("2- editar animal\n");
    printf("3- dar de alta (liberar)\n");
    printf("4- ver animales\n");
    printf("5- evaluar capacidad del refugio\n");
    printf("6- salir\n");
    printf("opcion: ");
}