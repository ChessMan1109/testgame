#include "Score.h"

Score::Score() :m_NumScore(5)
{
	ReadFile();
}

Score::Score(int n) : m_NumScore(n)
{
	ReadFile();
}

Score::~Score()
{
	WriteFile();
}


void Score::ReadFile()
{
	f = fopen("Scores.bin", "a+");

	if (fread(m_array_Scores, sizeof(m_array_Scores), 1, f))
	{
		printf("ReadFile success!\n");
	}else printf("ErrorRFile");

	fclose(f);
}
void Score::WriteFile() 
{
	f = fopen("Scores.bin", "w+"); 

	if (fwrite(m_array_Scores, sizeof(m_array_Scores), 1, f))
	{
		printf("WriteFile success!\n");
	}
	else printf("ErrorWFile"); fwrite(m_array_Scores,sizeof(m_array_Scores), 1, f);
	fclose(f);
}

void Score::Swap(int& a, int& b) 
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Score::Update(int newScore)
{
	for (int i = 0; i < m_NumScore; i++) 
	{
		if (newScore > m_array_Scores[i]) Swap(newScore, m_array_Scores[i]);
	}
}

void Score::Reset()
{
	for (int i = 0; i < m_NumScore; i++)
	{
		m_array_Scores[i] = 0;
	}
}

std::string Score::GetConvertIntToString(int i)
{
	int x = m_array_Scores[i];
	if (x == 0) return "0";
	std::string tmp = "";
	while (x)
	{
		char k = x % 10 + '0';
		tmp = k + tmp;
		x /= 10;
	}
	return tmp;
}