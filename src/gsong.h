#ifndef GSONG_H
#define GSONG_H

#ifndef GSONG_C
extern INSTR instr[MAX_INSTR];

extern unsigned char detailedTableRValue[MAX_TABLELEN];
extern unsigned char detailedTableMaxRValue[MAX_TABLELEN];
extern unsigned char detailedTableMinRValue[MAX_TABLELEN];
extern int detailedTableBaseRValue[MAX_TABLELEN];

extern unsigned int detailedTableLValue[MAX_TABLELEN];
extern unsigned char detailedTableMaxLValue[MAX_TABLELEN];
extern unsigned char detailedTableMinLValue[MAX_TABLELEN];
extern int detailedTableBaseLValue[MAX_TABLELEN];

extern unsigned char ltable[MAX_TABLES][MAX_TABLELEN];
extern unsigned char rtable[MAX_TABLES][MAX_TABLELEN];
extern unsigned char songorder[MAX_SONGS][MAX_CHN][MAX_SONGLEN+2];
extern unsigned char pattern[MAX_PATT][MAX_PATTROWS*4+4];
extern char songname[MAX_STR];
extern char authorname[MAX_STR];
extern char copyrightname[MAX_STR];
extern int pattlen[MAX_PATT];
extern int songlen[MAX_SONGS][MAX_CHN];
extern int highestusedpattern;
extern int highestusedinstr;
extern int loadedSongCount;
#endif

int loadsong(GTOBJECT *gt);
int mergesong(GTOBJECT *gt);
void loadinstrument(GTOBJECT *gt);
int savesong(void);
int saveinstrument(void);
void clearsong(int cs, int cp, int ci, int cf, int cn,GTOBJECT *gt);
void countpatternlengths(void);
void countthispattern(GTOBJECT *gt);
void clearpattern(int p);
int insertpattern(int p, GTOBJECT *gt);
void deletepattern(int p, GTOBJECT *gt);
void findusedpatterns(void);
void findduplicatepatterns(GTOBJECT *gt);
void optimizeeverything(int oi, int ot,GTOBJECT *gt);
void initQuickPlay();
void setQuickPlay(int song, int channel, int patternOffset, GTOBJECT *gt, int updateCounter);
int getQuickPlayChannels(int song, int channel, int patternOffset, GTOBJECT *gt, int updateCounter);

typedef struct
{
	CHN chn[MAX_PLAY_CH];
	int updateCounter;	// if this doesn't match the undo counter, we need to do a play song from beginning to calculate chn struct info
} CHN_QUICKPLAY;

#endif
