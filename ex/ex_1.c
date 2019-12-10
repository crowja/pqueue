#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

int
main(void)
{
   double      priority;
   char       *x;
   struct pqueue *z = pqueue_new();

   pqueue_push(z, 1.0, "pig");
   pqueue_push(z, 2.0, "cat");
   pqueue_push(z, 100.0, "dog");
   pqueue_push(z, 30.0, "cow");

   pqueue_peek(z, &priority, (void **) &x);
   printf("Peeking I see ... %s is at the head with priority %10.2f\n", x, priority);

   pqueue_pop(z, &priority, (void **) &x);
   printf("Popping I see ... %s is at the head with priority %10.2f\n", x, priority);
   printf("Empty? %d should be 0\n", pqueue_is_empty(z));

   pqueue_pop(z, &priority, (void **) &x);
   printf("Popping I see ... %s is at the head with priority %10.2f\n", x, priority);
   printf("Empty? %d should be 0\n", pqueue_is_empty(z));

   pqueue_pop(z, &priority, (void **) &x);
   printf("Popping I see ... %s is at the head with priority %10.2f\n", x, priority);
   printf("Empty? %d should be 0\n", pqueue_is_empty(z));

   pqueue_pop(z, &priority, (void **) &x);
   printf("Popping I see ... %s is at the head with priority %10.2f\n", x, priority);
   printf("Empty? %d should be 1\n", pqueue_is_empty(z));

   pqueue_push(z, -100.0, "horse");
   pqueue_peek(z, &priority, (void **) &x);
   printf("Peeking I see ... %s is at the head with priority %10.2f\n", x, priority);
   printf("Empty? %d should be 0\n", pqueue_is_empty(z));

   /* Testing an empty pqueue */
   pqueue_pop(z, &priority, (void **) &x);
   printf("Empty? %d should be 1\n", pqueue_is_empty(z));
   pqueue_pop(z, &priority, (void **) &x);
   printf("Empty? %d should be 1\n", pqueue_is_empty(z));
   pqueue_pop(z, &priority, (void **) &x);
   printf("Empty? %d should be 1\n", pqueue_is_empty(z));
   pqueue_pop(z, &priority, (void **) &x);
   printf("Empty? %d should be 1\n", pqueue_is_empty(z));

   pqueue_free(&z);

   return 0;
}
