#pragma once

#include <Windows.h>

class BitmapBits
{
public:
	BitmapBits() { bits = NULL; memset( &bmp, 0, sizeof( BITMAP ) ); };
	~BitmapBits() { clear(); };
	bool load( const char *path )
	{
		clear();
		HBITMAP hbitmap = (HBITMAP) ::LoadImage( NULL, path,
			IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );
		if( !hbitmap ) return false;
		::GetObject( hbitmap, sizeof( BITMAP ), &bmp );
		bits = new unsigned char[ bmp.bmHeight * bmp.bmWidthBytes ];
		HDC hdc = GetDC( NULL );
		BITMAPINFO bi = { { sizeof(BITMAPINFOHEADER), bmp.bmWidth, bmp.bmHeight, bmp.bmPlanes, bmp.bmBitsPixel } };
		::GetDIBits( hdc, hbitmap, 0, bmp.bmHeight, bits, &bi, DIB_RGB_COLORS );
		ReleaseDC( NULL, hdc );
		::DeleteObject( hbitmap );
		return true;
	}
	void clear( void )
	{
		if( bits ) { delete bits; bits = NULL; }
		memset( &bmp, 0, sizeof( BITMAP ) );
	}
	unsigned char* getBits( void ) { return bits; }
	int getWidth( void ) { return bmp.bmWidth; }
	int getHeight( void ) { return bmp.bmHeight; }
	int getBitsPerPixel( void ) { return bmp.bmBitsPixel; }
	int getBitsPerLine( void ) { return bmp.bmWidthBytes; }
protected:
	BITMAP bmp;
	unsigned char *bits;
};