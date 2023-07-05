#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main()
{
    Cliente *clientes[10] = {NULL};
    Dvd *catalogo[10] = {NULL};
    Locacao *locacoes[10] = {NULL};

    printf("\n================================================================================\n");
    printf("Cadastrando quatro clientes.");
    printf("\n================================================================================\n");
    clientes[0] = (Cliente *)malloc(sizeof(Cliente));
    clientes[1] = (Cliente *)malloc(sizeof(Cliente));
    clientes[2] = (Cliente *)malloc(sizeof(Cliente));
    clientes[3] = (Cliente *)malloc(sizeof(Cliente));
    cadastraCliente(clientes[0], 1, "Rafaela Menna", "991446033");
    cadastraCliente(clientes[1], 2, "Zaqueu Pereira", "991661385");
    cadastraCliente(clientes[2], 3, "Gilda Maria", "991394938");
    cadastraCliente(clientes[3], 4, "Michelle Menna", "999661425");

    printf("\n================================================================================\n");
    printf("Cadastrando DVD'S.");
    printf("\n================================================================================\n");
    catalogo[0] = (Dvd *)malloc(sizeof(Dvd));
    catalogo[1] = (Dvd *)malloc(sizeof(Dvd));
    catalogo[2] = (Dvd *)malloc(sizeof(Dvd));
    catalogo[3] = (Dvd *)malloc(sizeof(Dvd));
    catalogo[4] = (Dvd *)malloc(sizeof(Dvd));
    catalogo[5] = (Dvd *)malloc(sizeof(Dvd));
    cadastraDvd(catalogo[0], 1, "Perfume", 2006, 6);
    cadastraDvd(catalogo[1], 2, "Curtindo a vida", 1986, 3);
    cadastraDvd(catalogo[2], 3, "Perfume de mulher", 1992, 4);
    cadastraDvd(catalogo[3], 4, "Vida de inseto", 1998, 4);
    cadastraDvd(catalogo[4], 5, "Forrest Gump", 1994, 4);
    cadastraDvd(catalogo[5], 6, "Cubo", 1997, 4);

    printf("\n================================================================================\n");
    printf("Datas de locacao.");
    printf("\n================================================================================\n");
    Data loc; loc.dia = 16; loc.mes = 11; loc.ano = 2021;
    Data dev; dev.dia = 20; dev.mes = 11; dev.ano = 2021;

    printf("\n================================================================================\n");
    printf("Cadastrando locacoes.");
    printf("\n================================================================================\n");
    locacoes[0] = (Locacao *)malloc(sizeof(Locacao));
    locacoes[1] = (Locacao *)malloc(sizeof(Locacao));
    locacoes[2] = (Locacao *)malloc(sizeof(Locacao));
    locacoes[3] = (Locacao *)malloc(sizeof(Locacao));
    locacoes[4] = (Locacao *)malloc(sizeof(Locacao));
    locacoes[5] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[0], 1, clientes[0], catalogo[0], 4, 6.0, &loc, &dev);
    cadastraLocacao(locacoes[1], 2, clientes[1], catalogo[2], 4, 4.0, &loc, &dev);
    cadastraLocacao(locacoes[2], 3, clientes[2], catalogo[3], 4, 4.0, &loc, &dev);
    cadastraLocacao(locacoes[3], 4, clientes[3], catalogo[4], 4, 4.0, &loc, &dev);
    cadastraLocacao(locacoes[4], 5, clientes[1], catalogo[1], 4, 6.0, &loc, &dev);
    cadastraLocacao(locacoes[5], 6, clientes[2], catalogo[5], 4, 4.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("Mostra dados de um cliente.");
    printf("\n================================================================================\n");
    mostraCliente(*clientes[0]);

    printf("\n================================================================================\n");
    printf("Mostra dados de DVD's.");
    printf("\n================================================================================\n");
    mostraDvd(*catalogo[0]);
    mostraDvd(*catalogo[1]);

    printf("\n================================================================================\n");
    printf("Mostra dados de duas locacoes.");
    printf("\n================================================================================\n");
    mostraLocacao(*locacoes[0]);
    mostraLocacao(*locacoes[1]);
   
    printf("\n================================================================================\n");
    printf("Mostra todas as locacaes.");
    printf("\n================================================================================\n");
    mostraLocacoes(locacoes, 10);

    printf("\n================================================================================\n");
    printf("Simulando locacao de DVD indisponivel.");
    printf("\n================================================================================\n");
    printf("Dados do DVD:");
    printf("\n================================================================================\n");
    mostraDvd(*catalogo[0]);
    printf("Simulando a locacao 1.");
    printf("\n================================================================================\n");
    locacoes[5] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[6], 1, clientes[1], catalogo[0], 2, 6.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("DVD sendo entregue.");
    printf("\n================================================================================\n");
    devolveDvd(locacoes[0], 5, catalogo[0], 6.0);
    printf("\n================================================================================\n");
    printf("Situacao do dvd depois da entrega:");
    printf("\n================================================================================\n");
    mostraDvd(*catalogo[0]);

    // Efetuando locações e devoluções de 2 DVD'S.

    printf("\n================================================================================\n");
    printf("Locando DVD Perfume cliente 1.");
    printf("\n================================================================================\n");
    locacoes[0] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[0], 1, clientes[1], catalogo[0], 4, 6.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("Cliente 1 entregando DVD Perfume.");
    printf("\n================================================================================\n");
    devolveDvd(locacoes[0], 4, catalogo[0], 6.0);

    printf("\n================================================================================\n");
    printf("Locando DVD Perfume cliente 2.");
    printf("\n================================================================================\n");
    locacoes[0] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[0], 2, clientes[2], catalogo[0], 4, 6.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("Cliente 2 entregando DVD Perfume.");
    printf("\n================================================================================\n");
    devolveDvd(locacoes[0], 4, catalogo[0], 6.0);

    //=============================================================================================

    printf("\n================================================================================\n");
    printf("Locando DVD Forrest Gump cliente 3.");
    printf("\n================================================================================\n");
    locacoes[0] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[0], 3, clientes[3], catalogo[0], 4, 6.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("Cliente 3 entregando DVD Forrest Gump.");
    printf("\n================================================================================\n");
    devolveDvd(locacoes[0], 4, catalogo[0], 6.0);

    printf("\n================================================================================\n");
    printf("Locando DVD Forrest Gump cliente 4.");
    printf("\n================================================================================\n");
    locacoes[0] = (Locacao *)malloc(sizeof(Locacao));
    cadastraLocacao(locacoes[0], 4, clientes[4], catalogo[0], 4, 6.0, &loc, &dev);

    printf("\n================================================================================\n");
    printf("Cliente 4 entregando DVD Forrest Gump.");
    printf("\n================================================================================\n");
    devolveDvd(locacoes[0], 4, catalogo[0], 6.0);
    printf("\n================================================================================\n");

    // esvaziando memória
    for (int i = 0; i < 10; i++)
    {
        free(catalogo[i]);
        free(clientes[i]);
        free(locacoes[i]);
    }

    return 0;
}