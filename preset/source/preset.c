#include"preset.h"

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[])
{
	for (size_t i = 0; i < CARDS; ++i)
	{
		if (i == (CARDS - 2))
		{
			wDeck[i].face = wFace[13];
			wDeck[i].suit = wSuit[4];
		}
		else if (i == (CARDS - 1))
		{
			wDeck[i].face = wFace[13];
			wDeck[i].suit = wSuit[5];
		}
		else
		{
			wDeck[i].face = wFace[i % FACES];
			wDeck[i].suit = wSuit[i / FACES];
		}
	}
}

void shuffle(Card * const cardArray, int which)
{
	if (which == DECK)
		for (size_t i = 0; i < CARDS; ++i)
		{
			size_t j = rand() % CARDS;
			Card temp = cardArray[i];
			cardArray[i] = cardArray[j];
			cardArray[j] = temp;
		}
	else if (which == InHand)
	{
		for (size_t i = 0; i < HAND; ++i)
		{
			size_t j = rand() % HAND;
			Card temp = cardArray[i];
			cardArray[i] = cardArray[j];
			cardArray[j] = temp;
		}
	}
}

void handsPreset(Card * const Player, Card * const opponent1, Card * const opponent2)
{
	for (size_t i = 0; i < CARDS; ++i)
	{
		Player[i].face = 0;
		opponent1[i].face = 0;
		opponent2[i].face = 0;
	}
}

void cards_deal(const Card * const wDeck, Card * const Player, Card * const opponent1, Card * const opponent2)
{
	for (size_t i = 0; i < CARDS; ++i)
	{
		if (i < HAND)
		{
			Player[i % HAND].face = wDeck[i].face;
			Player[i % HAND].suit = wDeck[i].suit;
		}
		else if (HAND <= i && i < (HAND * 2))
		{
			opponent1[i % HAND].face = wDeck[i].face;
			opponent1[i % HAND].suit = wDeck[i].suit;
		}
		else
		{
			opponent2[i % HAND].face = wDeck[i].face;
			opponent2[i % HAND].suit = wDeck[i].suit;
		}
	}
}