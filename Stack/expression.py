from __future__ import print_function

def operator(c):
    if c == '+' or c == '-':
        return 1
    elif c == '/' or c == '*':
        return 2
    elif c == '(':
        return 0
    elif c == ')':
        return 3


def expressionConvertor(s):
    stack = []
    for i in s:
        if i.isdigit():
            print(i)
        else:
            if stack == [] or i == '(':
                stack.append(i)
            else:
                if operator(i) > operator(stack[-1]):
                    if i == ')':
                        while stack[-1] != '(':
                            print(stack.pop())
                        stack.pop()
                    else:
                        stack.append(i)
                else:
                    while len(stack) != 0 and (operator(i) <= operator(stack[-1])):
                        print(stack.pop())
                    stack.append(i)
        # print(stack)
    while stack != []:
        print(stack.pop())
    

def main():
    a = "1+2*3+(4*5+6)*7"
    b = "1*2+(3-4/5)*6"  
    expressionConvertor(b)

if __name__ == '__main__':
    main()