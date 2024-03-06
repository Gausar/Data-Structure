#include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  p->l_arr[p->l_len] = x;
  p->l_len += 1;
}
/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  int i;
  p->l_len += 1;
  for(i = p->l_len; i >= 0; i--){
    p->l_arr[i] = p->l_arr[i - 1];
  }
  p->l_arr[0] = x;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
  if(pos > p->l_len){
    p->l_arr[p->l_len] = x;
  }
  else{
    int i;
    for(i = p->l_len; i > pos; i--){
      p->l_arr[i] = p->l_arr[i - 1];
    }
    p->l_arr[pos] = x;
    p->l_len += 1;
  }
}


/* p-ийн зааж буй List-н эхлэлээс гаргана.
   List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
  int i;
  for(i = 0; i < p->l_len - 1; i++){
    p->l_arr[i] = p->l_arr[i + 1];
  }
  p->l_len -= 1;

}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
  p->l_len -= 1;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
  if(pos > p->l_len){
    printf("gargah bolomjgui bairlal\n");
  }
  else{
    int i;
    for(i = pos; i < p->l_len - 1; i++){
      p->l_arr[i] = p->l_arr[i + 1];
    }
    p->l_len =p->l_len -  1;
  }
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void l_print(List *p)
{
        int i;
        for (i = 0; i < p->l_len; i++) {
                printf("%d ", p->l_arr[i]);
        }
        printf("\n");
}

/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int l_search(List *p, int x)
{
  for(int i = 0; i < p->l_len; i++){
    if(p->l_arr[i] == x){
      return i;
    }
  }
  return -1;
}
