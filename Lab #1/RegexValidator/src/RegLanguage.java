//Samar @ Techgaun.Com
import java.util.regex.*;
public class RegLanguage {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String str = "0101010101";
		String reglang = "(0+1)*|0*1*";
		Pattern pattern = Pattern.compile(reglang);
		Matcher match = pattern.matcher(str);
		
		if (match.matches())
		{
			System.out.println("Given string " + str + " matches with given Regular language " + reglang + ".");
		}
		else
		{
			System.out.println("Given string " + str + " does not match with given Regular language " + reglang + ".");
		}
		
		str = "abbbc";
		reglang = "(ab*c|(def)+|a*d+e)+";
		
		if (match.matches())
		{
			System.out.println("Given string " + str + " matches with given Regular language " + reglang + ".");
		}
		else
		{
			System.out.println("Given string " + str + " does not match with given Regular language " + reglang + ".");
		}
		
		str = "ac";
		reglang = "((a+b)*(c+d)*)+|ab*c*d";
		
		if (match.matches())
		{
			System.out.println("Given string " + str + " matches with given Regular language " + reglang + ".");
		}
		else
		{
			System.out.println("Given string " + str + " does not match with given Regular language " + reglang + ".");
		}
		
		
	}

}
