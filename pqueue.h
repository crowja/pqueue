/**
 *  @file pqueue.h
 *  @version 0.3.2-dev0
 *  @date Fri Feb  7 22:21:54 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 *  @brief Provides a priority queue.
 */

#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "pqueue"

struct pqueue;

/**
 *  @brief Constructor.
 *  @details Create and return a new pqueue object.
 *  @returns New pqueue object.
 */
struct pqueue *pqueue_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a pqueue structure. This frees memory allocated
 *  by pqueue functions and sets *pp to NULL. Any allocated memory associated
 *  with the void * pointers passed in a pqueue_push() needs to be handled by
 *  the user.
 *  @param[in, out] pp. It is assumed *pp has been created by a call to 
 *  pqueue_new(), and on return *pp is set to NULL.
 */
void        pqueue_free(struct pqueue **pp);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *pqueue_version(void);

/**
 *  @brief Test if the priority queue is empty.
 *  @returns 1 if empty, 0 otherwise.
 */
int         pqueue_is_empty(struct pqueue *p);

/**
 *  @brief Get the length of the priority queue.
 *  @returns Length of the internal priority queue.
 */
int         pqueue_len(struct pqueue *p);


/**
 *  @brief Peek at the next value to pop.
 *  @details Return the priority and value of the next value pqueue_pop() will
 *  produce without actually popping from the queue.
 *  @param[out] priority. Next priority if not called with NULL.
 *  @param[out] x. Next value if not called with NULL.
 *  @returns 0 if there is nothing to pop, 1 otherwise.
 */
int         pqueue_peek(struct pqueue *p, double *priority, void **x);

/**
 *  @brief Pop the next value in the queue.
 *  @details Pop the queue, returning the next priority and value.
 *  @param[out] priority. Next priority if not called with NULL.
 *  @param[out] x. Next value if not called with NULL.
 *  @returns 0 if nothing was popped, 1 otherwise.
 */
int         pqueue_pop(struct pqueue *p, double *priority, void **x);

/**
 *  @brief Pop the smallest value in the queue.
 *  @details Pop the smallest value in the queue, returning its priority and
      value.
 *  @param[out] priority. Popped priority if not called with NULL.
 *  @param[out] x. Popped value if not called with NULL.
 *  @returns 0 if nothing was popped, 1 otherwise.
 */
int         pqueue_pop_min(struct pqueue *p, double *priority, void **x);

/**
 *  @brief Push  onto the queue.
 *  @details Push a value with priority onto the queue.
 *  @param[in] priority.
 *  @param[in] x. Pointer to value.
 *  @returns 0 on success, 1 otherwise.
 */
int         pqueue_push(struct pqueue *p, double priority, void *x);

#endif
