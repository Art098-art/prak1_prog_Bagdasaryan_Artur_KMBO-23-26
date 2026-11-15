#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

// Печатает сообщение об ошибке, освобождает массив и возвращает код ошибки.
static int fail(long long *results, const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    free(results);
    return EXIT_FAILURE;
}

int main(void)
{
    size_t capacity = 4; // сколько ячеек выделено
    size_t count = 0;   // сколько ячеек реально занято
    long long *results = malloc(capacity * sizeof(*results));

    // читаем выражения, пока не встретим "-k"
    while (1) {
        char symbol;
        char operation;
        long long number1;
        long long number2;
        long long answer = 0;
        int sign = 1;
      
        scanf(" %c", &symbol); 

        if (symbol == '-') {
            // Это либо флаг "-k", либо минус у отрицательного числа
            int next = getchar();
            if (next == 'k') {
                break; // нашли "-k": выражения закончились
            }
            if (!isdigit(next)) {
                return fail(results, "incorrect flag (only -k is allowed)");
            }
            sign = -1;           // это было отрицательное число
            ungetc(next, stdin); // возвращаем цифру обратно во ввод
        }
        else if (isdigit((unsigned char)symbol)) {
            ungetc(symbol, stdin); // эту цифру возвращаем, scanf прочтёт число
        }
        else {
            // Вместо числа или -k пришёл другой символ, например оператор
            return fail(results, "expected a number or -k (wrong arguments)");
        }

        scanf("%lld", &number1);
        number1 *= sign;

        scanf(" %c", &operation);

        if (operation == '\'') {
            // оператор введён в кавычках: '*' - берём сам символ внутри
            operation = (char)getchar();
            getchar(); // пропускаем закрывающую кавычку
        }

        scanf("%lld", &number2);

        switch (operation) {
        case '+':
            answer = number1 + number2;
            break;
        case '-':
            answer = number1 - number2;
            break;
        case '*':
            answer = number1 * number2;
            break;
        case '%':
            if (number2 == 0) {
                return fail(results, "division by zero");
            }
            answer = number1 % number2;
            break;
        default:
            return fail(results, "incorrect operator (allowed: + - * %)");
        }

        // Если массив заполнен - увеличиваем его вдвое
        if (count == capacity) {
            capacity *= 2;
            long long *bigger = realloc(results, capacity * sizeof(*results));
            results = bigger;
        }

        results[count] = answer;
        count++;

        printf("Ответ %zu: %lld\n", count, answer);
    }

    //читаем ключ и проверяем, что больше ничего нет
    if (count == 0) {
        return fail(results, "not enough arguments");
    }

    long long key;
    scanf("%lld", &key);

    //дешифруем и сразу выводим по одному символу
    printf("Результирующая строка: ");
    for (size_t i = 0; i < count; i++) {
        printf("%c", (char)(results[i] - key));
    }
    printf("\n");

    free(results);
    return EXIT_SUCCESS;
}
