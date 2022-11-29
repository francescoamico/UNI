import java.awt.event.*;

public class MioMouseAdapter extends MouseAdapter {
    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println("Click su (" + e.getX() + "," + e.getY() + ")");
    }

    @Override
    public void mousePressed(MouseEvent e) {
        System.out.println("Premuto su (" + e.getX() + "," + e.getY() + ")");
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        System.out.println("Rilasciato su (" + e.getX() + "," + e.getY() + ")");
    }
    // @Override public void mouseEntered(MouseEvent e) { }
    // @Override public void mouseExited(MouseEvent e) { }
}

public class MyFrame extends JFrame {
    private MyFrame() {
        super("Esempio di MouseAdapter");
        this.addMouseListener(new MioMouseAdapter());
        setSize(200, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MyFrame();
    }
}