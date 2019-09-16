package quotesGUI;

import java.io.*;
import java.text.*;
import java.util.*;
 
public class Source 
{ 
  public static String getQuote() 
  { 
	  File source = new File("/home/rchattopadhyay/Desktop/source.txt"); 
	  String fileName = "/home/rchattopadhyay/Desktop/dest.txt";  
	  BufferedReader dstR = null;
	  BufferedReader scr = null;
	try {
		scr  = new BufferedReader(new FileReader(source)); 
		dstR = new BufferedReader(new FileReader(fileName));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}

	  final ArrayList<Integer> shown = new ArrayList<Integer>();
	  String st;
	  try {
		while ((st = dstR.readLine()) != null) {
			     shown.add(Integer.parseInt(st));
		  }
	} catch (NumberFormatException | IOException e) {
		e.printStackTrace();
	}
	  try {
		dstR.close();
	} catch (IOException e) {
		e.printStackTrace();
	}	  
	  int offset = 0;
	  String pre = "<html>";
	  DateFormat dateFormat = new SimpleDateFormat("dd~MM~HH");
	  Date date = new Date();
	  String[]comps = dateFormat.format(date).split("~"); 
	  if(Integer.parseInt(comps[0])==15 && Integer.parseInt(comps[1])==8)
		  pre += "Happy Independence Day";
	  
	  else if(Integer.parseInt(comps[0])==26 && Integer.parseInt(comps[1])==1)
		  pre += "Happy Republic Day";
	  
	  else if(Integer.parseInt(comps[0])==5 && Integer.parseInt(comps[1])==9)
		  pre += "Happy Teachers' Day";
	  if(Integer.parseInt(comps[2])<12) 
		  offset = 0;
	  else if(Integer.parseInt(comps[2])<17)
		  offset = 120;
	  else 
		  offset = 240;
	  switch(offset) {
	  	case 0:
	  		pre += "<br/>Good Morning";
	  		break;
	  	case 120:
	  		pre += "<br/>Good Afternoon";
	  		break;
	  	case 240:
	  		pre += "<br/>Good Evening";
	  		break;
	  }
	  
	  Integer index = offset + (new Random()).nextInt(120);
	  int i = 0;
	  while(shown.contains(index)) {
		  i++;
		  index = offset + (new Random()).nextInt(120);
		  if(i==360) {
			  pre +="<br/>No more quotes today, comeback tomorrow";
			  return pre;
		  }
	  }
	  pre +="<br/>";
	  
	  String temp = null;
	  try {
		while ((temp = scr.readLine()) != null) {
			     if(i++==index) break;
		  }
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}	
	  pre += temp;
	  PrintWriter out = null;
	try {
		out = new PrintWriter(new BufferedWriter(new FileWriter(fileName,true)));
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	  out.println(index);
	  out.close();
	  return pre + "</html>";
  } 	
}