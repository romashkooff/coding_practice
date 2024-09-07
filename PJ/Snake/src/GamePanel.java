import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

//import java.io.File;
//import java.io.BufferedWriter;
//import java.io.FileWriter;
//import java.io.IOException;

public class GamePanel extends JPanel implements ActionListener {

    static final int SCREEN_WIDTH = 600;
    static final int SCREEN_HEIGHT = 600;
    static final int UNIT_SIZE = 25;
    static final int GAME_UNITS = (SCREEN_WIDTH*SCREEN_HEIGHT)/UNIT_SIZE;
    static final int DELAY = 100;
    final int[] x = new int[GAME_UNITS];
    final int[] y = new int [GAME_UNITS];
    int bodyParts = 6;
    int applesEaten;
    int appleX;
    int appleY;
    char direction = 'R';
    boolean running = false;
    Timer timer;
    Random random;
    GamePanel(){                                                                            // Defines object GamePanel
        random = new Random();
        this.setPreferredSize(new Dimension(SCREEN_WIDTH, SCREEN_HEIGHT));
        this.setBackground(Color.black);
        this.setFocusable(true);
        this.addKeyListener(new MyKeyAdapter());
        startGame();
    }

    public void startGame() {                                                               // Starts game
        newApple();
        running = true;
        timer = new Timer(DELAY, this);
        timer.start();
    }
    public void paintComponent(Graphics g) {
        super.paintComponent(g);                                                          // Draws background
        draw(g);
    }
    public void draw(Graphics g) {
        if(running) {
//            for (int i = 0; i < SCREEN_HEIGHT / UNIT_SIZE; i++) {                       // Draws vert. and hor. lines
//                g.drawLine(i * UNIT_SIZE, 0, i * UNIT_SIZE, SCREEN_HEIGHT);
//                g.drawLine(0, i * UNIT_SIZE, SCREEN_WIDTH, i * UNIT_SIZE);
//            }

            g.setColor(Color.red);                                                        // Draws an apple
            g.fillOval(appleX, appleY, UNIT_SIZE, UNIT_SIZE);

            g.setFont(new Font("Ink Free", Font.BOLD, 40));
            FontMetrics metrics = getFontMetrics(g.getFont());
            g.drawString("Score: " + applesEaten, (SCREEN_WIDTH - metrics.stringWidth("Score: " + applesEaten))/2, g.getFont().getSize());      // Draws centered Score according to its width

            for (int i = 0; i < bodyParts; i++) {                                       // Draws snake
                if (i == 0) {
                    g.setColor(Color.green);
                    g.fillRect(x[i], y[i], UNIT_SIZE, UNIT_SIZE);
                } else {
                    g.setColor(new Color(45, 180, 0));
                    g.fillRect(x[i], y[i], UNIT_SIZE, UNIT_SIZE);
                }
            }
        }
        else {
            gameOver(g);
        }
    }
    public void newApple() {                                                            // Gets new position of an apple
        appleX = random.nextInt(SCREEN_WIDTH/UNIT_SIZE)*UNIT_SIZE;
        appleY = random.nextInt(SCREEN_HEIGHT/UNIT_SIZE)*UNIT_SIZE;
    }
    public void move() {                                                                // Implements movement
        for(int i = bodyParts; i>0; i--) {
            x[i] = x[i-1];
            y[i] = y[i-1];
        }

        switch (direction){
            case 'U':
                y[0] = y[0] - UNIT_SIZE;
                break;
            case 'D':
                y[0] = y[0] + UNIT_SIZE;
                break;
            case 'R':
                x[0] = x[0] + UNIT_SIZE;
                break;
            case 'L':
                x[0] = x[0] - UNIT_SIZE;
                break;
        }
    }
    public void checkApple() {                                                          // Checks whether apple is eaten
        if((x[0] == appleX) && (y[0] == appleY)) {
            bodyParts++;
            applesEaten++;
            newApple();
        }
    }
    public void checkCollisions() {
        // Checks if head collides with body
        for(int i = bodyParts; i > 0; i--) {
            if (x[0] == x[i] && y[0] == y[i]) {
                running = false;
                break;
            }
        }
        // Check if head touches left border
        if(x[0]<0) {
            running = false;
        }
        // Check if head touches right border
        if(x[0]>SCREEN_WIDTH) {
            running = false;
        }
        // Check if head touches top border
        if(y[0]<0) {
            running = false;
        }
        // Check if head touches bottom border
        if(y[0]>SCREEN_HEIGHT) {
            running = false;
        }
        if(!running) {
            timer.stop();
//            saveScoreToTxt();
            saveScoreToDatabase();
        }
    }

    public void gameOver(Graphics g) {                                                  // Game over overlay
        //Game Over text + Score
        g.setColor(Color.red);
        g.setFont(new Font("Ink Free", Font.BOLD, 75));
        FontMetrics metrics_gameOver = getFontMetrics(g.getFont());
        g.drawString("Game Over", (SCREEN_WIDTH - metrics_gameOver.stringWidth("Game Over"))/2, SCREEN_HEIGHT/2);

        g.setColor(Color.red);
        g.setFont(new Font("Ink Free", Font.BOLD, 40));
        FontMetrics metrics_score = getFontMetrics(g.getFont());
        g.drawString("Score: " + applesEaten, (SCREEN_WIDTH - metrics_score.stringWidth("Score: " + applesEaten))/2, g.getFont().getSize());
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(running) {
            move();
            checkApple();
            checkCollisions();
        }
        repaint();
    }

    public void saveScoreToDatabase() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            String url = "jdbc:mysql://localhost:3306/score";
            String user = "root";
            String password = "";

            try (Connection connection = DriverManager.getConnection(url, user, password)) {
                String query = "INSERT INTO scores (nickname, score) VALUES (?, ?)";

                try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                    String nickname = JOptionPane.showInputDialog("Enter your nickname:");

                    if (nickname == null || nickname.trim().isEmpty()) {
                        nickname = "Anonymous";
                    }

                    preparedStatement.setString(1, nickname);
                    preparedStatement.setInt(2, applesEaten);

                    preparedStatement.executeUpdate();
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            throw new RuntimeException(e);
        }
    }

//    public void saveScoreToTxt() {                                      // Records player's name and score to the file
//        try {
//            // Prompt the player for their name using JOptionPane
//            String nickname = JOptionPane.showInputDialog("Enter your nickname:");
//
//            if (nickname == null || nickname.trim().isEmpty()) {
//                nickname = "Anonymous";
//            }
//
//            File file = new File("scores.txt");
//
//            try (BufferedWriter writer = new BufferedWriter(new FileWriter(file, true))) {
//                writer.write("Nickname: " + nickname +", Score: " + applesEaten + "; ");
//                writer.newLine();
//            }
//        }
//        catch (IOException e) {
//        throw new RuntimeException(e);
//        }
//    }


    public void restartGame() {                                                             // Restarts game
        new GameFrame();
    }
    public class MyKeyAdapter extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {                                                // Snake's moving
            switch (e.getKeyCode()) {
                case KeyEvent.VK_A:
                    if(direction != 'R') {
                        direction = 'L';
                    }
                    break;
                case KeyEvent.VK_D:
                    if(direction != 'L') {
                        direction = 'R';
                    }
                    break;
                case KeyEvent.VK_W:
                    if(direction != 'D') {
                        direction = 'U';
                    }
                    break;
                case KeyEvent.VK_S:
                    if(direction != 'U') {
                        direction = 'D';
                    }
                    break;
                case KeyEvent.VK_R:
                    restartGame();
                    break;
            }
        }
    }
}
