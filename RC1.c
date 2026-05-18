#include <stdio.h>
#include <string.h>

#define MAX 5

void menu();
int buscar(char especies[][50], int total, char esp[]);
void registrar(char especies[][50], float pesos[], int cuidadores[], int dias[], int *total);

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
        if (op == 1)
            registrar(especies, pesos, cuidadores, dias, &total);
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

int buscar(char especies[][50], int total, char esp[]){
    int i;
    for(i = 0; i < total; i++){
        if(strcmp(especies[i], esp) == 0)
            return i;
    }
    return -1;
}

void registrar(char especies[][50], float pesos[], int cuidadores[], int dias[], int *total){
    char esp[50];
    float p;
    int c, d;

    if(*total >= MAX){
        printf("el refugio esta lleno\n");
        return;
    }

    printf("especie del animal: ");
    scanf(" %s", esp);

    if(buscar(especies, *total, esp) >= 0){
        printf("esa especie ya esta registrada\n");
        return;
    }

    printf("peso promedio del animal (kg): ");
    scanf("%f", &p);
    printf("cuidadores necesarios por animal: ");
    scanf("%d", &c);
    printf("dias estimados de recuperacion: ");
    scanf("%d", &d);

    strcpy(especies[*total], esp);
    pesos[*total] = p;
    cuidadores[*total] = c;
    dias[*total] = d;
    (*total)++;

    printf("animal registrado\n");
}