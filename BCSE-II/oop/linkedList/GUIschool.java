package linkedList;

import java.awt.EventQueue;

import javax.swing.*;	

import java.awt.FlowLayout;
import java.awt.BorderLayout;
import javax.swing.JButton;
import java.util.*;
import javax.swing.JTextField;
import javax.swing.border.Border;

import java.awt.Font;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.text.*;
import java.awt.GridLayout;
import javax.swing.JTextArea;
import java.awt.SystemColor;

class Student{
	private static Integer[] deptCount = {0,0,0,0,0};
	private static String[] deptName = {
			"Computer Science Engineering",
			"Electronics and Telecommunication Engineering",
			"Information Technology",
			"Civil Engineering"
			};	
	private static String[][] subjects = {
			{"Object Oriented Programming","Mathematics V","Computer Architecture","Graph Theory","Microprocessor"},
			{"Network Analysis","Digital Electronics","Electrical Machines","Environment Studies","Analog Electronics"},
			{"Database Management","Web Designing","Software Engineering","Data Structures","Computer Organization"},
			{"Structural Mechanics","Concrete Technology","Fluid Mechanics","Railway Technology","Building and Town Planning"}
	};
	private static String[] deptCode = {
			"BCSE",
			"ETCE",
			"InTe",
			"CivE"
			};
	public Student(String name, int depID) {
		super();
		this.name = name;
		this.deptID = deptCode[depID];
		this.department = deptName[depID];
		this.roll = String.format("%s%03d",deptID, ++deptCount[depID]);
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
		Date date = new Date();
		this.adm_date = dateFormat.format(date);
		this.mySubjects = subjects[depID];
	}
	private String name;
	private String deptID;
	private String department;
	private String roll;
	private Integer marks[] = {-1,0,0,0,0,0};
	private String adm_date;
	private String[] mySubjects;
	private double cgpa = 0.0;
	
	public String getName() {
		return name;
	}
	public String getDepID() {
		return deptID;
	}
	public String getDepartment() {
		return department;
	}
	public String getRoll() {
		return roll;
	}
	public Integer[] getMarks() {
		if(marks[0] == -1 ) return null;
		return marks;
	}
	public boolean setMarks(Integer[] marks) {
		if(this.marks[0]!=-1)
			return false;		
		this.marks = marks;	
		for(int i : marks) {
			if(i>39) cgpa += (double)i;
			else if(i>0) cgpa += -1000;
		}
		return true;
	}
	public String getAdm_date() {
		return adm_date;
	}	
	public String[] getSubjects() {
		return mySubjects;
	}
	public Double getCGPA() {		
		return cgpa/(mySubjects.length*10);
	}
}

public class GUIschool {

	private JFrame frame;
	private JTextField keyField;
	private JTextField temp;
	private JPanel container;
	private JPanel studentInfoBox = new JPanel();
	private JButton marksSaveBtn = new JButton("Save Marks");
	private JTextArea marksContainers[] = new JTextArea[5];
	private Student dummyStudent;
	private JTextArea studentInfoMsg = new JTextArea();
	
	ArrayList<LinkedList<Student>> departments = new ArrayList<LinkedList<Student>>();
	JPanel[] deptPane = new JPanel[4] ;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUIschool window = new GUIschool();
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
	public GUIschool() {
		initialize();
	}
	private void display(JPanel p,LinkedList<Student> ll,int deptID) {
		p.removeAll();
		studentInfoBox.setVisible(false);
		studentInfoMsg.setText("Search or Click on student to get info");
		
		container.setLayout(new GridLayout(0, 1, 0, 0));
		List<Student> arr = LinkedList.allList(ll);
		String prefix = "";
		switch(deptID) {
			case 0: {	prefix = "CSE";	break;		}
			case 1: {	prefix = "ETC";	break;		}
			case 2: {	prefix = "IT";	break;		}
			case 3: {	prefix = "Civ";	break;		}			
		}
		p.add(new JLabel(String.format("<html>%s&emsp;:</html>",prefix)));
		for(Student i : arr) {
			p.add(new JLabel("<html>&#10230;</html>"));
			temp = new JTextField();
			temp.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					search(deptPane,departments,i.getRoll());
				}
			});
			temp.setText(i.getRoll());
			temp.setHorizontalAlignment(SwingConstants.CENTER);
			temp.setForeground(Color.WHITE);
			if(i.getMarks()!=null) 
				temp.setForeground(Color.GREEN);
			temp.setBackground(Color.BLACK);
			temp.setEditable(false);
			temp.setColumns(9);
			p.add(temp);
		}
		p.add(new JLabel("<html>&#10230;<b>null</b></html>"));
		p.updateUI();
		keyField.setText("");
	}
	private void search(JPanel[] ps,ArrayList<LinkedList<Student>> departments,String key) {
		int deptID = 0;
		studentInfoMsg.setText("");
		studentInfoBox.setVisible(false);
		marksSaveBtn.setVisible(false);
		marksSaveBtn.setBackground(Color.LIGHT_GRAY);
		container.setLayout(new GridLayout(0, 1, 0, 0));
		for(LinkedList<Student> department : departments ) {;
			JPanel p = ps[deptID];
			p.removeAll();
			List<Student> arr = LinkedList.allList(department);
			String prefix = "";
			switch(deptID) {
				case 0: {	prefix = "CSE";	break;		}
				case 1: {	prefix = "ETC";	break;		}
				case 2: {	prefix = "IT";	break;		}
				case 3: {	prefix = "Civ";	break;		}			
			}
			p.add(new JLabel(String.format("<html>%s&emsp;:</html>",prefix)));
			for(Student i : arr) {
				p.add(new JLabel("<html>&#10230;</html>"));
				temp = new JTextField();
				temp.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent e) {
						search(deptPane,departments,i.getRoll());
					}
				});
				temp.setText(i.getRoll());
				temp.setHorizontalAlignment(SwingConstants.CENTER);
				if(key.toUpperCase().equals(i.getRoll().toUpperCase())) {
					temp.setForeground(Color.BLACK);
					temp.setBackground(Color.WHITE);
					infoBoxDisplayer(i);
				}
				else {
					temp.setForeground(Color.WHITE);
					temp.setBackground(Color.BLACK);
				}
				if(i.getMarks()!=null) 
					temp.setForeground(Color.GREEN);
				
				temp.setEditable(false);
				temp.setColumns(9);
				p.add(temp);
			}
			p.add(new JLabel("<html>&#10230;<b>null</b></html>"));
			deptID++;
		}
		container.updateUI();
		keyField.setText("");
	}
	private void infoBoxDisplayer(Student s) {
		// TODO Auto-generated method stub
		studentInfoBox.removeAll();
		
		//iteration begins
//			label = new JLabel("New label");
//			label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
//			label.setVerticalAlignment(SwingConstants.TOP);
//			studentInfoBox.add(label);
//			JTextArea textArea = new JTextArea();
//			textArea.setEditable(false);
//			textArea.setBackground(new Color(238,238,238));
//			textArea.setLineWrap(true);
//			textArea.setWrapStyleWord(true);
//			studentInfoBox.add(textArea);
		//iteration ends

		//Roll number
		JLabel label = new JLabel("Roll Number");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		JLabel rollNo = new JLabel(s.getRoll());
		rollNo.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		rollNo.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(rollNo);
		
		//Name
		label = new JLabel("Name");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		JTextArea textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setBackground(new Color(238,238,238));
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		textArea.setText(s.getName());
		studentInfoBox.add(textArea);
		
		//Department
		label = new JLabel("Department");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setBackground(new Color(238,238,238));
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		textArea.setText(s.getDepartment());
		studentInfoBox.add(textArea);
		
		//Admission Date
		label = new JLabel("Admitted on");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setBackground(new Color(238,238,238));
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		textArea.setText(s.getAdm_date());
		studentInfoBox.add(textArea);
		
	
		//Marks
		label = new JLabel("<html><br/>Marksheet</html>");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		label = new JLabel();
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		label = new JLabel("Subject");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		studentInfoBox.add(label);
		label = new JLabel("Marks");
		label.setFont(new Font("AnjaliOldLipi", Font.BOLD, 13));
		label.setVerticalAlignment(SwingConstants.TOP);
		label.setHorizontalAlignment(SwingConstants.CENTER);
		studentInfoBox.add(label);
		
		Integer marks[] = s.getMarks();
		String subjects[] = s.getSubjects();
		boolean flag = marks==null?false:true;
		int i = 0;		
		marksContainers[0] = new JTextArea();
		marksContainers[1] = new JTextArea();
		marksContainers[2] = new JTextArea();
		marksContainers[3] = new JTextArea();
		marksContainers[4] = new JTextArea();
		
		for(String subject : subjects) {
			Border border = BorderFactory.createLineBorder(new Color(238,238,238));
			JTextArea mark = marksContainers[i];
			if(flag) {
				mark.setText((marks[i+1]>39?marks[i+1].toString():"X"));				
				mark.setEditable(false);
				mark.setBackground(new Color(238,238,238));
			}
			mark.setBorder(border);
			mark.setColumns(5);
			textArea = new JTextArea();
			textArea.setBackground(new Color(238,238,238));
			textArea.setLineWrap(true);
			textArea.setEditable(false);
			textArea.setWrapStyleWord(true);
			textArea.setText(subject);
			studentInfoBox.add(textArea);
			studentInfoBox.add(mark);
			i++;
		}
		if(flag && s.getCGPA()>0) {
			//pass
			JTextArea mark = new JTextArea();
			mark.setText(s.getCGPA().toString());
			mark.setEditable(false);
			mark.setBackground(new Color(238,238,238));
			mark.setColumns(5);
			textArea = new JTextArea();
			textArea.setEditable(false);
			textArea.setBackground(new Color(238,238,238));
			textArea.setLineWrap(true);
			textArea.setWrapStyleWord(true);
			textArea.setText("CGPA");
			studentInfoBox.add(textArea);
			studentInfoBox.add(mark);
			marksSaveBtn.setVisible(false);
		}
		else if(!flag) {
			//not set
			dummyStudent = s;
			marksSaveBtn.setVisible(true);
		}
		else {
			//fail
			JTextArea mark = new JTextArea();
			mark.setText("X");
			mark.setEditable(false);
			mark.setBackground(new Color(238,238,238));
			mark.setForeground(Color.RED);
			mark.setColumns(5);
			textArea = new JTextArea();
			textArea.setEditable(false);
			textArea.setBackground(new Color(238,238,238));
			textArea.setLineWrap(true);
			textArea.setWrapStyleWord(true);
			textArea.setText("CGPA");
			studentInfoBox.add(textArea);
			studentInfoBox.add(mark);
			marksSaveBtn.setVisible(false);
		}
		
		//make it visible
		studentInfoBox.updateUI();
		studentInfoBox.setVisible(true);
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		//linked list start
		departments.add(new LinkedList<Student>());
		departments.add(new LinkedList<Student>());
		departments.add(new LinkedList<Student>());
		departments.add(new LinkedList<Student>());
		LinkedList<Student> list = departments.get(0);
		container = new JPanel();
		deptPane[0] = new JPanel();
		deptPane[1] = new JPanel();
		deptPane[2] = new JPanel();
		deptPane[3] = new JPanel();
		//linked list end
		frame.setExtendedState(JFrame.MAXIMIZED_BOTH);
		frame.setTitle("School Linked List Visualization");
		frame.getContentPane().setLayout(new BorderLayout(0, 0));
		JLabel errMsg = new JLabel("Welcome!!");
		
		JPanel options = new JPanel();
		frame.getContentPane().add(options, BorderLayout.NORTH);
		options.setLayout(new BorderLayout(0, 0));
		
		JPanel menu = new JPanel();
		options.add(menu);

		studentInfoMsg.setLineWrap(true);
		studentInfoMsg.setWrapStyleWord(true);
		studentInfoMsg.setEditable(false);
		studentInfoMsg.setBackground(new Color(238,238,238));
		
		
		JButton insRear = new JButton("Add Student");
		insRear.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				JTextField name = new JTextField();

				JComboBox<String> department = new JComboBox<String>();
				department.setModel(new DefaultComboBoxModel<String>(new String[] {"Select Department", "Computer Science Engineering", "Electronics and Telecommincation Engineering", "Information Technology", "Civil Engineering"}));
				Object[] message = {
				    "Enter Name", name,
				    "Select Department:", department
				};	

				int option = JOptionPane.showConfirmDialog(frame, message, "Enter Student Details", JOptionPane.OK_CANCEL_OPTION,1);
				if (option == JOptionPane.OK_OPTION) {
					String Name = name.getText();
					String stuErrMsg = "";
					int deptID = department.getSelectedIndex()-1;
					if(Name.length()<2)
						stuErrMsg += "name ";
					if(deptID<0)
						stuErrMsg += "department ";
					if(stuErrMsg.length()>1) {
						errMsg.setText("Invalid " + stuErrMsg + "entered.");					
					}
					else {
						errMsg.setText("Student alloted roll number: " + (LinkedList.insert(departments.get(deptID), new Student(Name,deptID))).getRoll());						
						display(deptPane[deptID],departments.get(deptID),deptID);
					}
				} else {
				    System.out.println("Student addition canceled");
				}			
			}
		});
		
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
					    search(deptPane,departments,keyField.getText().trim());
					  } catch(NumberFormatException err){  
						  errMsg.setText("Error: Please enter an Integer");
						  return;
				  }
			}
		});
		
		keyField = new JTextField();
		search.setBackground(Color.LIGHT_GRAY);
		insRear.setBackground(Color.LIGHT_GRAY);
		
		//create menu
		menu.add(keyField);
		menu.add(search);
		menu.add(insRear);
		
		keyField.setToolTipText("Enter Roll number");
		keyField.setHorizontalAlignment(SwingConstants.RIGHT);
		keyField.setColumns(10);
				
		errMsg.setFont(new Font("Dialog", Font.BOLD, 16));
		errMsg.setHorizontalAlignment(SwingConstants.CENTER);
		options.add(errMsg, BorderLayout.SOUTH);
		
		frame.getContentPane().add(container, BorderLayout.CENTER);		
		for(int i = 0; i<deptPane.length;i++) {
			display(deptPane[i],departments.get(i),i);
		}
		FlowLayout flowLayout_3 = (FlowLayout) (deptPane[0]).getLayout();
		flowLayout_3.setAlignment(FlowLayout.LEFT);
		container.add(deptPane[0]);
		
		FlowLayout flowLayout_2 = (FlowLayout) deptPane[1].getLayout();
		flowLayout_2.setAlignment(FlowLayout.LEFT);
		container.add(deptPane[1]);
		
		FlowLayout flowLayout_1 = (FlowLayout) deptPane[2].getLayout();
		flowLayout_1.setAlignment(FlowLayout.LEFT);
		container.add(deptPane[2]);
		
		FlowLayout flowLayout = (FlowLayout) deptPane[3].getLayout();
		flowLayout.setAlignment(FlowLayout.LEFT);
		container.add(deptPane[3]);
		
		JPanel studentInfo = new JPanel();
		frame.getContentPane().add(studentInfo, BorderLayout.EAST);
		studentInfo.setLayout(new BorderLayout(0, 0));
		
		studentInfo.add(studentInfoBox, BorderLayout.CENTER);
		studentInfoBox.setLayout(new GridLayout(0, 2, 0, 0));
		
//		studentInfoBox.setVisible(false);
		JPanel studentInfoHeader = new JPanel();
		studentInfo.add(studentInfoHeader, BorderLayout.NORTH);
		studentInfoHeader.setLayout(new GridLayout(0, 1, 0, 0));
		
		JLabel studentInfoTitle = new JLabel("Student Information");
		studentInfoTitle.setVerticalAlignment(SwingConstants.TOP);
		studentInfoHeader.add(studentInfoTitle);
		studentInfoTitle.setHorizontalAlignment(SwingConstants.CENTER);
		studentInfoHeader.add(studentInfoMsg);
		
		JLabel lblNewLabel = new JLabel("");
		studentInfoHeader.add(lblNewLabel);
		marksSaveBtn.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {				
				//here
				Integer marksArr[] = new Integer[6];
				marksArr[0] = 0;
				int i = 1;
				try {
					for(i = 1;i<marksArr.length;i++) {					
						marksArr[i] = Integer.parseInt(marksContainers[i-1].getText().trim());
						if(marksArr[i]<0 || marksArr[i]>100) {							
							throw new Exception("Invalid marks");
						}
					}
					dummyStudent.setMarks(marksArr);
					infoBoxDisplayer(dummyStudent);
				}		
				catch(Exception e1) {
					studentInfoMsg.setText("Invalid marks entered for Subject #" + i);
				}
			}			
		}
		);
		marksSaveBtn.setBackground(UIManager.getColor("Button.toolBarBorderBackground"));
		marksSaveBtn.setVisible(false);
		studentInfo.add(marksSaveBtn, BorderLayout.SOUTH);
	}
}
