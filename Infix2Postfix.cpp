# include<iostream>
# include<stack>
# include<vector>

using namespace std;

// Checks if operator or not, 
// !! If new operator needed, change inside string
bool isOperand(char ch){
    for(char i : "+-*/^()"){
        if(i == ch) return false;
    }
    return true; // is not any operator of brackett
}

// Determines priority
int priority(char ch) {
    switch (ch) {
    case '^' : return 4;
    case '/' : return 3;
    case '*' : return 2;
    case '-' : return 1;
    case '+' : return 0;
    }
    return 6;
}

// Reverse Notation string(POstFix)
string polishString(string expression){
    string polishString;
    stack<char> stk;  // For polish string conversion

    for(char ch : expression){
        if(isOperand(ch)) {
            polishString += ch;
        }

        else if (ch == '(') {
            stk.push(ch); // Push (
        }

        else if(ch == ')') {
            // Pop till '('
            char temp = stk.top();
            while(temp != '(' ) {             
                polishString += temp;
                stk.pop();
                temp = stk.top();
            }
            stk.pop(); // Remove '('
        }

        else {
            char c = stk.top();
            while(priority(ch) > priority(c)){
                polishString += c;
                stk.pop();
                c = stk.top();
            }
            stk.push(ch);
        }
    }
    return polishString;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        string expression;
        cin >>expression;
        cout << polishString(expression)<< '\n';
    }
    return 0;
}