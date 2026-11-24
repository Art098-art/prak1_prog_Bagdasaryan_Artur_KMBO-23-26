#ifndef ERRORS_H
#define ERRORS_H

/* Печатает в stderr сообщение "Error: <message>", освобождает массив results
 и возвращает EXIT_FAILURE, чтобы можно было написать текст ошибки */

int fail(long long *results, const char *message);

#endif /* ERRORS_H */
