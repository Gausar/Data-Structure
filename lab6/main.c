#include "DS.h"
#include <stdio.h>

// Том санах ой эзлэх хувьсагчийг функцыг дотор заралах нь
// стакын хэмжээг дүүргэдэг. Заримдаа багтдаггүй тул
// глобалаар зарлав.
Heap hp;        // Heap бүтэц 100000 x sizeof(Msg) хэмжээ эзлэнэ

int main()
{
        int n, i;
        scanf("%d", &n);
        char cmd[5];
        Msg x;

        for (i = 0; i < n; i++) {
                scanf("%s", cmd);
                if (strcmp(cmd, "PUT") == 0) {
                        // PUT командаар heap-д оруулна
                        scanf("%s%d", x.text, &x.priority);
                        x.time = i;
                        insert(&hp, x);
                } else if (strcmp(cmd, "GET") == 0) {
                        // GET командаар heap-ээс гаргана
                        x = delMin(&hp);
                        printf("%s\n", x.text);
                }
        }
        return 0;  // EXIT 0 амжилттай дууслаа
}
