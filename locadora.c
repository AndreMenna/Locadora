#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int cadastraCliente(Cliente *cliente, int codigo, char *nome, char *telefone)
{
    cliente->cod = codigo;
    strcpy(cliente->nome, nome);
    strcpy(cliente->telefone, telefone);
    printf("Cadastro cliente numero, %d efetuado com sucesso!\n", codigo);
    return 0;
};

int cadastraDvd(Dvd *dvd, int codigo, char *titulo, int ano_lancamento, double valor)
{
    dvd->cod = codigo;
    strcpy(dvd->titulo, titulo);
    dvd->ano_lancamento = ano_lancamento;
    dvd->valor = valor;
    dvd->status = 1; // dvd disponível
    printf("Cadastro do DVD numero, %d efetuado com sucesso!\n", codigo);
    return 0;
}

int cadastraLocacao(Locacao *locacao, int codigo, Cliente *cliente, Dvd *dvd, int duracao, double valor, Data *dataLocacao, Data *dataDevolucao)
{
    if (dvd->status)
    {
        locacao->cod = codigo;
        locacao->cliente = cliente;
        locacao->dvd = dvd;
        locacao->dataLocacao.dia = (*dataLocacao).dia;
        locacao->dataLocacao.mes = (*dataLocacao).mes;
        locacao->dataLocacao.ano = (*dataLocacao).ano;
        locacao->dataDevolucao.dia = (*dataDevolucao).dia;
        locacao->dataDevolucao.mes = (*dataDevolucao).mes;
        locacao->dataDevolucao.ano = (*dataDevolucao).ano;
        locacao->duracao = duracao;
        locacao->totalLocacao = valor * duracao;
        dvd->status = 0;
        printf("Locacao numero, %d efetuada com sucesso!\n", codigo);
        return 0;
    }
    else
    {
        printf("O DVD esta locado atualmente.");
        return 0;
    }
}

int mostraCliente(Cliente cliente)
{
    //printf("Dados do cliente.\n");
    printf("Cod: %d\n", cliente.cod);
    printf("Nome: %s\n", cliente.nome);
    printf("Telefone: %s\n", cliente.telefone);
    printf("==========================\n");
    return 0;
}

int mostraDvd(Dvd dvd)
{
    //printf("Dados do DVD.\n");
    printf("Cod: %d\n", dvd.cod);
    printf("Titulo: %s\n", dvd.titulo);
    printf("Ano: %d\n", dvd.ano_lancamento);
    printf("Custo da diaria: R$ %.2f\n", dvd.valor);
    printf("Status: %s\n", (dvd.status ? "Disponivel" : "Indisponivel"));
    printf("==========================\n");
    return 0;
}

int mostraLocacao(Locacao locacao)
{
    //printf("Dados da locacao\n");
    printf("Cod: %d\n", locacao.cod);
    printf("Cliente: %s\n", locacao.cliente->nome);
    printf("Titulo: %s\n", locacao.dvd->titulo);
    printf("Dia da Locacao: %d/%d/%d\n", locacao.dataLocacao.dia, locacao.dataLocacao.mes, locacao.dataLocacao.ano);
    printf("Dia da Devolucao: %d/%d/%d\n", locacao.dataDevolucao.dia, locacao.dataDevolucao.mes, locacao.dataDevolucao.ano);
    printf("Diarias: %d\n", locacao.duracao);
    printf("Valor total: R$%.2f\n", locacao.totalLocacao);
    printf("==========================\n");
    return 0;
}

int mostraLocacoes(Locacao *locacoes[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        {if (locacoes[i] != NULL)
         mostraLocacao(*locacoes[i]);}
    }
    return 0;
}

int devolveDvd(Locacao *locacao, int duracao, Dvd *dvd, double valor)
{
    dvd->valor = valor;
    locacao->duracao = duracao;
    locacao->totalLocacao = valor * duracao;
    locacao->dvd->status = 1;
    printf("Dvd %d - %s devolvido com sucesso.\n", locacao->dvd->cod, locacao->dvd->titulo);
    printf("Valor da Diaria: R$ %.2f - Quantidade de Diarias: %d\n", valor, locacao->duracao);
    printf("Total a pagar: R$ %.2f", locacao->totalLocacao);
    return 0;
}