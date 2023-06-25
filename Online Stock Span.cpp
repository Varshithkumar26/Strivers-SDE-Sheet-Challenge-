#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>> st;
    vector<int> ans;
    for(int i=0;i<price.size();i++)
    {
        int days=1;
        while(!st.empty() && price[i]>=st.top().first)
        {
            days+=st.top().second;
            st.pop();
        }

        st.push({price[i],days});
        ans.push_back(days);
    }
    return ans;

}
