#include "DS.h"

int is_space(int x)
{
        switch(x) {
        case ' ':
        case '\t':
        case '\n':
        case '\r':
        case '\f':
        case '\v':
        case '\0':
                return 1;
        default:
                return 0;
        }
        return 0;
}
int convert_to_int(const char s[])
{
	int len = strlen(s);
	int t = 0, i;
	for (i = 0; i < len; i++)
		t = t * 10 + s[i] - '0';
	return t;
}

void tokenize(const char s[], List *p_list)
{
	char tmp[EQUATION_LENGTH];
	int i, j, k, len;
	j = 0;
	struct Token x;
	len = strlen(s);
	for (i = 0; i <= len; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			/* цифр орж ирлээ */
			tmp[j] = s[i];
			j++;
		} else {
			/* тэмдэгт орж ирлээ */
			if (j != 0) { /* Хөрвүүлэх тоо байгаа эсэх */
				tmp[j] = '\0';
				j = 0;
				/* хадгалсан цифрийн цувааг int-рүү хөрвүүл */
				k = convert_to_int(tmp);
				x.flag = 1;
				x.val = k;
				/*
				  Жагсаалтанд x элемнтийг оруулах
				  Жагсаалтын push_back функцыг дуудна
				*/
				l_push_back(p_list, x);
			}
			/*
			  тэмдэгтийг жагсаалтанд оруулах
			  Жагсаалтын push_back функцыг дуудна
			 */
			if (is_space(s[i])) /* хоосон зай, шинэ мөрийг хаяна. */
				continue;

            /*
              Энд +, -, *, /, (, ) тэмдэгтүүдийг жагсаалтад оруулна.
             */
			x.flag = 0;
			x.op = s[i];
			l_push_back(p_list, x);
		}
	}

	/* Тэмдэгтэн цуваанаас салгасан тэгшитгэлийг хэвлэх
	   Жагсаалтын print функцыг дуудна.
	 */
	/* l_print(p_list); */
}

/*
  p_token - жагсаалтад байгаа тэгштгэлийг postfix-рүү хөрвүүлнэ
 */
int get(char op) {
    if(op == '+' || op == '-'){
		return 1;
	}
	else if(op == '*' || op == '/' || op == '%'){
		return 2;
	}
	return 0;
}

void convert_to_postfix(List *p_token, List *p_post)
{

	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = NULL;
	s->len = 0;
	TokenElm *t = p_token->head;
	while(t != NULL){
		if(t->x.flag == 1){
			TokenElm *k = (TokenElm *)malloc(sizeof(TokenElm));
			k->x = t->x;
			k->next = NULL;

			if(p_post->head == NULL){
				p_post->head = k;
				p_post->tail = k;
			}
			else{
				p_post->tail->next = k;
				p_post->tail = k;
			}
		}
		else if(t->x.flag == 0){
			char ch = t->x.op;
			if(ch == '('){
				s_push(s, ch);

			}
			else if(ch == ')'){
				while(s->top != NULL && s->top->x != '('){
					TokenElm *new = (TokenElm *)malloc(sizeof(TokenElm));
					new->x.flag = 0;
					new->x.op = s->top->x;
					new->next = NULL;

					if(p_post->head == NULL){
						p_post->head = new;
						p_post->tail = new;
					}
					else{
						p_post->tail->next = new;
						p_post->tail = new;
					}
					s_pop(s);
				}
				s_pop(s);
			}
			else{
				while(s->top != NULL && s->top->x != '(' && get(ch) <= get(s->top->x)){
					TokenElm *new = (TokenElm *)malloc(sizeof(TokenElm));
					new->x.flag = 0;
					new->x.op = s->top->x;
					new->next = NULL;

					if(p_post->head == NULL){
						p_post->head = new;
						p_post->tail = new;
					}
					else{
						p_post->tail->next = new;
						p_post->tail = new;
					}
					s_pop(s);
				}
				s_push(s, ch);
			}
		}
		t = t->next;
	}
	while(s->top != NULL){
		TokenElm *new = (TokenElm *)malloc(sizeof(TokenElm));
		new->x.flag = 0;
		new->x.op = s->top->x;
		new->next = NULL;

		if(p_post->head == NULL){
			p_post->head = new;
			p_post->tail = new;
		}
		else{
			p_post->tail->next = new;
			p_post->tail = new;
		}
		s_pop(s);
	}
	free(s);
}
void free_list(List *p_list) {
    TokenElm *t = p_list->head;
    TokenElm *next;

    while (t != NULL) {
        next = t->next;
        free(t);
        t = next;
    }

    p_list->head = NULL;
    p_list->tail = NULL;
}

int solve(List *p_post)
{
	Stack operand_stack;
	operand_stack.top = NULL;
	operand_stack.len = 0;

	TokenElm *t = p_post->head;

	while(t != NULL){
		if(t->x.flag == 1){
			s_push(&operand_stack, t->x.val);
		}
		else if(t->x.flag == 0){
			int operand2 = operand_stack.top->x;
			s_pop(&operand_stack);

			int operand1 = operand_stack.top->x;
			s_pop(&operand_stack);

			char operator = t->x.op;
			
			int result;
			switch(operator){
				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					if(operand2 != 0){
						result = operand1 / operand2;
					}
					else{
						printf("toog 0t huwaah bolomjgui");
						exit(0);
					}
					break;
				case '%':
					result = operand1 % operand2;
					break;
				default:
					exit(0);
			}
			s_push(&operand_stack, result);
		}
		t = t->next;
	}
	if(operand_stack.len == 1){
		int final_result = operand_stack.top->x;
		free_list(p_post);
		return final_result;
	}
	else{
		printf("aldaa2");
		exit(0);
	}
}
