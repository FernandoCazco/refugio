#include <stdio.h>
#include <string.h>

#define MAX 5

void menu();
int buscar(char especies[][50], int total, char esp[]);
void registrar(char especies[][50], float pesos[], int cuidadores[], int dias[], int *total);
void mostrar(char especies[][50], float pesos[], int cuidadores[], int dias[], int total);
void editar(char especies[][50], float pesos[], int cuidadores[], int dias[], int total);
void dar_alta(char especies[][50], float pesos[], int cuidadores[], int dias[], int *total);
void evaluar(float pesos[], int cuidadores[], int dias[], int total, float alimentoDisp, int personalDisp);

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
            else if(op == 2)
                editar(especies, pesos, cuidadores, dias, total);
             else if(op == 4)
                mostrar(especies, pesos, cuidadores, dias, total);
             else if(op == 5)
                evaluar(pesos, cuidadores, dias, total, alimento, personal);
            else if(op == 6)
                printf("cerrando sistema...\n");
             else
                printf("opcion no valida\n");
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

void mostrar(char especies[][50], float pesos[], int cuidadores[], int dias[], int total){
    int i;

    if(total == 0){
        printf("el refugio esta vacio\n");
        return;
    }

    for(i = 0; i < total; i++){
        printf("%d) %s | peso: %.2f kg | cuidadores: %d | dias recuperacion: %d\n",
               i+1, especies[i], pesos[i], cuidadores[i], dias[i]);
    }
}

void editar(char especies[][50], float pesos[], int cuidadores[], int dias[], int total){
    char esp[50];
    int pos, op2;

    if(total == 0){
        printf("no hay animales registrados\n");
        return;
    }

    printf("especie a editar: ");
    scanf(" %s", esp);

    pos = buscar(especies, total, esp);
    if(pos == -1){
        printf("no se encontro esa especie\n");
        return;
    }

    printf("1-especie 2-peso 3-cuidadores 4-dias\n");
    scanf("%d", &op2);

    if(op2 == 1){
        printf("nueva especie: ");
        scanf(" %s", especies[pos]);
    } else if(op2 == 2){
        printf("nuevo peso (kg): ");
        scanf("%f", &pesos[pos]);
    } else if(op2 == 3){
        printf("nuevos cuidadores: ");
        scanf("%d", &cuidadores[pos]);
    } else if(op2 == 4){
        printf("nuevos dias: ");
        scanf("%d", &dias[pos]);
    }

    printf("actualizado\n");
}

void dar_alta(char especies[][50], float pesos[], int cuidadores[], int dias[], int *total){
    char esp[50];
    int pos, j;

    if(*total == 0){
        printf("no hay animales en el refugio\n");
        return;
    }

    printf("especie a liberar: ");
    scanf(" %s", esp);

    pos = buscar(especies, *total, esp);
    if(pos == -1){
        printf("no se encontro\n");
        return;
    }

    for(j = pos; j < *total - 1; j++){
        strcpy(especies[j], especies[j+1]);
        pesos[j] = pesos[j+1];
        cuidadores[j] = cuidadores[j+1];
        dias[j] = dias[j+1];
    }

    (*total)--;
    printf("animal dado de alta y liberado\n");
}

void evaluar(float pesos[], int cuidadores[], int dias[], int total, float alimentoDisp, int personalDisp){
    int i;
    float alimentoTotal = 0;
    int personalTotal = 0;

    if(total == 0){
        printf("no hay animales en el refugio\n");
        return;
    }

    for(i = 0; i < total; i++){
        alimentoTotal = alimentoTotal + (pesos[i] * 0.03f * dias[i]);
        personalTotal = personalTotal + cuidadores[i];
    }

    printf("alimento requerido: %.2f kg / disponible: %.2f kg\n", alimentoTotal, alimentoDisp);
    printf("personal requerido: %d / disponible: %d\n", personalTotal, personalDisp);

    if(alimentoTotal <= alimentoDisp && personalTotal <= personalDisp){
        printf("el refugio puede atender a todos los animales\n");
    } else {
        printf("capacidad insuficiente\n");
        if(alimentoTotal > alimentoDisp)
            printf("faltan %.2f kg de alimento\n", alimentoTotal - alimentoDisp);
        if(personalTotal > personalDisp)
            printf("faltan %d cuidadores\n", personalTotal - personalDisp);
    }
}