#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

// DEFINE STATES

typedef enum state {
	Q0, Q1, Q2, Q3
}State;
State accept = Q2;
State start = Q0;

int automata(State acc, State st, int* input, int length);

int main() {
	//INTRO
	//
	printf("WELCOME TO AUTOMATA SIMULATOR\n");
	printf("Table for this automata:\n");
	printf("State | Input|\n");

	printf("      | 0 | 1 |\n");
	printf(" q_0  |q_1|q_2|\n");
	printf(" q_1  |q_3|q_0|\n");
	printf(" q_2  |q_0|q_3|\n");
	printf(" q_3  |q_1|q_2|\n");
	printf("Q={ q0, q1, q2, q3 }, S={0, 1}, F={ q2 }.\n");
	printf("Please, enter your input symbols in one line: \n");

	//WORK ON INPUT
	//
	int sym[SIZE] = {};
	int c;
	int i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t') {
			break;
		}
		if (c == ' ') {
			continue;
		}
		if (c == '1' || c == '0')
			sym[i] = c - '0';
		else {
			printf("Only 0 and 1 !\n");
			return 1;
		}
		i++;
	}
	int len = i;
	//	int *input= sym[];

	automata(accept, start, sym, len);




}
int automata(State acc, State st, int* input, int length) {
	State current = st;
	printf("%d\n", current);
//	printf("Length:\n");
//	printf("%d\n", length);
	switch (st) {
	case 0:
		printf("q0");
		break;
	case 1:
		printf("q1");
		break;
	case 2:
		printf("q2");
		break;
	case 3:
		printf("q3");
		break;
	}
	for (int i = 0; i < length;i++)
		switch (current) {
		case 0:
			if (input[i] == 0) {
				printf("-[0]->q1");
				current = Q1;
				//					printf("%d",current);
			}
			else {
				printf("-[1]->q2");
				current = Q2;
				//					printf("%d",current);
			}
			break;
		case 1:
			if (input[i] == 0) {
				printf("-[0]->q3");
				current = Q3;
				//                                      printf("%d",current);
			}
			else {
				printf("-[1]->q0");
				current = Q0;
				//                                      printf("%d",current);
			}
			break;

		case 2:
			if (input[i] == 0) {
				printf("-[0]->q0");
				current = Q0;
				//                                      printf("%d",current);
			}
			else {
				printf("-[1]->q3");
				current = Q3;
				//                                      printf("%d",current);
			}
			break;

		case 3:
			if (input[i] == 0) {
				printf("-[0]->q1");
				current = Q1;
				//                                      printf("%d",current);
			}
			else {
				printf("-[1]->q2");
				current = Q2;
				//                                      printf("%d",current);
			}
			break;




			printf("\n");

		}
	if (current == acc) {
		printf("\nLanguage is accepted\n");
	}
	else {
		printf("\nLanguage is not accepted\n");
	}
	return 0;



}