// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int prior(char ch) {
  switch (ch) {
    case '(':
      return 0;
      break;
    case ')':
      return 1;
      break;
    case '+':
    case '-':
      return 2;
      break;
    case '*':
    case '/':
      return 3;
      break;
    default:
      return -1;
  }
}
std::string infx2pstfx(std::string inf) {
  TStack<char> stack1;
  std::string ops;
  std::string str;
  for (int i = 0; i <= inf.length(); i++) {
    if (prior(inf[i]) == -1) {
      while (prior(inf[i]) == -1) {
        ops += inf[i];
      }
      ops += ' ';
    }
    else if (stack1.empty() || prior(inf[i]) == 0 || prior(inf[i]) > prior(stack.top()) {
      stack1.push(inf[i]);
    }
    else if (prior(inf[i]) <= prior(stack.top()) {
      while (prior(inf[i]) <= prior(stack.top() && !stack1.empty()) {
        ops += stack1.top();
        ops += ' ';
        stack1.pop();
      }
      stack1.push(inf[i]);
    }
    else if (inf[i] == ')') {
      while (stack1.top() != '(') {
        ops += stack1.top();
        ops += ' ';
        stack1.pop();
      }
      stack1.pop();
    }
  }
  while (!stack1.empty()) {
    str = stack1.top() + str;
  }
  ops += str;
  return ops;
}

int eval(std::string pst) {
  TStack<int> stack2;
  std::string ops;
  int n;
  for (int i = 0; i < pst.length(); i++) {
    if (pst[i] >= '0' && pst[i] <= '9') {
      while (pst[i] >= '0' && pst[i] <= '9') {
        n = pst[i] - '0';
        stack2.push(n);
      }
    }
    else if (pst[i] != ' ') {
      int num2 = stack2.top();
      stack2.pop();
      int num1 = stack.top();
      stack2.pop();
      switch (pst[i]) {
        case '-':
          n = num1 - num2;
          break;
        case '+':
          n = num1 + num2;
          break;
        case '*':
          n = num1 * num2;
          break;
        case '/':
          n = num1 / num2;
          break;
      }
      stack2.push(n);
    }
  }
  while (!stack2.empty()) {
    ops = stack2.top() + ops;
  }
  return ops;
}
