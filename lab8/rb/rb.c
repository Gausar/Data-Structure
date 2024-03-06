#include "DS.h"
#include<assert.h>

/*
  Хоёр оюутны мэдээллийн хооронд нь харьцуулах функц
*/
int less(const Student *a, const Student *b)
{
	if (strcmp(a->id, b->id) < 0){
                return 1 ;
        }
        return 0;
}
int color(Elm *node){
        if(node==NULL) return 0;
        return node->color == 1;
        //red=1, black =0;

}
Elm *rotateLeft(Elm *node){
        if(color(node->R)){
                Elm *temp = node->R;
                node->R = temp->L;
                temp->L = node;
                temp->color = node->color;
                node->color = 1;
                return temp;     
        }
        return node;
}
Elm* rotateRight(Elm* node){
    if(color(node->L) && color(node->L->L)){
        Elm* temp = node->L;
        node->L = temp->R;
        temp->R = node;
        temp->color = node->color;
        node->color = 1;
        return temp;
    }
    return node;
}
void flipColor(Elm *node){
        node->color = 1;
        node->L->color = 0;
        node->R->color = 0;
}
Elm *insert(Elm *node, const Student *t){
        if (node == NULL){
                Elm *new = malloc(sizeof(Elm));
                new->x = *t;
                new->L = new->R = NULL;
                new->color = 1;
                node = new ;
                return node;
        }

        int result = strcmp(node->x.id, t->id);

        if (result > 0){
                node->R = insert(node->R, t);
        }

        else if (result < 0) {
                node->L = insert(node->L, t);

        }
        else {
                node->x = *t;
        }

        if (color(node->R) && !color(node->L)){ //left color ni har bas right ni ulaan bol
                node = rotateLeft(node);
        }
        if (color(node->L) && color(node->L->L)){//left color ni ulaan leftiin left bas ulaan
                node = rotateRight(node) ;
        }
        if(color(node->L) && color(node->R)){//left color ni ulaan right color ni bas ulaan
                flipColor(node);
        }
        return node;

}
/*
  `ptree`-ийн зааж байгаа модонд `x` утгыг оруулна.
  Мод хоосон байсан бол `ptree->root` хаяг өөрчлөгдөж шинээр орсон оройг заана.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */
void rb_put(RBT *ptree, const Student *px)
{
        ptree->root = insert(ptree->root, px);
}

/*
  `ptree`-ийн зааж байгаа модноос `x` утгыг хайн олдсон оройн `Elm*` хаягийг буцаана.
  Олдохгүй бол `NULL` хаягийг буцаана.
  Мод дандаа ялгаатай элементүүд хадгална гэж үзэж болно.
 */

Elm *rb_get(const RBT *ptree, const char id[])
{
        
        Elm *node = ptree->root ;
        while (node != NULL){
                int result= strcmp(node->x.id, id) ;
                if (result == 0){
                        return node ;
                }
                else if(result < 0){
                        node = node->L;
                }
                else{
                        node = node->R;
                }
        }
        return NULL ; 
}

/*
  Устгах функц: ТМноос `x` утгыг хайж олоод устгана.
  Олдохгүй бол юу ч хийхгүй.
  Хэрэв мод тэнцвэрээ алдсан бол тохирох тэнцвэржүүлэх үйлдлүүдийг хийнэ.
 */


Elm *min(Elm *h){
        while(h->L !=NULL){
                h = h->L;
        }
        return h;
}

Elm *del_node(Elm *p, const char id[])
{
        
        if(p == NULL){
                return p;
                //return NULL;
        }
        int result = strcmp(p->x.id, id) ;

        if (result > 0){
                p->R = del_node(p->R, id) ;
        }

        else if (result < 0) {
                p->L = del_node(p->L, id) ;

        }
        // Ustgah node
        else
        {
                if(p->R == NULL)
                {
                        Elm *tmp = p->L;
                        free(p);
                        return tmp;
                }
                if(p->L == NULL)
                {
                        Elm *tmp = p->R;
                        free(p);
                        return tmp;
                }
                Elm *tmp = min(p->R);
                p->x = tmp->x;
                p->R = del_node(p->R, tmp->x.id);
        }
        // Lean left
        if (color(p->R) && !color(p->L)){
                p = rotateLeft(p);
        }
        if (color(p->L) && color(p->L->L)){
                p = rotateRight(p) ;
        }
        if(color(p->L) && color(p->R)){
                flipColor(p);
        }
        return p;
}
void rb_del(RBT *ptree, const char id[])
{
        ptree->root = del_node(ptree->root, id);
}

void print(Elm *p)
{
	if (p)
		printf("%s %s %d %.1f\n", p->x.name, p->x.id, p->x.age, p->x.gpa);
	else
		printf("None\n");
}
