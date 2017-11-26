#include "ParseInput.cpp"
#include "Solver.cpp"

/*
 * Main function.
 * 
 * It expects an input file with N test cases according to 
 * the following format:
 * 
 * D1          -> Grid's dimmension D1 of the first test case
 * V1,V2,V3... -> D values of the first row of the grid
 * ...         -> Remaining rows of the current grid
 * D2          -> Grid's dimmension D2 of the second test case
 * ...         -> Remaining rows of the current grid
 *
 * Output will be in the following format:
 * # Test case <id>
 * # Sum of integers: <found_value>
 * First snake (integar value and position in the grid)
 * Second snake (integar value and position in the grid)
 *
 */
int main(int argc, char *args[])
{
	unsigned int dim = 0, t = 0;

	while (scanf("%d ", &dim) != EOF)
	{
		t++;
		
		int *grid[dim];
		for (unsigned int i = 0; i < dim; i++)
		{
			std::string line;
			std::getline(std::cin, line);			
			grid[i] = ParseInput::ParseRow(line, dim, ',');
		}
		
		bool found = false;
		for (unsigned int i = 0; i < dim && !found; i++)
		{
			for (unsigned int j = 0; j < dim && !found; j++)
			{
				SnakeCell snake[2][SNAKESIZE];		
				
				int sum = 0;
				if (Solver::FindSevenSnake(grid, dim, snake, i, j, 0, &sum))
				{
					printf("# TestCase %d\n# Sum of integers: %d\n", t, sum);	
					SnakeCell::PrintSnakeArray(snake[0]);
					SnakeCell::PrintSnakeArray(snake[1]);
					
					found = true;
				}
			}
		}

		if (!found)
		{
			printf("#TestCase %d\nFAIL\n", t);
		}
		
		printf("\n");
		
		for (unsigned int i = 0; i < dim; i++)
		{		
			delete[] grid[i];
		}
	}
	
	return 0;
}