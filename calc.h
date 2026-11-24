#ifndef CALC_H
#define CALC_H

// Результат вычисления выражения 
typedef enum {
    CALC_OK,           // всё хорошо (0)
    CALC_ERR_DIV_ZERO, // деление на ноль в операции % (1)
    CALC_ERR_OPERATOR  // неизвестный оператор (2)
} calc_status_t;

/* Вычисляет "number1 operation number2",
 Поддерживаются операторы: + - * %,
 Результат записывает в *result только если при CALC_OK */
calc_status_t calculate(long long number1, char operation, long long number2, long long *result);

#endif /* CALC_H */
