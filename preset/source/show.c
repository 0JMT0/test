#include"show.h"

void showHand(const Card * const Hand)
{
	int zeroCheck = 0;
	printf("\n");
	for (size_t i = 0; i < HAND; ++i)
	{
		if (Hand[i].face != 0)
		{
			printf("%5s of %-8s%s", Hand[i].face, Hand[i].suit, (zeroCheck + 1) % 6 ? " " : "\n");
			zeroCheck++;
		}
	}
	printf("\n\n");
}

void showDeck(const Card * const wDeck)
{
	for (size_t i = 0; i < CARDS; ++i)
	{
		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}

int CardsLeft(Card * const Hand)
{
	int howMany = 0;
	for (size_t i = 0; i < HAND; ++i)
	{
		if (Hand[i].face != 0)
		{
			howMany++;
		}
	}
	return howMany;
}