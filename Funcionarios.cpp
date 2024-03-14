#include <stdio.h>
#include <string.h>

#define MAX_FUNCIONARIOS 10

typedef struct {
char nome[50];
char cargo[50];
float salarioBase;
float beneficios;
float descontos;
} Funcionario;

void cadastrarFuncionario(Funcionario *func);
void exibirFuncionarios(Funcionario func[], int totalFuncionarios);
float calcularSalarioLiquido(Funcionario func);
void exibirMediaSalarial(Funcionario func[], int totalFuncionarios);
void exibirMaiorSalario(Funcionario func[], int totalFuncionarios);

int main() {
Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;
int opcao;

do {
printf("\nMenu:\n");
printf("1. Cadastrar funcionário\n");
printf("2. Listar funcionários\n");
printf("3. Exibir média salarial\n");
printf("4. Exibir maior salário\n");
printf("5. Sair\n");
printf("Escolha uma opção: ");
scanf("%d", &opcao);
getchar(); // Consume the newline character

switch (opcao) {
case 1:
if (totalFuncionarios < MAX_FUNCIONARIOS) {
cadastrarFuncionario(&funcionarios[totalFuncionarios]);
totalFuncionarios++;
} else {
printf("Limite de funcionários atingido.\n");
}
break;
case 2:
exibirFuncionarios(funcionarios, totalFuncionarios);
break;
case 3:
exibirMediaSalarial(funcionarios, totalFuncionarios);
break;
case 4:
exibirMaiorSalario(funcionarios, totalFuncionarios);
break;
case 5:
printf("Saindo...\n");
break;
default:
printf("Opção inválida.\n");
}
} while (opcao != 5);

return 0;
}

void cadastrarFuncionario(Funcionario *func) {
printf("Digite o nome do funcionário: ");
scanf("%[^\n]%*c", func->nome);
printf("Digite o cargo do funcionário: ");
scanf("%[^\n]%*c", func->cargo);
printf("Digite o salário base do funcionário: ");
scanf("%f%*c", &func->salarioBase);
printf("Digite os benefícios do funcionário: ");
scanf("%f%*c", &func->beneficios);
printf("Digite os descontos do funcionário: ");
scanf("%f%*c", &func->descontos);
}

void exibirFuncionarios(Funcionario func[], int totalFuncionarios) {
for(int i = 0; i < totalFuncionarios; i++) {
printf("\nNome: %s\nCargo: %s\nSalario Base: %.2f\nBeneficios: %.2f\nDescontos: %.2f\nSalario Liquido: %.2f\n",
func[i].nome, func[i].cargo, func[i].salarioBase, func[i].beneficios, func[i].descontos, calcularSalarioLiquido(func[i]));
}
}

float calcularSalarioLiquido(Funcionario func) {
return func.salarioBase + func.beneficios - func.descontos;
}

void exibirMediaSalarial(Funcionario func[], int totalFuncionarios) {
float somaSalarios = 0;
for(int i = 0; i < totalFuncionarios; i++) {
somaSalarios += calcularSalarioLiquido(func[i]);
}
printf("\nMedia Salarial da Loja: %.2f\n", somaSalarios / totalFuncionarios);
}

void exibirMaiorSalario(Funcionario func[], int totalFuncionarios) {
float maiorSalario = 0;
char nomeMaiorSalario[50];
for(int i = 0; i < totalFuncionarios; i++) {
float salarioLiquido = calcularSalarioLiquido(func[i]);
if(salarioLiquido > maiorSalario) {
maiorSalario = salarioLiquido;
strcpy(nomeMaiorSalario, func[i].nome);
}
printf("\nMaior Salario: %.2f, Funcionario: %s\n", maiorSalario, nomeMaiorSalario);
}
}
// As funções exibirFuncionarios, calcularSalarioLiquido, exibirMediaSalarial e exibirMaiorSalario permanecem as mesmas.