//HEADER_GOES_HERE
#ifndef __RENDER_H__
#define __RENDER_H__

void drawTopArchesUpperScreen(BYTE *pBuff);
void drawBottomArchesUpperScreen(BYTE *pBuff, unsigned int *pMask);
void drawUpperScreen(BYTE *pBuff);
void drawTopArchesLowerScreen(BYTE *pBuff);
void drawBottomArchesLowerScreen(BYTE *pBuff, unsigned int *pMask);
void drawLowerScreen(BYTE *pBuff);
void world_draw_black_tile(BYTE *pBuff);

/* rdata */

extern int WorldBoolFlag;
extern unsigned int gdwCurrentMask;
// extern char world_4B3264;
extern unsigned char *gpCelFrame;
extern unsigned int *gpDrawMask;
// extern char world_4B326D[16];
extern unsigned int RightMask[32];
extern unsigned int LeftMask[32];
extern unsigned int WallMask[32];
extern int WorldTbl3x16[48];
extern int WorldTbl17_1[17];
extern int WorldTbl17_2[17];


//SDL RENDER STUFF
BOOL LoadArtImage(char *pszFile, void **pBuffer, int frames, DWORD *data);



#endif /* __RENDER_H__ */
