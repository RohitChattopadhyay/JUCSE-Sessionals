// https://github.com/wordset/wordset-dictionary
import java.util. * ;
import java.io.File;
import java.io.FileNotFoundException;

class Main {
	private static String helper(String key, String line) {
		int sc1 = line.indexOf(";");
		int sc2 = line.lastIndexOf(";");
		String word = line.substring(0, sc1);
		if (key.equals(word.toLowerCase())) {
			return line.substring(sc1 + 1, sc2);
		} else return "";
	}
	private static String search(String key) {
		String search = key.toLowerCase();
		char dir = search.charAt(0);
		Integer length = key.length();
		String path = "./dictionary/" + dir + "/" + length.toString();
		String res;
		try {
			Scanner scanner = new Scanner(new File(path));
			while (scanner.hasNextLine()) {
				res = helper(search, scanner.nextLine());
				if (!res.equals("")) {
					scanner.close();
					return res;
				}
			}
			scanner.close();
			return "~";
		} catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		return "~";
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System. in );
		String inpFile = "./input.txt";
		try {
			Scanner scanner = new Scanner(new File(inpFile));
			int Row = 0;
      int tokenCounter=0;
			System.out.println("\nNum\tROW\tCOL\t  Lexem\t\tToken");
			System.out.println("--------------------------------------------------");
			while (scanner.hasNextLine()) {
				Row++;
				String str = scanner.nextLine();
				int Col = 0;
				String word = "";
				for (int i = 0; i < str.length(); i++) {
					char c = str.charAt(i);
					if ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".indexOf(c) == -1) {
						if (word.length() > 0) {
							String result = search(word);
							if (result.charAt(result.length() - 1) != '~') {
                tokenCounter++;
								System.out.printf("%3d\t%2d\t%3d%15s\t%s\n", tokenCounter,Row, Col - word.length() + 1, word, result);
							}
						}
						word = "";
					} else {
						word += c;
						Col++;
					}
				}
			}
			scanner.close();
      System.out.println("--------------------------------------------------");
      System.out.printf("Found %d tokens\n\n\n",tokenCounter);
		} catch(FileNotFoundException e) {
			e.printStackTrace();
		}
	}
}