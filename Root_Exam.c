#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_WINNT 0x501
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

const int PASS_SIZE = 12;

void anti();

int main() {

	anti();

	char inPass[13];
	char password1[13] = { 'A', '1', 'd', 'd', 'h', '!', 'c', 'U', 'C', '!', '`', 'e' };
	// 비교할 - 0xF	
	char password2[13] = { 'P', '@', 's', 's', 'w', '0', 'r', 'd', 'R', '0', 'o', 't' };
	// 입력

	//printf("%d\n", strlen(password2));

	printf("Enter the password : ");
	scanf("%s", &inPass);
	//printf("%d\n", strlen(inPass));

	if (strlen(inPass) != 12) {
		printf("Please Enter 12 Characters.\n");
		system("pause");
		return 0;
	}
	
	for (int i = 0; i < PASS_SIZE; i++) { // password 비교
		// RootPassword // 0xF = 15
		if (inPass[i] != password1[i] + 0xF) {
			printf("The password does not match. Please try again!\n");
			system("pause");
			return 0;
		}
	}

	printf("Congratulation! Correct Password!\n");
	system("pause");
	return 0;
}



void anti() {
	int flag = 0;

	__try {
		__asm { int 3 }
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		//MessageBox(NULL, "No Debugger Detected", "Notifications", MB_OK);
		flag = 1;
		printf("No Debugger Detected.\n");
	}
	if (flag == 0) {
		//MessageBox(NULL, "Debugger Detected", "Nofications", MB_OK);
		printf("Debugger Detected.\n");
		exit(1);
	}

}