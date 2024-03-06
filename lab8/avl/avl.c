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
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
int height(Elm *root){
        if(root == NULL){
                return 0;
        }
        return root->height;
}
int max(int a, int b){
        return (a > b) ? a : b;
}
Elm *rightRotation(Elm *root){
        Elm *x = root->L;
        Elm *T2 = x->R;

        x->R = root;
        root->L = T2;

        root->height = max(height(root->L), height(root->R)) + 1;

        x->height = max(height(x->L), height(x->R)) + 1;
        
        root->len = 1 + (root->L != NULL ? root->L->len : 0) + (root->R != NULL ? root->R->len : 0);
        
        x->len = 1 + (x->L != NULL ? x->L->len : 0) + (x->R != NULL ? x->R->len : 0);

        return x;
}
Elm *leftRotation(Elm *root){
        Elm *y = root->R;
        Elm *T2 = y->L;

        y->L = root;
        root->R = T2;

        root->height = max(height(root->L), height(root->R)) + 1;
        y->height = max(height(y->L), height(y->R)) + 1;

        root->len = 1 + (root->L != NULL ? root->L->len : 0) + (root->R != NULL ? root->R->len : 0);
        y->len = 1 + (y->L != NULL ? y->L->len : 0) + (y->R != NULL ? y->R->len : 0);

        return y;
}
int getBalance(Elm *N){
        if(N == NULL){
                return 0;
        }
        return height(N->L) - height(N->R);
}
Elm *insert(Elm *root, int x){
        if(root == NULL){
                return new(x);
        }
        if(x < root->x){
                root->L = insert(root->L, x);
                //root->len++;
        }
        else if(x > root->x){
                root->R = insert(root->R, x);
                //root->len++;
        }
        else{
                return root;
        }
        root->height = 1 + max(height(root->L), height(root->R));

        root->len = 1 + (root->L != NULL ? root->L->len : 0) + (root->R != NULL ? root->R->len : 0);
        
        int balance = getBalance(root);

        if(balance > 1 && x < root->L->x){
                return rightRotation(root);
        }
        if(balance < -1 && x > root->R->x){
                return leftRotation(root);
        }
        if(balance > 1 && x > root->L->x){
                root->L = leftRotation(root->L);
                return rightRotation(root);
        }
        if(balance < -1 && x < root->R->x){
                root->R = rightRotation(root->R);
                return leftRotation(root);
        }
        return root;
}
void avl_put(AVL *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root == NULL){
                ptree->root = new(x);
        }
        else{
                ptree->root = insert(ptree->root, x);
        }
}

/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */
Elm *avl_get(const AVL *ptree, int x)
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
  Устгах функц: ТМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
Elm *minValue(Elm *root){
        Elm *current = root;
        while(current->L != NULL){
                current = current->L;
        }
        return current;
}
int size2(Elm *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + size2(root->L) + size2(root->R);
}
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
        int balance = getBalance(p);

        if(balance > 1 && getBalance(p->L) >= 0){
                return rightRotation(p);
        }
        if(balance > 1 && getBalance(p->L) < 0){
                p->L = leftRotation(p->L);
                return rightRotation(p);
        }
        if(balance < -1 && getBalance(p->R) <= 0){
                return leftRotation(p);
        }
        if(balance < -1 && getBalance(p->R) > 0){
                p->R = rightRotation(p->R);
                return leftRotation(p);
        }
        return p;
}

void avl_del(AVL *ptree, int x)
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
  Хамгийн багыг устгах функц: ТМноос хамгийг бага утгыг нь устгах функц.
  Устгасан утгыг буцаана.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
int deleteMIN(Elm *root, Elm *parent){
        if(root->L == NULL){
                int min_val = root->x;
                if(parent != NULL){
                        parent->L = root->R;
                }
                free(root);
                return min_val;
        }
        else{
                return deleteMIN(root->L, root);
        }
        root->height = 1 + max(height(root->L), height(root->R));
        int balance = getBalance(root);

        if(balance > 1 && getBalance(root->L) >= 0){
                rightRotation(root);
        }
        if(balance > 1 && getBalance(root->L) < 0){
                root->L = leftRotation(root->L);
                rightRotation(root);
        }
        if(balance < -1 && getBalance(root->R) <= 0){
                leftRotation(root);
        }
        if(balance < -1 && getBalance(root->R) > 0){
                root->R = rightRotation(root->R);
                leftRotation(root);
        }
        
}
int avl_delMin(AVL *ptree)
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
                min_val = deleteMIN(ptree->root->L, ptree->root);
                ptree->root->len--;
        }
        return min_val;
}

/*
  ТМыг inorder дарааллаар, нэг мөрөнд нэг утга хэвлэнэ.
 */
void inorder(Elm *root){
        if(root != NULL){
                
                inorder(root->L); 
                printf("%d %d %d\n", root->x, root->len, root->height);
                inorder(root->R);
        }
}
void avl_inorder(const AVL *ptree)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root != NULL){
                inorder(ptree->root);
        }  
}

/*
  ТМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модонд хэдэн орой байгааг олж буцаана.
  Олдохгүй бол -1-ийг буцаана.
 */
int size(Elm *root, int x){
        if(root == NULL){
                return -1;
        }
        if(root->x == x){
                return root->len;
        }
        else if(root->x > x){
                return size(root->L, x);
        }
        else if(root->x < x){
                return size(root->R, x);
        }
        return -1;
}
int avl_size(const AVL *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root == NULL){
                return -1;
        }
        return size(ptree->root, x);
        
}

/*
  ТМноос `x` утгатай оройг хайж олоод, тухайн оройд суурилсан
  дэд модны өндөр хэд байгааг олж буцаана. Олдохгүй бол -1-ийг буцаана.
 */
int height_AVL(Elm *root, int x){
        if(root == NULL){
                return -1;
        }
        if(x == root->x){
                return root->height;
        }
        else if(x < root->x){
                return height_AVL(root->L, x);
        }
        else if(x > root->x){
                return height_AVL(root->R, x);
        }
        return -1;
}
int avl_height(const AVL *ptree, int x)
{
        // Функцийг хэрэгжүүлнэ үү
        if(ptree->root == NULL){
                return -1;
        }
        return height_AVL(ptree->root, x);
}
