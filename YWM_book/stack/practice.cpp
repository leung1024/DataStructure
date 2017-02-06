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

// 括号匹配
Status Match(char *exp) {
    int i = 0;
    SElemType e;
    SqStack s;
    InitStack(s);
    while (exp[i] != '\0') {
        switch(exp[i]) {
            case '(':
                Push(s, -1); // 代号为 －1
                break;
            case '[':
                Push(s, -2); // 代号为 -2
                break;
            case '{':
                Push(s, -3); // 代号为 -3
                break;
            case ')':
                if (!StackEmpty):
                    if (GetTop(s, e) == OK && e + 1 == 0) {
                        Pop(s, e);
                    }
                    else
                        return ERROR;
                else
                    return ERROR;
                break;
            case ']':
                if (!StackEmpty):
                    if (GetTop(s, e) == OK && e + 2 == 0) {
                        Pop(s, e);
                    }
                    else
                        return ERROR;
                else
                    return ERROR;
                break;
            case '}':
                if (!StackEmpty):
                    if (GetTop(s, e) == OK && e + 3 == 0) {
                        Pop(s, e);
                    }
                    else
                        return ERROR;
                else
                    return ERROR;
                break;
            default:
                break;
        } // switch
        i++;
    }
    return 
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
        TraverseStack(s, visit_display);
        CleanStack(s);
        if (ch != EOF)
            ch = getchar();
    } // while
    DestoryStack(s);
    return OK;
}

Status MatchReversedString(char *ch) {
    // abc&cba@ 合法
    // abc&bac@ abc&@ 不合法
    InitStack(s);
    int i = 0;
    char op = 'push';
    while (ch[i] != '@') { // @代表结束
        switch(ch[i]) {
            case '&':
                op = 'pop'; // &后面的元素要与栈内的元素进行比较
                break;
            default:
                if (op == 'push') { // 把&前面的元素入栈
                    Push(s, ch[i]);
                }
                else {
                    tmp = Pop(s, ch[i]);
                    if (tmp != ch[i])
                        printf("字符串不对称\n");
                        return FALSE;
                }
                break;
        } // switch
        i++;
    }
    if (!StackEmpty(s)) // 如果前面的元素没有完全pop出来说明不对称
        printf("字符串不对称\n");
        return FALSE;
    else
        printf("字符串对称\n");
    return TRUE;
}

Status MatchReversedString2() {
    char ch;
    InitStack(s);
    InitQueue(queue);
    SElemType se;
    QElemType qe;
    scanf(ch);
    while(ch != '@') {
        Push(s, ch);
        EnQueue(queue, ch);
        scanf(ch);
    }
    Status state = TRUE;
    while (!StackEmpty && state) {
        GetTop(s, se);
        GetHead(queue, qe);
        if (se == qe) {
            Pop(s);
            DeQueue(queue);
        }
        else
            state = FALSE;
    }
    return state
}