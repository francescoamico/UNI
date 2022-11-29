package biblioteca;

public abstract class Documento{
    private int id;
    private static int counter=0;

    public Documento(){
        this.id=++counter;
    }

    public int getId(){
        return this.id;
    }

    protected abstract String getInfo();
    protected abstract void info();
}