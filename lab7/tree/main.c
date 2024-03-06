#include "DS.h"

int main()
{
        int x, t, y;
        BST bst;
        bst.root = NULL;
        Elm *p;
        
        while (1) {
                printf("1: put, 2: get, 3: del, 4: delMin, 5: inorder, "
                       "6: rank, 7: size, 8: floor, 9: ceiling, 10: height, 11: exit\n");
                scanf("%d", &t);

                switch (t) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        bs_put(&bst, x);
                        break;
                case 2:
                        printf("Xandax utga: ");
                        scanf("%d", &x);
                        p = bs_get(&bst, x);
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
                        bs_del(&bst, x);
                        break;
                case 4:
                        if (bst.root) {
                                x = bs_delMin(&bst);
                                printf("Ustgasan xamgiin baga utga: %d\n", x);
                        } else
                                printf("Mod xooson\n");
                        break;
                case 5:
                        bs_inorder(&bst);
                        break;
                case 6:
                        printf("Rank olox utga: ");
                        scanf("%d", &x);
                        y = bs_rank(&bst, x);
                        printf("Rank(%d): %d\n", x, y);
                        break;
                case 7:
                        printf("Xemjee olox utga: ");
                        scanf("%d", &x);
                        y = bs_size(&bst, x);
                        printf("Size(%d): %d\n", x, y);
                        break;
                case 8:
                        printf("Dood buxel olox utga: ");
                        scanf("%d", &x);
                        p = bs_floor(&bst, x);
                        if (p != NULL)
                                printf("Floor(%d): %d\n", x, p->x);
                        else
                                printf("odlsongui\n");
                        break;
                case 9:
                        printf("Deed buxel olox utga: ");
                        scanf("%d", &x);
                        p = bs_ceiling(&bst, x);
                        if (p != NULL)
                                printf("Ceiling(%d): %d\n", x, p->x);
                        else
                                printf("odlsongui\n");
                        break;
                case 10:
                        printf("Undur olox utga: ");
                        scanf("%d", &x);
                        y = bs_height(&bst, x);
                        printf("Height(%d): %d\n", x, y);
                        break;
                case 11:
                        exit(0);
                default:
                        break;
                }
        }
        return 0;
}
