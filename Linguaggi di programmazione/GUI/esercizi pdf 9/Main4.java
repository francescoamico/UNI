import java.awt.*;
import java.awt.event.*;
import java.util.*;

import javax.swing.*;

public class Main4 extends JFrame {
    private JButton[] b1 = { new JButton("1A"), new JButton("1B"), new JButton("1C"), new JButton("2A"),
            new JButton("2B"),
            new JButton("2C"), new JButton("3A"), new JButton("3B"), new JButton("3C"), new JButton("4A"),
            new JButton("4B"), new JButton("4C") };
    private JButton[] b2 = { new JButton("1D"), new JButton("1E"), new JButton("1F"), new JButton("2D"),
            new JButton("2E"),
            new JButton("2F"), new JButton("3D"), new JButton("3E"), new JButton("3F"), new JButton("4D"),
            new JButton("4E"), new JButton("4F") };
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();
    private JMenuBar bar = new JMenuBar();
    private JMenu menu = new JMenu("menu");
    private JMenuItem item = new JMenuItem("list");
    private ArrayList<String> nc = new ArrayList<>();

    private Main4() {
        super("Aereo");
        p1.setLayout(new GridLayout(4, 3));
        p2.setLayout(new GridLayout(4, 3));
        for (int i = 0; i < 12; i++) {
            p1.add(b1[i]);
            b1[i].addActionListener(new Mylistener(b1[i], nc));
            p2.add(b2[i]);
            b2[i].addActionListener(new Mylistener(b2[i], nc));
        }
        item.addActionListener((ActionEvent e) -> {
            JFrame f = new JFrame("List");
            JTextArea txt = new JTextArea();
            for (String s : nc) {
                txt.append(s + "\n");
            }
            txt.setEditable(false);
            f.getContentPane().add(txt);
            f.setSize(300, 150);
            f.setLocationRelativeTo(null);
            f.setVisible(true);
        });
        this.setJMenuBar(bar);
        bar.add(menu);
        menu.add(item);
        this.getContentPane().add(p1, BorderLayout.WEST);
        this.getContentPane().add(p2, BorderLayout.EAST);
        this.setSize(400, 700);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    class Mylistener implements ActionListener {
        private JFrame f = new JFrame("Setting");
        private JButton b1 = new JButton("cancel");
        private JButton b2 = new JButton("add");
        private JTextField t = new JTextField(15);
        private JPanel p1 = new JPanel();
        private JPanel p2 = new JPanel();

        public Mylistener(JButton b, ArrayList<String> nc) {
            b1.addActionListener((ActionEvent ev) -> {
                if (b.getBackground().equals(new JButton().getBackground())) {
                    t.setText("Position already empty!");
                } else {
                    String s = "";
                    for (String t : nc) {
                        if (t.startsWith(b.getActionCommand()))
                            s = t;
                    }
                    nc.remove(s);
                    b.setBackground(null);
                    f.dispose();
                }
            });
            b2.addActionListener((ActionEvent ev) -> {
                if (b.getBackground().equals(Color.LIGHT_GRAY)) {
                    t.setText("Position already occupied!");
                } else {
                    JFrame f1 = new JFrame("Add passenger " + b.getActionCommand());
                    JLabel l = new JLabel("name ");
                    JTextField txt = new JTextField(12);
                    JButton b3 = new JButton("add");
                    JPanel panel = new JPanel();
                    b3.addActionListener((ActionEvent event) -> {
                        nc.add(b.getActionCommand() + " :: " + txt.getText());
                        b.setBackground(Color.LIGHT_GRAY);
                        f1.dispose();
                    });
                    panel.add(l);
                    panel.add(txt);
                    panel.add(b3);
                    f1.getContentPane().add(panel);
                    f1.setSize(300, 75);
                    f1.setLocationRelativeTo(null);
                    f1.setVisible(true);
                    f.dispose();
                }
            });
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            t.setText("");
            t.setEditable(false);
            p1.add(b1);
            p1.add(b2);
            p2.add(t);
            f.getContentPane().add(p1, BorderLayout.NORTH);
            f.getContentPane().add(p2, BorderLayout.CENTER);
            f.setSize(300, 100);
            f.setLocationRelativeTo(null);
            f.setVisible(true);
        }
    }

    public static void main(String[] args) {
        new Main4();
    }
}
