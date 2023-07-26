#include<stdio.h>
#include<string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char *names[CAPACITY]; //names //
char *numbers[CAPACITY]; // phone number, 전화번호를 숫자로 다루면  051-234-6787 등 -을 놓거나 첫글짜 0등의 처리가 어려워질 수 있다 //
int n = 0; //number of people in phone directory//

void add();
void find();
void status();
void remove_del();

int main(){
	char command[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", command);
		
		if (strcmp(command, "add")==0) // strcmp 함수는 두 문자열이 동일하면 0을 반환한다//
			add();
		else if (strcmp(command, "find")==0)
			find();
		else if (strcmp(command, "status")==0)
			status();
		else if (strcmp(command, "delete")==0)
			remove_del();
		else if (strcmp(command, "exit")==0)
			break; 
	}
	return 0; 
}

void add(){
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);
	
	names[n] = strdup(buf1); //strdup, strcpy //
	numbers[n] = strdup(buf2);
	n++;
	
	printf("%s was added successfully.\n", buf1);
}

void find(){
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	
	int i;
	for (i = 0; i<n; i++){
		if (strcmp(buf, names[i])==0){ 
			printf("%s\n", numbers[i]);
			return;
		}
	}
	printf("No person named '%s' exists. \n", buf); //for 문 동안 return 되지 않음// 
}

void status() {
	int i;
	for (i=0; i<n; i++){
		int i;
		for (i=0; i<n; i++)
			printf("%s %s\n", names[i], numbers[i]);
	}
	printf("Total %d persons.\n", n);
}

void remove_del(){
	char buf[BUFFER_SIZE];
	int i;
	scanf("%s", buf);
	for (i=0; i<n; i++){
		if (strcmp(buf, names[i])==0){
			names[i] = names[n-1]; //맨 마지막 사람을 삭제된 자리로 옮긴다 : 삭제한 자리에 맨 마지막 사람을 옮겨오는 것이 가장 단순하다// 
			numbers[i] = numbers[n-1];
			n--;
			printf("'%s' was deleted succesfully. \n", buf);
			return;
		}
	}
	printf("No person named '%s' exists. \n", buf);
}
