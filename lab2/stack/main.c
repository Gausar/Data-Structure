#include "DS.h"

int main()
{
        int x, t, ds, pos;
        List l;
        Queue q;
        Stack s;
        l.l_len = q.q_len = s.s_len = 0;
        while (1) {
                printf("1. Stack, 2. Queue, 3. List, 4. Exit\n");
                scanf("%d", &ds);
                if (ds == 4)
                        break;
                int done = 0;
                while (!done) {
                        printf("1: push (back), 2: pop (back), 3: print, "
                               "4: push_front, 5: insert, 6: pop_front, "
                               "7: erase, 8: search, 9: exit\n");
                        scanf("%d", &t);

                        switch (t) {
                        case 1:
                                printf("Oruulax utga: ");
                                scanf("%d", &x);
                                if (ds == 1)
                                        s_push(&s, x);
                                else if (ds == 2)
                                        q_push(&q, x);
                                else
                                        l_push_back(&l, x);
                                break;
                        case 2:
                                if (ds == 1)
                                        s_pop(&s);
                                else if (ds == 2)
                                        q_pop(&q);
                                else
                                        l_pop_back(&l);
                                break;
                        case 3:
                                if (ds == 1)
                                        s_print(&s);
                                else if (ds == 2)
                                        q_print(&q);
                                else
                                        l_print(&l);
                                break;
                        case 4:
                                if (ds == 1 || ds == 2)
                                        printf("Aldaa: Iim uildel xiix bolomjgui\n");
                                else {
                                        printf("Oruulax utga: ");
                                        scanf("%d", &x);
                                        l_push_front(&l, x);
                                }
                                break;
                        case 5:
                                if (ds == 1 || ds == 2)
                                        printf("Aldaa: Iim uildel xiix bolomjgui\n");
                                else {
                                        printf("Oruulax utga: ");
                                        scanf("%d", &x);
                                        printf("Oruulax bairlal: ");
                                        scanf("%d", &pos);
                                        l_insert(&l, x, pos);
                                }
                                break;
                        case 6:
                                if (ds == 1)
                                        printf("Aldaa: Iim uildel xiix bolomjgui\n");
                                else {
                                        if (ds == 2)
                                                q_pop(&q);
                                        else
                                                l_pop_front(&l);
                                }
                                break;
                        case 7:
                                if (ds == 1 || ds == 2)
                                        printf("Aldaa: Iim uildel xiix bolomjgui\n");
                                else {
                                        printf("Gargax bairlal: ");
                                        scanf("%d", &pos);
                                        l_erase(&l, pos);
                                }
                                break;
                        case 8:
                                if (ds == 1 || ds == 2)
                                        printf("Aldaa: Iim uildel xiix bolomjgui\n");
                                else {
                                        printf("Xaix utga: ");
                                        scanf("%d", &x);
                                        printf("Oldson bairlal: %d\n", l_search(&l, x));
                                }
                                break;
                        case 9:
                                done = 1;
                                break;
                        default:
                                break;
                        }
                }
        }
        return 0;
}
