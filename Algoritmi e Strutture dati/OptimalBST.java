public class OptimalBST {
    public static<T extends Comparable<? super T>> float minimumCost(T[] s, float[] p, float[] q) throws RuntimeException{
        int n = s.length;
        if(p.length != n || q.length != n+1) throw new RuntimeException();

        int j,k;
        float tmp;
        float [][]c = new float[n+1][n+1];
        float [][]w = new float[n+1][n+1];
        int [][]r = new int[n+1][n+1];
        for(int i = 0; i<=n; i++) w[i][i] = q[i];

        for(int d = 1; d<=n; d++){
            for(int i = 0; i<=n-d; i++){
                j = d+i;
                w[i][j] = w[i][j-1]+p[j-1]+q[j];
                c[i][j] = Float.MAX_VALUE;
                for(k = i+1; k<=j; k++){
                    tmp = w[i][j]+c[i][k-1]+c[k][j]; 
                    if(tmp<c[i][j]){
                        c[i][j] = tmp;
                        r[i][j] = k-1;
                    }
                }
            }
        }
 
        return c[0][n];
    }

    public static void main(String[] args) {
        Integer[] s = {1,16,18,23}; //non decrescente
        float[] p = {1/4f,1/8f,1/16f,1/16f};
        float[] q = {1/8f,3/16f,1/16f,1/16f,1/16f,};

     try{
            System.out.print("\nCosto di ricerca medio = "+minimumCost(s, p, q));
        }catch(RuntimeException ex){
            System.out.print(ex.getMessage());
        }
    }
}
