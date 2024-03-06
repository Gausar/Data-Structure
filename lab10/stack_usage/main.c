#include "DS.h"
#include <stdlib.h>

int main()
{
        /* Tree үүсгэн, эхлүүлэх */
        CBTree tr;
        tr.cb_len = 0;
        
        int t, x, pos, idx;

        while (1) {
                printf("1: insert, 2: preorder, 3: inorder, 4: postorder, "
                       "5: exit\n");
                scanf("%d", &t);

                switch (t) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        cb_push(&tr, x);
                        break;
                case 2:
                        cb_preorder(&tr, 0);
                        break;
                case 3:
                        cb_inorder(&tr, 0);
                        break;
                case 4:
                        cb_postorder(&tr, 0);
                        break;
                default:
                        exit(0);
                }
        }
        return 0;
}
