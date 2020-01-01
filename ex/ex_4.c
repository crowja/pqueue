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
   pqueue_push(z, 55.0, "ant");

   printf("Empty queue? %d\n", pqueue_is_empty(z));

   pqueue_pop_min(z, &pr, (void **) &cp);
   printf("Min-popped %s with priority %f\n", cp, pr);
   pqueue_pop_min(z, &pr, (void **) &cp);
   printf("Min-popped %s with priority %f\n", cp, pr);
   pqueue_pop_min(z, &pr, (void **) &cp);
   printf("Min-popped %s with priority %f\n", cp, pr);
   pqueue_pop_min(z, &pr, (void **) &cp);
   printf("Min-popped %s with priority %f\n", cp, pr);

   while (pqueue_pop(z, &pr, (void **) &cp))
      printf("Popped %s with priority %f\n", cp, pr);

   printf("Empty queue? %d\n", pqueue_is_empty(z));

   pqueue_free(&z);

   return 0;
}
