/**
 *  @file pqueue.c
 *  @version 0.2.1-dev0
 *  @date Tue Dec 10 13:11:45 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct pqnode {
   double      priority;
   void       *x;
   struct pqnode *next;
};

static struct pqnode *
pqnode_new(double priority, void *x)
{
   struct pqnode *tp;

   tp = (struct pqnode *) malloc(sizeof(struct pqnode));
   if (_IS_NULL(tp))
      return NULL;

   tp->priority = priority;
   tp->x = x;
   tp->next = NULL;

   return tp;
}

static void
pqnode_free(struct pqnode *p)
{
   _FREE(p);
}

struct pqueue {
   void       *x;
   struct pqnode *head;
};

struct pqueue *
pqueue_new(void)
{
   struct pqueue *tp;

   tp = (struct pqueue *) malloc(sizeof(struct pqueue));
   if (_IS_NULL(tp))
      return NULL;

   tp->head = NULL;

   return tp;
}

void
pqueue_free(struct pqueue **pp)
{
   _FREE(*pp);
   *pp = NULL;
}

const char *
pqueue_version(void)
{
   return "0.2.1-dev0";
}

static void
print_all(struct pqueue *p)
{
   struct pqnode *tmp = p->head;
   printf("Entire list:");
   while (!_IS_NULL(tmp)) {
      printf("\t%s", (char *) tmp->x);
      tmp = tmp->next;
   }
   printf("\n");
}

int
pqueue_is_empty(struct pqueue *p)
{
   return _IS_NULL(p->head) ? 1 : 0;
}

int
pqueue_peek(struct pqueue *p, double *priority, void **x)
{
   if (_IS_NULL(p->head))
      return 0;

   *priority = p->head->priority;
   *x = p->head->x;

   printf("DEBUG inside pqueue_peek x: %s\n", (char *) *x);

   return 1;
}

int
pqueue_pop(struct pqueue *p, double *priority, void **x)
{
   /* TODO make sure this is working right. Examples ex_1.c ought to be reporting horse. */
   if (_IS_NULL(p->head))
      return 0;

   else {
      struct pqnode *tmp = p->head->next;
      *priority = p->head->priority;
      *x = p->head->x;
      pqnode_free(p->head);
      p->head = tmp;
      return 1;
   }
}

int
pqueue_push(struct pqueue *p, double priority, void *x)
{
   struct pqnode *n = pqnode_new(priority, x);
   struct pqnode *tmp;

   if (_IS_NULL(n))                              /* failed to allocate new node */
      return 1;

#if 0
   printf("Given values                    %10.2f and x %s\n", priority, (char *) x);
   printf("Just created node with priority %10.2f and x %s\n", n->priority,
          (char *) n->x);
#endif

   if (_IS_NULL(p->head)) {                      /* list is empty */
      p->head = n;
#if 0
      print_all(p);
#endif
      return 0;
   }

   if (n->priority > p->head->priority) {        /* insert n at list head */
      n->next = p->head;
      p->head = n;
#if 0
      print_all(p);
#endif
      return 0;
   }

   /* Traverse the list */
   tmp = p->head;
   while (!_IS_NULL(tmp->next))
      if (n->priority > tmp->next->priority)     /* insert n between current tmp and its tmp->next */
         break;
      else
         tmp = tmp->next;

   n->next = tmp->next;
   tmp->next = n;

#if 0
   print_all(p);
#endif

   return 0;
}

#undef  _IS_NULL
#undef  _FREE
