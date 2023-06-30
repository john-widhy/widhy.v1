#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Variable {
    char name[100];
    char value[100];
};

struct Variable variables[100]; // Array untuk menyimpan variabel
int variableCount = 0; // Jumlah variabel yang sudah didefinisikan


void parseWidhyPrintln(const char* command) {
    const char* start = strchr(command, '("');
    const char* end = strrchr(command, ')"');
    
    if (start != NULL && end != NULL && start < end) {
        size_t textLength = end - start - 1;
        char text[100];
        strncpy(text, start + 1, textLength);
        text[textLength] = '\0';
        printf("%s\n", text);
    } else {
        printf("Error: Invalid command\n");
    }
}

void parsePrintVariable(const char* command) {
    char variableName[100];
    sscanf(command, "print %s", variableName);

    // Mencari variabel dengan nama yang sama
    int variableIndex = -1;
    int i;
    for (i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, variableName) == 0) {
            variableIndex = i;
            break;
        }
    }

    // Jika variabel ditemukan, mencetak nilainya
    if (variableIndex != -1) {
        printf("%s\n", variables[variableIndex].value);
    } else {
        printf("Error: Variable '%s' not found\n", variableName);
    }
}

void parseVariableAssignment(const char* command) {
    char name[100];
    char value[100];

    if (sscanf(command, "%s = %s", name, value) == 2) {
        // Mencari variabel dengan nama yang sama
        int variableIndex = -1;
        int i;
        for (i = 0; i < variableCount; i++) {
            if (strcmp(variables[i].name, name) == 0) {
                variableIndex = i;
                break;
            }
        }

        // Menyimpan variabel baru atau mengupdate variabel yang sudah ada
        if (variableIndex == -1) {
            strcpy(variables[variableCount].name, name);
            strcpy(variables[variableCount].value, value);
            variableCount++;
        } else {
            strcpy(variables[variableIndex].value, value);
        }
    } else {
        printf("Error: Invalid variable assignment\n");
    }
}

void parseCommand(const char* command) {
    if (strncmp(command, "print ", 6) == 0) {
        parsePrintVariable(command);
    } else if (strncmp(command, "plus ", 4) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s + %s", variableName1, variableName2) == 2) {
                // Mencari nilai operand pertama
                int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }

                // Melakukan operasi penambahan
                int result = operand1 + operand2;

                // Menyimpan hasil penambahan sebagai variabel baru
                sprintf(variables[variableCount].name, "result%d", variableCount);
                sprintf(variables[variableCount].value, "%d", result);
                variableCount++;

                printf("%d\n", result);
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "minus ", 5) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s + %s", variableName1, variableName2) == 2) {
                // Mencari nilai operand pertama
                int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }

                // Melakukan operasi penambahan
                int result = operand1 - operand2;

                // Menyimpan hasil penambahan sebagai variabel baru
                sprintf(variables[variableCount].name, "result%d", variableCount);
                sprintf(variables[variableCount].value, "%d", result);
                variableCount++;

                printf("%d\n", result);
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "slash ", 5) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s + %s", variableName1, variableName2) == 2) {
                // Mencari nilai operand pertama
                int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }

                // Melakukan operasi penambahan
                int result = operand1 / operand2;

                // Menyimpan hasil penambahan sebagai variabel baru
                sprintf(variables[variableCount].name, "result%d", variableCount);
                sprintf(variables[variableCount].value, "%d", result);
                variableCount++;

                printf("%d\n", result);
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "star ", 4) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s + %s", variableName1, variableName2) == 2) {
                // Mencari nilai operand pertama
                int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }

                // Melakukan operasi penambahan
                int result = operand1 * operand2;

                // Menyimpan hasil penambahan sebagai variabel baru
                sprintf(variables[variableCount].name, "result%d", variableCount);
                sprintf(variables[variableCount].value, "%d", result);
                variableCount++;

                printf("%d\n", result);
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "widhy.loop ", 10) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            char msg[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s (%s)", variableName1, msg) == 2) {
                // Mencari nilai operand pertama
                int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }

                // Melakukan operasi penambahan
                int result = operand1 * 1;

                // Menyimpan hasil penambahan sebagai variabel baru
                sprintf(variables[variableCount].name, "result%d", variableCount);
                sprintf(variables[variableCount].value, "%d", result);
                variableCount++;
                

                 for (i = 0; i < result; i++) {
                    printf(msg);
                    printf("\n");
                 }
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "if ", 2) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            char msg[100];
            char msgs[100];
            char operand1 = 0;
            char operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s == %s print(%s)", variableName1, variableName2, msg) == 3) {
                // Mencari nilai operand pertama
                 int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }
                 
                  if(operand1 == operand2){
                  	printf(msg);
                 	printf("\n");
				  } else{
				  	printf("false");
                 	printf("\n");
				  }
				 
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "iff ", 3) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            char msg[100];
            char msgs[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s > %s print(%s)", variableName1, variableName2, msg) == 3) {
                // Mencari nilai operand pertama
                 int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }
                 
                  if(variableName1 > variableName2){
                  	printf(msg);
                 	printf("\n");
				  } else{
				  	printf("false");
                 	printf("\n");
				  }
				 
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strncmp(command, "if< ", 3) == 0) {
        const char* start = strchr(command, '(');
        const char* end = strchr(command, ')');

        if (start != NULL && end != NULL && start < end) {
            size_t expressionLength = end - start - 1;
            char expression[100];
            strncpy(expression, start + 1, expressionLength);
            expression[expressionLength] = '\0';

            char variableName1[100];
            char variableName2[100];
            char msg[100];
            char msgs[100];
            int operand1 = 0;
            int operand2 = 0;

            // Mencari nama kedua variabel
            if (sscanf(expression, "%s < %s print(%s)", variableName1, variableName2, msg) == 3) {
                // Mencari nilai operand pertama
                 int i;
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName1) == 0) {
                        operand1 = atoi(variables[i].value);
                        break;
                    }
                }

                // Mencari nilai operand kedua
                for (i = 0; i < variableCount; i++) {
                    if (strcmp(variables[i].name, variableName2) == 0) {
                        operand2 = atoi(variables[i].value);
                        break;
                    }
                }
                 
                  if(operand1 < operand2){
                  	printf(msg);
                 	printf("\n");
				  } else{
				  	printf("false");
                 	printf("\n");
				  }
				 
            } else {
                printf("Error: Invalid math expression\n");
            }
        } else {
            printf("Error: Invalid math command\n");
        }
    } else if (strchr(command, '=') != NULL) {
        parseVariableAssignment(command);
    } else {
    }
}


void Println(const char* command) {
    const char* start = strchr(command, '(.');
    const char* end = strrchr(command, ').');
    
    if (start != NULL && end != NULL && start < end) {
        size_t textLength = end - start - 1;
        char text[100];
        strncpy(text, start + 1, textLength);
        text[textLength] = '\0';
        printf("%s\n", text);
    } else {
        printf("Error: Invalid command\n");
    }
}

void parseMathOperation(const char* command) {
    char operator;
    int operand1, operand2;
    
    if (sscanf(command, "%d %c %d", &operand1, &operator, &operand2) == 3) {
        int result;
        switch (operator) {
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
                result = operand1 / operand2;
                break;
            default:
                printf("Error: Invalid operator\n");
                return;
        }
        
        printf("%d\n", result);
    } else {
    }
}

void widhy(const char* command) {
    char operator;
    int operand1, operand2;
    
    if (sscanf(command, "%d %c %d", &operand1, &operator, &operand2) == 3) {
        int result;
        switch (operator) {
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
                result = operand1 / operand2;
                break;
            default:
                printf("Error: Invalid operator\n");
                return;
        }
        
        printf("%d\n", result);
    } else {
    }
}


int main() {
    char input[100];
    printf("Welcome To Widhy.1.0\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Menghilangkan karakter newline
        
        if (strncmp(input, "widhy.println(", 14) == 0 && input[strlen(input) - 1] == ')') {
            parseWidhyPrintln(input);
        } else if (strncmp(input, "widhy.print(", 12) == 0 && input[strlen(input) - 1] == ')') {
            parseWidhyPrintln(input);
        } else if (strncmp(input, "clear", 5) == 0) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD coordScreen = {0, 0};
            DWORD cCharsWritten;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            DWORD dwConSize;

            if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
                return 1;

            dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

            if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten))
                return 1;

            if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
                return 1;

            if (!SetConsoleCursorPosition(hStdOut, coordScreen))
                return 1;
        } else if(strncmp(input, "exit", 4) == 0){
            return 0;
        } else if(strncmp(input, "help", 4) == 0){
        	printf("The Most Basic Code In WIDHY.V1");
        	printf("\n");
            printf("\n");
			printf("1. widhy.println() // for make output text");
            printf("\n");
            printf("2. widhy.print() // for make output text");
            printf("\n");
            printf("3. clear // for make clear display");
            printf("\n");
            printf("4. w = widhy // for make variable");
            printf("\n");
            printf("5. print w // for output that variable");
            printf("\n");
            printf("6. exit // for exit for this program");
            printf("\n");
            printf("\n");
        } else if(strncmp(input, "widhy.var(", 10) == 0 && input[strlen(input) - 1] == ')'){
            parseCommand(input);
        } else if (input) {
            parseCommand(input);
            parseMathOperation(input);
            
        } else {
            printf("Error: Invalid command\n");
        }
    }  

    return 0;
}
