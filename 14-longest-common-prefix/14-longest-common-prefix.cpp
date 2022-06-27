class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i,j,min;
        string pr;
        char ch;
        min=strs[0].length();
        for(i=1;i<strs.size();i++)
        {
            if(min>strs[i].length())
                min=strs[i].length();
        }
        for(i=0;i<min;i++)
        {
            ch=strs[0][i];
            for(j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=ch)
                    return pr;
            }
            pr=pr+ch;
        }
        return pr;
        
    }
};