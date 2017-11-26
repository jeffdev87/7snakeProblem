/*
 * HashValue class with the item data used to populate the map.
 *
 */

#include "SnakeCell.cpp"

#define INVALID_INT -1

class HashValue
{
	private:
		SnakeCell m_snake[SNAKESIZE];
		int **m_grid, m_dim;
	
	public:
	
	HashValue(int **in_grid, int in_dim, SnakeCell *in_snake)
	{
		m_dim = in_dim;
		for (unsigned int i = 0; i < SNAKESIZE; i++)
			m_snake[i] = in_snake[i];
			
		m_grid = new int*[m_dim];
		for (unsigned int i = 0; i < m_dim; i++)
		{
			m_grid[i] = new int[m_dim];
			for (unsigned int j = 0; j < m_dim; j++)	
			{
				m_grid[i][j] = in_grid[i][j];
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
			
			if (m_grid[otherSnakeRow][otherSnakeCol] == INVALID_INT)
				return false;
		}
		return true;
	}
	
	SnakeCell *GetSnakeArray()
	{
		return (SnakeCell*) m_snake;
	}
};