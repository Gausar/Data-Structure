#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int case_insensitive = 0;

int Q = 1299709;
int R = 256;
int RM = 1;
/*
  s тэмдэгтэн цувааны hash-ыг буцаана
 */
int hash(const char *s)
{       
        int m = strlen(s);
        long h = 0;
        for(int j = 0; j < m; j++){
                char d = s[j];
                if(case_insensitive == 1){
                        d = tolower(d);
                }
                h = (h * R + d) % Q;
        }
        return h;
}

/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцанаа.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++

  buf     :    Хайлт хийх тэмдэгтэн цуваа
  n       :    buf-ын урт
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  m       :    pattern-ны урт
  pat_hash:    pattern хэвийн hash
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int buh_temdeg_taarah(const char *buf, const char *patt, int i){
        for(int k = 0 ; k < strlen(patt); k++){
                char t = patt[k];
                char s = buf[i + k];
                if(case_insensitive == 1){
                        t = tolower(t);
                        s = tolower(s);
                }
                if (t != s){
                        return 0; 
                }
        }
        return 1 ;
}
int find(const char *buf, int n, int index, const char *pattern, int m, int pat_hash, int *pline)
{
        int txt_hash = 0 ;
        for(int i = index ; i < m  + index; i++){
                char t = buf[i];
                if(case_insensitive == 1){
                        t = tolower(t);
                }
                txt_hash = (txt_hash * R + t) % Q ;
        }

        if((pat_hash == txt_hash) && buh_temdeg_taarah(buf, pattern, index)){
                return index;
        }
        for(int i = index + m; i < n; i++){    
                char t = buf[i - m];
                char s = buf[i];
                if(case_insensitive == 1){
                        t = tolower(t);
                        s = tolower(s);
                }           
                txt_hash = (txt_hash + Q - RM * t % Q) % Q;
                txt_hash = (txt_hash * R + s) % Q;
                if(t == '\n'){
                        (*pline)++;
                }
                int a = i - m + 1;
                if((txt_hash == pat_hash) && buh_temdeg_taarah(buf, pattern, a)){
                        return a;
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
        } else
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
        buf[len - 1] = 0;              /* тэмдэгт мөр төгсгөл заагч */

        int ret = -1;
        int line = 0;
        int pat_hash = hash(pattern);  // hash кодыг тооцоолно
        int m = strlen(pattern);

        for(int i = 1; i < m; i++){
                RM = (RM * 256) % Q;
        }
        
        do {
                ret = find(buf, len - 1, ret + 1, pattern, m, pat_hash, &line);
                if (ret != -1) {
                        printf("%d: ", line);
                        /*
                          Олдсон газраас доошоо 5
                          дээшээ 5 тэмдэгтийг хэвлэнэ.
                         */
                        int L = ret - 5;
                        int R = ret + strlen(pattern) + 5;
                        if (L < 0) L = 0;
                        if (R >= len) R = len - 1;
                        for (i = L; i <= R; i++)
                                printf("%c", buf[i]);
                        printf("\n");
                }
        } while (ret != -1);

        free(buf);
        return 0;
}
