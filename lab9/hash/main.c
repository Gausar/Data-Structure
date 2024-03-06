#include "DS.h"

int main()
{
        HashTable htable;
        ht_init(&htable);
        
        int n, i, j, m;
        FILE *fin;
        fin = fopen("student.info", "r");
        if (fin == NULL) {
                printf("student.info file oldsongui\n");
                exit(1);
        }
        fscanf(fin, "%d", &n);
        Student x, *p;
        for (i = 0; i < n; i++) {
                fscanf(fin, "%s%s%s", x.ovog, x.ner, x.id);
                ht_insert(&htable, x);
        }
        fclose(fin);
        fin = fopen("input.txt", "r");
        char cmd[10];
        fscanf(fin, "%d", &m);
        FILE *fout = fopen("output.txt", "w");

        for (i = 0; i < m; i++) {
                fscanf(fin, "%s", cmd);
                if (strcmp(cmd, "search") == 0) {
                        fscanf(fin, "%s", x.id);
                        p = ht_search(&htable, x.id);
                        student_print(fout, p);
                } else if (strcmp(cmd, "update") == 0) {
                        fscanf(fin, "%s%s%s", x.ovog, x.ner, x.id);
                        ht_update(&htable, x);
                } else if (strcmp(cmd, "delete") == 0) {
                        fscanf(fin, "%s", x.id);
                        ht_del(&htable, x.id);
                }
        }
        fclose(fin);
        fclose(fout);
        ht_release(&htable);
        return 0;
}
