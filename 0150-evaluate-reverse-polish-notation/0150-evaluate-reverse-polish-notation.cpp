
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            string x = tokens[i];

            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int b = s.top();
                s.pop();

                int a = s.top();
                s.pop();

                if (x == "+")
                    s.push(a + b);
                else if (x == "-")
                    s.push(a - b);
                else if (x == "*")
                    s.push(a * b);
                else
                    s.push(a / b);
            }
            else {
                s.push(stoi(x));
            }
        }

        return s.top();
    }
};
