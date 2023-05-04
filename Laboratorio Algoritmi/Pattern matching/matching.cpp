#include "matching.hpp"
#include <unordered_map>

int** createDFA(std::string pattern, std::unordered_map<char, int> sigma){
    int m = pattern.length();
    int alpha = sigma.size();

    int **dfa = new int*[alpha];
    for(int i=0; i<alpha; i++)
        dfa[i] = new int[m+1];

    dfa[sigma[pattern[0]]][0] = 1;
    int x = 0;
    for (int i=1; i<m; i++){
        for(int j=0; j<alpha; j++)
            dfa[j][i] = dfa[j][x];  // Copy mismatch cases
        dfa[sigma[pattern[i]]][i] = i+1; // Set match case
        x = dfa[sigma[pattern[i]]][x];  // Update restart state.
    }

    for(int j=0; j<alpha; j++) // to count the pattern's occurence
        dfa[j][m] = dfa[j][x];

    return dfa;
}

int match(std::string txt, std::string pattern){  
    int n = txt.length();
    int m = pattern.length();

    if(n==0 || m==0 || m>n) return -1;

    std::unordered_map<char, int> sigma;
    int i,j;
    for(i=0, j=0; i<m; i++)
        if(sigma.find(pattern[i])==sigma.end())
            sigma[pattern[i]] = j++;
      
    int **dfa = createDFA(pattern, sigma);
    for(i=0, j=0; i<n && j<m; i++)
        j = sigma.find(txt[i])==sigma.end() ? 0:dfa[sigma[txt[i]]][j];

    return j==m ? i-m:-1;
}

int countMatch(std::string txt, std::string pattern){
    int n = txt.length();
    int m = pattern.length();

    if(n==0 || m==0 || m>n) return -1;

    std::unordered_map<char, int> sigma;
    int i,j;
    for(i=0, j=0; i<m; i++){
        if(sigma.find(pattern[i])==sigma.end())
            sigma[pattern[i]] = j++;
    }
    
    int **dfa = createDFA(pattern, sigma);
    int counter = 0;
    for(i=0, j=0; i<n; i++){
        j = sigma.find(txt[i])==sigma.end() ? 0:dfa[sigma[txt[i]]][j];
        if(j==m) counter++;
    }

    return counter;
}

bool cyclicRotation(std::string txt, std::string pattern){
    int n = txt.length();
    int m = pattern.length();

    if(n!=m) return false;
    if(n==0 && m==0) return true;

    return match(txt+txt,pattern)==-1 ? false:true;
}

int tandemRepeat(std::string txt, std::string pattern){
    int n = txt.length();
    int m = pattern.length();

    if(n==0 || m==0 || m>n) return -1;

    std::unordered_map<char, int> sigma;
    int i,j;
    for(i=0, j=0; i<m; i++){
        if(sigma.find(pattern[i])==sigma.end())
            sigma[pattern[i]] = j++;
    }

    int **dfa = createDFA(pattern, sigma);
    int counter=0, max = 0;
    for(i=0, j=0; i<n; i++){
        if(sigma.find(txt[i])==sigma.end()){
            max = counter>max ? counter:max;
            counter = 0;
            j = 0;
            continue;
        }
        if((j!=m && dfa[sigma[txt[i]]][j]!=j+1) || (j==m && dfa[sigma[txt[i]]][j]!=1)){
            max = counter>max ? counter:max;
            counter = 0;
        }
        j = dfa[sigma[txt[i]]][j];
        if(j==m) counter++;
    }
    max = counter>max ? counter:max;

    return max;
}

int borderLength(std::string s){
    int n = s.length();
    int i = 0;
    int dp[n];
    dp[0] = -1;
    for(int j=1; j<n; j++){
        dp[j] = i;
        while(i>=0 && s[i]!=s[j])
            i = dp[i];
        i++;
    }

    return i;
}

int period(std::string s){
    return s.length()-borderLength(s);
}

std::vector<int> matchList(std::string txt, std::vector<std::string> patterns){
    int n = txt.length();
    std::vector<int> res(patterns.size(),-1);
    if(n==0) return res;

    std::vector<std::unordered_map<char, int>> sigma(patterns.size());
    std::vector<int**> dfas(patterns.size());
    int k,i,j,m;
    for(k=0; k<patterns.size(); k++){
        m = patterns[k].length();
        if(m==0 || m>n){
            dfas[k] = nullptr;
            continue;
        }
        for(i=0, j=0; i<m; i++){
            if(sigma[k].find(patterns[k][i]) == sigma[k].end())
                sigma[k][patterns[k][i]] = j++;
        }
        dfas[k] = createDFA(patterns[k],sigma[k]);
    }
    
    std::vector<int> states(patterns.size(), 0);
    for(i=0; i<n; i++){
        for(k=0; k<dfas.size(); k++){
            if(states[k]==patterns[k].length() || dfas[k]==nullptr) continue;
            states[k] = sigma[k].find(txt[i])==sigma[k].end() ? 0:dfas[k][sigma[k][txt[i]]][states[k]];
            if(states[k]==patterns[k].length()) res[k] = i+1-patterns[k].length();
        }
    }
        
    return res;
}