bool isValid(char* s) {
    int len = strlen(s);
    char stack[len]; 
    int top = -1;    

   
    for (int i = 0; i < len; i++) {
        char current = s[i];

       
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
       
        else {
            if (top == -1) {
                return false; 
            }

            if ((current == ')' && stack[top] != '(') ||
                (current == '}' && stack[top] != '{') ||
                (current == ']' && stack[top] != '[')) {
                return false; 
            }

            
            top--;
        }
    }

    
    return top == -1;
}
