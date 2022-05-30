class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        if(v.size()==0 || (v.size()==1 && v[0]==val)) return 0;
        int i=0, j=0;
        while(j<v.size())
        {
            if(v[j]!=val)
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
            }
            j++;
        }
        if(i>=v.size()) return i;
        return (v[i]==val) ? i : i+1;
    }
};