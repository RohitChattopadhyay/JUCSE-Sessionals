package hospital;

import java.util.*;
import java.io.*;
import java.time.Year;

class Doctor {
	String Name;
	Doctor(String e){
		Name = e;
	}
	ArrayList<Patient> patients = new ArrayList<Patient>();
	public String getName() {
		return Name;
	}
	public Patient addPatient(Patient temp){
		patients.add(temp);
		return temp;
	}
	public void removePatient(long id) {
		for(int i = 0 ; i< patients.size(); i++) {
			if(id == patients.get(i).getID())
				patients.remove(i);
		}
		return;
	}
	public void showAllPatients() {
		System.out.println("Doctor Name:\tDr. "+Name);
		if(patients.size()==0) System.out.println("No patients seen yet");
		for(Patient patient : patients) {
			System.out.println("Patient details:\nSocial security ID:\t" + patient.getID() + "\nName:\t" + patient.getName() + "\nAge:\t" + (Year.now().getValue()-patient.getAge()) + " years\n"+ "Checkin time:\t" + patient.getCheckin()+"\n");
		}
	}
}
public class Main {
	private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private ArrayList<Patient> list = new ArrayList<Patient>();
	HashMap<String, Doctor> doctors = new HashMap<String, Doctor>();
	Integer docID = 0;
	///helper function to input and admit a patient to hospital
	public void admit() throws IOException {
		System.out.print("Enter patient details:\n");
		long pID = System.currentTimeMillis() / 1000;
		System.out.print("Name: ");
		String pNm = br.readLine();
		System.out.print("Year of Birth: ");	
		int a = Integer.parseInt(br.readLine());
		while(a<1 || a> Year.now().getValue()) {
			System.out.print("Invalid Year, Enter again:\t");		
			a = Integer.parseInt(br.readLine());			
		}
		System.out.print("Doctor ID: ");
		String dctr = br.readLine();
		while(doctors.get(dctr)==null) {
			System.out.print("Invalid Doctor ID\nEnter again: ");
			dctr = br.readLine();
		}
		String chckin = new Date().toString();
		list.add(doctors.get(dctr).addPatient(new Patient(pID, a, pNm, chckin, dctr)));
	}
	public void showDoctor() throws IOException {
		System.out.print("Doctor ID: ");
		String dctr = br.readLine();
		if(doctors.get(dctr)==null) {
			System.out.println("No such doctors");
		}
		doctors.get(dctr).showAllPatients();
	}
	public String addDoctor() throws IOException {
		System.out.print("Enter Doctor Name:\t");
		String docName = br.readLine();
		docID++;
		doctors.put("DOC"+docID.toString(), new Doctor(docName));
		return "DOC" + docID.toString();
	}
	///helper function to find a patient in hospital
	public int find() throws IOException {
		System.out.print("Enter social security ID: ");
		int ID = Integer.parseInt(br.readLine()), i;
		for(i = 0; i < list.size(); ++i)
			if(list.get(i).getID() == ID)
				return i;
		return -1;
	}
	///helper function to discharge a patient from hospital
	public void discharge() throws IOException {
		int ID = check();
		if(ID == -1)
			return;
		Patient temp = list.get(ID);
		doctors.get(temp.getDoctor()).removePatient(temp.getID());
		list.remove(temp);
		System.out.println("Discharge time: " + new Date().toString());
	}
	///helper function to examine a patient in hospital
	public void examine() throws Exception {
		int ID = find();
		System.out.println();
		if(ID == -1) {
			System.out.println("Patient not found");
			return;
		}
		String vitals[] = new String[Patient.parameters.length];
		for(int i = 1; i < Patient.parameters.length; ++i) {
			System.out.print("Enter " + Patient.parameters[i] + ": ");
			vitals[i] = br.readLine();
		}
		list.get(ID).examine(vitals);
	}
	///helper function to check if a patient is in hospital
	public int check() throws IOException {
		int ID = find();
		System.out.println();
		if(ID == -1) {
			System.out.println("Patient not found");
			return -1;
		}
		Patient patient = list.get(ID);
		System.out.println("Patient details:\nSocial security ID:\t" + patient.getID() + "\nName:\t" + patient.getName() + "\nAge:\t" + (Year.now().getValue()-patient.getAge()) + " years\nDoctor assigned:\t" + patient.getDoctor() + "\nCheckin time:\t" + patient.getCheckin())	;
		if(patient.getExamined()) {
			
			for(int i = 0; i < Patient.parameters.length; ++i)
				System.out.print(Patient.parameters[i]);
			for(int i = 0;i < patient.getVisits().size();i++) {
				String visit = patient.getVisits().get(i);
				System.out.println(visit);
			}
		}
		else
			System.out.println("Not yet examined");
		return ID;
	}
	public static void main(String args[]) {
		int c = 1;
		Main obj = new Main();
		System.out.println("\nWelcome to KPC Medical College\n\n");
		do {
			System.out.println("\nMENU:\n\n0\tTo Exit\n1\tTo Admit New patient\n2\tTo discharge patient\n3\tTo examine a patient\n4\tTo check patient history\n5\tTo add Doctor\n6\tTo see Doctor Profile");
			System.out.print("\nEnter operation code: ");
			try {
				c = Integer.parseInt(obj.br.readLine());
				switch(c) {
					case 0: System.out.println("terminating program"); break;
					case 1: obj.admit(); break;
					case 2:	obj.discharge(); break;
					case 3: obj.examine(); break;
					case 4: obj.check(); break;
					case 5: System.out.println("New Doctor ID: " + obj.addDoctor());break;
					case 6: obj.showDoctor();break;
					default: throw new Exception("Invalid Option choosen");
				}
			}
			catch(Exception e) {
				System.out.println(e.toString() + ": Enter again");
			}
		}	while(c != 0);
	}
}