#include <stdio.h>

int main()
{
    int x = 5;

    int *p              = &x; /* variable pointer to variable x */
    *p = 10;                  /* allowed */
    p++;                      /* allowed */

    const int *q1       = &x; /* variable pointer to const variable x
    /* *q1 = 10;              /* NOT allowed */
    q1++;                     /* allowed */

    int const *q2       = &x; /* variable pointer to const variable x
    /* *q2 = 10;              /* NOT allowed */
    q2++;                     /* allowed */

    int * const r       = &x; /* constant pointer to variable x
    *r = 10;                  /* allowed */
    /* r++;                   /* NOT allowed */

    const int *const s1 = &x; /* constant pointer to constant variable x
    /* *s1 = 10               /* NOT allowed */
    /* s1++;                  /* NOT allowed */

    int const *const s2 = &x; /* constant pointer to constant variable x
    /* *s2 = 10;              /* NOT allowed */
    /* s2+;                   /* NOT allowed */
    return 0;
}
