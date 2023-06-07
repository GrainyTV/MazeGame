#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Eredmenykezelo.h"

void eredmenykezelo(int ido, int nehezseg)
{
	if(ido < 5999000)
	{
		FILE *fp;
		fp = fopen("results.txt", "r");

		time_t nyers_ido = time(NULL);
		struct tm *ptm = localtime(&nyers_ido);

		if(fp == NULL)
		{
			fp = fopen("results.txt", "a");
			switch(nehezseg)
			{
			case 1:
				fprintf(fp,"[%d.%02d.%02d %02d:%02d] [ EASY ] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			case 2:
				fprintf(fp,"[%d.%02d.%02d %02d:%02d] [MEDIUM] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			case 3:
				fprintf(fp,"[%d.%02d.%02d %02d:%02d] [ HARD ] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			}
		}
		else
		{
			fp = fopen("results.txt", "a");
			switch(nehezseg)
			{
			case 1:
				fprintf(fp,"\n[%d.%02d.%02d %02d:%02d] [ EASY ] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			case 2:
				fprintf(fp,"\n[%d.%02d.%02d %02d:%02d] [MEDIUM] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			case 3:
				fprintf(fp,"\n[%d.%02d.%02d %02d:%02d] [ HARD ] [%02d:%02d]", ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min,((ido/1000)/60),((ido/1000)%60));
				break;
			}
		}

		fclose(fp);
	}
}
