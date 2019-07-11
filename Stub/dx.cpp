//#include "dx_stub.h"
#include "miniwin_sdl.h"

#include "../types.h"
#include "stubs.h"



//additional Vars
int sgdwLockCount;
static CCritSect sgMemCrit;
BYTE *sgpBackBuf;

//End




#ifndef NO_GLOBALS
//Screen *gpBuffer;

IDirectDraw *lpDDInterface;
IDirectDrawSurface *lpDDSPrimary;
IDirectDrawSurface *lpDDSBackBuf;
IDirectDrawPalette *lpDDPalette;

char gbBackBuf; // unread
char gbEmulate; // unread
#endif

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;

/** 32-bit in-memory backbuffer surface */
SDL_Surface *surface;

/** 8-bit surface wrapper around #gpBuffer */
SDL_Surface *pal_surface;
/** Currently active palette */
SDL_Palette *palette;


/**
 * Is #sdl_pal_surface dirty?
 *
 * This is required so the front buffer would not be updated twice per game loop in unlock_buf_priv()
 * which causes the cursor to flicker.
 */
bool surface_dirty;

//
// DirectDraw COM interface stub implementations
//

#define METHOD virtual __stdcall
//int zfoo = 0;
class StubSurface : public IDirectDrawSurface
{
	METHOD HRESULT QueryInterface(REFIID refiid, LPVOID *lpvoid) { UNIMPLEMENTED(); };
	METHOD ULONG AddRef() { UNIMPLEMENTED(); };
	METHOD ULONG Release() { UNIMPLEMENTED(); };

	METHOD HRESULT AddAttachedSurface(LPDIRECTDRAWSURFACE lpDDSAttachedSurface) { UNIMPLEMENTED(); }
	METHOD HRESULT AddOverlayDirtyRect(LPRECT lpRect) { UNIMPLEMENTED(); }
	METHOD HRESULT Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags,
	                   LPDDBLTFX lpDDBltFx)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags) { UNIMPLEMENTED(); }


unsigned int rand_interval(unsigned int min, unsigned int max)
{
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}






	METHOD HRESULT BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
	{
		DUMMY_ONCE();
		

		//gpBuffer = sgpBackBuf;
		assert(lpDDSrcSurface == lpDDSBackBuf);
		int w = lpSrcRect->right - lpSrcRect->left + 1;
		int h = lpSrcRect->bottom - lpSrcRect->top + 1;

		SDL_Rect src_rect = {lpSrcRect->left, lpSrcRect->top, w, h};
		SDL_Rect dst_rect = {(int)dwX, (int)dwY, w, h};


		//printf("SRC   %d %d %d %d \n",src_rect.x, src_rect.y, src_rect.w, src_rect.h  );
		//printf("DST   %d %d %d %d \n",dst_rect.x, dst_rect.y, dst_rect.w, dst_rect.h  );

		// Convert from 8-bit to 32-bit

			// int red = rand_interval(1,255);
			// int blue = rand_interval(1,255);
			// int green = rand_interval(1,255);

		 	// SDL_FillRect(pal_surface, NULL, SDL_MapRGB(pal_surface->format, red, blue, green));
		 	

		// }
	
		// test function  -- SDL_FillRect(pal_surface, NULL, SDL_MapRGB(pal_surface->format, 255, 255, 255));
		SDL_CHECK(SDL_BlitSurface(pal_surface, &src_rect, surface, &dst_rect));// coppies PAL SURFACE to SURFACE which is then presented.
		surface_dirty = true;
		return S_OK;

	}

	METHOD HRESULT DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSAttachedSurface) { UNIMPLEMENTED(); }
	METHOD HRESULT EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT Flip(LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride, DWORD dwFlags) { UNIMPLEMENTED(); }
	METHOD HRESULT GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE *lplpDDAttachedSurface)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT GetBltStatus(DWORD dwFlags) { UNIMPLEMENTED(); }
	METHOD HRESULT GetCaps(LPDDSCAPS lpDDSCaps) { UNIMPLEMENTED(); }
	METHOD HRESULT GetClipper(LPDIRECTDRAWCLIPPER *lplpDDClipper) { UNIMPLEMENTED(); }
	METHOD HRESULT GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) { UNIMPLEMENTED(); }

	METHOD HRESULT GetDC(HDC *lphDC)
	{
		DUMMY_ONCE();
		return S_OK;
	}

	METHOD HRESULT GetFlipStatus(DWORD dwFlags) { UNIMPLEMENTED(); }
	METHOD HRESULT GetOverlayPosition(LPLONG lplX, LPLONG lplY) { UNIMPLEMENTED(); }
	METHOD HRESULT GetPalette(LPDIRECTDRAWPALETTE *lplpDDPalette) { UNIMPLEMENTED(); }
	METHOD HRESULT GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat) { UNIMPLEMENTED(); }
	METHOD HRESULT GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc) { UNIMPLEMENTED(); }
	METHOD HRESULT Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc) { UNIMPLEMENTED(); }

	METHOD HRESULT IsLost()
	{
		DUMMY_ONCE();
		return S_OK;
	}

	METHOD HRESULT Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
	{
		UNIMPLEMENTED();
	}

	METHOD HRESULT ReleaseDC(HDC hDC)
	{
		DUMMY_ONCE();
		return S_OK;
	}

	METHOD HRESULT Restore() { UNIMPLEMENTED(); }
	METHOD HRESULT SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper) { UNIMPLEMENTED(); }
	METHOD HRESULT SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey) { UNIMPLEMENTED(); }
	METHOD HRESULT SetOverlayPosition(LONG lX, LONG lY) { UNIMPLEMENTED(); }
	METHOD HRESULT SetPalette(LPDIRECTDRAWPALETTE lpDDPalette) { UNIMPLEMENTED(); }
	METHOD HRESULT Unlock(LPVOID lpSurfaceData) { UNIMPLEMENTED(); }
	METHOD HRESULT UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE lpDDDestSurface, LPRECT lpDestRect,
	                             DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT UpdateOverlayDisplay(DWORD dwFlags) { UNIMPLEMENTED(); }
	METHOD HRESULT UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSReference) { UNIMPLEMENTED(); }
};

class StubPalette : public IDirectDrawPalette
{
	METHOD HRESULT QueryInterface(REFIID refiid, LPVOID *lpvoid) { UNIMPLEMENTED(); };
	METHOD ULONG AddRef() { UNIMPLEMENTED(); };
	METHOD ULONG Release() { UNIMPLEMENTED(); };

	METHOD HRESULT GetCaps(LPDWORD lpdwCaps) { UNIMPLEMENTED(); };
	METHOD HRESULT GetEntries(DWORD dwFlags, DWORD dwBase, DWORD dwNumEntries, LPPALETTEENTRY lpEntries)
	{
		UNIMPLEMENTED();
	};
	METHOD HRESULT Initialize(LPDIRECTDRAW lpDD, DWORD dwFlags, LPPALETTEENTRY lpDDColorTable) { UNIMPLEMENTED(); };
	METHOD HRESULT SetEntries(DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries)
	{
		UNIMPLEMENTED();
	};
};

class StubDraw : public IDirectDraw
{
	METHOD HRESULT QueryInterface(REFIID refiid, LPVOID *lpvoid) { UNIMPLEMENTED(); };
	METHOD ULONG AddRef() { UNIMPLEMENTED(); };
	METHOD ULONG Release() { UNIMPLEMENTED(); };

	METHOD HRESULT Compact() { UNIMPLEMENTED(); }
	METHOD HRESULT CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER *lplpDDClipper, IUnknown *pUnkOuter)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE *lplpDDPalette,
	                             IUnknown *pUnkOuter)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT CreateSurface(LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE *lplpDDSurface,
	                             IUnknown *pUnkOuter)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT DuplicateSurface(LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE *lplpDupDDSurface)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext,
	                                LPDDENUMMODESCALLBACK lpEnumModesCallback)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext,
	                            LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
	{
		UNIMPLEMENTED();
	}
	METHOD HRESULT FlipToGDISurface() { UNIMPLEMENTED(); }
	METHOD HRESULT GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps) { UNIMPLEMENTED(); }
	METHOD HRESULT GetDisplayMode(LPDDSURFACEDESC lpDDSurfaceDesc) { UNIMPLEMENTED(); }
	METHOD HRESULT GetFourCCCodes(LPDWORD lpNumCodes, LPDWORD lpCodes) { UNIMPLEMENTED(); }
	METHOD HRESULT GetGDISurface(LPDIRECTDRAWSURFACE *lplpGDIDDSurface) { UNIMPLEMENTED(); }
	METHOD HRESULT GetMonitorFrequency(LPDWORD lpdwFrequency) { UNIMPLEMENTED(); }
	METHOD HRESULT GetScanLine(LPDWORD lpdwScanLine) { UNIMPLEMENTED(); }
	METHOD HRESULT GetVerticalBlankStatus(BOOL *lpbIsInVB) { UNIMPLEMENTED(); }
	METHOD HRESULT Initialize(GUID *lpGUID) { UNIMPLEMENTED(); }
	METHOD HRESULT RestoreDisplayMode() { UNIMPLEMENTED(); }
	METHOD HRESULT SetCooperativeLevel(HWND hWnd, DWORD dwFlags) { UNIMPLEMENTED(); }
	METHOD HRESULT SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP) { UNIMPLEMENTED(); }
	METHOD HRESULT WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
	{
		DUMMY();
		return S_OK;
	}
};

static StubDraw stub_draw;
static StubSurface stub_surface;
static StubPalette stub_palette;

//
// Main functions
//

void sdl_init_video()
{
	SDL_CHECK(SDL_Init(SDL_INIT_VIDEO));
	//moved to SDLrender.cpp

/*

	window =  SDL_CreateWindow("devil-test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	assert(window);

	// Hack since ShowCursor is called before dx_init()
	SDL_ShowCursor(SDL_DISABLE);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	assert(renderer);


	// FUTURE: Use SDL_CreateRGBSurfaceWithFormat with SDL_PIXELFORMAT_RGBA8888
	palette = SDL_AllocPalette(256);

	assert(palette);*/
}

void  dx_init(HWND hWnd)
{
	DUMMY();

	sdl_init_video();

	gbActive = TRUE;

	lpDDInterface = &stub_draw;
	lpDDSPrimary = &stub_surface;
	lpDDSBackBuf = &stub_surface;
	lpDDPalette = &stub_palette;
}

/** Copy the palette surface to the main backbuffer */
void sdl_update_entire_surface()
{

	assert(surface && pal_surface);
	SDL_Rect src_rect = {64, 160, 640, 480};
	SDL_CHECK(SDL_BlitSurface(pal_surface, &src_rect, surface, NULL));
}

void sdl_present_surface()
{	
	//assert(!SDL_MUSTLOCK(surface));
	SDL_CHECK(SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch));//pitch is 2560

	SDL_CHECK(SDL_RenderCopy(renderer, texture, NULL, NULL));
	SDL_RenderPresent(renderer);

	surface_dirty = false;
}


//CHANGE REMOVE LATER
// struct ScreenRow
// {
// 	char col_unused_1[64];
// 	char pixels[640];
// 	char col_unused_2[64];
// };

// struct Screen /* create union for work data vs visible data */
// {
// 	ScreenRow row_unused_1[160];
// 	ScreenRow row[480];
// 	ScreenRow row_unused_2[16];
// };




void __cdecl lock_buf_priv()
{

	if (!gpBuffer) {
		printf(" GpBuffer Created\n ");
		const int pitch = 640 + 64 + 64;
		gpBuffer = (BYTE *)malloc(503808);
		gpBufEnd += (unsigned int)gpBuffer;


		pal_surface = SDL_CreateRGBSurfaceFrom(gpBuffer, pitch, 160 + 480 + 16, 8, pitch, 0, 0, 0, 0);
		SDL_SetSurfacePalette(pal_surface, palette);
		assert(pal_surface);

		SDL_CHECK(SDL_SetSurfacePalette(pal_surface, palette));
	}

	unlock_buf_priv();


}

// void lock_buf_priv()
// {
// 	DDSURFACEDESC ddsd;
// 	HRESULT error_code;

// #ifdef __cplusplus
// 	sgMemCrit.Enter();
// #endif
// 	if (sgpBackBuf != NULL) {
// 		gpBuffer = sgpBackBuf;
// 		sgdwLockCount++;
// 		return;
// 	}

// 	if (lpDDSBackBuf == NULL) {
// 		Sleep(20000);
// 		app_fatal("lock_buf_priv");
// 		sgdwLockCount++;
// 		return;
// 	}

// 	if (sgdwLockCount != 0) {
// 		sgdwLockCount++;
// 		return;
// 	}
// 	ddsd.dwSize = sizeof(ddsd);
// #ifdef __cplusplus
// 	error_code = lpDDSBackBuf->Lock(NULL, &ddsd, 0, NULL);
// #else
// 	error_code = lpDDSBackBuf->lpVtbl->Lock(lpDDSBackBuf, NULL, &ddsd, DDLOCK_WAIT, NULL);
// #endif
// 	if (error_code != S_OK)
// 		DDErrMsg(error_code, 235, "C:\\Src\\Diablo\\Source\\dx.cpp");

// 	gpBufEnd += (uintptr_t)ddsd.lpSurface;
// 	gpBuffer = (BYTE *)ddsd.lpSurface;
// 	sgdwLockCount++;
// }











void __cdecl unlock_buf_priv()
{
	gpBufEnd -= (unsigned int)gpBufEnd;
		


	if (!surface_dirty) {
		return;
	}

	sdl_present_surface();
}

void __cdecl dx_reinit()
{
	UNIMPLEMENTED();
}

//
// Storm functions
//



BOOL STORMAPI SDrawUpdatePalette(unsigned int firstentry, unsigned int numentries, PALETTEENTRY *pPalEntries, int a4)
{
//	DUMMY_PRINT("first: %d num: %d", firstentry, numentries);




	assert(firstentry == 0);
	assert(numentries == 256);

	SDL_Color colors[256];
	for (int i = firstentry; i < numentries; i++) {
		SDL_Color *c = &colors[i];
		PALETTEENTRY *p = &pPalEntries[i];
		c->r = p->peRed;
		c->g = p->peGreen;
		c->b = p->peBlue;
		c->a = SDL_ALPHA_OPAQUE;
	}

	assert(palette);
	SDL_CHECK(SDL_SetPaletteColors(palette, colors, firstentry, numentries));
	//printf("Is this ever hit?\n");
	if (pal_surface) {
		sdl_update_entire_surface();
		sdl_present_surface();
	}

	return TRUE;
}

//
// Windows API functions
//

WINBOOL WINAPI SetCursorPos(int X, int Y)
{
	DUMMY();
	assert(window);
	SDL_WarpMouseInWindow(window, X, Y);
	return TRUE;
}

int WINAPI ShowCursor(WINBOOL bShow)
{
	DUMMY_PRINT("%d", bShow);
	if (window) {
		SDL_ShowCursor(bShow ? SDL_ENABLE : SDL_DISABLE);
	}
	return bShow;
}

WINBOOL WINAPI TextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c)
{
	DUMMY_ONCE();

	assert(window);
	SDL_SetWindowTitle(window, lpString);

	return TRUE;
}