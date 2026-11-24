#include "errors.h"

#include <stdio.h>
#include <stdlib.h>

int fail(long long *results, const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    free(results);
    return EXIT_FAILURE;
}

