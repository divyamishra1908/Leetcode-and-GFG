class Solution {
public:
    
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1]; 
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
               
        sort(courses.begin(), courses.end(), cmp);
           
        priority_queue<int> pq;
        int endTime = 0;
        
        for(auto &course:courses)
        {
            if (course[0] + endTime <= course[1])
            {
                pq.push(course[0]);
                endTime += course[0];
            }
            else if(!pq.empty() && pq.top()>course[0])
            {
                endTime -= pq.top();
                pq.pop();
                pq.push(course[0]);
                endTime += course[0];
            }
        }
        
        return pq.size();        
    }
};