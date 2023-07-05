#include <stdio.h>
#ifndef locadora_h
#define locadora_h

typedef struct data
{
    int dia, mes, ano;
} Data;

typedef struct cliente
{
    int cod;
    char nome[15];
    char telefone [30];
} Cliente;

typedef struct dvd
{
    int cod;
    char titulo[20];
    int ano_lancamento;
    int status;
    double valor;
} Dvd;

typedef struct locacao
{
    int cod;
    Cliente *cliente;
    Dvd *dvd;
    Data dataLocacao, dataDevolucao;
    int duracao;
    double totalLocacao;
} Locacao;

int cadastraCliente(Cliente *cliente, int codigo, char *nome, char *telefone);
int cadastraDvd(Dvd *dvd, int codigo, char *titulo, int ano_lancamento, double valor);
int cadastraLocacao(Locacao *locacao, int codigo, Cliente *cliente, Dvd *dvd, int duracao, double valor, Data *dataLocacao, Data *dataDevolucao);
int mostraCliente(Cliente cliente);
int mostraDvd(Dvd dvd);
int mostraLocacao(Locacao locacao);
int mostraLocacoes(Locacao *locacoes[], int tamanho);
int devolveDvd(Locacao *locacao, int duracao, Dvd *dvd, double valor);

#endif