/**
 *  @file pqueue.h
 *  @version 0.1.1-dev0
 *  @date Mon Dec  9 09:11:14 CST 2019
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
 *  @brief Initialize a pqueue object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a pqueue object
 *  @param[in] x FIXME
    @returns FIXME
 */
int         pqueue_init(struct pqueue *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *pqueue_version(void);

void        pqueue_peek(struct pqueue *p, double *priority, void **x);
int         pqueue_pop(struct pqueue *p, double *priority, void **x);
int         pqueue_push(struct pqueue *p, double priority, void *x);

#endif
