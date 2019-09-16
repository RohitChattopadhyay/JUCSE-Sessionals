//package quotes;

import java.io.*;
import java.text.*;
import java.util.*;
 
public class Main 
{ 
  public static void main(String[] args)throws Exception 
  { 
	  File source = new File("/home/rchattopadhyay/Desktop/source.txt"); 
	  String fileName = "/home/rchattopadhyay/Desktop/dest.txt";

	  BufferedReader scr = new BufferedReader(new FileReader(source)); 
	  BufferedReader dstR = new BufferedReader(new FileReader(fileName));

	  ArrayList<Integer> shown = new ArrayList<Integer>();
	  String st;
	  while ((st = dstR.readLine()) != null) {
		     shown.add(Integer.parseInt(st));
	  }
	  dstR.close();	  
	  int offset = 0;
	  DateFormat dateFormat = new SimpleDateFormat("dd~MM~HH");
	  Date date = new Date();
	  ; //2016/11/16 12:08:43
	  String[]comps = dateFormat.format(date).split("~"); 
	  if(Integer.parseInt(comps[0])==15 && Integer.parseInt(comps[1])==8)
		  System.out.println("Happy Independence Day");
	  
	  else if(Integer.parseInt(comps[0])==26 && Integer.parseInt(comps[1])==1)
		  System.out.println("Happy Republic Day");
	  
	  else if(Integer.parseInt(comps[0])==5 && Integer.parseInt(comps[1])==9)
		  System.out.println("Happy Teachers' Day");
	  if(Integer.parseInt(comps[2])<12) 
		  offset = 0;
	  else if(Integer.parseInt(comps[2])<17)
		  offset = 120;
	  else 
		  offset = 240;
	  switch(offset) {
	  	case 0:
	  		System.out.println("Good Morning");
	  		break;
	  	case 120:
	  		System.out.println("Good Afternoon");
	  		break;
	  	case 240:
	  		System.out.println("Good Night");
	  		break;
	  }
	  System.out.println("Quote of the Day:");
	  
	  Integer index = offset + (new Random()).nextInt(120);
	  int i = 0;
	  while(shown.contains(index)) {
		  i++;
		  index = offset + (new Random()).nextInt(120);
		  if(i==360) {
			  System.out.println("No more quotes today, comeback tomorrow");
			  System.exit(0);
		  }
	  }
	  
	  String temp;
	  while ((temp = scr.readLine()) != null) {
		     if(i++==index) System.out.println(temp);
	  }	
	  PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fileName,true)));
	  out.println(index);
	  out.close();
  } 	
}
