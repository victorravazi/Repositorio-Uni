/*Crie um programa que leia 3 números inteiros representando os lados de um triângulo. Verifique se os 3 números
formam um triângulo e caso formem, calcule o seu tipo entre os possíveis: Equilátero, Isósceles ou Escaleno. Após
este cálculo, os dados devem ser imediatamente persistidos em um arquivo binário. Crie funcionalidades que
permitam alterar e listar esses dados.*/

/*  Requisitos:
1. Defina a seguinte struct para gerenciar os dados que serão manipulados:
*/
/*typedef struct 
{
    unsigned int id, lado1, lado2, lado3;
    char tipo[12];
} Triangulo;*/

/*2. Ao ler dados do arquivo, estes devem ser completamente transferidos para um array de structs que comporte
todos os registros. Defina o array com 1000 posições: Triangulo triangulos[1000];*/

/*Funcionalidades obrigatórias:
📂 Cadastro do triângulo:
- Grave os dados no arquivo logo após a digitação.
📋 Listagem:
- Listar todos os triângulos.
- Listar somente os equiláteros.
- Listar somente os escalenos.
- Listar somente os isósceles.
- Exemplo de listagem:

id | Lado 1 | Lado 2 | Lado 3 | Status
-----------------------------------------
1      3        3        3      equilatero
2      3        1        30     nao existe*/


/*✏️Alteração:
- Execute a alteração no array de structs e logo em
seguida atualize o arquivo com essa alteração.

[] Menu de Opções:
1. Cadastrar triangulo
2. Listar todos os triangulos
3. Listar somente os equilateros
4. Listar somente os isosceles
5. Listar somente os escalenos
6. Alterar dados
0. Sair*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "pss.h"

int main() {
    Triangulo triangulos[1000];
    int total = carregarArquivo(triangulos);
    int opcao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar triângulo\n");
        printf("2. Listar todos os triângulos\n");
        printf("3. Listar somente os equiláteros\n");
        printf("4. Listar somente os isósceles\n");
        printf("5. Listar somente os escalenos\n");
        printf("6. Alterar dados\n");
        printf("0. Sair\n");

        opcao = input_d("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                total = cadastrarTriangulo(triangulos, total);
                break;
            case 2:
                listarTriangulos(triangulos, total, NULL);
                break;
            case 3:
                listarTriangulos(triangulos, total, "equilatero");
                break;
            case 4:
                listarTriangulos(triangulos, total, "isosceles");
                break;
            case 5:
                listarTriangulos(triangulos, total, "escaleno");
                break;
            case 6:
                alterarTriangulo(triangulos, total);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
