#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        p->q_arr[p->q_len] = x;
        p->q_len += 1;

}


/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{       
        if(p->q_len == 0){
                return;
        }
        else{

                int i;
                for(i = 0; i < p->q_len - 1; i++){
                        p->q_arr[i] = p->q_arr[i + 1];
                }
                p->q_len -= 1;
        }
}

/* p-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void q_print(Queue *p)
{
        int i;
        for (i = 0; i < p->q_len; i++) {
                printf("%d ", p->q_arr[i]);
        }
        printf("\n");
}
