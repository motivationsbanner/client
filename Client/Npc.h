#pragma once
#include "Base.h"

class Npc : public Base
{
	bool friendly;
	int questID;

public:
	Npc();
	Npc(int hp);
	Npc(int hp, int posX, int posY);
	Npc(int hp, int posX, int posY, int map);
	
	~Npc();

	// Getter
	bool getFriendly() { return this->friendly; }
	int getQuestID() { return this->questID; }

	// Setter
	void setFriendly(bool friendly) { this->friendly = friendly; }
	void setQuestID(int questID) { this->questID = questID; }

};

