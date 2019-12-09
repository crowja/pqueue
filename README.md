# pqueue 0.2.1-dev0.

Linked-list implementation of a priority queue.

*  pqueue\_new()
*  pqueue\_free()
*  pqueue\_is\_empty()
*  pqueue\_peek()
*  pqueue\_pop()
*  pqueue\_push()

Requires only pqueue.c and pqueue.h. Use it like this:

     static struct pqueue *z = pqueue_new();
      . . .
     pqueue_push(z, this_priority, this_ptr);
     pqueue_pop(z, &priority, &ptr);

Pqueue does not manage (free) memory associated with this\_ptr.
