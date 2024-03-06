#include "DS.h"

static void swim(Heap *p, int);
static void sink(Heap *p, int);

/*
  Хоёр зурвасын чухлыг харьцуулах функц.
  b нь илүү чухал бол 1, бусад үед 0-ыг буцаах функц.
  Өөрөөр хэлбэл a < b үйлдэл юм.
*/
int less(const Msg *a, const Msg *b)
{
        // Энд жиших үйлдийг хийнэ
        if(a->priority < b->priority){
                return 1;
        }
        else if(a->priority == b->priority){
                if(a->time < b->time){
                        return 1;
                }
                else return 0;
        }
        else return 0;
}

/*
  Оруулах функц. heap зарчмаар чухлын дарааллыг баримтлан оруулна.
  Ингэхдээ хамгийн чухал зурвас heap-ын оройд хадгалагдана.
  x зурвасыг p-ын зааж буй heap бүтцэд оруулна.
 */
void insert(Heap *p, const Msg x)
{
        // Энд оруулах үйлдлийг хийнэ
        p->heap.a[p->heap.len] = x;
        swim(p, p->heap.len);
        p->heap.len++;
}

/*
  Heap бүтцийн swim үйлдэл.
  k нь swim үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void swim(Heap *p, int k)
{
        // Энд swim үйлдлийг хийнэ
        while(k > 0){
                int parent = (k - 1)/2;

                if(less(&p->heap.a[k], &p->heap.a[parent])){
                        Msg temp = p->heap.a[k];
                        p->heap.a[k] = p->heap.a[parent];
                        p->heap.a[parent] = temp;
                        k = parent;
                }
                else{
                        break;
                }
        } 
}

/*
  Heap бүтцийн sink үйлдэл.
  k нь sink үйлдлийг p-ын зааж буй heap дээр эхлүүлэх индекс.
 */
static void sink(Heap *p, int k)
{
        // Энд sink үйлдлийг хийнэ
        while(1){
                int left = 2 * k + 1;
                int right = 2 * k + 2;
                int min = k;

                if(left < p->heap.len && less(&p->heap.a[left], &p->heap.a[min])){
                        min = left;
                }
                if(right < p->heap.len && less(&p->heap.a[right], &p->heap.a[min])){
                        min = right;
                }

                if(min != k){
                        Msg temp = p->heap.a[k];
                        p->heap.a[k] = p->heap.a[min];
                        p->heap.a[min] = temp;
                        k = min;
                }
                else{
                        break;
                }
        }
}

/*
  p-ын зааж буй heap бүтцээс оройн элементийг гаргаад буцаах функц.
  Гаргасны дараа орой бүрийн хувьд heap зарчим хадгалах ёстой.
 */
Msg delMin(Heap *p)
{
        // Энд хамгийн багыг гаргах үйлдлийг хийнэ
        if(p->heap.len == 0){
                Msg emptyMsg = {"", 0, 0};
                return emptyMsg;
        }
        Msg min = p->heap.a[0];
        p->heap.len--;
        p->heap.a[0] = p->heap.a[p->heap.len];

        sink(p, 0);
        return min;
}

