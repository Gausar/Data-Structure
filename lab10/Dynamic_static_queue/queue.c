#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        Elm *t = (Elm*)malloc(sizeof(Elm));
        if(t == NULL){
                printf("aldaa1");
                exit(0);
        }
        t->x = x;
        t->next = NULL;
        if(p->len == 0){
                p->head = t;
                p->tail = t;
        }
        else{
                p->tail->next = t;
                p->tail = t;
        }
        p->len += 1;

}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
        if(p->len == 0){
                return;
        }
        Elm *t = p->head;
        p->head = p->head->next;
        free(t);
        if(p->head == NULL){
                p->tail = NULL;
        }
        p->len--;
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
        Elm *t = p->head;
        while(t != NULL){
                printf("%d\n", t->x);
                t = t->next;
        }
}
