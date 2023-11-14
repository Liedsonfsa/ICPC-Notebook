// O(n + m) time complexity

vector<int> pi(string a){
    vector<int> p(a.size());
    for(int i = 1, j = 0; i < a.size(); i++){
      while(j > 0 && a[i] != a[j]) j = p[j-1];
      if(a[j] == a[i]) j++;
      p[i] = j;
    }
  
  
    return p;
  }
    
  vector<int> matching(string& a, string& b ){
    vector<int> p = pi(b+'$'), match;
    for(int i = 0, j = 0; i < a.size(); i++){
      while(j > 0 && a[i] != b[j]) j = p[j-1];
      if(a[i] == b[j]) j++;
      if(j == b.size()) match.push_back(i-j+1);
    }
  
    return match;
  }


  int findLastOccurence(string A,string B){
    vector<int> p = matching(A, B);
    int ans;
    ans = (p.size() == 0) ? -1 : p[p.size() - 1] + 1;	
  
    return ans;
  }
