#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "pqueue.h"
#include "t/tinytest.h"

#ifdef  _COLOR_CODE
#undef  _COLOR_CODE
#endif
#define _COLOR_CODE       0x1B

#ifdef  _COLOR_RED
#undef  _COLOR_RED
#endif
#define _COLOR_RED        "[1;31m"

#ifdef  _COLOR_GREEN
#undef  _COLOR_GREEN
#endif
#define _COLOR_GREEN      "[1;32m"

#ifdef  _COLOR_YELLOW
#undef  _COLOR_YELLOW
#endif
#define _COLOR_YELLOW     "[1;33m"

#ifdef  _COLOR_RESET
#undef  _COLOR_RESET
#endif
#define _COLOR_RESET      "[0m"


static void
_printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, name, _COLOR_CODE, _COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}


static int
_two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}


static void
test_constr(void)
{
   struct pqueue *z;

   _printf_test_name("test_constr()", "pqueue_new, pqueue_free");

   z = pqueue_new();
   ASSERT("Constructor test", z);
   pqueue_free(z);

}

static void
test_push_pop_1(void)
{
   unsigned    i;
   unsigned    n = 1000;
   int         rc;
   double      priority;
   double     *xp;
   struct pqueue *z;

   _printf_test_name("test_push_pop_1", "pqueue_push, pqueue_pop");

   z = pqueue_new();

   for (i = 0; i < n; i++) {
      priority = 100 * sin(0.5 * i);
      xp = malloc(sizeof(double));
      *xp = (double) i;
      ASSERT_EQUALS(0, pqueue_push(z, priority, (void *) xp));
   }

   while (rc = pqueue_pop(z, &priority, (void **) &xp)) {
      free(xp);
   }

   /* A few extra pops */
   ASSERT_EQUALS(0, pqueue_pop(z, &priority, (void **) &xp));
   ASSERT_EQUALS(0, pqueue_pop(z, &priority, (void **) &xp));
   ASSERT_EQUALS(0, pqueue_pop(z, &priority, (void **) &xp));
   ASSERT_EQUALS(0, pqueue_pop(z, &priority, (void **) &xp));

   pqueue_free(z);
}

static void
test_push_pop_2(void)
{
   char       *x;
   double      priority;
   struct pqueue *z;

   _printf_test_name("test_push_pop_2", "pqueue_push, pqueue_pop");

   z = pqueue_new();
   pqueue_push(z, 1.0, "ant");
   pqueue_push(z, 4.0, "cat");
   pqueue_push(z, 5.0, "cow");
   pqueue_push(z, 8.0, "fox");
   pqueue_push(z, 13.0, "pig");
   pqueue_push(z, 6.0, "crow");
   pqueue_push(z, 10.0, "goose");
   pqueue_push(z, 12.0, "horse");
   pqueue_push(z, 14.0, "skunk");
   pqueue_push(z, 2.0, "beaver");
   pqueue_push(z, 3.0, "bobcat");
   pqueue_push(z, 16.0, "zebra");
   pqueue_push(z, 15.0, "turkey");
   pqueue_push(z, 11.0, "hamster");
   pqueue_push(z, 9.0, "giraffe");
   pqueue_push(z, 7.0, "elephant");
   pqueue_push(z, 17.0, "woodchuck");
   /* and repeat */
   pqueue_push(z, 17.0, "woodchuck");

   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("woodchuck", x);
   /* and repeat */
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("woodchuck", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("zebra", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("turkey", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("skunk", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("pig", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("horse", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("hamster", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("goose", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("giraffe", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("fox", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("elephant", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("crow", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("cow", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("cat", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("bobcat", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("beaver", x);
   pqueue_pop(z, &priority, (void **) &x);
   ASSERT_STRING_EQUALS("ant", x);

   pqueue_free(z);
}

static void
test_free(void)
{
   struct pqueue *z;

   _printf_test_name("test_free", "pqueue_free");

   z = pqueue_new();

   pqueue_push(z, 1.0, "cat");
   pqueue_push(z, 2.0, "mouse");
   pqueue_push(z, 3.0, "dog");

   pqueue_free(z);
}

#if 0                                            /* 14 yy */
static void
test_stub(void)
{
   struct pqueue *z;
   double      x = 1.23;                    /* TODO */

   _printf_test_name("test_stub()", NULL);

   z = pqueue_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", _two_doubles_equal(x, 1.23));

   pqueue_free(z);
}
#endif


int
main(void)
{
   printf("%s\n", pqueue_version());

   RUN(test_constr);
   RUN(test_push_pop_1);
   RUN(test_push_pop_2);
   RUN(test_free);

   return TEST_REPORT();
}
