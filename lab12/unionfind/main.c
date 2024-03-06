#include "DS.h"

int a[10000][10000] ; // Бүх нүд хаалттай эсэх мэдээллийг хадгалах хүснэгт
int n, m ;


int available(int a, int b){ //Боломжтой эсэхийн шалгана
	if (a >= 0 & b >= 0 & a < n & b < n){
		return 1 ;
	}
	else {
		return 0 ;
	}

}
int main()
{
	int x, y;
	scanf("%d%d", &n, &m);

	WeightedUF uf;
	uf_init(&uf, n * n + 2);          // Нэмэлт 2 хийсвэр оройг нэмнэ.
	// Цаашаа үргэлжүүлэн бичнэ үү!
    
	for(int i = 1 ; i <= m  ; i++){

		scanf("%d %d", &x, &y) ;
	// buh nud haalttai ehleh ystoi
		a[x][y] = 1 ;
		if (x == 0){
			uf_union(&uf, y+1, 0) ;
		}
		if (x == n -1){
			uf_union(&uf, n*x+y+1, n*n+1) ;
		}
		/* Бүгд нийлсэн байгаа хэсгээр дамжина */
		if (available(x + 1, y) && a[x+1][y]){
			uf_union(&uf, n * x + y + 1, n * x + n + y + 1) ;
		}

		if (available(x - 1, y) && a[x-1][y]){
			uf_union(&uf, n * x +y + 1, n * x - n + y + 1) ;
		
		}

		if (available(x, y + 1) && a[x][y+1]){
			uf_union(&uf, n * x + y + 1, n * x + y + 2) ;
		}

		if (available(x, y - 1) && a[x][y-1]){
			uf_union(&uf, n * x + y + 1, n * x + y) ;
		}

		if (uf_find(&uf, n * n + 1) == 0){ //uf_connected(&uf, n * n + 1, 0)
			printf("%d\n", i) ;
			return 0;
		}	
	}

	printf("-1\n") ;
	return 0;
}