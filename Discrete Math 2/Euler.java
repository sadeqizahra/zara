import java.util.Arrays;
import java.util.Scanner;

public class EulerGraph()
{
	public static void main(String[] args) {
	Scanner scan = new Scanner(System.in);
	
	vertices = scan.nextInt();
	
	int[][] matrix = new int [vertices][vertices];
	
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; i < vertices; j++)
		{
			matrix[i][j]= scan.nextInt();
		}
		}
	}
}