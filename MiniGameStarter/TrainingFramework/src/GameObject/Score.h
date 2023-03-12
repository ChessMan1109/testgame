#pragma once
#include<string>
class Score
{
private:
	FILE* f;
	int m_array_Scores[12];
	void Swap(int&, int&);
	
public:
	int m_NumScore;
	Score();
	Score(int);
	~Score();
	void ReadFile();
	void WriteFile();
	void Update(int newScore);
	void Reset();
	std::string GetConvertIntToString(int i);
	int GetHighScore()
	{
		return m_array_Scores[0];
	}
};