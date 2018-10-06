/*  Student information for assignment:
 *
 *  On my honor, Angela Cao, this programming assignment is my own work
 *  and I have not provided this code to any other student.
 *
 *  Name: Angela Cao
 *  email address: angela_cao@utexas.edu
 *  UTEID: abc2949
 *  Section 5 digit ID: 51480
 *  Grader name: Jacob
 *  Number of slip days used on this assignment: 2
 */

// add imports as necessary

import java.util.Set;
import java.util.TreeMap;
import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Iterator;

/**
 * Manages the details of EvilHangman. This class keeps
 * tracks of the possible words from a dictionary during
 * rounds of hangman, based on guesses so far.
 *
 */
public class HangmanManager {

    // instance vars
	private ArrayList<String> originalDictionary;
	private Set<String> activeDictionary = new TreeSet<String>();
	private Set<Character> lettersGuessed = new TreeSet<Character>();
	private boolean debug;
	private int wordLength;
	private int maxGuesses;
	private int numGuess;
	private int guessesLeft;
	private ArrayList<String> storedPatterns;
	private HangmanDifficulty difficulty;
    /**
     * Create a new HangmanManager from the provided set of words and phrases.
     * pre: words != null, words.size() > 0
     * @param words A set with the words for this instance of Hangman.
     * @param debugOn true if we should print out debugging to System.out.
     */
    public HangmanManager(Set<String> words, boolean debugOn)
    {
    	if((words == null) || (words.size() <= 0))
    		throw new IllegalArgumentException("The parameter words should not be null nor should size be less than or equal to 0.");
    	originalDictionary = new ArrayList<String>();
    	//loop adds words to instance variable originalDictionary
    	for(String s: words)
    	{
    		originalDictionary.add(s);
    	}
		debug = debugOn;
    }

    /**
     * Create a new HangmanManager from the provided set of words and phrases.
     * Debugging is off.
     * pre: words != null, words.size() > 0
     * @param words A set with the words for this instance of Hangman.
     */
    public HangmanManager(Set<String> words)
    {
    	this(words, false);
    }


    /**
     * Get the number of words in this HangmanManager of the given length.
     * pre: none
     * @param length The given length to check.
     * @return the number of words in the original Dictionary with the given length
     */
    public int numWords(int length)
    {
    	int count = 0;
    	String word = "";
    	//loop goes through all the words in the originalDictionary and counts the number of words that have length of the length passed into the method
    	for(int i = 0; i < originalDictionary.size(); i++)
    	{
    		word = originalDictionary.get(i);
    		if(word.length() == length)
    			count++; //increment
    	}
        return count;
    }


    /**
     * Get for a new round of Hangman. Think of a round as a complete game of Hangman.
     * @param wordLen the length of the word to pick this time. numWords(wordLen) > 0
     * @param numGuesses the number of wrong guesses before the player loses the round. numGuesses >= 1
     * @param diff The difficulty for this round.
     */
    public void prepForRound(int wordLen, int numGuesses, HangmanDifficulty diff)
    {
		wordLength = wordLen;
		guessesLeft = numGuesses;
		numGuess = 1;
		//Loop goes over the dictionary to get words that are of the length wordLength
		//and add them to the words suggested to be guessed.
		for(int i = 0; i < originalDictionary.size(); i++)
		{
			if((originalDictionary.get(i)).length() == wordLength)
				activeDictionary.add(originalDictionary.get(i));
		}
		difficulty = diff;
    }


    /**
     * The number of words still possible (live) based on the guesses so far. Guesses will eliminate possible words.
     * @return the number of words that are still possibilities based on the original dictionary and the guesses so far.
     */
    public int numWordsCurrent()
    {
        return activeDictionary.size();
    }


    /**
     * Get the number of wrong guesses the user has left in this round (game) of Hangman.
     * @return the number of wrong guesses the user has left in this round (game) of Hangman.
     */
    public int getGuessesLeft()
    {
        return guessesLeft;
    }


    /**
     * Return a String that contains the letters the user has guessed so far during this round.
     * The String is in alphabetical order. The String is in the form [let1, let2, let3, ... letN].
     * For example [a, c, e, s, t, z]
     * @return a String that contains the letters the user has guessed so far during this round.
     */
    public String getGuessesMade()
    {
        return lettersGuessed.toString();
    }


    /**
     * Check the status of a character.
     * @param guess The characater to check.
     * @return true if guess has been used or guessed this round of Hangman, false otherwise.
     */
    public boolean alreadyGuessed(char guess)
    {
    	//Enhanced for loop goes over the letters guessed in the lettersGuessed set to see if
    	//guessed letter passed into the method is already guessed or not.
    	for(char c: lettersGuessed)
    	{
    		if(c == guess)
    			return true;
    	}
        return false;
    }


    /**
     * Get the current pattern. The pattern contains '-''s for unrevealed (or guessed)
     * characters and the actual character for "correctly guessed" characters.
     * @return the current pattern.
     */
    public String getPattern()
    {
    	StringBuffer sb = new StringBuffer();
    	//At the start of the game, all the letters of the word are blank
    	if(lettersGuessed.size() == 0)
    	{
			for(int i = 0; i < wordLength; i++)
			{
				sb.append('-');
			}
    	}
    	//As the user guesses each letter, some of the blanks pop up as letters,
    	//depending on the user guesses.
    	else
    	{
    		Iterator<String> it = activeDictionary.iterator();
    		String word = it.next();
    		for(int i = 0; i < wordLength; i++)
    		{
    			char atChar = word.charAt(i);
    			if(lettersGuessed.contains(atChar))
    				sb.append(atChar);
    			else
    				sb.append('-');
    		}
    	}
        return sb.toString();
    }


    // pre: !alreadyGuessed(ch)
    // post: return a tree map with the resulting patterns and the number of
    // words in each of the new patterns.
    // the return value is for testing and debugging purposes
    /**
     * Update the game status (pattern, wrong guesses, word list), based on the give
     * guess.
     * @param guess pre: !alreadyGuessed(ch), the current guessed character
     * @return return a tree map with the resulting patterns and the number of
     * words in each of the new patterns.
     * The return value is for testing and debugging purposes.
     */
    public TreeMap<String, Integer> makeGuess(char guess)
    {
		if(alreadyGuessed(guess))
			throw new IllegalStateException("Letter already guessed.");
		storedPatterns = new ArrayList<String>();
		TreeMap<String, Integer> patterns = new TreeMap<String, Integer>();
		TreeMap<String, ArrayList<String>> wordFamilies = new TreeMap<String, ArrayList<String>>();
		ArrayList<String> wordFamily;
		for(String s : activeDictionary)
		{
			StringBuffer sb = new StringBuffer();
			String pattern =  createPattern(sb, s, guess, lettersGuessed); //creates pattern based on word and character guessed
			boolean containsPat = patterns.containsKey(pattern);
			addingWords(patterns, wordFamilies, pattern, s, containsPat); //updates the TreeMaps patterns and wordFamilies depending on the occuring of the pattern
		}
		String finPattern = findPattern(patterns, guess, wordLength, numGuess, difficulty, debug); //find the pattern that the word should have; logic error occuring here...
		storedPatterns.add(finPattern); //adds the most common pattern as update
		removeWords(activeDictionary, finPattern, wordFamilies); //removes all the words that don't follow the pattern; logic error occurring here...
		lettersGuessed.add(guess); //adds the guessed letter into an inventory of letters that the user guesses;
		String guessStr = ""+guess;
    	if(!finPattern.contains(guessStr))
    		this.guessesLeft = this.guessesLeft - 1;
    	this.printDebugPattern(patterns, finPattern);
    	numGuess++;
        return patterns;
    }

    //Helper Methods below:
    /**
     *Helper method for makeGuess which prints out the new pattern and new family based on the guess if debug == true
     *@pre: patterns != null and finPattern != null
     *@param: TreeMap <String, Integer> patterns is the TreeMap of all the patterns of the words in the active dictionary
     *aka suggestions, String finPattern is the pattern used to determine whether the guess is "right" or not.
     */
     public void printDebugPattern(TreeMap<String, Integer> patterns, String finPattern)
     {
     	 if((patterns == null) || (finPattern == null))
     	 	throw new IllegalArgumentException("Parameter(s) cannot be null.");
     	 if(debug)
     	 {
     	 	//calls the getPattern method to convert the finPattern into String (finPattern is already set to be the pattern)
     	 	//patterns.get(finPattern) is called to get the number of occurences of the finPattern.
     	 	System.out.println("DEBUGGING: New pattern is: "+this.getPattern()+". New family has "+patterns.get(finPattern)+" words.");
			System.out.println();
     	 }
     }
    /**
     *Helper method for makeGuess which updates the patterns and wordFamiles TreeMaps depending
     *on the occurence of the pattern
     *@pre: patterns != null and wordFamilies != null and pattern != null and str != null
     *@post: patterns and wordFamilies are updated
     *@param: patterns is the TreeMap of all the patterns of the words in the active dictionary
     *aka suggestions, wordFamilies is the TreeMap of all the wordFamilies generated based on
     *the patterns generated, pattern is the pattern generated from the createPattern method based
     *on the String str (the word, another parameter), boolean contains is boolean that indicates
     *whether the TreeMaps contain the pattern or not.
     */
    public static void addingWords(TreeMap<String, Integer> patterns, TreeMap<String, ArrayList<String>> wordFamilies, String pattern, String str, boolean contains)
    {
    	if((patterns == null) || (wordFamilies == null) || (pattern == null) || (str == null))
    		throw new IllegalArgumentException("Parameters cannot be null.");
    	ArrayList<String> wordFamily;
		if(!contains) //if the pattern doesn't exist in the TreeMap
		{
			patterns.put(pattern, 1);
			wordFamily = new ArrayList<String>();
			wordFamily.add(str);
			wordFamilies.put(pattern, wordFamily);
		}
		else //if the pattern already exists in the TreeMap, increment the value of the pattern
		{
			int num = patterns.get(pattern);
			patterns.put(pattern, num + 1); //increments the number of occurence of the pattern by 1.
			wordFamily = wordFamilies.get(pattern);
			wordFamily.add(str);
			wordFamilies.put(pattern, wordFamily);
		}
    }
    /**
     *Helper method for makeGuess which creates the pattern of each word iterated
     *based on letter guessed.
     *@pre: StringBuilder sb != null and String word != null
     *@param: StringBuilder sb, String word is the word iterated over to create pattern
     *while char guess is the letter guessed by the user.
     *@return: a String pattern of the pattern of the word based on the letter guessed.
     */
	private static String createPattern(StringBuffer sb, String word, char guess, Set<Character> guessedLetters)
	{
		if((sb == null) || (word == null))
			throw new IllegalArgumentException("Parameters cannot be null.");
		char currentChar = 'a';
		//loop goes through all the word and append the characters into the StringBuffer based on whether it is equal to the guess character or not.
		for(int k = 0; k < word.length(); k++)
		{
			currentChar = word.charAt(k);
			if(currentChar == guess) //if character is equal to String
				sb.append(currentChar);
			else if(guessedLetters.contains(currentChar)) //else if character is already guessed and was correct in previous guesses, and is in String.
				sb.append(currentChar);
			else //if character is not equal to String, then dash is substituted instead.
				sb.append('-');
		}
		String pattern = sb.toString();
		return pattern;
	}
	/**
	 *Along with other helper methods, this helper method determines the hardest or second hardest pattern based on the difficulty
	 *of the round.
	 *@pre: patterns != null, hangDiff != null, length != null
	 *@param: TreeMap<String, Integer> patterns contains all the patterns generated from the words of the active dictionary, char guess
	 *is the letter guessed by the user/player, int length is the length of the word to be "guessed", int atGuess is the number of
	 *guesses the user/player has already guessed in the game, HangmanDifficulty is the difficulty of the round.
	 *@return: String finPattern which is the hardest or second hardest String found in patterns, and to be used.
	 */
	public static String findPattern(TreeMap<String, Integer> patterns, char guess, int length, int atGuess, HangmanDifficulty hangDiff, boolean debug)
	{
		if((patterns == null) || (hangDiff == null) || (length == 0))
			throw new IllegalArgumentException("The parameters cannot be null or 0 (for int).");
		String finPattern = "";
		if(hangDiff == HangmanDifficulty.EASY) //if difficulty is easy
			finPattern = findPatternEasy(patterns, guess, length, atGuess, debug);
		else if(hangDiff == HangmanDifficulty.MEDIUM) //if difficulty is medium
			finPattern = findPatternMed(patterns, guess, length, atGuess, debug);
		else //if difficulty is hard
		{
			finPattern = findPatternHard(patterns, guess, length, debug);
			printHard(debug, patterns, finPattern);
		}
		return finPattern;
	}
	/**
	 *This helper method indicates and prints out the hardest list of patterns to be used based on guess.
	 *It only happens if debug == true
	 *@pre: patterns != null and pattern != null and debug == true
	 *@param: boolean debug is instance variable, TreeMap<String, Integer> patterns stores all the patterns and
	 *occurences, String pattern is the pattern that is found to be the "hardest".
	 */
	public static void printHard(boolean debug, TreeMap<String, Integer> patterns, String pattern)
	{
		if((patterns == null) || (pattern == null))
			throw new IllegalArgumentException("Parameter(s) cannot be null.");
		if(debug == true)
		{
			System.out.println();
			System.out.println("DEBUGGING: Picking hardest list.");
		}
	}
	/**
	 *This helper method indicates and prints out the second hardest list of patterns to be used based on guess.
	 *This only happens if debug == true.
	 *@pre: patterns != null and pattern != null and debug == true
	 *@param: boolean debug is instance variable, TreeMap<String, Integer> patterns stores all the patterns and
	 *occurences, String pattern is the pattern that is found to be the "second hardest".
	 */
	public static void printSecHard(boolean debug, TreeMap<String, Integer> patterns, String pattern)
	{
		if((patterns == null) || (pattern == null))
			throw new IllegalArgumentException("Parameter(s) cannot be null.");
		if(debug == true)
		{
			System.out.println("\n");
			System.out.println("DEBUGGING: Difficulty second hardest pattern and list.");
			System.out.println();
		}
	}
	/**
	 *Helper method for makeGuess which helps organize the patterns into the TreeMap.
	 *@pre: patterns != null
	 *@param: TreeMap<String, Integer> patterns is the TreeMap where the patterns go
	 *to while char guess is the letter the user guesses.
	 *@return: finPattern, which is apparently the hardest word.
	 */
	private static String findPatternHard(TreeMap<String, Integer> patterns, char guess, int length, boolean debug)
	{
		if((patterns == null) || (length == 0))
			throw new IllegalArgumentException("The parameter, patterns, cannot be null or 0 (for int).");
		Iterator<String> it = patterns.keySet().iterator();
		String finPattern = it.next();
		int max = patterns.get(finPattern); //max and finPattern initially are the first number of occurences and first String of patterns...for now :)
		while(it.hasNext())
		{
			String str = it.next();
			int num = patterns.get(str);
			if(num > max) //if found the so-far maximum number of occurences in the TreeMap so far
			{
				max = num;
				finPattern = str;
			}
			else if(num == max)
				findPatternAlt(finPattern, str, guess, length); //compare lexigraphically now...
		}
		return finPattern;
	}
	/**
	 *Helper method finds the maximum number of occurences for any pattern in the patterns TreeMap.
	 *@pre: patterns != null
	 *@param: TreeMap<String, Integer> patterns stores all the patterns generated from the words of
	 *the active dictionary/suggestions
	 *@return: int max is the maximum number of occurences of any pattern stored in patterns
	 */
	public static int findMax(TreeMap<String, Integer> patterns)
	{
		if(patterns == null)
			throw new IllegalArgumentException("The parameter patterns cannot be null.");
		Iterator<String> it = patterns.keySet().iterator();
		int max = 0;
		//while loop looks for max occurences
		while(it.hasNext())
		{
			String str = it.next();
			int num = patterns.get(str);
			if(num > max)
				max = num;
		}
		return max;
	}
	/**
	 *This helper method finds the second hardest pattern out of all the patterns in the patterns Tree Map.
	 *@pre: patterns != null, length != 0
	 *@param: TreeMap<String, Integer> patterns has all the patterns and the amount of occurences in the active
	 *dictionary known as suggestions, char guess is the character the player/user guesses, int length is the
	 *length of the words in the active dictionary/suggestions.
	 *@return: String finPattern which returns the second hardest pattern in the patterns TreeMap
	 */
	public static String findSecHardest(TreeMap<String, Integer> patterns, char guess, int length, boolean debug)
	{
		if((patterns == null) || (length == 0))
			throw new IllegalArgumentException("The parameters cannot be null or 0 (for ints).");
		Iterator<String> it = patterns.keySet().iterator();
		int max = findMax(patterns);
		String maxStr = findPatternHard(patterns, guess, length, debug);
		Iterator<String> secIt = patterns.keySet().iterator();
		int secMax = 0;
		String finPattern = "";
		while(secIt.hasNext())
		{
			String secStr = secIt.next();
			int secNum = patterns.get(secStr);
			if((secNum > secMax) && ((secNum != max) || (!secStr.equals(maxStr)))) //finds the second hardest if number of occurences doesn't tie with maximum number of occurences
			{																	   //or if the String doesn't equal to the String associated with the maximum number of occurences.
				secMax = secNum;
				finPattern = secStr;
			}
			else if((secNum == secMax) && (secNum != max)) //if tied
				findPatternAlt(finPattern, secStr, guess, length); //now compares Strings lexigraphically
		}
		printSecHard(debug, patterns, finPattern);
		return finPattern;
	}
	/**
	 *This helper method decides what list to use (hardest or second) hardest, depending on the number of guesses
	 *the user/player has taken in the game in medium difficulty.
	 *@pre:patterns != null, length != 0
	 *@param:TreeMap<String, Integer> patterns is the TreeMap that stores all the patterns generated from the active
	 *dictionary/suggestions along with the amount/number of occurences of each individual pattern, char guess is the
	 *letter that the user/player just guessed, int length is the length of the word, int atGuess is the number of
	 *guesses the user/player has guessed so far.
	 *@return: String finPattern that returns the pattern to be used for the "correct set of words".
	 */
	public static String findPatternMed(TreeMap<String, Integer> patterns, char guess, int length, int atGuess, boolean debug)
	{
		if((patterns == null) || (length == 0))
			throw new IllegalArgumentException("Parameters cannot be null or 0 (for ints).");
		String finPattern = "";
		if(atGuess % 4 == 0) //if guess is a multiple of 4, then find secondHardest pattern unless size of patterns is 1
		{
			if(patterns.keySet().size() > 1)
				finPattern = findSecHardest(patterns, guess, length, debug);
			else
			{
				System.out.println();
				System.out.println("DEBUGGING: Should pick second hardest pattern this turn, but only one pattern available.");
				finPattern = findPatternHard(patterns, guess, length, debug);
				printHard(debug, patterns, finPattern);
			}
		}
		else //else find hardest pattern
		{
			finPattern = findPatternHard(patterns, guess, length, debug);
			printHard(debug, patterns, finPattern);
		}
		return finPattern;
	}
	/**
	 *This helper method decides what list to use (hardest or second) hardest, depending on the number of guesses
	 *the user/player has taken in the game in easy difficulty.
	 *@pre:patterns != null, length != 0
	 *@param:TreeMap<String, Integer> patterns is the TreeMap that stores all the patterns generated from the active
	 *dictionary/suggestions along with the amount/number of occurences of each individual pattern, char guess is the
	 *letter that the user/player just guessed, int length is the length of the word, int atGuess is the number of
	 *guesses the user/player has guessed so far.
	 *@return: String finPattern that returns the pattern to be used for the "correct set of words".
	 */
	public static String findPatternEasy(TreeMap<String, Integer> patterns, char guess, int length, int atGuess, boolean debug)
	{
		String finPattern = "";
		if(atGuess % 2 == 0) //if guess is multiple of 2, then find second hardest pattern unless size of patterns is 1.
		{
			if(patterns.keySet().size() > 1)
				finPattern = findSecHardest(patterns, guess, length, debug);
			else
			{
				System.out.println("DEBUGGING: Should pick second hardest pattern this turn, but only one pattern available.");
				finPattern = findPatternHard(patterns, guess, length, debug);
				printHard(debug, patterns, finPattern);
			}
		}
		else //else find hardest pattern
		{
			finPattern = findPatternHard(patterns, guess, length, debug);
			printHard(debug, patterns, finPattern);
		}
		return finPattern;
	}
	/**
	 *Helper method for makeGuess and findPattern if the number of occurences of individual patterns doesn't determine
	 *what is the hardest/second hardest pattern to be used.
	 *@pre: pattern != null, str != null, length != 0
	 *@param: String pattern is the pattern that is currently stored to be used, String str is the pattern evaluated,
	 *char guess is the letter that the player/user just guessed, int length is the length of the words in the active
	 *dictionary/suggestions.
	 *@return: String finPattern that returns the pattern to be used for the "correct set of words".
	 */
	private static String findPatternAlt(String pattern, String str, char guess, int length)
	{
		if((pattern == null) || (str == null) || (length == 0))
			throw new IllegalArgumentException("Parameters cannot be null or 0 (for ints).");
		int countOne = 0;
		int countTwo = 0;
		String finPattern = pattern;
		for(int i = 0; i < length; i++) //this loop counts the number of times a dash appear in the current pattern created.
		{
			char charOne = str.charAt(i);
			if(charOne == '-')
				countOne++;
		}
		for(int i = 0; i < length; i++) //this loop counts the number of times a dash appear in the created pattern.
		{
			char charTwo = pattern.charAt(i);
			if(charTwo == '-')
				countTwo++;
		}
		if(countOne > countTwo)
			finPattern = str;
		else if(countOne == countTwo) //now has to compare the two Strings lexigraphically use helper method
		{
			finPattern = compare(str, pattern);
		}
		return finPattern;
	}
	/**
	 *Helper method compares two Strings (patterns) lexigraphically.
	 *@pre: str != null and pattern != null
	 *@param: String str is the first String or the pattern generated, String pattern is the second
	 *String or pattern to be used to generate the "correct set of words".
	 *@return: String superiorStr or the pattern that is going to be used to generate "correct set
	 *of words".
	 */
	public static String compare(String str, String pattern)
	{
		if((str == null) || (pattern == null))
			throw new IllegalArgumentException("Parameters cannot be null.");
		int compareTo = str.compareTo(pattern);
		String smallerStr = "";
		if(compareTo < 0) //if str is lexigraphically smaller
			smallerStr = str;
		else //if str is lexigraphically larger
			smallerStr = pattern;
		return smallerStr;
	}
	/**
	 *Helper method removes the words that don't associate with the hardest or second hardest pattern that was determined.
	 *@pre: suggestions != null, pattern != null, wordFamilies != null
	 *@param: Set<String> suggestions is the active dictionary of all words that could be guessed based on length passed into
	 *the constructor of HangmanManager, String pattern is the hardest/second hardest pattern already determined by other
	 *helper methods, TreeMap<String, ArrayList<String>> is the TreeMap of all the word families grouped together based on
	 *pattern.
	 */
	private static void removeWords(Set<String> activDic, String pattern, TreeMap<String, ArrayList<String>> wordFamilies)
	{
		if((activDic == null) || (pattern == null) || (wordFamilies == null))
			throw new IllegalArgumentException("The parameter(s) cannot be null.");
		activDic.clear(); //clears the active dictionary in order to add in words that fit in with the hardest/second hardest pattern.
		ArrayList<String> words = wordFamilies.get(pattern);
		//this loop adds all the words that are associated with the hardest/second hardest pattern.
		for(int i = 0; i < words.size(); i++)
		{
			String word = words.get(i);
			activDic.add(word);
		}
	}
    /**
     * Return the secret word this HangmanManager finally ended up picking for this round.
     * If there are multiple possible words left one is selected at random.
     * <br> pre: numWordsCurrent() > 0
     * @return return the secret word the manager picked.
     */
    public String getSecretWord()
    {
    	if(activeDictionary.size() == 0)
    		throw new IllegalStateException("Size of active dictionary called suggestions is size 0.");
    	Iterator<String> it = activeDictionary.iterator();
    	if(activeDictionary.size() == 1) //loop gets the word left if size == 1
    		return it.next();
    	else //loop randomly returns word if size > 1
    	{
    		int random = (int) Math.random() * activeDictionary.size(); //random index/position of word
    		String secretWord = "";
    		for(int i = 0; i <= random; i++)
    		{
    			secretWord = it.next();
    		}
    		return secretWord;
    	}
    }
}