#include <stdio.h>

int main() {
    int corrente;
    float salario, poupanca;
    FILE *arquivo;

    // 1. ENTRADA DE DADOS PELO USUARIO
    printf("Digite o numero da conta corrente:\n");
    scanf("%d", &corrente);

    printf("Digite o salario:\n");
    scanf("%f", &salario);

    printf("Digite quanto voce tem na poupanca:\n");
    scanf("%f", &poupanca);

    // ==========================================
    // ETAPA A: ABRIR, ESCREVER E FECHAR
    // ==========================================
    
    // ABRIR para gravacao ("w" cria ou substitui o arquivo)
    arquivo = fopen("dados_conta.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravar!\n");
        return 1;
    }

    // ESCREVER os dados no arquivo
    fprintf(arquivo, "%d\n%.2f\n%.2f\n", corrente, salario, poupanca);

    // FECHAR para salvar os dados no disco
    fclose(arquivo);


    // ==========================================
    // ETAPA B: ABRIR, LER, FECHAR E USAR
    // ==========================================
    int conta_lida;
    float salario_lido, poupanca_lida;

    // ABRIR para leitura ("r" apenas le um arquivo existente)
    arquivo = fopen("dados_conta.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para ler!\n");
        return 1;
    }

    // LER os dados do arquivo para dentro das variaveis
    fscanf(arquivo, "%d", &conta_lida);
    fscanf(arquivo, "%f", &salario_lido);
    fscanf(arquivo, "%f", &poupanca_lida);

    // FECHAR o arquivo apos terminar a leitura
    fclose(arquivo);

    // USAR os dados lidos no programa (exibir, somar e testar condicao)
    printf("\n--- DADOS LIDOS E USADOS DO ARQUIVO ---\n");
    printf("Conta Corrente: %d\n", conta_lida);
    printf("Salario: R$ %.2f\n", salario_lido);
    printf("Poupanca: R$ %.2f\n", poupanca_lida);

    float total = salario_lido + poupanca_lida;
    printf("Total acumulado: R$ %.2f\n", total);

    if (salario_lido > 1000 && poupanca_lida > 1000) {
        printf("Status: Voce tem mais de 1000 no salario e na poupanca!\n");
    } else {
        printf("Status: Pelo menos um dos valores nao passa de 1000.\n");
    }

    return 0;
}