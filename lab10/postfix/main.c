#include "DS.h"

int main()
{
	char s[EQUATION_LENGTH];
	printf("Tegshitgel oruul:");
	fgets(s, EQUATION_LENGTH, stdin);

	/* Тэгшитгэлд байгаа хоосон зайнуудыг байхгүй болгоно */
	int i, j, len;
    
	/* List-ийг эхлүүлнэ */
	List tokens, postfix;
	tokens.head = tokens.tail = NULL;
    tokens.len = 0;
	postfix.head = postfix.tail = NULL;
    postfix.len = 0;

	tokenize(s, &tokens);
	
	/* tokens жагсаалтад хадгалсан тэгшитгэлээ postfix-рүү хөрвүүлэх */
	convert_to_postfix(&tokens, &postfix);
	l_print(&postfix);
	/* postfix жагсаалтад хадгалсан postfix хэлбэрийг тэгштгэлийг
	   бодоод хариуг нь буцаах функц
	 */
	int res;
	res = solve(&postfix);
	printf("Xariu: %d\n", res);
	return 0;
}
