#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card
{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const cardArray, int which);
void cards_deal(const Card * const wDeck, Card * const Player, Card * const opponent1, Card * const opponent2);
void handsPreset(Card * const Player, Card * const opponent1, Card * const opponent2);

#define CARDS 54
#define HAND 18
#define FACES 13
#define DECK 0
#define InHand 1