#pragma once

void Clear(char * scene, int len);
void Display(char * scene, int len, const char* str);

bool Input(char * scene, int len, int& playerValue);
void Playgame(char * scene, int len, int& playerValue);
bool Gameend(char * scene, int len, int& playerValue);

void Initialize(char * scene, int len, int& playerValue);
void GameLoop(char * scene, int len);
