#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

int
main(int argc, char *argv[])
{
   double      priority;
   char        x[100];

   struct pqueue *z = pqueue_new();

   pqueue_push(z, 1.0, "pig");
   pqueue_push(z, 2.0, "cat");
   pqueue_push(z, 100.0, "dog");
   pqueue_push(z, 30.0, "cow");

   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);

   /* Testing an empty pqueue */
   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);
   pqueue_pop(z, &priority, &x);

   pqueue_free(z);

   return 0;
}
