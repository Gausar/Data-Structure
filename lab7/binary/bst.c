#include "DS.h"
void delMin(Elm *p,Elm *pre);
Elm *del(Elm *p,int x);
void inorder(Elm *p);
Elm *ceiling(Elm *p ,int x);
Elm *floor1(Elm *p,int x);
int rank(Elm *p,int x);
int size(Elm *p);
Elm *ceiling(Elm *p ,int x);
Elm *new(int x){
        Elm * node = (Elm *)malloc(sizeof(Elm));
        node->x = x;
        node->height = 1;
        node->len = 1;
        node->L = NULL;
        node->R = NULL;
        return node;
}

/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Оруулахдаа хоёртын хайлтын модны зарчмаар оруулах бөгөөд оруулсан
  байрлалаас дээшхи өвөг эцгийн `len`, `height` утгууд өөрчлөгдөнө.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
 */
void put(Elm *p,int x){
	if(p->x < x) 
	{	
                put(p->R, x);
                p->len++;
                if(p->L == NULL) {
                        p->height = p->R->height + 1;    
                }
                else if (p->L->height < p->R->height)
                {
                        p->height = p->R->height + 1;
                }
                else return;
	}
	else if(p->x > x ){
		put(p->L, x);
		p->len++;
		if(p->R == NULL){
			p->height = p->L->height + 1;
		   
		}
		else if(p->L->height > p->R->height)
		{
			   p->height = p->L->height + 1;
			   
		}
		else return ;
	}
	else return ;
}

void bs_put(BST *ptree, int x)
{
        Elm *p = ptree->root , *pre = NULL, *n;
    
        while(p != NULL){
                pre = p;
                if(p->x < x){
                        p = p->R;
                }
                else p = p->L;
	}
	p = (Elm *)malloc(sizeof(Elm));
   	p->x = x;
   	p->L = p->R = NULL;
	p->len = 1;
	p->height = 1;
        if(pre == NULL){
    	        ptree->root=p;
	}
	else{
		if(pre->x < x) {
			pre->R = p;
	                put(ptree->root, x);
		} 
		else {
			pre->L = p;
		  	put(ptree->root, x);
	 	}
	}
}
/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *bs_get(const BST *ptree, int x)
{ 
        Elm *p = ptree->root, *pre = NULL;
        while (p != NULL){
                if(p->x == x){
                        break ;
                }
                else if(p->x < x){
                        p = p->R;
                }
                else  p = p->L;	
        }
        return p;
}

/*
  Устгах функц: ХХМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
 */

Elm *del(Elm *p,int x )
{
    if(p->x < x){
    	    p->R = del(p->R,x);
	    	--p->len;
			if(p->L == NULL && p->R == NULL){
                p->height=1;
            }
			else if( p->R == NULL){
				p->height = p->L->height + 1;
            }
			else if(p->L == NULL ){
                p->height = p->R->height + 1;
            }
			else if(p->L->height > p->R->height){
                p->height = p->L->height + 1;
            } 
			else {
                p->height = p->R->height + 1;
            }		
	}
    else if(p->x > x){
        p->L = del(p->L,x);
        --p->len;
        if(p->L == NULL && p->R == NULL){
            p->height = 1;
        } 
        else if( p->R == NULL){
            p->height = p->L->height + 1;
        }
        else if(p->L == NULL ) {
            p->height = p->R->height + 1;
        }
        else if(p->L->height > p->R->height){
                p->height = p->L->height + 1;
        }
        else{
            p->height = p->R->height + 1;
        } 
    }
    else{
        if( p->L == NULL && p->R == NULL){
            free(p);
            return NULL;
        }
        else if(p->L == NULL){
            Elm *temp = p->R;
            free(p);
            return temp;
        }
        else if(p->R == NULL){
            Elm *temp = p->L;
            free(p);
            return temp;
        }
        else
        {
            Elm	*t = p->R;
           	while(t->L != NULL) t = t->L;
           	int tmp = t->x;
            p->x = tmp;
            p->R = del(p->R,tmp);
            
            p->len--;
            
			if(p->L == NULL && p->R != NULL){ 
                p->height = p->R->height + 1;
            }
			else if(p->L == NULL && p->R == NULL){
                p->height = 1;
            }
			else if(p->L != NULL && p->R == NULL){
                p->height = p->L->height + 1;
            }
			else if(p->L->height > p->R->height){
                p->height = p->L->height + 1;
            }
			else p->height = p->R->height + 1;
        }
    }
    return p;
}
void bs_del(BST *ptree, int x)
{
		Elm *p=ptree->root,*pre=NULL;
     	while (p != NULL){
            if(p->x == x){
                break ;
            }
            else if(p->x < x){
                p = p->R;
            }
            else  p = p->L;	
    	}
    	if(p == NULL){
            return ;
        }
    	else ptree->root = del(ptree->root, x);
}

/*
  Хамгийн багыг устгах функц: ХХМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
 */
void delMin(Elm *p,Elm *pre){
	if(p->L == NULL) {
	  	pre->L = p->R;
	  	free(p);
	  	return;
	}
	else {
        delMin(p->L,p);
        if(p->R == NULL && p->L == NULL){
            p->height = 1;
        }
        else if(p->R == NULL && p->L != NULL){
            p->height = p->L->height + 1;
        }
        else if(p->R != NULL && p->L == NULL){
            p->height = p->R->height + 1;
        }
        else if(p->L->height > p->R->height){
            p->height = p->L->height + 1;
        }
        else p->height = p->R->height + 1;
        return;
	}
}

int bs_delMin(BST *ptree)
{
    Elm *p = ptree->root, *pre = NULL;
	int n;
	while(p->L != NULL){
		pre = p;
		p = p->L;
	}
	n = p->x;
	if(pre == NULL){
        if(p->R != NULL && p->L == NULL) {
            ptree->root = p->R;
            free(p);
            return n;
        }
        else if( p->L == NULL && p->R == NULL){
            ptree->root = NULL;
            free(p);
            return n;
        }
	}
	else delMin(ptree->root, NULL);
	return n;
}


/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void inorder(Elm *p)
{
	if(p != NULL){
		inorder(p->L);
		printf("%d %d %d\n", p->x, p->len, p->height);
		inorder(p->R);
	}
}
void bs_inorder(const BST *ptree)
{
  inorder(ptree->root);
}

/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */
int rank(Elm *p,int x){
	if(p == NULL){
                return 0;
        }
	if(p->x < x){
                return 1 + size(p->L) + rank(p->R,x);
        }
	else if(x < p->x){
                return  rank(p->L, x);
        }
	else return 1 + size(p->L);
}
int bs_rank(const BST *ptree, int x)
{
    Elm *p = ptree->root;
    return rank(ptree->root, x);
}

/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int size(Elm *p){
	if(p == NULL){
                return 0;
        }
	return p->len;
}
int bs_size(const BST *ptree, int x)
{
        Elm *p=ptree->root;
	while(p != NULL)
	{
		if(p->x == x){
                        return size(p);
                }
		if(p->x < x){
                        p = p->R;
                }
		else p = p->L;
	}
	return -1;    
}


/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *floor1(Elm *p, int x)
{
	if(p == NULL){
                return NULL;
        }
	if(p->x == x){
                return p;
        }
	if(p->x > x){
                return floor1(p->L, x);
        }
	Elm *n = floor1(p->R, x);
	if(n != NULL){
                return n;
        }
	else return p;
}
Elm *bs_floor(const BST *ptree, int x)
{
  	Elm *p = floor1(ptree->root, x);
	if(p == NULL){
                return NULL;
        }
	return p;   
}
/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *ceiling(Elm *p ,int x){
	if(p == NULL){
                return NULL;
        }
	if(p->x == x){
                return p;
        }
	if(p->x < x){
                return ceiling(p->R, x);
        }
	
	Elm *n = ceiling(p->L, x);
	if(n != NULL){
                return n;
        }
	else return p;
}
Elm *bs_ceiling(const BST *ptree, int x)
{
    Elm *p = ceiling(ptree->root, x);
	if(p == NULL){
                return NULL;
        }
	return p;
}
/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */

int bs_height(const BST *ptree, int x)
{
  	Elm *p = ptree->root, *pre = NULL;
	while (p != NULL){
		if(p->x == x){
                        break ;
                }
		else if(p->x < x) {
			pre = p;
			p = p->R;
		}
		else {
			pre = p;
			p = p->L;
		} 
	}
	if(p == NULL){
        return -1;
    }
	else return p->height;    
}