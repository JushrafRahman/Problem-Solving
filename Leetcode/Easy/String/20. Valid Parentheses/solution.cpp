class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool valid=true;
        for(int i=0;i<s.length(); i++)
        {
            if((s[i] == '(') ||(s[i] == '{')||(s[i] == '['))
                {
                    st.push(s[i]);
                }
                else if(s[i] == ')')
                {
                    if(st.empty())
                    {
                        valid=false;
                        break;
                    }
                    else if(!st.empty())
                    {
                        char c=st.top();
                        if(c == '(')
                        {
                            st.pop(); 
                        }
                        else
                        {
                            valid=false;
                            break;
                        }
                        
                    }
                }
                else if(s[i] == '}')
                {
                    if(st.empty())
                    {
                        valid=false;
                        break;
                    }
                    else if(!st.empty())
                    {
                        char c=st.top();
                        if(c == '{')
                        {
                            st.pop(); 
                        }
                        else
                        {
                            valid=false;
                            break;
                        }
                        
                    }
                }
                else if(s[i] == ']')
                {
                    if(st.empty())
                    {
                        valid=false;
                        break;
                    }
                    else if(!st.empty())
                    {
                        char c=st.top();
                        if(c == '[')
                        {
                            st.pop(); 
                        }
                        else
                        {
                            valid=false;
                            break;
                        }
                        
                    }
                }
                
        }
        if(!st.empty())
        {
            return false;
        }
        return valid;
        
    }
};