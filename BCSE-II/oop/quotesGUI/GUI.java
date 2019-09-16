package quotesGUI;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;
import java.awt.Canvas;
import javax.swing.JSeparator;
import java.awt.Window.Type;

class quoteFetch implements Runnable{  
	JLabel data;
	quoteFetch(JLabel t){
		data = t;
	}
	public void run(){  
		data.setText(Source.getQuote());
		System.out.println("New quote fetched");  
	}
}

class colorChange implements Runnable{  
	JLabel a;
	JLabel b;
	JPanel c;
	Color fore;
	Color back;
	colorChange(JLabel a,JLabel b,JPanel c){
		this.a = a;
		this.b = b;
		this.c = c;
	}
	public void run(){
		getColor();
		a.setForeground(fore);
		b.setForeground(fore);
		c.setBackground(back);
		System.out.println("Colors Changed");  
	}
	private void getColor() {
		Random rand = new Random();
		int r = rand.nextInt(255);
		int b = rand.nextInt(255);
		int g = rand.nextInt(255);
		this.fore =  new Color(r,b,g);
		this.back =  new Color(255-r,255-b,255-g);
	}
}


public class GUI extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI frame = new GUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public GUI() {
		setTitle("Quote GUI");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JLabel labelQoute = new JLabel(Source.getQuote());
		labelQoute.setFont(new Font("Chilanka", Font.BOLD, 18));
		labelQoute.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(labelQoute, BorderLayout.CENTER);
		
		JLabel labelTitle = new JLabel("Quote of the Day");
		labelTitle.setFont(new Font("Gargi", Font.BOLD, 17));
		labelTitle.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(labelTitle, BorderLayout.NORTH);
		quoteFetch m1=new quoteFetch(labelQoute);  
		colorChange clr = new colorChange(labelTitle,labelQoute,contentPane);
		
		JButton nextButton = new JButton("Next Quote");
		nextButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				Thread t1 = new Thread(m1);
				Thread t2 = new Thread(clr);
				t1.start();
				t2.start();

			}
		});
		nextButton.setBackground(Color.LIGHT_GRAY);
		nextButton.setFont(new Font("Garuda", Font.BOLD, 13));
		contentPane.add(nextButton, BorderLayout.SOUTH);
	}
}
