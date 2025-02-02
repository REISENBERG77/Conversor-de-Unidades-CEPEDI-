#include <stdio.h>
#include <stdlib.h>

// Funcao para limpar a tela em ambos sistemas operacionais
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Funcao para pausar a tela em ambos sistemas operacionais
void pausarTela() {
    #ifdef _WIN32
        system("pause");
    #else
        printf("Pressione qualquer tecla para continuar...");
        getchar();
    #endif
}

// Funcao para realizar os calculos e gerenciar a interface do conversor de volume
void calcularVolume() {
    int entradaUnidade, saidaUnidade;
    float valor, resultado;
    char *siglaSaida;

    while (1) {
        limparTela();
        printf("Conversor de Volume\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metros Cubicos\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &entradaUnidade) != 1 || entradaUnidade < 1 || entradaUnidade > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        // Voltar ao menu principal
        if (entradaUnidade == 4) {
            return;
        }

        limparTela();
        printf("Conversor de Volume\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metros Cubicos\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &saidaUnidade) != 1 || saidaUnidade < 1 || saidaUnidade > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        // Voltar ao menu principal
        if (saidaUnidade == 4) {
            return;
        }

        printf("Digite o valor a ser convertido (ex: 50.00 ou 50) : ");
        
        if (scanf("%f", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        // Define a sigla da unidade de saída
        if (saidaUnidade == 1) {
            siglaSaida = "L";
        } else if (saidaUnidade == 2) {
            siglaSaida = "ml";
        } else if (saidaUnidade == 3) {
            siglaSaida = "m3";
        }

        // Realiza o calculo com base nas unidades
        switch (entradaUnidade) {
            case 1:
                switch (saidaUnidade) {
                    case 1:
                        resultado = valor; // Litros -> Litros
                        break;
                    case 2:
                        resultado = valor * 1000; // Litros -> Mililitros
                        break;
                    case 3:
                        resultado = valor / 1000; // Litros -> Metros Cubicos
                        break;
                }
                break;
            case 2:
                switch (saidaUnidade) {
                    case 1:
                        resultado = valor / 1000; // Mililitros -> Litros
                        break;
                    case 2:
                        resultado = valor; // Mililitros -> Mililitros
                        break;
                    case 3:
                        resultado = valor / 1000000; // Mililitros -> Metros Cubicos
                        break;
                }
                break;
            case 3:
                switch (saidaUnidade) {
                    case 1:
                        resultado = valor * 1000; // Metros Cubicos -> Litros
                        break;
                    case 2:
                        resultado = valor * 1000000; // Metros Cubicos -> Mililitros
                        break;
                    case 3:
                        resultado = valor; // Metros Cubicos -> Metros Cubicos
                        break;
                }
                break;
        }

        limparTela();
        printf("Resultado da conversao: %.6f %s\n", resultado, siglaSaida);
        pausarTela();
    }
}

/*
    Procedimento que faz o calculo e gerencia a interface do conversor de potencia.
    O procedimento pode fazer a conversão em Watt, KiloWatt, Cavalo-vapor e HorsePower.
*/
void calcularPotencia() {
    double valor, conversoes[] = {735.49875,1.0138696654,1.3410220896};
    char *siglas [4];
    siglas[0] = "W";
    siglas[1] = "CV";
    siglas[2] = "HP";
    siglas[3] = "kW";
    int in, out;
    int diff, j;

    
    while(1){
        limparTela();
        printf("Conversor de Potencia\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Watt\n");
        printf("2 - Cavalo-vapor\n");
        printf("3 - Horsepower\n");
        printf("4 - KiloWatt\n");
        printf("5 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &in) != 1 || in < 1 || in > 5) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (in == 5) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de Potencia\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Watt\n");
        printf("2 - Cavalo-vapor\n");
        printf("3 - Horsepower\n");
        printf("4 - KiloWatt\n");
        printf("5 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &out) != 1 || out < 1 || out > 5) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        // Voltar ao menu principal
        if (out == 5) {
            return;
        }

        printf("Digite o valor a ser convertido (ex: 50.00 ou 50) : ");
        
        if (scanf("%lf", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        diff = in - out;

        // decide em qual posição do vetor de conversão vai começar a iteração
        if(diff < 0) {
            j = in - 1;
        }
        else {
            j = in - 2;
        }

        for (int i = 0; i < abs(diff); i++){
            if(diff > 0) {
                valor = valor * conversoes[j];
                j--;
            }
            else if (diff < 0){
                valor = valor / conversoes[j];
                j++;
            }
        }
        limparBuffer();
        limparTela();
        printf("Resultado da conversao: %.4lf %s\n", valor, siglas[out - 1]);
        pausarTela();
    }
}

// Funcao para realizar os calculos e gerenciar a interface do conversor de temperatura
void calcularTemperatura() {
    double valor, resultado;
    char *siglas[] = {"C", "F", "K"};
    int in, out;

    while (1) {
        limparTela();
        printf("Conversor de Temperatura\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Celsius (C)\n");
        printf("2 - Fahrenheit (F)\n");
        printf("3 - Kelvin (K)\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &in) != 1 || in < 1 || in > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (in == 4) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de Temperatura\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Celsius (C)\n");
        printf("2 - Fahrenheit (F)\n");
        printf("3 - Kelvin (K)\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &out) != 1 || out < 1 || out > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (out == 4) {
            return; // Voltar ao menu principal
        }

        printf("Digite o valor a ser convertido (ex: 50.00 ou 50): ");

        if (scanf("%lf", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        if (in == 1) { // Celsius
            if (out == 2) {
                resultado = (valor * 9.0 / 5.0) + 32.0; // Celsius para Fahrenheit
            } else if (out == 3) {
                resultado = valor + 273.15; // Celsius para Kelvin
            } else {
                resultado = valor; // Celsius para Celsius
            }
        } else if (in == 2) { // Fahrenheit
            if (out == 1) {
                resultado = (valor - 32.0) * 5.0 / 9.0; // Fahrenheit para Celsius
            } else if (out == 3) {
                resultado = (valor - 32.0) * 5.0 / 9.0 + 273.15; // Fahrenheit para Kelvin
            } else {
                resultado = valor; // Fahrenheit para Fahrenheit
            }
        } else if (in == 3) { // Kelvin
            if (out == 1) {
                resultado = valor - 273.15; // Kelvin para Celsius
            } else if (out == 2) {
                resultado = (valor - 273.15) * 9.0 / 5.0 + 32.0; // Kelvin para Fahrenheit
            } else {
                resultado = valor; // Kelvin para Kelvin
            }
        }

        limparBuffer();
        limparTela();
        printf("Resultado da conversao: %.2lf %s\n", resultado, siglas[out - 1]);
        pausarTela();
    }
}
// Funcao para realizar os calculos e gerenciar a interface do conversor de unidades de area
void calcularArea() {
    int entradaarea, saidaarea;
    float valor, resultado;
    char *siglaSaida;

    while (1) {
        limparTela();
        printf("Conversor de unidade de area\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - metros quadrados\n");
        printf("2 - centimetros quadrados\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &entradaarea) != 1 || entradaarea < 1 || entradaarea > 3) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (entradaarea == 3) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de unidade de area\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - metros quadrados\n");
        printf("2 - centimetros quadrados\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &saidaarea) != 1 || saidaarea < 1 || saidaarea > 3) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (saidaarea == 3) {
            return;
        }


        printf("Digite o valor a ser convertido (ex: 50.00 ou 50) : ");
        
        if (scanf("%f", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        // Define a sigla da unidade de saída
        if (saidaarea == 1) {
            siglaSaida = "m2";
        } else if (saidaarea == 2) {
            siglaSaida = "cm2";
        }

        // Realiza o calculo com base nas unidades
        if (entradaarea == 1) { // metros quadrados
            if (saidaarea == 2) {
                resultado = valor * 10000; // metros quadrados -> centimetros quadrados
            } else if (saidaarea == 1) { // metros quadrados -> metros quadrados (sem conversão)
                resultado = valor;
            }
        } else if (entradaarea == 2) { // centimetros quadrados
            if (saidaarea == 1) {
                resultado = valor / 10000; // centimetros quadrados -> metros quadrados
            } else if (saidaarea == 2) { // centimetros quadrados -> centimetros quadrados (sem conversão)
                resultado = valor;
            }
        }

        limparTela();
        printf("Resultado da conversao: %.4f %s\n", resultado, siglaSaida);
        pausarTela();
    }
}

// Função que calcula e gerencia a interface do conversor de armazenamento de dados
void calcularArmazenamento()
{
    double valor;
    char *siglas[6];
    siglas[0] = "b";
    siglas[1] = "B";
    siglas[2] = "KB";
    siglas[3] = "MB";
    siglas[4] = "GB";
    siglas[5] = "TB";
    int in, out, diff;

    while (1)
    {
        limparTela();
        printf("Conversor de Armazenamento de Dados\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Bit\n");
        printf("2 - Byte\n");
        printf("3 - Kilobyte\n");
        printf("4 - Megabyte\n");
        printf("5 - Gigabyte\n");
        printf("6 - Terabyte\n");
        printf("7 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &in) != 1 || in < 1 || in > 7)
        {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (in == 7)
        {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de Armazenamento de Dados\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Bit\n");
        printf("2 - Byte\n");
        printf("3 - Kilobyte\n");
        printf("4 - Megabyte\n");
        printf("5 - Gigabyte\n");
        printf("6 - Terabyte\n");
        printf("7 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &out) != 1 || out < 1 || out > 7)
        {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        // Voltar ao menu principal
        if (out == 7)
        {
            return;
        }

        printf("Digite o valor a ser convertido (ex: 50.00 ou 50) : ");

        if (scanf("%lf", &valor) != 1)
        {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        diff = in - out;

        for (int i = 0; i < abs(diff); i++)
        {
            if (diff > 0)
            {
                if (out == 1 && i == abs(diff) - 1)
                {
                    valor = valor * 8;
                }
                else
                {
                    valor = valor * 1024;
                }
            }
            else if (diff < 0)
            {
                if (in == 1 && i == 0)
                {
                    valor = valor / 8;
                }
                else
                {
                    valor = valor / 1024;
                }
            }
        }

        limparBuffer();
        limparTela();
        printf("Resultado da conversao: %.4lf %s\n", valor, siglas[out - 1]);
        pausarTela();
    }
}

void converterTempo() {
    double valor, resultado;
    char *siglas[] = {"s", "min", "h"};
    int in, out;

    while (1) {
        limparTela();
        printf("Conversor de Unidade de Tempo\n\n");
        printf("Escolha a unidade de entrada:\n");
        printf("1 - Segundos (s)\n");
        printf("2 - Minutos (min)\n");
        printf("3 - Horas (h)\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &in) != 1 || in < 1 || in > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (in == 4) {
            return; // Voltar ao menu principal
        }

        limparTela();
        printf("Conversor de Unidade de Tempo\n\n");
        printf("Escolha a unidade de saida:\n");
        printf("1 - Segundos (s)\n");
        printf("2 - Minutos (min)\n");
        printf("3 - Horas (h)\n");
        printf("4 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");

        if (scanf("%d", &out) != 1 || out < 1 || out > 4) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        if (out == 4) {
            return; // Voltar ao menu principal
        }

        printf("Digite o valor a ser convertido (ex: 50.00 ou 50): ");

        if (scanf("%lf", &valor) != 1) {
            limparBuffer();
            printf("Por favor, insira um valor no formato do exemplo.\n");
            pausarTela();
            continue;
        }

        if (in == 1) { // Segundos
            if (out == 2) { // Segundos para Minutos
                resultado = valor / 60; 
            } else if (out == 3) {
                resultado = valor / 3600;  // Segundo para horas
            } else {
                resultado = valor; // Segundo para Segundo
            }
        } else if (in == 2) { // Minutos
            if (out == 1) {
                resultado = valor * 60 ; // Minutos para segundos
            } else if (out == 3) {
                resultado = valor/60 ; // Minutos para Horas
            } else {
                resultado = valor; // Minutos para Minutos
            }
        } else if (in == 3) { // Horas
            if (out == 1) {
                resultado = valor * 3600; // Horas para Segundos
            } else if (out == 2) {
                resultado = valor * 60; // Horas para Minutos
            } else {
                resultado = valor; // Horas para Horas
            }
        }

        limparBuffer();
        limparTela();
        printf("Resultado da conversao: %.2lf %s\n", resultado, siglas[out - 1]);
        pausarTela();
    }  
}
int main() {
    int opcao;

    while (1) {
        limparTela();
        printf("Bem-vindo ao Conversor de Unidades\n\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Converter Volume\n");
        printf("2 - Conversor de Potencia\n");
        printf("3 - Conversor de Temperatura\n");
        printf("4 - Conversor de unidade de area\n");
        printf("5 - Conversor de Armazenamento de Dados\n");
        printf("6 - Conversor de Unidade de Tempo\n");
        printf("10 - Sair\n");
        printf("\nDigite a opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Por favor, escolha uma opcao existente no menu.\n");
            pausarTela();
            continue;
        }

        switch (opcao) {
            case 1:
                calcularVolume();
                break;
            case 2:
                calcularPotencia();
                break;
            case 3:
                calcularTemperatura();
                break;
            case 4:
                calcularArea();
                break;
            case 5:
                calcularArmazenamento();
                break;
            case 6:
                 converterTempo();
                 break;
            case 10:
                limparTela();
                printf("Finalizando o conversor...\n");
                return 0;
            default:
                limparBuffer();
                printf("Por favor, escolha uma opcao existente no menu.\n");
                pausarTela();
        }
    }

    return 0;
}