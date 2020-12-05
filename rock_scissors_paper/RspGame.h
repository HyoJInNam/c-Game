#pragma once


//game
void Initialize(char * scene, int& playerValue);
int Input(int value);
void Playgame(char * scene, int& playerValue);
bool Gameend(char * scene, int& playerValue);

int RandomValue();

const char* RSP(char * temp, const char* name, int value);
const char* RspValueCompare3(int playerValue);