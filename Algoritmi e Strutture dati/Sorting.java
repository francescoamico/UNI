import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Random;
import java.util.function.Function;

public class Sorting {

    /* SELECTION SORT */
    public static <T extends Comparable<? super T>> void selectionSort(T[] array){
       selectionSort(array,true);
    }

    public static <T extends Comparable<? super T>> void selectionSort(T[] array, boolean ascending){
        selectionSort(array,Comparator.naturalOrder(),ascending);
    }

    public static <T> void selectionSort(T[] array, Comparator<T> comp){
        selectionSort(array,comp,true);
    }

    public static <T> void selectionSort(T[] array, Comparator<T> comp, boolean ascending){
        int order = ascending ? 1:-1;
        for(int i = 0; i<array.length-1; i++){
            int min = i;
            for(int j = i+1; j<array.length; j++)
                if(comp.compare(array[j], array[min])*order < 0) min = j;

            T tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }


    /* BUBBLE SORT */
    public static <T extends Comparable<? super T>> void bubbleSort(T[] array){
        bubbleSort(array,true);
    }

    public static <T extends Comparable<? super T>> void bubbleSort(T[] array, boolean ascending){
        bubbleSort(array,Comparator.naturalOrder(),ascending);
    }

    public static <T> void bubbleSort(T[] array, Comparator<T> comp){
        bubbleSort(array,comp,true);
    }

    public static <T> void bubbleSort(T[] array, Comparator<T> comp, boolean ascending){
        int order = ascending ? 1:-1;
        boolean swap = true;
        int len = array.length;
        while(swap){
            swap = false;
            for(int j = 1; j<len; j++){
                if(comp.compare(array[j],array[j-1])*order < 0){
                    T tmp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = tmp;
                    swap = true;
                }
            }
            len--;
        }
    }


    /* INSERTION SORT */
    public static <T extends Comparable<? super T>> void insertionSort(T[] array){
        insertionSort(array,true);
    }

    public static <T extends Comparable<? super T>> void insertionSort(T[] array, boolean ascending){
        insertionSort(array,Comparator.naturalOrder(),ascending);
    }

    public static <T> void insertionSort(T[] array, Comparator<T> comp){
        insertionSort(array,comp,true);
    }

    public static <T> void insertionSort(T[] array, Comparator<T> comp, boolean ascending){
        int order = ascending ? 1:-1;
        int j;
        for(int i=1; i<array.length; i++){
            T tmp = array[i];
            for(j=i-1; j>=0 && (comp.compare(array[j],tmp)*order > 0);j--)
                array[j+1] = array[j];
            array[j+1] = tmp;
        }
    }


    /* MERGE SORT */
    public static <T extends Comparable<? super T>> void mergeSort(T[] array){
        mergeSort(array,true);
    }   

    public static <T extends Comparable<? super T>> void mergeSort(T[] array, boolean ascending){
        mergeSort(array,Comparator.naturalOrder(),ascending);
    }   

    public static <T> void mergeSort(T[] array, Comparator<T> comp){
        mergeSort(array,comp,true);
    }

    public static <T> void mergeSort(T[] array, Comparator<T> comp, boolean ascending){
        divide(array,0,array.length-1,comp,ascending);
    }

    public static <T> void divide(T[] array, int start, int stop, Comparator<T> comp, boolean ascending){
        if(start>=stop) return;
        int mid = (start+stop)/2;
        divide(array,start,mid,comp,ascending);
        divide(array,mid+1,stop,comp,ascending);
        merge(array,start,mid,stop,comp,ascending);
    }

    public static <T> void merge(T[] array, int start, int mid, int stop, Comparator<T> comp, boolean ascending){
        ArrayList<T> tmp = new ArrayList<>();
        int order = ascending ? 1:-1;
        int left = start;
        int right = mid+1;
        
        while(left<=mid && right<=stop){
            if(comp.compare(array[left],array[right])*order <= 0) //<= mantiene la stabilità
                tmp.add(array[left++]);
            else
                tmp.add(array[right++]);
        }

        if(left>mid)    
            while(right<=stop) tmp.add(array[right++]);
        else
            while(left<=mid)  tmp.add(array[left++]);

        left = 0;
        for(int i = start; i<=stop; i++,left++)
            array[i] = tmp.get(left);
    }


    /* HEAP SORT */
    public static <T extends Comparable<? super T>> void heapSort(T[] array){
       heapSort(array,true);
    }
    
    public static <T extends Comparable<? super T>> void heapSort(T[] array, boolean ascending){
       heapSort(array,Comparator.naturalOrder(),ascending);
    }

    public static <T> void heapSort(T[] array, Comparator<T> comp){
        heapSort(array,comp,true);
    }

    public static <T> void heapSort(T[] array,  Comparator<T> comp, boolean ascending){
        int order = ascending ? 1:-1;
        //heapify bottom-up -> heap con struttura rafforzata
        int lastParent = (array.length-2)/2;
        for(int i=lastParent;i>=0; i--)
            fixHeap(array,array.length,i,(a,b) -> comp.compare(a,b)*order);
        //ordinamento
        int heapSize = array.length;
        while(heapSize > 1){
            T tmp = array[0];
            array[0] = array[heapSize-1];
            array[heapSize-1] = tmp;
            heapSize--;
            fixHeap(array,heapSize,0,(a,b) -> comp.compare(a,b)*order); //bubble down
        }
    }

    public static <T> void fixHeap(T[] array, int heapSize, int node, Comparator<T> comp){
        int leftChild = 2*node+1;
        int rightChild = 2*node+2;
        int max;
        if(leftChild<heapSize && rightChild<heapSize)
            max = comp.compare(array[leftChild],array[rightChild]) < 0 ? rightChild:leftChild;
        else if(leftChild<heapSize) max = leftChild;
        else if(rightChild<heapSize) max = rightChild;
        else return;

        if(comp.compare(array[node],array[max])< 0){
            T tmp = array[node];
            array[node] = array[max];
            array[max] = tmp;
            fixHeap(array, heapSize, max, comp);
        }
    }


    /* QUICK SORT */
    public static <T extends Comparable<? super T>> void quickSort(T[] array){
        quickSort(array,true);
    }   

    public static <T extends Comparable<? super T>> void quickSort(T[] array, boolean ascending){
        quickSort(array,Comparator.naturalOrder(),ascending);
    }

    public static <T> void quickSort(T[] array, Comparator<T> comp){
        quickSort(array,comp,true);
    }

    public static <T> void quickSort(T[] array, Comparator<T> comp, boolean ascending){
        quickSort(array,0,array.length-1,comp,ascending);
    }

    private static <T> void quickSort(T[] array, int start, int stop, Comparator<T> comp, boolean ascending){
        if(start>=stop) return;
        int pivot = partition(array,start,stop,comp,ascending);
        quickSort(array,start,pivot-1,comp,ascending);
        quickSort(array,pivot+1,stop,comp,ascending);
    }

    public static <T> int partition(T[] array, int start, int stop, Comparator<T> comp, boolean ascending){
        int indexPivot = new Random().nextInt(stop-start+1)+start; // tra start e stop
        // scambia elemento in posizione iniziale con quello in posizione casuale
        T tmp;
        tmp = array[indexPivot];
        array[indexPivot] = array[start];
        array[start] = tmp;

        T pivot = array[start]; 
        int inf = start;
        int sup = stop;
        int order = ascending ? 1:-1;
        
        while(inf < sup){
            while(inf <= stop && comp.compare(array[inf], pivot)*order <= 0) inf++;
            while(sup >= start && comp.compare(array[sup], pivot)*order > 0) sup--;
            if(inf < sup){
                tmp = array[inf];
                array[inf] = array[sup];
                array[sup] = tmp;
            }
        }
        tmp = array[start];
        array[start] = array[sup];
        array[sup] = tmp;
        return sup;
    }

 
    /* COUNTING SORT */
    public static void countingSort(int[] array){
        countingSort(array,true);
    }

    public static void countingSort(int[] array, boolean ascending){
        if(array.length<=1) return;
        int max = array[0];
        int min = array[0];
        for(int i = 0; i<array.length; i++){ //ricerca del massimo e del minimo
            max = array[i]>max ? array[i]:max;
            min = array[i]<max ? array[i]:max;
        }

        min = Math.abs(min); //minimo in valore assoluto
        int k = max+min+1;

        //se k >> array.length -> radixSort

        countingSort(array,min,k,ascending);
    }

    private static void countingSort(int[] array, int absMin, int k, boolean ascending){
        int i;
        int[] count = new int[k]; //già inizializzato a 0
        for(i = 0; i<array.length; i++) count[array[i]+absMin]++;
        for(i = 1; i<k; i++) count[i] += count[i-1]; //stabilità: count[i]-1 = ultima posizione in cui i deve apparire nell'array ordinato
        
        int[] res = new int[array.length];
        for(i = array.length-1; i>=0; i--){ //stabilità: da destra a sinistra
            count[array[i]+absMin] -= 1;
            res[count[array[i]+absMin]] = array[i];
        }

        if(ascending)
            for(i = 0; i<array.length; i++) array[i] = res[i];
        else
            for(i = 0; i<array.length; i++) array[i] = res[array.length-i-1];
    }


    /* BUCKET SORT */
    public static <T> void bucketSort(T[] array, Function<T,Integer> f){ // f restituisce la chiave di ordinamento intera
        bucketSort(array,f,true);
    }

    public static <T> void bucketSort(T[] array, Function<T,Integer> f, boolean ascending){
        if(array.length<=1) return;
        int max = f.apply(array[0]);
        int min = f.apply(array[0]);
        for(int i = 1; i<array.length; i++){
            max = f.apply(array[i])>max ? f.apply(array[i]):max;
            min = f.apply(array[i])<min ? f.apply(array[i]):min;
        }

        min = Math.abs(min);
        int k = max+min+1;

        bucketSort(array,k,min,f,ascending);
    }

    private static <T> void bucketSort(T[] array, int k, int absMin,Function<T,Integer> f, boolean ascending){
        ArrayList<LinkedList<T>> list = new ArrayList<>(k);
        int i;
        for(i = 0; i<k; i++) list.add(new LinkedList<>());
        for(i = 0; i<array.length; i++)
            list.get(f.apply(array[i])+absMin).add(array[i]);

        int j = 0;
        if(ascending){
            for(i = 0; i<k; i++)
                while(list.get(i).size()>0){
                    array[j] = list.get(i).removeFirst();
                    j++;
            }
        }else{
            for(i = k-1; i>=0; i--)
                while(list.get(i).size()>0){
                    array[j] = list.get(i).removeFirst();  
                    j++;
                } 
        }
    }

    /* RADIX SORT */

    public static void main(String[] args) {
        String[] array = {"ciao","a","voi","tutti"};
        bucketSort(array, x->x.length(),false);         

        for(int i =0; i<array.length; i++)
            System.out.println(array[i]);
    }
    
}
 