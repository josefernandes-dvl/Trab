#include <stdio.h>
#include <string.h>
#include "prototipos.h"

// Funcao login_usuario com o ponteiro da instancia dados.
// atribuindo os enderecos das variaveis da main e os modificando
void cadastro(Cadastro *dados)
{
    limpar();
    bordas();
    ir_para(25, 2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    ir_para(25, 3);
    printf("%c   \033[1;35mSISTEMA DE CADASTRO E LOGIN\033[0m   %c", 179, 179);
    ir_para(25, 4);
    printf("%c             Cadastro            %c", 179, 179);
    ir_para(25, 5);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

    int nome_existe;
    char tentativa_nome[50];
    ir_para(25, 9);
    printf("Nome: ");
    fgets(tentativa_nome, 50, stdin);
    tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
    nome_existe = verificar_nome(dados, tentativa_nome);
    while (nome_existe == 1) // Enquanto o nome que eu digitar, for igual algum nome salvo. Vai repetir.
    {
        ir_para(25, 8);
        printf("\033[1;31mNome ja cadastrado! Tente outro:\033[0m");

        ir_para(25, 9);
        limpar_linha();
        ir_para(25, 9);
        printf("Nome: ");
        fgets(tentativa_nome, 50, stdin);
        tentativa_nome[strcspn(tentativa_nome, "\n")] = '\0';
        nome_existe = verificar_nome(dados, tentativa_nome);
    }

    strcpy(dados->nome, tentativa_nome); // Copia a tentiva valida para o nome

    ir_para(25, 10);
    printf("Senha: ");
    fgets(dados->senha, 50, stdin);
    dados->senha[strcspn(dados->senha, "\n")] = '\0';

    ir_para(25, 11);
    printf("Pergunta secreta: ");
    fgets(dados->pergunta, 100, stdin);
    dados->pergunta[strcspn(dados->pergunta, "\n")] = '\0';

    ir_para(25, 12);
    printf("Resposta da pergunta secreta: ");
    fgets(dados->resposta, 100, stdin);
    dados->resposta[strcspn(dados->resposta, "\n")] = '\0';

    if (dados->menu_principal == '1') // Só o usuario q vai ter isso a mais
    {
        do
        {
            ir_para(25, 13);
            limpar_linha();
            ir_para(25, 13);
            printf("CPF - 11 DIGITOS: ");
            fgets(dados->cpf, 12, stdin);
            dados->cpf[strcspn(dados->cpf, "\n")] = '\0';
        } while (cpf_valido(dados->cpf) == 0);

        int tentativa_email = 0, eh_email; // ainda não tentou

        do
        {
            eh_email = 1; // inicia com email inválido

            ir_para(25, 15);
            limpar_linha();
            ir_para(25, 14);
            limpar_linha();
            ir_para(25, 14);
            printf("Email: ");
            fgets(dados->email, 50, stdin);
            dados->email[strcspn(dados->email, "\n")] = '\0';

            int tamanho = strlen(dados->email);

            for (int i = 0; i < tamanho; i++)
            {
                if (dados->email[i] == '@')
                {
                    eh_email = 0;
                    break;
                }
            }

            if ((eh_email == 1 || tamanho < 6) && tentativa_email > 0)
            {
                ir_para(25, 16);
                printf("\033[1;31mEmail Invalido!\033[0m");
            }

            tentativa_email++;

        } while (eh_email == 1 || strlen(dados->email) < 6);
    }
}
