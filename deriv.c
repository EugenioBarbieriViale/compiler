#include <stdio.h>
#include <ctype.h>

enum operations {
	PLUS,
	MIN,
	MULT,
	DIV
};

enum literal {
	INT
};


int length(char s[]) {
	int n = 0;
	for (int i = 0; s[i] != '\0'; ++i) n++;
	return n;
}

void tokenize(char s[]) {
	for (int i=0; i<length(s); i++) {
		if (s[i] == '+') printf("%c\n", s[i]);
		if (s[i] == '-') printf("%c\n", s[i]);
		if (s[i] == '*') printf("%c\n", s[i]);
		if (s[i] == '/') printf("%c\n", s[i]);
		if (s[i] == 'x') printf("%c\n", s[i]);
		if (isdigit(s[i])) printf("%d\n", s[i] - '0');
	}
}

int main() {
	char s[] = "3x**2 + 4";
	tokenize(s);
	return 0;
}
