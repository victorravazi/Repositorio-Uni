#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"

#define ARQUIVO_BINARIO "lotes.bin"

typedef struct {
    int dia, mes, ano;
    float litros;
} Lote;

void somatorioMensalCSV() {
    float totalPorMes[12] = {0};  // Índices 0 a 11 correspondem a meses 1 a 12

    FILE *bin = fopen(ARQUIVO_BINARIO, "rb");
    if (!bin) {
        perror("Erro ao abrir arquivo binario");
        return;
    }

    Lote lote;
    while (fread(&lote, sizeof(Lote), 1, bin) == 1) {
        if (lote.mes >= 1 && lote.mes <= 12)
            totalPorMes[lote.mes - 1] += lote.litros; // lote.mes - 1 para ajustar os indice do array
    }                                                 // os meses sao de 1 a 12 porém o array é de 0 a 11
    fclose(bin);                                      // 0 seria janeiro por exemplo

    FILE *csv = fopen("somatorio_mensal.csv", "w");
    if (!csv) {
        perror("Erro ao criar arquivo CSV");
        return;
    }

    fprintf(csv, "Mes,Litros\n");
    for (int i = 0; i < 12; i++) {
        fprintf(csv, "%02d,%.2f\n", i + 1, totalPorMes[i]);
    }
    fclose(csv);

    printf("Arquivo 'somatorio_mensal.csv' gerado com sucesso.\n");
}

void listarCSV() {
    FILE *csv = fopen("somatorio_mensal.csv", "r");
    if (!csv) {
        perror("Erro ao abrir arquivo CSV");
        return;
    }

    char linha[100];
    printf("\n--- SOMATORIO MENSAL ---\n");
    while (fgets(linha, sizeof(linha), csv)) { // condição do while verifica o valor de retorno de fgets(). Se fgets() ler com sucesso uma linha
        printf("%s", linha);                   // ele retorna o próprio ponteiro linha (que é diferente de NULL), e a condição é verdadeira. 
    }
    fclose(csv);
}

void inserirLote() {
    char nomeArquivo[100]; // Cria variavel para guardar o nome do arquivo 
    // Aqui o usuario digita o nome do arquivo a ser lido
    input_s("Digite nome do arquivo com .txt no final ",nomeArquivo,sizeof(nomeArquivo));

    FILE *txt = fopen(nomeArquivo, "r"); // Cria uma variavel do tipo arquivo chamada txt e abre o arquivo da variavel nomeArquivo no modo read
    if (!txt) { // verifica se o arquivo existe/abriu corretamente 
        perror("Erro ao abrir o arquivo .txt"); // caso contrario mostre uma mensagem de erro com a função perror
        return; 
    }

    FILE *bin = fopen(ARQUIVO_BINARIO, "ab"); // Cria uma variavel do tipo arquivo chamada bin e abre o "ARQUIVO_BINARIO" que é o lotes.bin, no modo append, este modo adiciona as informações ao final do arquivo
    if (!bin) { // verifica se o arquivo existe/abriu corretamente
        perror("Erro ao abrir o arquivo binario");
        fclose(txt);
        return;
    }

    Lote lote; // Cria um struct Lote
    while (fscanf(txt, "%d/%d/%d %f", &lote.dia, &lote.mes, &lote.ano, &lote.litros) == 4) { // retorna o numero de itens que foram lidos e atribuidos com sucesso
        fwrite(&lote, sizeof(Lote), 1, bin);                                                 // se a leitura funcionou, ele deve ter lido 4 itens e a condição == 4                                                                                     
    }                                                                                        // faz com que o loop so continue se o fscanf consiga ler os 4 itens esperados
    // sizeof(Lote): Este é o tamanho, em bytes, de uma única estrutura Lote. 
    // Isso garante que fwrite() saiba quantos bytes precisa copiar para cada "registro" no arquivo binário.
    // &lote é o endereço de memoria da estrutura Lote, o numero 1 indica que é uma estrutura escrita por vez
    // bin é o nome do arquivo aberto
    printf("Lotes inseridos com sucesso\n");

    fclose(txt); // fecha os dois arquivos
    fclose(bin);
}

void eliminarLote() {
    int mesExclusao; // Cria uma variavel mesExclusao
    printf("Digite o numero do mes que deseja excluir: "); //  pede para o usuario digitar e guarda na variavel
    scanf("%d", &mesExclusao);

    FILE *bin = fopen(ARQUIVO_BINARIO, "rb");  // abre o arquivo dados.bin no modo read 
    if (!bin) {
        perror("Erro ao abrir o arquivo binario para leitura");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb"); // abre/cria um arquivo chamado temp.bin no modo write 
    if (!temp) {
        perror("Erro ao criar arquivo temporario");
        fclose(bin);
        return;
    }

    Lote lote; // Cria uma struct lote
    int encontrados = 0; // Cria uma variavel encontrados

    while (fread(&lote, sizeof(Lote), 1, bin) == 1) { // fread() tenta ler 1 item do tamanho de sizeof(Lote) bytes na memória 
        if (lote.mes != mesExclusao) {                // no endereço de &lote, a partir do arquivo bin. 
            fwrite(&lote, sizeof(Lote), 1, temp);     // a condição == 1 garante que ele so vai continuar o loop se ele conseguir ler um lote completo
        } else {
            encontrados++;
        }
    }

    fclose(bin);
    fclose(temp);

    remove(ARQUIVO_BINARIO);
    rename("temp.bin", ARQUIVO_BINARIO);

    if (encontrados)
        printf("Lotes do mes %02d excluidos com sucesso\n", mesExclusao);
    else
        printf("Nenhum lote encontrado para o mes %02d\n", mesExclusao);
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir lote\n");
        printf("2 - Eliminar lote\n");
        printf("3 - Somatorio mensal (CSV) [Refresh] \n");
        printf("4 - Listagem (CSV) \n");
        printf("5 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

                switch (opcao) {
            case 1:
                inserirLote();
                break;
            case 2:
                eliminarLote();
                break;
            case 3:
                somatorioMensalCSV();
                break;
            case 4:
                listarCSV();
                break;
            case 5:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 5);

    return 0;
}
