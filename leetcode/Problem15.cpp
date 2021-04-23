// Problem 15 : https://leetcode.com/problems/goal-parser-interpretation/

/* 

class Solution {
public:
    string interpret(string command) {
        string ans="";
        stack<char> st;
        for(int i=0;i<command.length();i++){
            st.push(command[i]);
            if(st.top()=='G'){
                ans+=st.top();
                st.pop();
            }else if(st.top()=='(' and command[i+1]==')'){
                ans+='o';
                while(!st.empty()){
                    st.pop();
                }
            }else{
                if(st.top()!=')')
                    continue;
                else{
                    string temp="";
                    while(!st.empty()){
                        if(st.top()>='a' and st.top()<='z')
                            temp+=st.top();
                        st.pop();
                     }
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                }
            }
        }
        
        return ans;
    }
};

 */
