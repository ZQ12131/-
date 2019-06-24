#include<iostream>
using namespace std;
#pragma once
class Game
{
private:
	char status[9];
	int score[9];
	int fail,counter;

public:
	Game(void);
	void Print();
int Cal(int i,int g);
bool Judge(int i,int j,int k,char);
 void Play();
};

