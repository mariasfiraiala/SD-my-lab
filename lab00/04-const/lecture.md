# Const 

The `const` is a keyword that specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it. 
In other words, we **cannot WRITE** on const variables.

### READ operations on a variable

```c
int x;
```

1. 
    ```c 
    int y = x;
    ```
1. 
    ```c
    printf("%d", &x);
    ```

1.  ```c
    int z = x + 1;
    ```

### WRITE operations on a variable

```c
int fun(int y)
{
    return y + 1;
};

int x;
```

1. 
    ```c 
    x = 2;
    ```
1. 
    ```c
    x++;
    ```

1.  ```c
    scanf("%d", &x);
    ```

1.  ```c
    x = fun(2);
    ```

### Rule
`const` is applied to leftmost token if it exists.
If it doesn't exists, it takes the first from the right.

```c 
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
``` 
