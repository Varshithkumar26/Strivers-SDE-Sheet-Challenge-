vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n=pattern.size();
    vector<int>ans;
    for(int i=0; i<text.size(); i++)
    {
        if(text[i]==pattern[0] && (i+n-1)<text.size())
        {
            string str=text.substr(i, n);
            if(str==pattern)
			  ans.push_back(i+1);
        }
    }

    return ans;
}
