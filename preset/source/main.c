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
	printf("先後順序:player -> opponent1 -> opponent2\n\n");
	printf("原始手牌");
	showHand(player);//看player手牌
	sameCards(player);//player清手牌
	sameCards(opponent1);//opponent1清手牌
	sameCards(opponent2);//opponent2清手牌
	printf("清理後的手牌");
	showHand(player);//看player手牌
	GAMING();
}

void GAMING()
{
	int game = 1;//1為player、2為opponent1、3為opponent2
	int fin[3] = { 0,0,0 };
	while (game)
	{
		int EnterCheck = 1;
		switch (game)
		{
		case 0:
			break;
		case 1://player's turn
			if (fin[0] == 0)//player還有牌
			{
				printf("\n抽牌<--");
				while (EnterCheck == 1)
				{
					if (getchar() == '\n')
					{
						EnterCheck = 0;
						printf("\n");
						break;
					}
				}
				if (fin[1] == 0)//opponent1還有牌
				{
					printf("player抽走了opponent1的");
					//plyer抽牌
					card_draw(player, opponent1, 1);
					if (NoCards(opponent1) == 1)//檢查抽opponent1後opponent1沒牌了沒
					{
						fin[0] = -1;//-1表示跳過剩下的fin[]判斷
						fin[1] = 1;
						fin[2] = -1;
						printf("opponent1沒牌了\n");
						game = 0;
					}
					else
						game = 2;
				}
				//player清手牌
				sameCards(player);
				if (NoCards(player) == 1)//檢查player抽完後沒牌了沒
				{
					fin[0] = 1;
					fin[1] = -1;
					fin[2] = -1;//-1表示跳過剩下的fin[]判斷
					printf("player沒牌了\n");
					game = 0;
				}
				else
				{
					printf("清理後的手牌剩%d張", CardsLeft(player));
					//看player手牌
					showHand(player);
				}
			}

		case 2://opponent1's turn
			if (fin[1] == 0)//opponent1還有牌
			{
				if (fin[2] == 0)//opponent2還有牌
				{
					printf("opponent1抽了opponent2的牌\n");
					//opponent1抽牌
					card_draw(opponent1, opponent2, 0);
					if (NoCards(opponent2) == 1)//檢查抽opponent2後opponent2沒牌了沒
					{
						fin[0] = -1;//-1表示跳過剩下的fin[]判斷
						fin[1] = -1;
						fin[2] = 1;
						printf("opponent2沒牌了\n");
						game = 0;
					}
					else
						game = 3;
				}
				//opponent1清手牌
				sameCards(opponent1);
				if (NoCards(opponent1) == 1)//檢查opponent1抽完後沒牌了沒
				{
					fin[0] = -1;//-1表示跳過剩下的fin[]判斷
					fin[1] = 1;
					fin[2] = -1;
					printf("opponent1沒牌了\n");
					game = 0;
				}
				else
				{
					printf("opponent1剩%d張牌\n", CardsLeft(opponent1));
				}
			}

		case 3://opponent2's turn
			if (fin[2] == 0)//opponent2還有牌
			{
				if (fin[0] == 0)//player還有牌
				{
					printf("\nopponent2抽了player的牌\n");
					//opponent2抽牌
					card_draw(opponent2, player, 0);
					if (NoCards(player) == 1)//檢查抽player後player沒牌了沒
					{
						fin[0] = 1;
						fin[1] = -1;
						fin[2] = -1;//-1表示跳過剩下的fin[]判斷
						printf("player沒牌了\n");
						game = 0;
					}
					else
						game = 1;
				}
				//opponent2清手牌
				sameCards(opponent2);//throw out the same cards
				if (NoCards(opponent2) == 1)//檢查opponent2抽完後沒牌了沒
				{
					fin[0] = -1;//-1表示跳過剩下的fin[]判斷
					fin[1] = -1;
					fin[2] = 1;
					printf("opponent2沒牌了\n");
					game = 0;
				}
				else
				{
					printf("opponent2剩%d張牌\n", CardsLeft(opponent2));
				}
			}
		}
		if (fin[0] == 1 || fin[1] == 1 || fin[2] == 1)
		{
			printf("遊戲結束\n");
			if (fin[0] == 1)
				printf("player贏得遊戲\n");
			else if (fin[1] == 1)
				printf("opponent1贏得遊戲\n");
			else if (fin[2] == 1)
				printf("opponent2贏得遊戲\n");
		}
	}
}