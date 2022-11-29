package geometria.figurepiane;

public class Punto{
    private double x,y;

    public Punto(double x,double y){
        this.x=x;
        this.y=y;
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

    public static double distanza(Punto p1,Punto p2){
        return Math.sqrt(Math.pow(p2.getX()-p1.getX(), 2)+Math.pow(p2.getY()-p1.getY(), 2));
    }
}