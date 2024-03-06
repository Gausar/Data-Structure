#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Token x)
{
	 TokenElm *t = (TokenElm *)malloc(sizeof(TokenElm));
    if (t == NULL) {
        return;
    }
    t->x = x;
    t->next = NULL;
    if (p->len == 0) {
        p->head = t;
        p->tail = t;
    } else {
        p->tail->next = t;
        p->tail = t;
    }
    p->len++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Token x)
{
	TokenElm *t = (TokenElm *)malloc(sizeof(TokenElm));
    if (t == NULL) {
        return;
    }
    t->x = x;
    t->next = p->head;
    if (p->len == 0) {
        p->head = t;
        p->tail = t;
    } else {
        p->head = t;
    }
    p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Token x, int pos)
{
	TokenElm *new = (TokenElm *)malloc(sizeof(TokenElm));
    if (new == NULL) {
        return;
    }
    new->x = x;
    if (pos >= p->len) {
        new->next = NULL;
        if (p->len == 0) {
            p->head = new;
            p->tail = new;
        } else {
            p->tail->next = new;
            p->tail = new;
        }
    } else if (pos == 0) {
        new->next = p->head;
        p->head = new;
    } else {
        TokenElm *t = p->head;
        for (int i = 0; i < pos - 1; i++) {
            t = t->next;
        }
        new->next = t->next;
        t->next = new;
    }

    p->len++;
}


/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	int i;
  TokenElm *temp = p->head;
  p->head = p->head->next;
  free(temp);
  p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	if(p->len == 0){
    return;
  }
  if(p->len == 1){
    free(p->head);
    p->head = NULL;
    p->tail = NULL;
  }
  else{
    TokenElm *t = p->head;
    while(t->next != p->tail){
      t = t->next;
    }
    free(p->tail);
    t->next = NULL;
    p->tail = t;
  }
  p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	if(pos < 0 || pos >= p->len) {
    return;
  }
  if(pos == 0) {
    TokenElm *temp = p->head;
    p->head = p->head->next;
    free(temp);
    if (p->head == NULL) {
      p->tail = NULL;
    }
  }
  else {
    TokenElm *a = p->head;
    for (int i = 0; i < pos - 1; i++) {
        a = a->next;
    }

    TokenElm *temp = a->next;
    a->next = temp->next;
    free(temp);
    if (a->next == NULL) {
        p->tail = a;
    }
  }

  p->len--;
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
  TokenElm *t = p->head;
  while(t != NULL){
    if(t->x.flag == 0){
      printf("%c", t->x.op);
    }
    else if(t->x.flag == 1){
      printf("%d", t->x.val);
    }
    t = t->next;
  }
  printf("\n");
}

