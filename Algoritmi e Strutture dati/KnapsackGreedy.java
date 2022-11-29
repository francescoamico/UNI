import java.util.Comparator;

class Item{
    private int id;
    private float weight;
    private float value;
    private static int count;

    Item(float weight, float value){
        this.weight = weight;
        this.value = value;
        this.id = ++count;
    }

    public float getWeight(){
        float copy = this.weight;
        return copy;
    }

    public float getValue(){
        float copy = this.value;
        return copy;
    }

    public int getId(){
        int copy = this.id;
        return copy;
    }
}

public class KnapsackGreedy {
    public static String[] Knapsack(Item[] items, Float KnapsackSize){
        Comparator<Item> comp = new Comparator<>() {
            @Override
            public int compare(Item a,Item b){
                Float x = a.getValue()/a.getWeight();
                Float y = b.getValue()/b.getWeight();
                return x.compareTo(y); 
            }
        };

        Sorting.heapSort(items,comp,false); //ordino gli oggetti in ordine decrescente per costo unitario
        
        int j = 0;
        while(j<items.length && KnapsackSize>=items[j].getWeight()){
            KnapsackSize -= items[j].getWeight();
            j++;
        }
        
        if (j<items.length){
            String[] res = new String[j+1];
            for(int i = 1; i<=j; i++) res[i-1] = "Item"+items[i-1].getId()+" : 1"; //100% dei primi j oggetti ordinati
            res[j] ="Item"+items[j].getId()+" : "+KnapsackSize/items[j].getWeight(); //solo una parte dell'j+1-mo oggetto
            return res;
        }else{
            String[] res = new String[j];
            for(int i = 1; i<=j; i++) res[i-1] = "Item"+items[i-1].getId()+" : 1"; //prendo il 100% di tutti gli oggetti
            return res;
        }
    }

    public static void main(String[] args) {
        Item[] items = new Item[3];
       
        items[1] = new Item(3, 5);
        items[0] = new Item(1, 10);
        items[2] = new Item(1, 100);

        String[] res = Knapsack(items, 5f);

        for(int i = 0; i<res.length; i++)
            System.out.println(res[i]);

    }
}
