
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main1 extends JFrame{
    private JLabel l = new JLabel("Insert file name ");
    private JTextField t = new JTextField(12);
    private JLabel l2 = new JLabel("Append ");
    private JCheckBox ck = new JCheckBox();
    private JButton b = new JButton("load");
    private JTextArea a = new JTextArea(30,30);
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();

    private Main1(){
        Container c=this.getContentPane();
        b.addActionListener((ActionEvent e)->{
            try{
                BufferedReader r=new BufferedReader(new FileReader(t.getText()));
                String s,t="";
                while((s=r.readLine())!=null)
                    t+=s+"\n";
                if(ck.isSelected()==true) a.append("\n"+t);
                else a.setText(t);
                r.close();
            }catch(IOException ex){
                t.setText("File not found!");
            }
        });
        a.setEditable(false);
        p1.add(l);p1.add(t);p1.add(l2);p1.add(ck);p1.add(b);
        p2.setBorder(BorderFactory.createTitledBorder("File"));
        p2.add(a);
        c.add(p1, BorderLayout.NORTH);
        c.add(p2,BorderLayout.CENTER);
        this.pack();
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }
    
    public static void main(String[] args) {
        new Main1();
    }
}