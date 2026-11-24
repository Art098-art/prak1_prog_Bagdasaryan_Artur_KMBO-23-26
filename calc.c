#include "calc.h"
 
calc_status_t calculate(long long number1, char operation, long long number2, long long *result)
{
    switch (operation) {
    case '+':
        *result = number1 + number2;
        break;

    case '-':
        *result = number1 - number2;
        break;

    case '*':
        *result = number1 * number2;
        break;

    case '%':
        if (number2 == 0) {
            return CALC_ERR_DIV_ZERO;
        }
        *result = number1 % number2;
        break;

    default:
        return CALC_ERR_OPERATOR;
    }
    return CALC_OK;
}
