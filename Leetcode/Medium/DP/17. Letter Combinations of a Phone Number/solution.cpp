class Solution
{
public:
    vector<vector<char>> arr
    {
        {'a'}, //0
        {'a'}, //1
        {'a','b','c'}, //2
        {'d','e','f'}, //3
        {'g','h','i'}, //4
        {'j','k','l'}, //5
        {'m','n','o'}, //6
        {'p','q','r','s'}, //7
        {'t','u','v'}, //8
        {'w','x','y','z'}//9
    };
    vector<string> res;

    vector<string> letterCombinations(string digits)
    {
        if(digits.length() == 0)
        {
            return res;
        }

        findval("",0,0,digits); //keypad_idx = 2,3,4 ; letter_idx = a,b,c
        return res;


    }

    void findval(string curstr,int keypad_idx,int letter_idx,string digits)
    {
        if(curstr.length() == digits.length())
        {
           // cout<<"currently pushing "<<curstr<<endl;
            res.push_back(curstr);
        }
        else if(keypad_idx<digits.length())
        {
            int arr_idx = digits[keypad_idx]-'0';
            vector<char> letters = arr[arr_idx]; //for arr_idx = 2, letters = {a,b,c}
            //either take or leave
            //take:
            if(letter_idx<letters.size())
            {
                findval(curstr+letters[letter_idx],keypad_idx+1,0,digits);
                //leave:
                findval(curstr,keypad_idx,letter_idx+1,digits);
            }
        }


    }
};
