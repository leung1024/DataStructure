#include <stdio.h>
#include <stdlib.h>

#include "type_def.h"
#include "sq_stack.h"


Status conversion() {
    SqStack s;
    int n;
    SElemType e;
    InitStack(s);
    scanf("%d", N);
    while (N) {
        Push(s, N % 8);
        N = N / 8;
    }
    while (!StackEmpty(s)) {
        Pop(s, e);
        printf("%d", e);
    }
    return OK;
}

Status LineEdit() {
    InitStack(s);
    ch = getchar(); // 终端接收第一个字符, 输入缓冲区
    while (ch != EOF) {
        while (ch != EOF && ch != '\n') {
            switch(ch) {
                case '#':
                    Pop(s,c);
                    break;
                case '@':
                    ClearStack(s);
                    break;
                default:
                    Push(s, ch);
                    break;
            } // switch
            ch = getchar();
        } // while
        CleanStack(s);
        if (ch != EOF)
            ch = getchar();
    } // while
    DestoryStack(s);
    return OK;
}

