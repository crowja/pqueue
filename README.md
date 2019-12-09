# pqueue 0.1.1-dev0.

Linked-list implementation of a priority queue.

Intend to support (at least):

*  pqueue\_new()
*  pqueue\_peek()
*  pqueue\_pop()
*  pqueue\_push()

Will look like

     static struct *z = pqueue_new();
      . . .
     pqueue_push(z, this_priority, this_ptr);

It will not manage (free) any memory associated with this\_ptr.
