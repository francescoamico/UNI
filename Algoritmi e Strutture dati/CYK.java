import java.util.*;

public class CYK {
    public static boolean CYK_algo(String str,String s,Map<String,Set<String>> CNF){

        int n = str.length();
        int i,k,j=0;
        Set<String>[][] dp = new Set[n][n];

        for (i=0; i<str.length(); i++){//caso base
            dp[i][i] = new HashSet<>();
            for(String key:CNF.keySet())
                if(CNF.get(key).contains(str.substring(i, i+1))) dp[i][i].add(key);
        }

        for(int d = 1; d<n; d++){//relazione di ricorrenza
            for(i = 0; i<n-d; i++){
                j = d+i;
                dp[i][j] = new HashSet<>();
                for(String key:CNF.keySet()){
                    for(String el:CNF.get(key)){
                        if(el.length()==2){
                            for(k = i; k<j; k++){
                                if(dp[i][k].contains(el.substring(0,1)) && dp[k+1][j].contains(el.substring(1,2))){
                                    dp[i][j].add(key);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n-1].contains(s);
    }

    public static void main(String[] args) {
        Map<String,Set<String>> CNF = new HashMap<>();
        CNF.put("S", Set.of("AB"));
        CNF.put("A", Set.of("CD","CF"));
        CNF.put("B", Set.of("c","EB"));
        CNF.put("C", Set.of("a"));
        CNF.put("D", Set.of("b"));
        CNF.put("E", Set.of("c"));
        CNF.put("F", Set.of("AD"));
        
        String str = "abc";
        String s = "S";

        if(CYK_algo(str,s,CNF))
            System.out.println(str+" generata dalla grammatica!");
        else
            System.out.println(str+" non generata dalla grammatica!");
    }
}
