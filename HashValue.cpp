/*
 * HashValue class with the item data used to populate the map.
 * 
 * It is stored the 7Snake array and a boolean version of the grid whose
 * cells of the snake are set true, while the remaining cells are false.
 * This is used to improve performance while comparing two snakes. 
 *
 */

#include "SnakeCell.cpp"

#define VISITED_CELL -1

class HashValue
{
	private:
		SnakeCell m_snake[SNAKESIZE];
		bool **m_grid;
		int m_dim;
	
	public:
	
	HashValue(int **in_grid, int in_dim, SnakeCell *in_snake)
	{
		m_dim = in_dim;
		for (unsigned int i = 0; i < SNAKESIZE; i++)
			m_snake[i] = in_snake[i];
			
		m_grid = new bool*[m_dim];
		for (unsigned int i = 0; i < m_dim; i++)
		{
			m_grid[i] = new bool[m_dim];
			for (unsigned int j = 0; j < m_dim; j++)	
			{
				if (in_grid[i][j] == VISITED_CELL)
					m_grid[i][j] = true;
				else
					m_grid[i][j] = false;
			}
		}
	}

	~HashValue() 
	{
		if (m_grid)
		{
			for (unsigned int i = 0; i < m_dim; i++)
			{
				delete[] m_grid[i];
			}
			delete[] m_grid;
		}
	}

	bool IsDistinct(HashValue other)
	{
		for (unsigned int i = 0; i < SNAKESIZE; i++)
		{
			int otherSnakeRow = other.m_snake[i].GetRow(), 
			    otherSnakeCol = other.m_snake[i].GetCol();
			
			if (m_grid[otherSnakeRow][otherSnakeCol])
				return false;
		}
		return true;
	}
	
	SnakeCell *GetSnakeArray()
	{
		return (SnakeCell*) m_snake;
	}
};