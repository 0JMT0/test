#include"preset.h"

Card deck[CARDS];
Card player[CARDS];
Card opponent1[CARDS];
Card opponent2[CARDS];
void GAMING();

int main(void)
{
	const char *suit[] = { "Heart","Diamonds","Clubs","Spades","Black","Red" };

	const char *face[] = { "Ace","Deuce","Three","Four",
							"Five","Six","Seven","Eight",
							"Nine","Ten","Jack","Queen","King","Joker" };

	srand(time(NULL));

	handsPreset(player, opponent1, opponent2);
	fillDeck(deck, face, suit);
	shuffle(deck, DECK);
	cards_deal(deck, player, opponent1, opponent2);
	printf("���ᶶ��:player -> opponent1 -> opponent2\n\n");
	printf("��l��P");
	showHand(player);//��player��P
	sameCards(player);//player�M��P
	sameCards(opponent1);//opponent1�M��P
	sameCards(opponent2);//opponent2�M��P
	printf("�M�z�᪺��P");
	showHand(player);//��player��P
	GAMING();
}

void GAMING()
{
	int game = 1;//1��player�B2��opponent1�B3��opponent2
	int fin[3] = { 0,0,0 };
	while (game)
	{
		int EnterCheck = 1;
		switch (game)
		{
		case 0:
			break;
		case 1://player's turn
			if (fin[0] == 0)//player�٦��P
			{
				printf("\n��P<--");
				while (EnterCheck == 1)
				{
					if (getchar() == '\n')
					{
						EnterCheck = 0;
						printf("\n");
						break;
					}
				}
				if (fin[1] == 0)//opponent1�٦��P
				{
					printf("player�⨫�Fopponent1��");
					//plyer��P
					card_draw(player, opponent1, 1);
					if (NoCards(opponent1) == 1)//�ˬd��opponent1��opponent1�S�P�F�S
					{
						fin[0] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
						fin[1] = 1;
						fin[2] = -1;
						printf("opponent1�S�P�F\n");
						game = 0;
					}
					else
						game = 2;
				}
				//player�M��P
				sameCards(player);
				if (NoCards(player) == 1)//�ˬdplayer�⧹��S�P�F�S
				{
					fin[0] = 1;
					fin[1] = -1;
					fin[2] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
					printf("player�S�P�F\n");
					game = 0;
				}
				else
				{
					printf("�M�z�᪺��P��%d�i", CardsLeft(player));
					//��player��P
					showHand(player);
				}
			}

		case 2://opponent1's turn
			if (fin[1] == 0)//opponent1�٦��P
			{
				if (fin[2] == 0)//opponent2�٦��P
				{
					printf("opponent1��Fopponent2���P\n");
					//opponent1��P
					card_draw(opponent1, opponent2, 0);
					if (NoCards(opponent2) == 1)//�ˬd��opponent2��opponent2�S�P�F�S
					{
						fin[0] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
						fin[1] = -1;
						fin[2] = 1;
						printf("opponent2�S�P�F\n");
						game = 0;
					}
					else
						game = 3;
				}
				//opponent1�M��P
				sameCards(opponent1);
				if (NoCards(opponent1) == 1)//�ˬdopponent1�⧹��S�P�F�S
				{
					fin[0] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
					fin[1] = 1;
					fin[2] = -1;
					printf("opponent1�S�P�F\n");
					game = 0;
				}
				else
				{
					printf("opponent1��%d�i�P\n", CardsLeft(opponent1));
				}
			}

		case 3://opponent2's turn
			if (fin[2] == 0)//opponent2�٦��P
			{
				if (fin[0] == 0)//player�٦��P
				{
					printf("\nopponent2��Fplayer���P\n");
					//opponent2��P
					card_draw(opponent2, player, 0);
					if (NoCards(player) == 1)//�ˬd��player��player�S�P�F�S
					{
						fin[0] = 1;
						fin[1] = -1;
						fin[2] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
						printf("player�S�P�F\n");
						game = 0;
					}
					else
						game = 1;
				}
				//opponent2�M��P
				sameCards(opponent2);//throw out the same cards
				if (NoCards(opponent2) == 1)//�ˬdopponent2�⧹��S�P�F�S
				{
					fin[0] = -1;//-1��ܸ��L�ѤU��fin[]�P�_
					fin[1] = -1;
					fin[2] = 1;
					printf("opponent2�S�P�F\n");
					game = 0;
				}
				else
				{
					printf("opponent2��%d�i�P\n", CardsLeft(opponent2));
				}
			}
		}
		if (fin[0] == 1 || fin[1] == 1 || fin[2] == 1)
		{
			printf("�C������\n");
			if (fin[0] == 1)
				printf("playerĹ�o�C��\n");
			else if (fin[1] == 1)
				printf("opponent1Ĺ�o�C��\n");
			else if (fin[2] == 1)
				printf("opponent2Ĺ�o�C��\n");
		}
	}
}