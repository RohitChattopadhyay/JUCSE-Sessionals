package linkedList;

import java.awt.EventQueue;

import javax.swing.JFrame;	
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import javax.swing.SwingConstants;
import javax.swing.JButton;
import java.util.*;
import javax.swing.JTextField;
import java.awt.Font;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class GUIstring<T> {

	private JFrame frame;
	private JTextField keyField;
	private JTextField temp;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUIstring window = new GUIstring();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public GUIstring() {
		initialize();
	}
	private void display(JPanel p,LinkedList<T> ll) {
		p.removeAll();
		p.add(new JLabel("Head"));
		List<T> arr = LinkedList.allList(ll);
		for(T i : arr) {
			p.add(new JLabel("<html>&#10230;</html>"));
			temp = new JTextField();
			temp.setText(i.toString());
			temp.setHorizontalAlignment(SwingConstants.CENTER);
			temp.setForeground(Color.WHITE);
			temp.setBackground(Color.BLACK);
			temp.setEditable(false);
			temp.setColumns(9);
			p.add(temp);
		}
		p.add(new JLabel("<html>&#10230;<b>null</b></html>"));
		p.updateUI();
		keyField.setText("");
	}
	private void search(JPanel p,LinkedList<T> ll,T key) {
		p.removeAll();
		p.add(new JLabel("Head"));
		List<T> arr = LinkedList.allList(ll);
		for(T i : arr) {
			p.add(new JLabel("<html>&#10230;</html>"));
			temp = new JTextField();
			temp.setText(i.toString());
			temp.setHorizontalAlignment(SwingConstants.CENTER);
			if(!i.toString().toLowerCase().contains(key.toString().toLowerCase())) {
				temp.setForeground(Color.WHITE);
				temp.setBackground(Color.BLACK);				
			}
			else {
				temp.setForeground(Color.BLACK);
				temp.setBackground(Color.WHITE);				
			}
			temp.setEditable(false);
			temp.setColumns(9);
			p.add(temp);
		}
		p.add(new JLabel("<html>&#10230;<b>null</b></html>"));
		keyField.setText("");
		p.updateUI();
	}
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		//linked list start
		LinkedList<String> list = new LinkedList<String>();
		JPanel container = new JPanel();
		//linked list end
		frame.setExtendedState(JFrame.MAXIMIZED_BOTH);
		frame.setTitle("Linked List Visualization using String");
		frame.getContentPane().setLayout(new BorderLayout(0, 0));
		JLabel errMsg = new JLabel("Welcome!!");
		
		JPanel options = new JPanel();
		frame.getContentPane().add(options, BorderLayout.NORTH);
		options.setLayout(new BorderLayout(0, 0));
		
		JPanel panel_1 = new JPanel();
		options.add(panel_1);
		
		JButton insFrn = new JButton("Ins_Front");
		insFrn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if(keyField.getText().length()==0) {
					errMsg.setText("Error: Please enter an String");
					return;
				}
			  try {  
				    LinkedList.insertFront(list, keyField.getText().trim());
				    errMsg.setText("Message: Inserted " + keyField.getText().trim() + " at front");  
				    display(container,(LinkedList<T>)list);
				  } catch(NumberFormatException err){  
					  errMsg.setText("Error: Please enter an Integer");
					  return;
			  }
			}
		});
		panel_1.add(insFrn);
		
		JButton insRear = new JButton("Ins_Rear");
		insRear.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if(keyField.getText().length()==0) {
					errMsg.setText("Error: Please enter an String");
					return;
				}
				  try {  
					    LinkedList.insert(list, keyField.getText().trim());
					    errMsg.setText("Message: Inserted " + keyField.getText().trim() + " at rear");  
					    display(container,(LinkedList<T>)list);
					  } catch(NumberFormatException err){  					
						  errMsg.setText("Error: Please enter an String");
						  return;
				  }
			}
		});
		panel_1.add(insRear);
		
		JButton delFron = new JButton("Del_Front");
		delFron.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				  try {  
					    LinkedList.deleteAtPosition(list, 0);  
					    errMsg.setText("Message: Deleted from front");
					    display(container,(LinkedList<T>)list);
					  } catch(NumberFormatException err){  
						  errMsg.setText("Error: Please enter an Integer");
						  return;
				  }
			}
		});
		panel_1.add(delFron);
		
		JButton search = new JButton("Search");
		search.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if(keyField.getText().length()==0) {
					errMsg.setText("Error: Please enter an String");
					return;
				}
				  try {    
					    errMsg.setText("Message: Search result for " + keyField.getText().trim());
					    search(container,(LinkedList<T>)list,(T)keyField.getText().trim());
					  } catch(NumberFormatException err){  
						  errMsg.setText("Error: Please enter an Integer");
						  return;
				  }
			}
		});
		panel_1.add(search);
		
		keyField = new JTextField();
		keyField.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {				
				if(e.getKeyCode() == KeyEvent.VK_ENTER) {
					if(keyField.getText().length()==0) {
						errMsg.setText("Error: Please enter an Integer");
						return;
					}
					  try {  
						    LinkedList.insert(list,keyField.getText().trim());
						    errMsg.setText("Message: Inserted " + keyField.getText().trim() + " at rear");  
						    display(container,(LinkedList<T>)list);
						  } catch(NumberFormatException err){  					
							  errMsg.setText("Error: Please enter an Integer");
							  return;
					  }
				}
			}
		});
		panel_1.add(keyField);
		keyField.setToolTipText("Enter String");
		keyField.setHorizontalAlignment(SwingConstants.RIGHT);
		keyField.setColumns(10);
		
		errMsg.setFont(new Font("Dialog", Font.BOLD, 16));
		errMsg.setHorizontalAlignment(SwingConstants.CENTER);
		options.add(errMsg, BorderLayout.SOUTH);
		FlowLayout fl_container = (FlowLayout) container.getLayout();
		fl_container.setAlignment(FlowLayout.LEADING);
		frame.getContentPane().add(container, BorderLayout.CENTER);
		container.add(new JLabel("<html><hr /></html>"));
		display(container,(LinkedList<T>)list);
	}
}
