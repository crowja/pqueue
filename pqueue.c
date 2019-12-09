/**
 *  @file pqueue.c
 *  @version 0.1.1-dev0
 *  @date Mon Dec  9 09:11:14 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
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
pqueue_free(struct pqueue *p)
{
   /* Do some magic here ... */
   _FREE(p);
}

int
pqueue_init(struct pqueue *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
pqueue_version(void)
{
   return "0.1.1-dev0";
}

/* TODO */
void                                        /* FIXME */
pqueue_peek(struct pqueue *p, double *priority, void **x)
{
   /* TODO also handle the case where p->head is NULL */

   *priority = p->head->priority;
   *x = p->head->x;
}

int
pqueue_pop(struct pqueue *p, double *priority, void **x)
{
   /* TODO need to handle case of p->head == NULL */

   *priority = p->head->priority;
   *x = p->head->x;
   p->head = p->head->next;
   /* pqnode_free(head); FIXME */
}

int
pqueue_push(struct pqueue *p, double priority, void *x)
{
   struct pqnode *n = pqnode_new(priority, x);
   struct pqnode *tmp;

   if (_IS_NULL(p->head)) {                      /* empty list */
      p->head = n;
      return 0;
   }

   if (n->priority > p->head->priority) {        /* new list head */
      n->next = p->head;
      p->head = n;
      return 0;
   }

   /* Traverse the list */
   tmp = p->head;
   while (!_IS_NULL(tmp)) {
      if (n->priority > tmp->priority) {
         /* TODO insert n in front of tmp and break */
      }
      else
         tmp = tmp->next;
   }

   return 0;
}

#undef  _IS_NULL
#undef  _FREE
