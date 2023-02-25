#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *message;
	char *word;
	char *gen_pol;
	int max_len;
	int message_len;
	int word_len;
	double epsilon;
	int count;
	int errors;
} Coder;

void init(Coder *c, char *message, char *gen_pol, int max_len, double epsilon);
void l_shift(Coder *c);

int main(int argc, char **argv) {
	Coder coder;
	init(&coder, argv[1], "1011", 3, 0.1);
	l_shift(&coder);
	for (int i = 0; i < coder.word_len; ++i)
		printf("%d ", *(coder.word + i));
	return 0;
}

void init(Coder *c, char *message, char *gen_pol, int max_len, double epsilon) {
	c->message = message;
	c->gen_pol = gen_pol;
	c->max_len = max_len;
	c->message_len = strlen(message);
	c->epsilon = epsilon;
}

void l_shift(Coder *c) {
	c->word_len = c->message_len + strlen(c->gen_pol) - 1;
	c->word = malloc(c->word_len);
	for (int i = 0; i < c->message_len; ++i)
		*(c->word + i) = *(c->message + i);
}
