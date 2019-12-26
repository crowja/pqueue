#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

int
main(void)
{
   char       *cp;
   double      pr;
   struct pqueue *z = pqueue_new();

   pqueue_push(z, 90.0, "dog");
   pqueue_push(z, 50.0, "cat");
   pqueue_push(z, 75.0, "pig");

   printf("Empty queue? %d\n", pqueue_is_empty(z));

   while (pqueue_pop(z, &pr, (void **) &cp))
      printf("Popped %s with priority %f\n", cp, pr);

   printf("Empty queue? %d\n", pqueue_is_empty(z));

   pqueue_free(&z);

   return 0;
}
