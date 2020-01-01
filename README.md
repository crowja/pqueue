# pqueue 0.3.1.

Linked-list implementation of a priority queue.

*   pqueue\_new()
*   pqueue\_free()
*   pqueue\_is\_empty()
*   pqueue\_peek()
*   pqueue\_pop()
*   pqueue\_push()

Requires only pqueue.c and pqueue.h.

     #include "pqueue.h"
      . . .
     void *ptr, *this_ptr;
     static struct pqueue *z = pqueue_new();
      . . .
     this_ptr = some_pointer_here;
     pqueue_push(z, this_priority, this_ptr);
     pqueue_pop(z, &priority, &ptr);
      . . .
     pqueue_free(&z);

Pqueue does not manage/free memory associated with the pointers it's passed,
e.g. this\_ptr.

## Example

```c
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
```

Running this will produce the output

    Empty queue? 0
    Popped dog with priority 90.000000
    Popped pig with priority 75.000000
    Popped cat with priority 50.000000
    Empty queue? 1


jac
