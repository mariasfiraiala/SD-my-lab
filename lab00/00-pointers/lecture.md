# Pointers

* Q: What is a variable?

   A: A symbol that can be characterized by

   1. starting address

   2. size

   3. content

* Q: Following this idea, what's a pointer?

   A: A variable that stores in its content the starting address of another variable.

* Q: What's `&`, what about `*`?

   A: `&` returns the starting address of the variable it precedes.
   `*` returns the content of the variable pointed at by the pointer it precedes

* Q: Look at the following snippet:

   ```C
   int val = 16;
   int *p = &val;
   int **q = &p;
   ```

   What does get printed?

   ```C
   printf("p\tcontains: %p\n", p); // adresa lui val
   printf("*p\tcontains: %d\n", *p); // valoarea lui val
   printf("q\tcontains: %p\n", q); // adresa lui p
   printf("*q\tcontains: %p\n", *q); // adresa lui val
   printf("**q\tcontains: %d\n", **q); // valoarea lui val
   ```
