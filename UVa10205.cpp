#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string values[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
string suits[] = {"Clubs","Diamonds","Hearts","Spades"};
string Deck[53];

void initDeck()
{
	for (int i=1; i<53; i++)
			Deck[i] = values[(i-1)%13] + " of " + suits[(i-1)/13];


	return;
}

void Map(string SourceDeck[], string TargetDeck[], vector< vector<int> > ShuffleMaps, int ShuffleNumber)
{
	for (int i=1; i<53; i++)
		TargetDeck[i] = SourceDeck[ShuffleMaps[ShuffleNumber][i]]; 
	
}
int main()
{
	int N;
	scanf("%d\n",&N);

	for (int i=0; i<N; i++)
	{
		
		scanf("\n");

		int nShuffles;
		scanf("%d\n",&nShuffles);

		vector< vector<int> > ShuffleMaps;
		
		ShuffleMaps.push_back( *(new vector<int>));
		for (int j=1; j<=nShuffles; j++)
		{
			ShuffleMaps.push_back( *(new vector<int>));
			ShuffleMaps[j].push_back(0);
			for (int k=1; k<53; k++)
			{
				int T;
				scanf("%d",&T);
				ShuffleMaps[j].push_back(T);
			}
		}

		vector<int> Shuffles;

		char Input[1000];
		scanf("\n");

		while(fgets(Input,5,stdin)!=NULL)
		{
			int T;
			if (Input[0] == '\n') break;
			stringstream s(Input);
			s >> T;
			Shuffles.push_back(T);
		}

		
		initDeck();
		
		for (int j=0; j<Shuffles.size(); j++)
		{
			string TempDeck[53];
			Map(Deck,TempDeck,ShuffleMaps,Shuffles[j]);

			for (int k=1; k<53; k++) Deck[k] = TempDeck[k];

		}

		for (int k=1; k<53; k++) 
		{
			cout << Deck[k];

			cout << endl;
		}

		if (i != N-1) cout << endl;
		
	}

	return 0;

}