#include <stdio.h>
#include <math.h>

int main() {
    int d, m, y, h1, m1, h2, m2, minuteResult, hourResult, hourOption, tempOption, measureOption, dateOption;
    char option;
    float temp, c, h, wallArea, brickArea, brickUnits;

    printf("*****************\n");
    printf("*     ZOXY      *\n");
    printf("*****************\n");

    printf("Menu inicial\n");
    printf("a. Validação de data\n");
    printf("b. Diferença de horários\n");
    printf("c. Conversão de temperatura\n");
    printf("d. Cálculo de material\n");
    printf("> Selecione uma opção: ");
    scanf(" %c", &option);

    if (option == 'A' || option == 'a') {
        printf("A > Validação de data.\n");

        printf("> Dia: ");
        scanf("%d", &d);
        printf("> Mês: ");
        scanf("%d", &m);
        printf("> Ano: ");
        scanf("%d", &y);

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 31) {
                printf("> O mês selecionado só tem 31 dias.\n");
                return 0;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 30) {
                printf("> O mês selecionado só tem 30 dias.\n");
                return 0;
            }
        } else if (m == 2) {
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                if (d > 29) {
                    printf("> O mês selecionado só tem 29 dias.\n");
                    return 0;
                }
            } else if (d > 28) {
                printf("> O mês selecionado só tem 28 dias.\n");
                return 0;
            }
        } else {
            printf("> A opção de mês digitada é inválida.");

            return 0;
        }

        printf("1. DD/MM/YYYY\n2. YYYY-MM-DD\n3. DD de [MÊS] de YYYY\n");
        printf("> Selecione uma opção: ");
        scanf("%d", &dateOption);

        if (dateOption == 1) {
            printf("> Opção 1: %d/%.2d/%d\n", d, m, y);
        } else if (dateOption == 2) {
            printf("> Opção 2: %d-%.2d-%d\n", y, m, d);
        } else if (dateOption == 3) {
            if (m == 1) {
                printf("> Opção 3: %d de janeiro de %d\n", d, y);
            }
            else if (m == 2) {
                printf("> Opção 3: %d de fevereiro de %d\n", d, y);
            }
            else if (m == 3) {
                printf("> Opção 3: %d de março de %d\n", d, y);
            }
            else if (m == 4) {
                printf("> Opção 3: %d de abril de %d\n", d, y);
            }
            else if (m == 5) {
                printf("> Opção 3: %d de maio de %d\n", d, y);
            }
            else if (m == 6) {
                printf("> Opção 3: %d de junho de %d\n", d, y);
            }
            else if (m == 7) {
                printf("> Opção 3: %d de julho de %d\n", d, y);
            }
            else if (m == 8) {
                printf("> Opção 3: %d de agosto de %d\n", d, y);
            }
            else if (m == 9) {
                printf("> Opção 3: %d de setembro de %d\n", d, y);
            }
            else if (m == 10) {
                printf("> Opção 3: %d de outubro de %d\n", d, y);
            }
            else if (m == 11) {
                printf("> Opção 3: %d de novembro de %d\n", d, y);
            }
            else if (m == 12) {
                printf("> Opção 3: %d de dezembro de %d\n", d, y);
            }
        } else {
            printf("> A opção digitada é inválida.\n");
        }

    } else if (option == 'B' || option == 'b') {
        printf("B > Diferença de horários\n");

        printf("> Hora h1: ");
        scanf("%d", &h1);
        printf("> Minuto m1: ");
        scanf("%d", &m1);
        printf("> Hora h2: ");
        scanf("%d", &h2);
        printf("> Minuto m2: ");
        scanf("%d", &m2);

        if (h1 > 24 || h2 > 24 || m1 > 60 || m2 > 60) {
            printf("> O valor das horas precisa ter até 23 horas e o valor dos minutos até 59 minutos.");
            return 0;
        }

        printf("1. Padrão\n2. Minutos\n3. Segundos\n4. Milisegundos\n");
        printf("> Selecione uma opção: ");
        scanf("%d", &hourOption);

        if (h1 > h2 || h1 == h2) {
            hourResult = h2 ? (24 - h1) + (h2) : h1;
        } else if (h2 > h1) {
            hourResult = h2 - h1;
        }

        if (m1 > m2) {
            hourResult = hourResult == h1 && !h2 ? hourResult : hourResult - 1;
            minuteResult = m2 ? (60 - m1) + m2 : m1;
        } else if (m2 > m1) {
            hourResult = hourResult == h1 && !h2 ? hourResult - 1 : hourResult;
            minuteResult = m2 - m1;
        } else {
            minuteResult = 0;
        }

        if (minuteResult > 60) {
            minuteResult -= 60;
            hourResult += 1;
        }

        if (hourOption == 1) {
            printf("> Opção 1: %d horas e %d minutos", hourResult, minuteResult);
        } else if (hourOption == 2) {
            hourResult = (hourResult * 60) + minuteResult;
            printf("> Opção 2: %dm", hourResult);
        } else if (hourOption == 3) {
            hourResult = ((hourResult * 60) + minuteResult) * 60;
            printf("> Opção 3: %ds", hourResult);
        } else if (hourOption == 4) {
            hourResult = (((hourResult * 60) + minuteResult) * 60) * 1000;
            printf("> Opção 4: %dms", hourResult);
        } else {
            printf("> Opção digitada é inválida.");

            return 0;
        }

    } else if (option == 'C' || option == 'c') {
        printf("C > Conversão de temperatura\n");
        printf("> Temperatura (ºC): ");
        scanf("%f", &temp);

        printf("1. Fahrenheit\n2. Kelvin\n3. Rankine\n");
        printf("> Selecione uma opção: ");
        scanf("%d", &tempOption);

        if (tempOption == 1) {
            printf("> Opção 1: %.2fºF", (temp * 9/5) + 32);
        } else if (tempOption == 2) {
            printf("> Opção 2: %.2fK", temp + 273.15);
        } else if (tempOption == 3) {
            printf("> Opção 3: %.2fºR", (temp * 9/5) + 491.67);
        } else {
            printf("> Opção digitada é inválida.");

            return 0;
        }

    } else if (option == 'D' || option == 'd') {
        printf("D > Cálculo de material\n");

        printf("> Altura (m): ");
        scanf("%f", &h);
        printf("> Comprimento (m): ");
        scanf("%f", &c);

        printf("1. 6 furos\n2. 8 furos\n3. 9 furos\n");
        printf("> Selecione uma opção: ");
        scanf("%d", &measureOption);

        wallArea = h * c;

        if (measureOption == 1) {
            brickArea = 0.14 * 0.19;
            brickUnits = ceilf(wallArea / brickArea);

            printf("> Opção 1: %.f unidades R$ %.2f", brickUnits, brickUnits * 0.4);
        } else if (measureOption == 2) {
            brickArea = 0.19 * 0.19;
            brickUnits = ceilf(wallArea / brickArea);

            printf("> Opção 2: %.f unidades R$ %.2f", brickUnits, brickUnits * 0.7805);
        } else if (measureOption == 3) {
            brickArea = 0.19 * 0.29;
            brickUnits = ceilf(wallArea / brickArea);

            printf("> Opção 3: %.f unidades R$ %.2f", brickUnits, brickUnits * 0.89999);
        } else {
            printf("> Opção digitada é inválida.");

            return 0;
        }

    } else {
        printf("> A opção digitada não corresponde a nenhuma das apresentadas.\n");
        return 0;
    }

    return 0;
}