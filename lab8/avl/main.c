#include "DS.h"

int main()
{
        int x, t, y;
        AVL avl;
        avl.root = NULL;
        Elm *p;
        
        while (1) {
                printf("1: put, 2: get, 3: del, 4: delMin, 5: inorder, "
                       "6: size, 7: height, 8: exit\n");
                scanf("%d", &t);

                switch (t) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        avl_put(&avl, x);
                        break;
                case 2:
                        printf("Xandax utga: ");
                        scanf("%d", &x);
                        p = avl_get(&avl, x);
                        if (p == NULL)
                                printf("Oldsongui\n");
                        else {
                                printf("Utga: %d\n", p->x);
                                printf("len: %d\n", p->len);
                                printf("height: %d\n", p->height);
                        }
                        break;
                case 3:
                        printf("Ustgax utga: ");
                        scanf("%d", &x);
                        avl_del(&avl, x);
                        break;
                case 4:
                        if (avl.root) {
                                x = avl_delMin(&avl);
                                printf("Ustgasan xamgiin baga utga: %d\n", x);
                        } else
                                printf("Mod xooson\n");
                        break;
                case 5:
                        avl_inorder(&avl);
                        break;
                case 6:
                        printf("Xemjee olox utga: ");
                        scanf("%d", &x);
                        y = avl_size(&avl, x);
                        printf("Size(%d): %d\n", x, y);
                        break;
                case 7:
                        printf("Undur olox utga: ");
                        scanf("%d", &x);
                        y = avl_height(&avl, x);
                        printf("Height(%d): %d\n", x, y);
                        break;
                case 8:
                        exit(0);
                default:
                        break;
                }
        }
        return 0;
}
