package geometria;
import geometria.figurepiane.*;
import geometria.figuresolide.*;

public class Main{

    static int numeroRettangoli(Quadrilatero[] q){
        int n=0;
        double area=0;

        for(Quadrilatero c:q)
            area+=c.getArea();
        area/=q.length;

        for(Quadrilatero c:q){
            if(c.getArea()>=area&&c.getL1()==c.getL3()&&c.getL2()==c.getL4()&&c.getL1()!=c.getL2()&&c.getL3()!=c.getL4()){
                n++;
            }
        }
        return n;
    }

    public static void main(String[] args){
        /*i punti vanno assegnati in senso orario a partire dall' alto a sinistra*/
        Quadrilatero[] q=new Quadrilatero[5];

        Punto p1=new Punto(-4,1);
        Punto p2=new Punto(2,1);
        Punto p3=new Punto(2,-3);
        Punto p4=new Punto(-4,-3);

        q[0]=new Trapezio(p1,p2,p3,p4);
        q[1]=new Parallelogramma(p1,p2,p3,p4);
        q[2]=new Rettangolo(p1,p2,p3,p4);
        q[3]=new Rombo(p1,p2,p3,p4);
        q[4]=new Quadrato(p1,p2,p3,p4);
       
        for(int i=0;i<5;i++){
            System.out.println("Perimetro :: "+q[i].getPerimetro());
            System.out.println("Area :: "+q[i].getArea());
        }

        System.out.println("Numero rettangoli :: "+numeroRettangoli(q));
    }
}