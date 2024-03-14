#include <stdio.h>
#include <time.h>

typedef struct {
int dia, mes, ano;
} Data;

typedef struct {
char nome[100];
Data dataNascimento;
int idade;
char sexo; // 'M' ou 'F'
} Cliente;

int calcularIdade(Data nascimento);
void cadastrarCliente(Cliente clientes[], int *totalClientes);
void listarClientes(Cliente clientes[], int totalClientes);

int main() {
Cliente clientes[50];
int totalClientes = 0;
int opcao;

do {
printf("1. Cadastrar cliente\n");
printf("2. Listar clientes\n");
printf("3. Sair\n");
printf("Escolha uma opção: ");
scanf("%d", &opcao);

switch (opcao) {
case 1:
if (totalClientes < 50) {
cadastrarCliente(clientes, &totalClientes);
} else {
printf("Limite de clientes atingido.\n");
}
break;
case 2:
listarClientes(clientes, totalClientes);
break;
case 3:
printf("Saindo...\n");
break;
default:
printf("Opção inválida.\n");
}
} while (opcao != 3);

return 0;
}

int calcularIdade(Data nascimento) {
time_t agora = time(NULL);
struct tm *agora_tm = localtime(&agora);
Data atual = {agora_tm->tm_mday, agora_tm->tm_mon + 1, agora_tm->tm_year + 1900};

int idade = atual.ano - nascimento.ano;
if (atual.mes < nascimento.mes || (atual.mes == nascimento.mes && atual.dia < nascimento.dia)) {
idade--;
}
return idade;
}

void cadastrarCliente(Cliente clientes[], int *totalClientes) {
printf("Digite o nome do cliente: ");
scanf("%s", clientes[*totalClientes].nome);
printf("Digite a data de nascimento (dd mm aaaa): ");
scanf("%d %d %d", &clientes[*totalClientes].dataNascimento.dia, &clientes[*totalClientes].dataNascimento.mes, &clientes[*totalClientes].dataNascimento.ano);
clientes[*totalClientes].idade = calcularIdade(clientes[*totalClientes].dataNascimento);
printf("Digite o sexo do cliente (M/F): ");
scanf(" %c", &clientes[*totalClientes].sexo);
(*totalClientes)++;
}

void listarClientes(Cliente clientes[], int totalClientes) {
for (int i = 0; i < totalClientes; i++) {
printf("Nome: %s\n", clientes[i].nome);
printf("Data de Nascimento: %02d/%02d/%04d\n", clientes[i].dataNascimento.dia, clientes[i].dataNascimento.mes, clientes[i].dataNascimento.ano);
printf("Idade: %d\n", clientes[i].idade);
printf("Sexo: %c\n\n", clientes[i].sexo);
}
}