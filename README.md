# pqueue 0.2.0-dev0.

Linked-list implementation of a priority queue.

Intend to support (at least):

*  pqueue\_new()
*  pqueue\_peek()
*  pqueue\_pop()
*  pqueue\_push()

Will look like

     static struct pqueue *z = pqueue_new();
      . . .
     pqueue_push(z, this_priority, this_ptr);
     pqueue_pop(z, &priority, &ptr);

It will not manage (free) memory associated with this\_ptr.
