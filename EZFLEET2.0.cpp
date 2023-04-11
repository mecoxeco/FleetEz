#include <stdio.h>
#include <stdlib.h>

struct Veiculo {
    char marca[20];
    char modelo[20];
    int ano;
    char placa[10];
    float quilometragem;
    float capacidade_carga;
    float consumo_combustivel;
};

struct Motorista {
    char nome[50];
    char cpf[20];
    char cnh[20];
    char telefone[20];
    char endereco[100];
};

struct Infracao {
    char descricao[100];
    float valor;
    int prazo;
};

struct Multa {
    char placa1[10];
    char cpf_motorista[20];
    struct Infracao infracao;
};


void registrarVeiculo(Veiculo *veiculo) {
    printf("Marca: ");
    scanf("%s", veiculo->marca);

    printf("Modelo: ");
    scanf("%s", veiculo->modelo);

    printf("Ano: ");
    scanf("%d", &veiculo->ano);

    printf("Placa: ");
    scanf("%s", veiculo->placa);

    printf("Quilometragem: ");
    scanf("%f", &veiculo->quilometragem);

    printf("Capacidade de carga: ");
    scanf("%f", &veiculo->capacidade_carga);

    printf("Consumo de combustivel: ");
    scanf("%f", &veiculo->consumo_combustivel);

    printf("Veiculo registrado.\n");
}

void registrarMotorista(Motorista *motorista) {
    printf("Nome: ");
    scanf("%s", motorista->nome);

    printf("CPF: ");
    scanf("%s", motorista->cpf);

    printf("CNH: ");
    scanf("%s", motorista->cnh);

    printf("Telefone: ");
    scanf("%s", motorista->telefone);

    printf("Endereco: ");
    scanf("%s", motorista->endereco);

    printf("Motorista registrado.\n");
}

void registrarInfracao(Infracao *infracao) {
    printf("Descricao da infracao: ");
    scanf("%s", infracao->descricao);

    printf("Valor da infracao: ");
    scanf("%f", &infracao->valor);

    printf("Prazo para pagamento (em dias): ");
    scanf("%d", &infracao->prazo);

    printf("Infracao registrada.\n");
}

void registrarMulta(Multa *multa) {
    printf("Placa do veiculo: ");
    scanf("%s", multa->placa1);

    printf("CPF do motorista: ");
    scanf("%s", multa->cpf_motorista);

    registrarInfracao(&multa->infracao);

    printf("Multa registrada.\n");
}

void consultarVeiculo(Veiculo veiculo) {
    printf("Marca: %s\n", veiculo.marca);
    printf("Modelo: %s\n", veiculo.modelo);
    printf("Ano: %d\n", veiculo.ano);
    printf("Placa: %s\n", veiculo.placa);
    printf("Quilometragem: %.2f\n", veiculo.quilometragem);
    printf("Capacidade de carga: %.2f\n", veiculo.capacidade_carga);
    printf("Consumo de combustivel: %.2f\n", veiculo.consumo_combustivel);
}

void consultarMotorista(Motorista motorista) {
    printf("Nome: %s\n", motorista.nome);
    printf("CPF: %s\n", motorista.cpf);
    printf("CNH: %s\n", motorista.cnh);
    printf("Telefone: %s\n", motorista.telefone);
    printf("Endereco: %s\n", motorista.endereco);
}

void consultarInfracao(Infracao infracao) {
    printf("Descricao: %s\n", infracao.descricao);
    printf("Valor: %.2f\n", infracao.valor);
    printf("Prazo para pagamento: %d dias\n", infracao.prazo);
}

void consultarMulta(Multa multa) {
    printf("Placa do veiculo: %s\n", multa.placa1);
    printf("CPF do motorista: %s\n", multa.cpf_motorista);
    printf("Infracao:\n");
     consultarInfracao(multa.infracao);
}

int main() {
    struct Veiculo veiculo = {0};
    struct Motorista motorista = {0};
    struct Infracao infracao = {0};
    struct Multa multa = {0};
    int opcao = 0;
    int opcao2 = 0;
    int opcao3 = 0;

    do {
        printf("\n== O que você gostaria de fazer? ==\n");
        printf("1 - Registrar informações\n");
        printf("2 - Consultar informações\n");
        printf("0 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                do {
                    printf("1 - Registrar informacoes de veiculo\n");
                    printf("2 - Registrar informacoes de motorista\n");
                    printf("3 - Registrar informacoes de multa\n");
                    printf("0 - Sair\n");
                    scanf("%d", &opcao2);
                
                    switch (opcao2) {
                        case 1: {
                            registrarVeiculo(&veiculo);
                            break;
                        }
                        case 2: {
                            registrarMotorista(&motorista);
                            break;
                        }
                        case 3: {
                            registrarMulta(&multa);
                            break;
                        }
                        case 0: {
                            break;
                        }
                        default: {
                            printf("Opcao invalida. Tente novamente.\n");
                            break;
                        }
                    }
                } while (opcao2 != 0);
                break;
            }
            case 2: {
                do {
                    printf("1 - Consultar informacoes de veiculo\n");
                    printf("2 - Consultar informacoes de motorista\n");
                    printf("3 - Consultar informacoes de multa\n"); 
                    printf("0 - Sair\n");
                    scanf("%d", &opcao3);

                    switch (opcao3) {          
                        case 1: {
                            consultarVeiculo(&veiculo);
                            break;
                        }
                        case 2: {
                            consultarMotorista(&motorista);
                            break;
                        }
                        case 3: {
                            consultarMulta(&multa);
                            break;
                        }
                        case 0: {
                            printf("saindo");
                            break;
                        }
                        default: {
                            printf("Opcao invalida.\n");
                            break;
                        }
                    }
                } while (opcao3 != 0); 
                break;             
            }
            case 0: {
                printf("Encerrando programa.\n");
                break;
            }
            default: {
                printf("Opcao invalida.\n");
                break;
            }
        }
    } while (opcao != 0);    

    return 0;
}
