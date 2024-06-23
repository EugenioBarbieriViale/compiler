#include <stdio.h>
#include <ctype.h>

enum keyword {
	MAIN,
	RETURN
};

enum separator {
	OPEN_BRAC,
	CLOSE_BRAC,
	OPEN_PAR,
	CLOSE_PAR,
	SEMIC
};

enum literal {
	INT
};


int length(char s[]) {
	int n = 0;
	for (int i = 0; s[i] != '\0'; ++i) n++;
	return n;
}

int find(int pos, char s[], char to_find[]) {
	int res = 0;
	for (int j=0; j<length(to_find); j++) {
		if (s[pos+j] == to_find[j]) res++;
		else res *= 0;
	}
	/* if (pos == 1) { */
	/* 	if (res == length(to_find) && s[pos+length(to_find)] == ' ' && s[pos-1] == ' ') return 1; */
	/* } else { */
		if (res == length(to_find) && (s[pos+length(to_find)] == '(' || s[pos+length(to_find)] == '{' || s[pos+length(to_find)] == ' ')) return 1;
	/* } */
	return 0;
}

void tokenize(char s[]) {
	for (int i=0; i<length(s); i++) {
		char current = s[i];
		if (current == '(') printf("%c\n", current);
		if (current == ')') printf("%c\n", current);
		if (current == '{') printf("%c\n", current);
		if (current == '}') printf("%c\n", current);
		if (current == ';') printf("%c\n", current);
		if (isdigit(current)) printf("%d\n", current - '0');
		if (find(i, s, "int") == 1) printf("int\n");
		if (find(i, s, "return") == 1) printf("return\n");
		if (find(i, s, "main") == 1) printf("main\n");
	}
}

int main() {
	FILE *file;
	file = fopen("return_2.c", "r");
	char s[200];

	while (fgets(s, 200, file)) {
		tokenize(s);
	}
	
	fclose(file);
	return 0;
}
