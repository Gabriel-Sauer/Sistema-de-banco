#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Dados de login
const char login_correto[] = "pipoca";
const char senha_correta[] = "1609";

// Saldo inicial
float saldo = 0;

// Função para realizar o login
bool fazer_login() {
    char login_digitado[50];
    char senha_digitada[50];

    printf("Digite o login: ");
    scanf("%s", login_digitado);
    printf("Digite a senha: ");
    scanf("%s", senha_digitada);

    if (strcmp(login_digitado, login_correto) == 0 && strcmp(senha_digitada, senha_correta) == 0) {
        printf("Logado na conta %s\n", login_correto);
        return true;
    } else {
        printf("Login ou senha incorretos. Encerrando o sistema.\n");
        return false;
    }
}

// Função para realizar depósito
void fazer_deposito() {
    float valor_deposito;
    printf("Digite o valor do depósito: ");
    scanf("%f", &valor_deposito);

    saldo += valor_deposito;
    printf("Depósito de $%.2f realizado com sucesso. Novo saldo: $%.2f\n", valor_deposito, saldo);
}

// Função para realizar saque
void fazer_saque() {
    float valor_saque;
    printf("Digite o valor do saque: ");
    scanf("%f", &valor_saque);

    if (valor_saque > saldo) {
        printf("Saldo insuficiente. Saque não realizado.\n");
    } else {
        saldo -= valor_saque;
        printf("Saque de $%.2f realizado com sucesso. Novo saldo: $%.2f\n", valor_saque, saldo);
    }
}

// Função para exibir o saldo
void exibir_saldo() {
    printf("Saldo atual: $%.2f\n", saldo);
}

// Função para a calculadora de investimento
void calculadora_investimento() {
    float investimento_total, rentabilidade_mensal;

    printf("Digite o valor do investimento: ");
    scanf("%f", &investimento_total);
    printf("Digite a rentabilidade mensal em %%: ");
    scanf("%f", &rentabilidade_mensal);

    float retorno_mensal = (investimento_total * rentabilidade_mensal) / 100;
    float retorno_anual = retorno_mensal * 12;
    float total_investido = investimento_total + retorno_anual;

    printf("Retorno mensal $: %.2f\n", retorno_mensal);
    printf("Retorno anual $: %.2f\n", retorno_anual);
    printf("Total investido: %.2f / Rentabilidade: %.2f / Total: %.2f\n", investimento_total, retorno_anual, total_investido);
}

// Função principal
int main() {
    while (1) {
        if (fazer_login()) {
            while (1) {
                // Menu de opções
                printf("\nMenu:\n");
                printf("1 - Depósito\n");
                printf("2 - Saque\n");
                printf("3 - Saldo\n");
                printf("4 - Calculadora de investimento\n");
                printf("5 - Sair\n");

                int opcao;
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        fazer_deposito();
                        break;
                    case 2:
                        fazer_saque();
                        break;
                    case 3:
                        exibir_saldo();
                        break;
                    case 4:
                        calculadora_investimento();
                        break;
                    case 5:
                        printf("Saindo do programa. Até mais!\n");
                        return 0;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                        break;
                }
            }
        } else {
            return 0;
        }
    }

    return 0;
}
