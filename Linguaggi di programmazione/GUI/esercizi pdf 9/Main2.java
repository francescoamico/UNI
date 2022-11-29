import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

public class Main2 extends JFrame {
    private Icon i = new ImageIcon("cs.png");
    private JLabel im = new JLabel(i);
    private JButton b1 = new JButton("show secret message");
    private JButton b2 = new JButton("set password");
    private JPanel p1 = new JPanel();
    private JPanel p2 = new JPanel();
    private String psw = "";
    private String msg = "I'm the secret message.";
    private JTextField tex = new JTextField(15);

    private Main2() {
        super("Strongbox");

        b1.addActionListener(new ActionListener() {
            JFrame f = new JFrame("Insert password");
            JLabel l = new JLabel("insert psw ");
            JPasswordField p = new JPasswordField(12);
            JTextField t = new JTextField(18);
            JButton b = new JButton("show");
            JPanel panel = new JPanel();
            JPanel panel2 = new JPanel();
            JPanel panel3 = new JPanel();
            int count = 3;

            @Override
            public void actionPerformed(ActionEvent ev) {
                if (!psw.equals("")) {
                    t.setEditable(false);
                    b.addActionListener(new MioListener());
                    panel.add(l);
                    panel.add(p);
                    panel2.add(b);
                    panel3.add(t);
                    f.getContentPane().add(panel, BorderLayout.NORTH);
                    f.getContentPane().add(panel2);
                    f.getContentPane().add(panel3, BorderLayout.SOUTH);
                    f.pack();
                    f.setVisible(true);
                    f.setLocationRelativeTo(null);
                } else
                    tex.setText("unsetted password!");
            }

            class MioListener implements ActionListener {
                @Override
                public void actionPerformed(ActionEvent ev) {
                    if (count > 0) {
                        if (new String(p.getPassword()).equals(psw)) {
                            count = 3;
                            t.setText(msg);
                        } else {
                            count--;
                            t.setText("wrong password! " + count + " attempts left...");
                        }
                    } else
                        t.setText("strongbox locked!");
                }
            }
        });

        b2.addActionListener((ActionEvent e) -> {
            if (this.psw.equals("")) {
                JFrame f = new JFrame("Set Password");
                JLabel l = new JLabel("set psw ");
                JPasswordField p = new JPasswordField(12);
                JTextField t = new JTextField(13);
                JButton b = new JButton("set");
                JPanel panel = new JPanel();
                JPanel panel2 = new JPanel();
                JPanel panel3 = new JPanel();

                p.getDocument().addDocumentListener(new DocumentListener() {
                    @Override
                    public void insertUpdate(DocumentEvent e) {
                        String psw = new String(p.getPassword());
                        if (psw.length() < 6 && !psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.RED);
                        else if (psw.length() > 6 && psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.GREEN);
                        else
                            p.setBackground(Color.ORANGE);
                    }

                    @Override
                    public void removeUpdate(DocumentEvent e) {
                        String psw = new String(p.getPassword());
                        if (psw.length() < 6 && !psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.RED);
                        else if (psw.length() > 6 && psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.GREEN);
                        else
                            p.setBackground(Color.ORANGE);
                    }

                    @Override
                    public void changedUpdate(DocumentEvent e) {
                        String psw = new String(p.getPassword());
                        if (psw.length() < 6 && !psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.RED);
                        else if (psw.length() > 6 && psw.matches(".*(0|1|2|3|4|5|6|7|8|9).*"))
                            p.setBackground(Color.GREEN);
                        else
                            p.setBackground(Color.ORANGE);
                    }
                });

                b.addActionListener((ActionEvent ev) -> {
                    if (new String(p.getPassword()).length() != 0) {
                        this.psw = new String(p.getPassword());
                        f.setVisible(false);
                    } else
                        t.setText("invalid password!");
                });

                t.setEditable(false);
                panel.add(l);
                panel.add(p);
                panel2.add(b);
                panel3.add(t);
                f.getContentPane().add(panel, BorderLayout.NORTH);
                f.getContentPane().add(panel2);
                f.getContentPane().add(panel3, BorderLayout.SOUTH);
                f.pack();
                f.setVisible(true);
                f.setLocationRelativeTo(null);
            } else
                tex.setText("password already setted!");
        });

        Container c = this.getContentPane();
        tex.setEditable(false);
        p1.add(b1);
        p1.add(b2);
        p2.add(tex);
        c.add(im, BorderLayout.NORTH);
        c.add(p1, BorderLayout.CENTER);
        c.add(p2, BorderLayout.SOUTH);
        this.pack();
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        new Main2();
    }
}