#include "DS.h"

/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{       
        if(p->tree.len > 100){
                printf("Mod duursen bna");
                return;
        }

        p->tree.a[p->tree.len] = x;
        p->tree.len++;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
        int zuun = 2 * idx + 1;
        if(zuun >= p->tree.len){
                return -1;
        }
        else return zuun;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
        int baruun = 2 * idx + 2;
        if(baruun >= p->tree.len){
                return -1;
        }
        else return baruun;
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
        int i;
        for(i = 0; i < p->tree.len; i++){
                if(p->tree.a[i] == x){
                        return i;
                }
        }
        return -1;	
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
        int i = idx;
        while(i > 0){
                i = (i - 1)/2;
                printf("%d\n", p->tree.a[i]);
        }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
        int i = 0;
        while(p->tree.len > pow(2, i) - 1){
                i++;
        }
        return i;
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
        int i = (idx - 1)/2;
        if(idx == i * 2 + 2 && i * 2 + 2 < p->tree.len){
                return 2 * i + 1;
        }
        else if(idx == i * 2 + 1 && i * 2 + 2 < p->tree.len){
                return 2 * i + 2;
        }
        else return -1;
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
        Stack k, m;
        k.top = NULL;
        m.top = NULL;
        s_push(&k, idx);

        while(k.top != NULL){
                idx = k.top->x;
                s_pop(&k);
                if(cb_right(p, idx) != -1){
                        s_push(&k, cb_right(p, idx));
                }
                if(cb_left(p, idx) != -1){
                        s_push(&k, cb_left(p, idx));
                }
                
                s_push(&m, idx);
                while(m.top != NULL){
                        idx = m.top->x;
                        s_pop(&m);
                        printf("%d\n", p->tree.a[idx]);
                }
                
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
        Stack k;
        k.top = NULL;
        while(idx != -1 || k.top != NULL){
                while(idx != -1){
                        s_push(&k, idx);
                        idx = cb_left(p, idx);
                }
                if(k.top != NULL){
                        idx = k.top->x;
                        s_pop(&k);
                        printf("%d\n", p->tree.a[idx]);
                        idx = cb_right(p, idx);
                }
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
        Stack k, m;
        k.top = NULL;
        m.top = NULL;
        s_push(&k, idx);
        while (k.top != NULL)
        {
                idx = k.top->x;
                s_pop(&k);
                s_push(&m, idx);

                if (cb_left(p, idx) != -1)
                {
                        s_push(&k, cb_left(p, idx));
                }
                if (cb_right(p, idx) != -1)
                {
                        s_push(&k, cb_right(p, idx));
                }
        }

        while (m.top != NULL)
        {       
                idx = m.top->x;
                s_pop(&m);
                printf("%d\n", p->tree.a[idx]);
        }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
        int i = idx;
        if(i * 2 + 1 >= p->tree.len){
                printf("%d\n", p->tree.a[i]);
        }
        else{
                cb_leaves(p, i * 2 + 1);
                cb_leaves(p, i * 2 + 2);
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
        int i = idx;
        if(i * 2 + 1 < p->tree.len){
                printf("%d\n", p->tree.a[i * 2 + 1]);
                cb_descendants(p, i * 2 + 1);
        }
        if(i * 2 + 2 < p->tree.len){
                printf("%d\n", p->tree.a[i * 2 + 2]);
                cb_descendants(p, i * 2 + 2);
        }
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
        return p->tree.len;
	
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
         int t = -1;
        for(int j = 0; j < p->tree.len; j++){
                if(p->tree.a[j] == x){
                        t = 0;
                        while(j > 0){
                                j = (j - 1)/2;
                                t++;
                        }
                        break;
                }
        }
        return t;
}

