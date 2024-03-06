#include "DS.h"

int main()
{
	RBT rbt;
        rbt.root = NULL;
        Elm *p;
        int n, i;
        scanf("%d", &n);
        char cmd[5];
        Student x;

        for (i = 0; i < n; i++) {
                scanf("%s", cmd);
                if (strcmp(cmd, "PUT") == 0) {
                        // PUT командаар RBT-д оруулна
                        scanf("%s%s%d%f", x.name, x.id, &x.age, &x.gpa);
			rb_put(&rbt, &x);
                } else if (strcmp(cmd, "GET") == 0) {
                        // GET командаар RBT-ээс хайна
			scanf("%s", x.id);
			p = rb_get(&rbt, x.id);
			print(p);
                } else if (strcmp(cmd, "DEL") == 0) {
			scanf("%s", x.id);
			rb_del(&rbt, x.id);
		}
        }
        return 0;
}