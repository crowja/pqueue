#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pqueue.h"

int
main(void)
{
   unsigned    i, n = 100000;
   int         rc;
   double      u;
   double      priority;
   char       *x;
   struct pqueue *z = pqueue_new();

   for (i = 0; i < n; i++) {
      u = rand() / (double) RAND_MAX;
      if (u < 0.3) {                             /* push */
         priority = rand();
         x = malloc(20 * sizeof(char));
         strcpy(x, "abcdefg");
         pqueue_push(z, priority, (void *) x);
      }
      else if (u < 0.6)
         pqueue_peek(z, &priority, (void **) &x);
      else {                                     /* pop */
         rc = pqueue_pop(z, &priority, (void **) &x);
         if (rc)
            free(x);
      }
   }

   while ((rc = pqueue_pop(z, &priority, (void **) &x))) {
      if (rc) {
#if 0
         printf("%10.2f -- %s\n", priority, x);
#endif
         free(x);
      }
   }

   pqueue_free(&z);

   return 0;
}
