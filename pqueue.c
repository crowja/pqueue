/**
 *  @file pqueue.c
 *  @version 0.3.1-dev0
 *  @date Wed Jan  1 17:22:11 CST 2020
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
   struct pqnode *tp = (struct pqnode *) malloc(sizeof(struct pqnode));

   if (_IS_NULL(tp))
      return NULL;

   tp->priority = priority;
   tp->x = x;
   tp->next = NULL;

   return tp;
}

static void
pqnode_free(struct pqnode **pp)
{
   _FREE(*pp);
   *pp = NULL;
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

   while (!_IS_NULL((*pp)->head)) {
      struct pqnode *tmp = (*pp)->head->next;
      pqnode_free(&((*pp)->head));
      (*pp)->head = tmp;
   }

   _FREE(*pp);
   *pp = NULL;
}

const char *
pqueue_version(void)
{
   return "0.3.1-dev0";
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

   if (!_IS_NULL(priority))
      *priority = p->head->priority;

   if (!_IS_NULL(x))
      *x = p->head->x;

   return 1;
}

int
pqueue_pop(struct pqueue *p, double *priority, void **x)
{
   if (_IS_NULL(p->head))
      return 0;

   else {
      struct pqnode *tmp = p->head->next;
      if (!_IS_NULL(priority))
         *priority = p->head->priority;
      if (!_IS_NULL(x))
         *x = p->head->x;
      pqnode_free(&(p->head));
      p->head = tmp;
      return 1;
   }
}

int
pqueue_pop_min(struct pqueue *p, double *priority, void **x)
{
   if (_IS_NULL(p->head))
      return 0;

   else if (_IS_NULL(p->head->next)) {
      if (!_IS_NULL(priority))
         *priority = p->head->priority;
      if (!_IS_NULL(x))
         *x = p->head->x;
      pqnode_free(&(p->head));
      p->head = NULL;
   }

   else {
      struct pqnode *tmp = p->head;         /* find penultimate node */
      while (!_IS_NULL(tmp->next->next))
         tmp = tmp->next;
      if (!_IS_NULL(priority))
         *priority = tmp->next->priority;
      if (!_IS_NULL(x))
         *x = tmp->next->x;
      pqnode_free(&(tmp->next));
      tmp->next = NULL;
   }
   return 1;
}

int
pqueue_push(struct pqueue *p, double priority, void *x)
{
   struct pqnode *n = pqnode_new(priority, x);
   if (_IS_NULL(n))                              /* failed to allocate new node */
      return 1;
   if (_IS_NULL(p->head))                        /* list is empty */
      p->head = n;
   else if (n->priority > p->head->priority) {   /* insert n at list head */
      n->next = p->head;
      p->head = n;
   }

   else {                                        /* traverse the list */
      struct pqnode *tmp = p->head;
      while (!_IS_NULL(tmp->next))
         if (n->priority > tmp->next->priority)  /* insert n between current tmp and its tmp->next */
            break;
         else
            tmp = tmp->next;
      n->next = tmp->next;
      tmp->next = n;
   }

   return 0;
}

#undef  _IS_NULL
#undef  _FREE
