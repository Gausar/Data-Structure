#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
        Elm *t = (Elm*)malloc(sizeof(Elm));
        if(t == NULL){
                printf("aldaa1");
                exit(0);
        }
        t->x = x;
        t->next = p->top;
        p->top = t;
        p->len = p->len + 1;
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
        
        if(p->top == NULL){
                //printf("aldaa2");
                return;
        }
        Elm *t = p->top;
        p->top = p->top->next;
        p->len -= 1;
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
        Elm *t = p->top;
        while(t != NULL){
                printf("%d\n", t->x);
                t = t->next;
        }
}
