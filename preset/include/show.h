#pragma onc#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void showHand(const Card * const Hand);
void showDeck(const Card * const wDeck);
int CardsLeft(Card * const Hand);

#define CARDS 54
#define HAND 18
