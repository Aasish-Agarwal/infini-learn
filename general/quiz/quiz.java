import java.util.Scanner; 
import java.util.*;

class Question
{
	private String description;
	private String Options[];
	private int current;
	private int optionCount = 0;
	private int correctOption;
	
	public Question( String desc )
	{
		Options = new String[3];
		description =  desc;
		current = 0;
	}

	void AppendOption(String value) 
	{
		Options[current] = value;
		++optionCount;
		++current;
	}
	
	void SetCorrectResult(int correct) 
	{
		correctOption = correct;
	}

	public void PrintQuestion()
	{
		System.out.println(description);
		for(int i = 0 ; i < optionCount ; i++ )
		{
			System.out.println(i+1 + ". " + Options[i]);
		}
		
	}
	boolean IsCorrectOption( int userInput ) 
	{
		return userInput == correctOption;
	}	
}

class QuestionLoader
{
	private Question questionList[];
	private int QuestionCount;
	private int nextQuestionToReturn = 0;
	
	public QuestionLoader()
	{
		questionList = new Question[10];
		
		// difficulty
		// subject
		// topic		
		
		int questionNumber = 0;
		questionList[questionNumber] = new Question("Capital of India");
		questionList[questionNumber].AppendOption("Mumbai");
		questionList[questionNumber].AppendOption("Pune");
		questionList[questionNumber].AppendOption("Delhi");
		questionList[questionNumber].SetCorrectResult(3);
		
		questionList[++questionNumber] = new Question("Days In January");
		questionList[questionNumber].AppendOption("29");
		questionList[questionNumber].AppendOption("31");
		questionList[questionNumber].AppendOption("28");
		questionList[questionNumber].SetCorrectResult(2);

		questionList[++questionNumber] = new Question("Days in Leap Year");
		questionList[questionNumber].AppendOption("366");
		questionList[questionNumber].AppendOption("364");
		questionList[questionNumber].AppendOption("365");
		questionList[questionNumber].SetCorrectResult(1);

		QuestionCount = 10; 
	}
	
	Question GetNextQuestion()
	{
		return questionList[nextQuestionToReturn++];
	}
}

public class quiz
{
	public static void main(String[] args)
	{
		int score = 0;		
		QuestionLoader loader = new QuestionLoader();
		
		Scanner sc = new Scanner(System.in);
		Question q ;
		int answer ;
		int i = 3;
		while ( i-- > 0  )
		{
			q = loader.GetNextQuestion();
			q.PrintQuestion(); 
			answer = sc.nextInt();
			if ( q.IsCorrectOption(answer) )
				score++;
		}
		System.out.println("SCORE: " + score);		
	}
}
