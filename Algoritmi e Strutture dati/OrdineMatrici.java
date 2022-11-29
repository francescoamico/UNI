public class OrdineMatrici {
    static int[][] dpTable;

    static public int ordine(int ...r) throws RuntimeException{
        if(r.length<2) throw new RuntimeException();
        int n = r.length-1;
        int j,tmp = 0;
        int[][] c = new int [n][n]; //prima diagonale già a zero

        for(int d = 1; d<n; d++){
            for(int i = 0; i<n-d; i++){
                j = d+i;
                c[i][j] = Integer.MAX_VALUE;
                for(int k = i; k<j; k++){
                    tmp = c[i][k]+c[k+1][j]+r[i]*r[k+1]*r[j+1]; 
                    c[i][j] = Math.min(tmp, c[i][j]);
                }
            }
        }
        return c[0][n-1];
    }

    public static int ordineRicorsivo(int ...r){
        dpTable = new int[r.length-1][r.length-1];
        return ricorsivo(0,r.length-2,r);

    }

    private static int ricorsivo(int i, int j, int[] r){
        if(j==i) return 0;
        if(dpTable[i][j]!=0) return dpTable[i][j];
        dpTable[i][j] = Integer.MAX_VALUE;
        int tmp = 0;
        for(int k = i; k<j; k++){
            tmp = ricorsivo(i,k,r)+ricorsivo(k+1,j,r)+r[i]*r[k+1]*r[j+1];
            dpTable[i][j] = Math.min(tmp,dpTable[i][j]);
        }
        return dpTable[i][j];
    }
    

    public static void main(String[] args) {
        System.out.println("Costo minimo per la moltiplicazione :: "+ordineRicorsivo(2,3,2,3));
    }
}
