#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int case_insensitive = 0;

/*
  DFA хүснэгтийг байгуулах функц
 */
void KMP(const char *pattern, int *dfa[], int R)
{
        int M = strlen(pattern);
        
        dfa[pattern[0]][0] = 1;
        int x = 0;
        for(int j = 1; j < M; j++){
                char s = pattern[j];
                if(case_insensitive == 1){
                        s = tolower(s);
                }
                for(int c = 0; c < R; c++){
                        dfa[c][j] = dfa[c][x];
                }
                dfa[s][j] = j + 1;
                x = dfa[s][x];
        }
}

/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцанаа.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++

  buf     :    Хайлт хийх тэмдэгтэн цуваа
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  dfa     :    dfa хүснэгт
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int find(const char *buf, int index, const char *pattern, int *dfa[], int *pline)
{
        int i, j = 0;
        int m = strlen(pattern);
        int n = strlen(buf);
        
        for(i = index; i < n; i++){

                char d = buf[i];
                if(case_insensitive == 1){
                        d = tolower(d);
                }
                if(buf[i] == '\n'){
                        (*pline)++;
                }

                j = dfa[d][j];
                if(j == m){
                        if(m == 0){
                                return i;
                        }
                        else{
                                return i - m + 1;
                        }
                }
        }
        return -1;
        
}

int main(int argc, char *argv[])
{
        // Аргументийн тоо ядаж 3 байх ёстой.
        if (argc < 3) {
                printf("%s [-i] pattern FILE", argv[0]);
                exit(-1);
        }

        const char *pattern;
        if (argc > 3 && strcmp("-i", argv[1]) == 0) {
                case_insensitive = 1; // Том жижгийг хайхрахгүй адил гэж үзнэ.
                pattern = argv[2];
        } 
        else
                pattern = argv[1];

        FILE *fin;
        fin = fopen(argv[argc - 1], "r");
        if (fin == NULL) {
                printf("Error openning %s file", argv[argc - 1]);
                exit(-1);
        }
        int len = 0;
        char ch;                 
        while (!feof(fin)) {
                ch = fgetc(fin);
                len++;          // Файлд доторх тэмдэгтүүдийг тоолъё.
        }
        char *buf;
        buf = (char *) malloc(sizeof(char) * (len + 1)); // Энд тэмдэгтүүдийг хадгална
        fseek(fin, 0, SEEK_SET);                        // Файл заагчийг буцаад эхлэлд нь аваачна.
        int i = 0;
        while (!feof(fin))
                buf[i++] = fgetc(fin); // Өгөгдлийг уншиж байна.
        buf[len - 1] = '\0';              /* тэмдэгт мөр төгсгөл заагч */
        int ret = -1;
        int line = 0;


        int R = 256;
        int *dfa[R];
        for (i = 0; i < R; i++)
                dfa[i] = (int *) malloc(sizeof(int) * strlen(pattern));
        KMP(pattern, dfa, R);

        do {
                ret = find(buf, ret + 1, pattern, dfa, &line);
                if (ret != -1) {
                        printf("%d: ", line);
                        /*
                          Олдсон газраас доошоо 5
                          дээшээ 5 тэмдэгтийг хэвлэнэ.
                         */
                        int L = ret - 5;
                        int R = ret + strlen(pattern) + 5;
                        if (L < 0) L = 0;
                        if (R >= strlen(buf)) R = strlen(buf);
                        for (i = L; i <= R; i++)
                                printf("%c", buf[i]);
                        printf("\n");
                }
        } while (ret != -1);


        for (i = 0; i < R; i++)
                free(dfa[i]);
        free(buf);
        return 0;
}
