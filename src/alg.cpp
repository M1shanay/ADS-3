// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
static int Priority(char c) {
    if (c == '*' || c == '/') {
        return 3;
    } else {
        if (c == '+' || c == '-') {
            return 2;
        } else {
            return 0;
        }
    }
}
std::string infx2pstfx(std::string inf) {
      TStack<char> stack;
    std::string strok;
    for (int i = 0; i < inf.length(); ++i) {
        if ((inf[i] <= '9') && (inf[i] >= '0')) {
            strok += inf[i];
            strok += ' ';
} else if ((inf[i] == '(')
    || (stack.isEmpty())
    || (Priority(inf[i]) > Priority(stack.get()))) {
             stack.push(inf[i]);
        } else if (inf[i] == ')') {
            char rl = stack.get();
            stack.pop();
            while (rl != '(') {
                strok += rl;
                strok += ' ';
                rl = stack.get();
                stack.pop();
            }
} else { while (!stack.isEmpty()
    && (Priority(stack.get()) >= Priority(inf[i]))) {
                strok += stack.get();
                strok += ' ';
                stack.pop();
            }
            stack.push(inf[i]);
        }
    }
    while (!stack.isEmpty()) {
        strok += stack.get();
        stack.pop();
    }
    return strok;
}

int eval(std::string pst) {
      TStack<int> stack;
    for (int i = 0; i < pst.length(); i++) {
        if (pst[i] <= '9' && pst[i] >= '0') {
            stack.push(pst[i]);
        } else { if (pst[i] != ' ') {
                int a2 = stack.get();
                stack.pop();
                int a1 = stack.get();
                stack.pop();
                if (pst[i] == '-') {
                    stack.push(a1 - a2);
                } else {
                    if (pst[i] == '+')
                        stack.push(a1 + a2);
                    else if (pst[i] == '*')
                        stack.push(a1 * a2);
                    else
                        stack.push(a1 / a2);
                }
            }
        }
        return stack.get();
    }
}
