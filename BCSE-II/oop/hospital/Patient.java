package hospital;
import java.io.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
///class to store and manipulate Patient values
public class Patient {
	public static final String parameters[] = {"Date\t\t\t","Height\t\t", "Weight\t\t", "BP\t\t", "Temperature\t", "Remarks\n\n"}; ///<member to hold parameters of examination
	private long ID; ///<member to hold ID
	private int	age; ///<member to hold age
	private String name, ///<member to hold name
		checkin, ///<member to hold checkin time
		doctor, ///<member to hold doctor
		vitals[]; ///<member to hold vitals
	ArrayList<String> visits = new ArrayList<String>();
	private boolean examined; ///<member to hold examination state
	///constructor to initialize data members and validate class invariants
	public Patient(long pID, int a, String pNm, String chkin, String dctr) {
		ID = pID;
		name = pNm;
		age = a;
		checkin = chkin;
		doctor = dctr;
		examined = false;
		vitals = new String[parameters.length];
		System.out.println("Patient Admited with Social Security Number: " + ID);
		System.out.println("Please note down this number");
	}
	///getter function for ID
	public long getID() {
		return ID;
	}
	///getter function for age
	public int getAge() {
		return age;
	}
	///getter function for name
	public String getName() {
		return name;
	}
	///getter function for checkin
	public String getCheckin() {
		return checkin;
	}
	///getter function for doctor
	public String getDoctor() {
		return doctor;
	}
	///getter function for vitals
	public String[] getVitals() {
		return vitals;
	}
	public ArrayList<String> getVisits(){
		return visits;
	}
	///getter function for examined
	public boolean getExamined() {
		return examined;
	}
	///member function to examine a patient
	public void examine(String parameters[]) throws Exception {
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yy");
		Date date = new Date();
		vitals[0] = dateFormat.format(date).toString();
		if(parameters.length != Patient.parameters.length)
			throw new Exception("Insufficient data");
		String temp = dateFormat.format(date).toString() + "\t\t";
		for(int i = 1; i < Patient.parameters.length; ++i) {
			vitals[i] = parameters[i];
			temp += vitals[i] + "\t\t";
		}
		
		examined = true;
		visits.add(temp);
	}
}