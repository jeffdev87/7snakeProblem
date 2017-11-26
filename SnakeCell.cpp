/*
 * SnakeCell class represents part of the 7Sneak array.
 *
 * It is stored the integer value as well as its position 
 * in the original grid.
 *
 */
 
#define SNAKESIZE 7

class SnakeCell
{
	private:
		int m_value;
		unsigned int m_row, m_col;

	public:

	SnakeCell() {}
	
	SnakeCell(int in_value, int in_row, int in_col) :
		m_value(in_value),
		m_row(in_row),
		m_col(in_col)
	{
	}
	
	~SnakeCell() {}
	
	int GetValue()
	{
		return m_value;	
	}
	
	int GetRow()
	{
		return m_row;	
	}
	
	int GetCol()
	{
		return m_col;	
	}
	
	void operator=(const SnakeCell& other)
	{
		m_value = other.m_value;
		m_row = other.m_row;
		m_col = other.m_col;
	}
	
	void SetValues(int in_value, int in_row, int in_col)
	{
		m_value = in_value;
		m_row = in_row;
		m_col = in_col;
	}
	
	static void PrintSnakeArray(SnakeCell *snake)
	{
		for (unsigned int i = 0; i < SNAKESIZE; i++)
			printf("%d (%d,%d) ", snake[i].m_value, snake[i].m_row, snake[i].m_col);
		printf("\n");
	}
	
	static void CopySnakeArray(SnakeCell *dest, SnakeCell *source)
	{
		for (unsigned int i = 0; i < SNAKESIZE; i++)
			dest[i] = source[i];
	}
};