#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"  

typedef struct {
    unsigned int id, lado1, lado2, lado3;
    char tipo[12];
} Triangulo;

int carregarArquivo(Triangulo triangulos[]);
int cadastrarTriangulo(Triangulo triangulos[], int total);
void listarTriangulos(Triangulo triangulos[], int total, const char* tipo);
void alterarTriangulo(Triangulo triangulos[], int total);
const char* tipoTriangulo(unsigned int l1, unsigned int l2, unsigned int l3);
int formaTriangulo(unsigned int l1, unsigned int l2, unsigned int l3);

int carregarArquivo(Triangulo triangulos[]) {
    FILE *file = fopen("triangulos.bin", "rb");
    if (!file) return 0;

    int count = fread(triangulos, sizeof(Triangulo), 1000, file);
    fclose(file);
    return count;
}

void salvarArquivo(Triangulo triangulos[], int total) {
    FILE *file = fopen("triangulos.bin", "wb");
    if (!file) {
        printf("Erro ao salvar o arquivo!\n");
        return;
    }
    fwrite(triangulos, sizeof(Triangulo), total, file);
    fclose(file);
}

const char* tipoTriangulo(unsigned int l1, unsigned int l2, unsigned int l3) {
    if (!formaTriangulo(l1, l2, l3)) return "nao existe";
    if (l1 == l2 && l2 == l3) return "equilatero";
    if (l1 == l2 || l1 == l3 || l2 == l3) return "isosceles";
    return "escaleno";
}

int formaTriangulo(unsigned int l1, unsigned int l2, unsigned int l3) {
    return (l1 + l2 > l3) && (l1 + l3 > l2) && (l2 + l3 > l1);
}

int cadastrarTriangulo(Triangulo triangulos[], int total) {
    if (total >= 1000) {
        printf("Limite de triângulos atingido.\n");
        return total;
    }

    Triangulo t;
    t.id = total + 1;

    t.lado1 = input_d("Digite o lado 1: ");
    t.lado2 = input_d("Digite o lado 2: ");
    t.lado3 = input_d("Digite o lado 3: ");

    strcpy(t.tipo, tipoTriangulo(t.lado1, t.lado2, t.lado3));

    triangulos[total] = t;

    FILE *file = fopen("triangulos.bin", "ab");
    if (file) {
        fwrite(&t, sizeof(Triangulo), 1, file);
        fclose(file);
    } else {
        printf("Erro ao salvar no arquivo.\n");
    }

    printf("Triângulo cadastrado com sucesso!\n");
    return total + 1;
}

void listarTriangulos(Triangulo triangulos[], int total, const char* tipo) {
    printf("\nid | Lado 1 | Lado 2 | Lado 3 | Tipo\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < total; i++) {
        if (!tipo || strcmp(triangulos[i].tipo, tipo) == 0) {
            printf("%2u | %6u | %6u | %6u | %s\n",
                   triangulos[i].id,
                   triangulos[i].lado1,
                   triangulos[i].lado2,
                   triangulos[i].lado3,
                   triangulos[i].tipo);
        }
    }
}

void alterarTriangulo(Triangulo triangulos[], int total) {
    unsigned int id = input_d("Digite o ID do triângulo a ser alterado: ");

    if (id == 0 || id > total) {
        printf("ID inválido.\n");
        return;
    }

    Triangulo *t = &triangulos[id - 1];

    t->lado1 = input_d("Novo lado 1: ");
    t->lado2 = input_d("Novo lado 2: ");
    t->lado3 = input_d("Novo lado 3: ");

    strcpy(t->tipo, tipoTriangulo(t->lado1, t->lado2, t->lado3));

    salvarArquivo(triangulos, total);
    printf("Triângulo alterado com sucesso!\n");
}

#endif
