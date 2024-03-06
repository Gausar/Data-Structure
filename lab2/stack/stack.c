#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        p->s_arr[p->s_len] = x; // p->stack.a[0] = x;
        p->s_len += 1;    // p->stack.len = 1;
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        p->s_len -= 1;

}
void s_print(Stack *p)
{
        int i;
        for (i = 0; i < p->s_len; i++) {
                printf("%d ", p->s_arr[i]);
        }
        printf("\n");
}
