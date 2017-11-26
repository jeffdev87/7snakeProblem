/*
 * Solver class with the core of the solution.
 *
 * The strategy used to solve the 7Snake problem is looking recursively for 7Snakes 
 * in a given grid until two distinct snakes with the same sum of integers be found.
 *
 * A hashtable is kept to group 7-snakes with the same sum of integers (sum of integers is key), 
 * so whenever a 7-sneak is added to the hash, it is checked whether it is distinct of the 
 * others with the same key. If so, the programs ends, otherwise it keeps searching. 
 *
 */
#include<map>
#include<vector>
#include "HashValue.cpp"

std::map<int, std::vector<HashValue>> SnakeMap;

class Solver
{
	public:
	
	Solver(){}
	~Solver()
	{
		for (unsigned int i = 0; i < SnakeMap.size(); i++)
		{ 
			SnakeMap[i].clear();
		}
		SnakeMap.clear();
	}
		
	static void AddGridToTable(int **grid, int dim, SnakeCell *snake, int snakeSum)
	{
		HashValue *hashValue = new HashValue(grid, dim, snake);
		SnakeMap[snakeSum].push_back(*hashValue);
		delete hashValue;
	}

	static bool FindDistinctSnake(int **grid, int dim, SnakeCell snake[2][SNAKESIZE], int snakeSum)
	{
		std::map<int, std::vector<HashValue>>::iterator it = SnakeMap.find(snakeSum);
		
		if (it == SnakeMap.end())
			return false;
		
		HashValue* currHashValue = new HashValue(grid, dim, snake[0]);		
		
		bool found = false;
		std::vector<HashValue> hashValueArray = it->second;
		for (unsigned int i = 0; i < hashValueArray.size() && !found; i++)
		{
			if (currHashValue->IsDistinct(hashValueArray[i]))
			{
				SnakeCell::CopySnakeArray(snake[1], hashValueArray[i].GetSnakeArray());				
				found = true;
			}
		}
		
		if (currHashValue)
		{
			delete currHashValue;
			currHashValue = NULL;
		}
		
		return found;
	}

	static bool FindSevenSnake(int **grid, unsigned int dim, SnakeCell snake[2][SNAKESIZE], int row, int col, unsigned int snakeSize, int *snakeSum)
	{
		snake[0][snakeSize].SetValues(grid[row][col], row, col);
		
		grid[row][col] = INVALID_INT;
		
		if (snakeSize == SNAKESIZE - 1)
		{	
			*snakeSum+=snake[0][snakeSize].GetValue();

			bool foundDistinct = FindDistinctSnake(grid, dim, snake, *snakeSum);			
			
			if (!foundDistinct)
			{
				AddGridToTable(grid, dim, snake[0], *snakeSum);
				*snakeSum-=snake[0][snakeSize].GetValue();
			}

			grid[row][col] = snake[0][snakeSize].GetValue();
			
			return foundDistinct;
		}
		
		for (int i = row - 1; i <= row + 1; i++)
		{	
			if (i < 0 || i >= dim)
				continue;
			
			for (int j = col - 1; j <= col + 1; j++)
			{					
				if (j < 0 || j >= dim)
					continue;

				if (i == row && j == col)
					continue;
				
				if ((i == row - 1 && j == col - 1) ||
					(i == row - 1 && j == col + 1) ||
					(i == row + 1 && j == col - 1) ||
					(i == row + 1 && j == col + 1))
					continue;

				if (grid[i][j] == INVALID_INT)
					continue;
				
				*snakeSum+=snake[0][snakeSize].GetValue();
				if (FindSevenSnake(grid, dim, snake, i, j, snakeSize + 1, snakeSum))
				{
					grid[row][col] = snake[0][snakeSize].GetValue();
					return true;
				}
				*snakeSum-=snake[0][snakeSize].GetValue();
			}
		}	

		grid[row][col] = snake[0][snakeSize].GetValue();
		
		return false;
	}
};