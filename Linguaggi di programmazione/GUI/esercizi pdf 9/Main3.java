import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class Main3 extends JFrame {
    private JMenuBar menuBar = new JMenuBar();
    private JMenu file = new JMenu("File");
    private JMenuItem newFile = new JMenuItem("new            CTRL+N");
    private JMenuItem newWin = new JMenuItem("new window");
    private JMenuItem open = new JMenuItem("open...");
    private JMenuItem save = new JMenuItem("save          CTRL+S");
    private JMenu edit = new JMenu("Edit");
    private JMenuItem cut = new JMenuItem("cut              CTRL+X");
    private JMenuItem cpy = new JMenuItem("copy           CTRL+C");
    private JMenuItem pst = new JMenuItem("paste          CTRL+V");
    private JMenuItem selectAll = new JMenuItem("select all    CTRL+A");
    private JTextArea txt = new JTextArea(400, 400);
    private JScrollPane scroll = new JScrollPane(txt);
    private JFileChooser chooser = new JFileChooser();

    private Main3() {
        super("Editor");

        newFile.addActionListener((ActionEvent e) -> {
            JFrame f = new JFrame("Editor");
            JLabel l = new JLabel("save changes?");
            JPanel p = new JPanel();
            JPanel p2 = new JPanel();
            JButton b1 = new JButton("save");
            JButton b2 = new JButton("not save");
            JButton b3 = new JButton("cancel");
            b1.addActionListener((ActionEvent ev) -> {
                chooser.showSaveDialog(null);
                try {
                    PrintWriter w = new PrintWriter(new FileWriter(chooser.getSelectedFile().getPath()));
                    w.write(txt.getText());
                    w.close();
                } catch (IOException e1) {
                    txt.setText("Impossible to save file");
                }
                f.dispose();
            });
            b2.addActionListener((ActionEvent ev) -> {
                txt.setText("");
                f.dispose();
            });
            b3.addActionListener((ActionEvent ev) -> f.dispose());
            l.setFont(new Font(Font.SANS_SERIF, Font.ITALIC, 20));
            p2.add(l);
            f.getContentPane().add(p2, BorderLayout.NORTH);
            p.add(b1);
            p.add(b2);
            p.add(b3);
            f.getContentPane().add(p, BorderLayout.CENTER);
            f.setSize(300, 125);
            f.setVisible(true);
            f.setLocationRelativeTo(null);
        });
        newWin.addActionListener((ActionEvent e) -> new Main3());
        open.addActionListener((ActionEvent e) -> {
            chooser.setDialogTitle("Open file");
            chooser.showOpenDialog(this);
            txt.setText("");
            try (BufferedReader r = new BufferedReader(new FileReader(chooser.getSelectedFile().getPath()))) {
                String s;
                while ((s = r.readLine()) != null)
                    txt.append(s + "\n");
                r.close();
            } catch (IOException e1) {
                txt.setText("Impossible to open this file");
            }
        });
        save.addActionListener((ActionEvent ev) -> {
            chooser.showSaveDialog(null);
            try {
                PrintWriter w = new PrintWriter(new FileWriter(chooser.getSelectedFile().getPath()));
                w.write(txt.getText());
                w.close();
            } catch (IOException e1) {
                txt.setText("Impossible to save file");
            }
        });
        file.add(newFile);
        file.add(newWin);
        file.add(open);
        file.add(save);
        cut.addActionListener((ActionEvent e) -> txt.cut());
        cpy.addActionListener((ActionEvent e) -> txt.copy());
        pst.addActionListener((ActionEvent e) -> txt.paste());
        selectAll.addActionListener((ActionEvent e) -> txt.selectAll());
        menuBar.add(file);
        menuBar.add(edit);
        edit.add(cut);
        edit.add(cpy);
        edit.add(pst);
        edit.add(selectAll);
        txt.addKeyListener(new MyListener());
        txt.setFont(new Font(Font.SANS_SERIF, Font.ITALIC, 20));
        this.getContentPane().add(scroll);
        this.setJMenuBar(menuBar);
        this.setSize(500, 500);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
    }

    class MyListener extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            if (e.isControlDown() && e.getKeyChar() != 's' && e.getKeyCode() == 83) {
                chooser.showSaveDialog(null);
                try {
                    PrintWriter w = new PrintWriter(new FileWriter(chooser.getSelectedFile().getPath()));
                    w.write(txt.getText());
                    w.close();
                } catch (IOException e1) {
                    txt.setText("Impossible to save file");
                }
            }
            if (e.isControlDown() && e.getKeyChar() != 'n' && e.getKeyCode() == 78) {
                JFrame f = new JFrame("Editor");
                JLabel l = new JLabel("save changes?");
                JPanel p = new JPanel();
                JPanel p2 = new JPanel();
                JButton b1 = new JButton("save");
                JButton b2 = new JButton("not save");
                JButton b3 = new JButton("cancel");
                b1.addActionListener((ActionEvent ev) -> {
                    chooser.showSaveDialog(null);
                    try {
                        PrintWriter w = new PrintWriter(new FileWriter(chooser.getSelectedFile().getPath()));
                        w.write(txt.getText());
                        w.close();
                    } catch (IOException e1) {
                        txt.setText("Impossible to save file");
                    }
                    f.dispose();
                });
                b2.addActionListener((ActionEvent ev) -> {
                    txt.setText("");
                    f.dispose();
                });
                b3.addActionListener((ActionEvent ev) -> f.dispose());
                l.setFont(new Font(Font.SANS_SERIF, Font.ITALIC, 20));
                p2.add(l);
                f.getContentPane().add(p2, BorderLayout.NORTH);
                p.add(b1);
                p.add(b2);
                p.add(b3);
                f.getContentPane().add(p, BorderLayout.CENTER);
                f.setSize(300, 125);
                f.setVisible(true);
                f.setLocationRelativeTo(null);
            }
        }
    }

    public static void main(String[] args) {
        new Main3().setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}