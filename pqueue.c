/**
 *  @file pqueue.c
 *  @version 0.3.2-dev0
 *  @date Sun Feb 16, 2020 03:44:49 PM CST
 *  @copyright 2019-2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>
#include "pqueue.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct pqnode {
   double      priority;
   void       *x;
   struct pqnode *next;
};

static struct pqnode *
pqnode_new(double priority, void *x)
{
   struct pqnode *tp = (struct pqnode *) malloc(sizeof(struct pqnode));

   if (IS_NULL(tp))
      return NULL;

   tp->priority = priority;
   tp->x = x;
   tp->next = NULL;

   return tp;
}

static void
pqnode_free(struct pqnode **pp)
{
   FREE(*pp);
   *pp = NULL;
}

struct pqueue {
   void       *x;
   struct pqnode *head;
   int         len;
};

struct pqueue *
pqueue_new(void)
{
   struct pqueue *tp;

   tp = (struct pqueue *) malloc(sizeof(struct pqueue));
   if (IS_NULL(tp))
      return NULL;

   tp->head = NULL;
   tp->len = 0;                                  /* redundant, a shortcut */

   return tp;
}

void
pqueue_free(struct pqueue **pp)
{

   while (!IS_NULL((*pp)->head)) {
      struct pqnode *tmp = (*pp)->head->next;
      pqnode_free(&((*pp)->head));
      (*pp)->head = tmp;
   }

   FREE(*pp);
   *pp = NULL;
}

const char *
pqueue_version(void)
{
   return "0.3.2-dev0";
}

int
pqueue_is_empty(struct pqueue *p)
{
   return IS_NULL(p->head) ? 1 : 0;
}

int
pqueue_len(struct pqueue *p)
{
   return IS_NULL(p->head) ? 0 : p->len;
}

int
pqueue_peek(struct pqueue *p, double *priority, void **x)
{
   if (IS_NULL(p->head))
      return 0;

   if (!IS_NULL(priority))
      *priority = p->head->priority;

   if (!IS_NULL(x))
      *x = p->head->x;

   return 1;
}

int
pqueue_pop(struct pqueue *p, double *priority, void **x)
{
   if (IS_NULL(p->head))
      return 0;

   else {
      struct pqnode *tmp = p->head->next;
      if (!IS_NULL(priority))
         *priority = p->head->priority;
      if (!IS_NULL(x))
         *x = p->head->x;
      pqnode_free(&(p->head));
      p->head = tmp;
      p->len--;
      return 1;
   }
}

int
pqueue_pop_min(struct pqueue *p, double *priority, void **x)
{
   if (IS_NULL(p->head))
      return 0;

   else if (IS_NULL(p->head->next)) {
      if (!IS_NULL(priority))
         *priority = p->head->priority;
      if (!IS_NULL(x))
         *x = p->head->x;
      pqnode_free(&(p->head));
      p->head = NULL;
   }

   else {
      struct pqnode *tmp = p->head;         /* find penultimate node */
      while (!IS_NULL(tmp->next->next))
         tmp = tmp->next;
      if (!IS_NULL(priority))
         *priority = tmp->next->priority;
      if (!IS_NULL(x))
         *x = tmp->next->x;
      pqnode_free(&(tmp->next));
      tmp->next = NULL;
   }

   p->len--;

   return 1;
}

int
pqueue_push(struct pqueue *p, double priority, void *x)
{
   struct pqnode *n = pqnode_new(priority, x);

   if (IS_NULL(n))                               /* failed to allocate new node */
      return 1;

   if (IS_NULL(p->head))                         /* list is empty */
      p->head = n;

   else if (n->priority > p->head->priority) {   /* insert n at list head */
      n->next = p->head;
      p->head = n;
   }

   else {                                        /* traverse the list */
      struct pqnode *tmp = p->head;
      while (!IS_NULL(tmp->next))
         if (n->priority > tmp->next->priority)  /* insert n between current tmp and its tmp->next */
            break;
         else
            tmp = tmp->next;
      n->next = tmp->next;
      tmp->next = n;
   }

   p->len++;

   return 0;
}

#undef  IS_NULL
#undef  FREE
