/**
 *  @file pqueue.h
 *  @version 0.2.1-dev0
 *  @date Mon Dec  9 18:27:40 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
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
 *  @details Clean up and free a pqueue structure.
 *  @param[in, out] p.
 */
void        pqueue_free(struct pqueue *p);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *pqueue_version(void);

int         pqueue_is_empty(struct pqueue *p);
int         pqueue_peek(struct pqueue *p, double *priority, void **x);
int         pqueue_pop(struct pqueue *p, double *priority, void **x);
int         pqueue_push(struct pqueue *p, double priority, void *x);

#endif
