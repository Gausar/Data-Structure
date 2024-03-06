#include "DS.h"

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
void bs_put2(Elm * root, int x){
        if(x < root->x){
                if(root->L == NULL){
                        root->L = new(x);
                }
                else{
                        bs_put2(root->L, x);        
                }
        }
        else if(x > root->x){
                if(root->R == NULL){
                        root->R = new(x);
                }
                else{
                        bs_put2(root->R, x);       
                }
        }
        root->len++;

        int leftHeight = (root->L == NULL) ? 0 : root->L->height;
        int rightHeight = (root->R == NULL) ? 0 : root->R->height;

        root->height = (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
void bs_put(BST *ptree, int x)
{
        if(ptree->root == NULL){
                ptree->root = new(x);
        }
        else{
                bs_put2(ptree->root, x);
        }     
}
/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *bs_get(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        Elm *current = ptree->root;
        while(current != NULL){
                if(x == current->x){
                        return current;
                }
                else if(x < current->x){
                        current = current->L;
                }
                else{
                        current = current->R;
                }
        }
        return NULL;
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
                        Elm *t = p->R;
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
int bs_delMin2(Elm *root, Elm *parent){
        if(root->L == NULL){
                int min_val = root->x;
                if(parent != NULL){
                        parent->L = root->R;
                }
                free(root);
                return min_val;
        }
        else{
                return bs_delMin2(root->L, root);
        }
}
int bs_delMin(BST *ptree)
{
        // Функцийг хэрэгжүүлнэ үү
        int min_val;
        if(ptree->root->L == NULL){
                min_val = ptree->root->x;
                Elm *temp = ptree->root;
                ptree->root = ptree->root->R;
                free(temp);
        }
        else{
                min_val = bs_delMin2(ptree->root->L, ptree->root);
        }
        return min_val;
}

/*
  ХХМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void bs_inorder2(const Elm *root){
        if(root != NULL){
                if(root->L != NULL){
                        bs_inorder2(root->L);
                } 
                printf("%d %d %d\n", root->x, root->len, root->height);
                if(root->R != NULL){
                        bs_inorder2(root->R);
                } 
        }
}
void bs_inorder(const BST *ptree)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree != NULL){
                bs_inorder2(ptree->root);
        }
}

/*
  ХХМноос `x` утгаас эрс бага буюу тэнцүү байх хэдэн орой байгааг олж буцаана.
  Өөрөөр хэлбэл хоёртын хайлтын модны утгуудыг өсөх дарааллаар байрлуулбал
  `x`-ийг оролцуулаад өмнө хэдэн тоо байх вэ? гэсэн үг.
  `x` утга заавал модонд байх албагүй.
 */

int rank(Elm *p, int x) {
    if (p == NULL) {
        return 0;
    }
    if (p->x < x) {
        return 1 + size(p->L) + rank(p->R, x);
    } else if (x < p->x) {
        return rank(p->L, x);
    } else {
        return 1 + size(p->L);
    }
}

int bs_rank(const BST *ptree, int x) {
    Elm *p = ptree->root;
    return rank(ptree->root, x);
}

int size(Elm *p) {
    if (p == NULL) {
        return 0;
    }
    return p->len;
}


/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */

int bs_size2(const Elm *root, int x){
        if(root == NULL){
                return -1;
        }
        if(root->x == x){
                return root->len;
        }
        else if(root->x > x){
                return bs_size2(root->L, x);
        }
        else if(root->x < x){
                return bs_size2(root->R, x);
        }
        return -1;
}
int bs_size(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root == NULL){
                return -1;
        }
        return bs_size2(ptree->root, x);
}


/*
  XXMноос `x`-ээс бага буюу тэнцүү байх хамгийн их утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *findfloor(Elm *root, int x, Elm *prevfloor){
        if (root == NULL) {
                return prevfloor;
        }
        if (x == root->x) {
                return root;
        }
        if (x < root->x) {
                return findfloor(root->L, x, prevfloor);
        }
        return findfloor(root->R, x, root);
}

Elm *bs_floor(const BST *ptree, int x)
{
     // Функцийг хэрэгжүүлнэ үү
        if(ptree == NULL || ptree->root == NULL){
                return NULL;
        }
        else{
                return findfloor(ptree->root, x, NULL);
        }
        
}
/*
  XXMноос `x`-ээс их буюу тэнцүү байх хамгийн бага утгын `Elm *` хаягийг олж буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
 */
Elm *findCeiling(Elm *root, int x, Elm *prevCeiling) {
        if (root == NULL) {
                return prevCeiling;
        }
        if (x == root->x) {
                return root;
        }
 
        if (x > root->x) {
                return findCeiling(root->R, x, prevCeiling);
        }
        return findCeiling(root->L, x, root);
}
Elm *bs_ceiling(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree == NULL || ptree->root == NULL){
                return NULL;
        }
        return findCeiling(ptree->root, x, NULL);
 
}


/*
  ХХМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */

int bs_height2(const Elm *root, int x){
        if(root == NULL){
                return -1;
        }
        if(x == root->x){
                return root->height;
        }
        else if(x < root->x){
                return bs_height2(root->L, x);
        }
        else if(x > root->x){
                return bs_height2(root->R, x);
        }
        return -1;
}
int bs_height(const BST *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root == NULL){
                return -1;
        }
        return bs_height2(ptree->root, x);
}